void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {

				XRDB_LOAD_COLOR("dwm.color7", normfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", normbordercolor);
				XRDB_LOAD_COLOR("dwm.color5", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", selfgcolor);
				XRDB_LOAD_COLOR("dwm.color10", selbgcolor);
				XRDB_LOAD_COLOR("dwm.color7", selbordercolor);
				XRDB_LOAD_COLOR("dwm.color7", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.color7", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.color5", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.color10", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.color7", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.color7", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color7", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.color5", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.color10", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.color7", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.color7", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color7", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.color9", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.color9", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.color9", urgfloatcolor);

				XrmDestroyDatabase(xrdb);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}

