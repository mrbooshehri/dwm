static int epoll_fd;
static int dpy_fd;
static Monitor *lastselmon;

int
handlexevent(struct epoll_event *ev)
{
	if (ev->events & EPOLLIN) {
		XEvent ev;
		while (running && XPending(dpy)) {
			XNextEvent(dpy, &ev);
			/* Unfortunately the xkbEventType is not constant hence it can't be part of the
			 * normal event handler below */
			if (ev.type == xkbEventType) {
				xkbeventnotify(&ev);
				continue;
			}

			if (handler[ev.type]) {
				handler[ev.type](&ev); /* call handler */
				ipc_send_events(mons, &lastselmon, selmon);
			}
		}
	} else if (ev-> events & EPOLLHUP)
		return -1;

	return 0;
}

void
setlayoutsafe(const Arg *arg)
{
	const Layout *ltptr = (Layout *)arg->v;
	if (ltptr == 0)
		setlayout(arg);
	for (int i = 0; i < LENGTH(layouts); i++) {
		if (ltptr == &layouts[i])
			setlayout(arg);
	}
}

void
setupepoll(void)
{
	epoll_fd = epoll_create1(0);
	dpy_fd = ConnectionNumber(dpy);
	struct epoll_event dpy_event;

	// Initialize struct to 0
	memset(&dpy_event, 0, sizeof(dpy_event));

	DEBUG("Display socket is fd %d\n", dpy_fd);

	if (epoll_fd == -1)
		fputs("Failed to create epoll file descriptor", stderr);

	dpy_event.events = EPOLLIN;
	dpy_event.data.fd = dpy_fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, dpy_fd, &dpy_event)) {
		fputs("Failed to add display file descriptor to epoll", stderr);
		close(epoll_fd);
		exit(1);
	}

	if (ipc_init(ipcsockpath, epoll_fd, ipccommands, LENGTH(ipccommands)) < 0)
		fputs("Failed to initialize IPC\n", stderr);
}

void
setstatus(const Arg *arg)
{
	Monitor *m;
	if (!gettextprop(root, XA_WM_NAME, rawstext, sizeof(rawstext)))
		strcpy(stext, "dwm-"VERSION);
	else
		copyvalidchars(stext, rawstext);
	for (m = mons; m; m = m->next)
		drawbar(m);
}

