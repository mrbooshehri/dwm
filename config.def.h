/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const int corner_radius           = 0;
static const unsigned int snap           = 24;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 4;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 4;  /* vert inner gap between windows */
static const unsigned int gappoh         = 4;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 4;  /* vert outer gap between windows and screen edge */
static const int smartgaps               = 1;   /* 1 means no outer gap when there is only one window */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int usealtbar               = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass           = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd             = "$HOME/bar.sh"; /* Alternate bar launch command */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 0;  /* vertical padding of bar */
static const int sidepad                 = 0;  /* horizontal padding of bar */
static const int focusonwheel            = 0;
static const int horizpadbar             = 2;   /* horizontal padding for statusbar */
static const int vertpadbar              = 7;   /* vertical padding for statusbar */
static const char buttonbar[]            = "";
static const unsigned int systrayspacing = 3;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char font[]                 = "Font Awesome 6 Pro Regular 10";
static const char dmenufont[]            = "monospace:size=10";

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidfgcolor[]                 = "#005577";
static char hidbgcolor[]                 = "#222222";
static char hidbordercolor[]             = "#005577";
static char hidfloatcolor[]              = "#f76e0c";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";



static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHid]          = { hidfgcolor,       hidbgcolor,       hidbordercolor,       hidfloatcolor },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};



static const char *layoutmenu_cmd = "layoutmenu.sh";



/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "", "", "", "", "", "", "", "", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Alacritty", .isterminal= 1)
	RULE(.class = "MEGAsync", .isfloating = 1)
	RULE(.class = "Skype", .isfloating = 1)
	RULE(.class = "Safeeyes", .isfloating = 1)
	RULE(.class = "Variety", .isfloating = 1)
	RULE(.class = "Gpick", .isfloating = 1)
	RULE(.class = "SpeedCrunch", .isfloating = 1)
	RULE(.class = "VirtualBox Manager", .isfloating = 1)
	RULE(.class = "Software-properties-gtk", .isfloating = 1)
	RULE(.class = "Gnome-calendar", .isfloating = 1)
	RULE(.class = "Gnome-calculator", .isfloating = 1)
	RULE(.class = "Blueman-manager", .isfloating = 1)
	RULE(.class = "Pavucontrol", .isfloating = 1)
	RULE(.class = "Hamster", .isfloating = 1)
	RULE(.class = "Orage", .isfloating = 1)
	RULE(.class = "Firefox", .tags = 1 << 1)
	RULE(.class = "Brave-browser", .tags = 1 << 1)
	RULE(.class = "LibreWolf", .tags = 1 << 1)
	RULE(.class = "firefox", .tags = 1 << 1)
	RULE(.class = "qutebrowser", .tags = 1 << 1)
	RULE(.class = "Code", .tags = 1 << 2)
	RULE(.class = "jetbrains-studio", .tags = 1 << 2)
	RULE(.class = "obs", .tags = 1 << 3)
	RULE(.class = "korganizer", .tags = 1 << 4)
	RULE(.class = "Gpodder", .tags = 1 << 5)
	RULE(.class = "Tor Browser", .tags = 1 << 6)
	RULE(.class = "Transmission-gtk", .tags = 1 << 6)
	RULE(.class = "Rambox", .tags = 1 << 7)
	RULE(.class = "TelegramDesktop", .tags = 1 << 7)
	RULE(.class = "Signal", .tags = 1 << 7)
	RULE(.class = "Spotify", .tags = 1 << 8)
};

static const MonitorRule monrules[] = {
	/* monitor  tag   layout  mfact  nmaster  showbar  topbar */
	{  1,       -1,   2,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor
	{  -1,      -1,   0,      -1,    -1,      -1,      -1     }, // default
};


/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor  bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,       0,     BAR_ALIGN_LEFT,   width_stbutton,          draw_stbutton,          click_stbutton,          "statusbutton" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" },
	{  0,       0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" },
	{ -1,       0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" },
	{ 'A',      0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_statuscmd,         "status2d" },
	{  0,       0,     BAR_ALIGN_RIGHT,  width_xkb,               draw_xkb,               click_xkb,               "xkb" },
	{ -1,       0,     BAR_ALIGN_NONE,   width_wintitle,          draw_wintitle,          click_wintitle,          "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */



static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ "|||",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ ">M>",      flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "[D]",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "TTT",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "===",      flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "-M-",      flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ ":::",      flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "(@)",      flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "[T]",      flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	{ NULL,       NULL,             {0} },
};

/* xkb frontend */
static const char *xkb_layouts[]  = {
	"[EN]",
	"[FA]",
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "alacritty", NULL };



static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_j,          rotatestack,            {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_k,          rotatestack,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_j,          pushdown,               {0} },
	{ MODKEY|ControlMask,           XK_k,          pushup,                 {0} },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_r,          self_restart,           {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   /* flextile, 2 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|Mod5Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|Mod5Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
	{ MODKEY|Mod5Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|Mod5Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|ControlMask,           XK_Return,     mirrorlayout,           {0} },          /* flextile, flip master and stack areas */
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY|ShiftMask,             XK_f,          fullscreen,             {0} },
	{ MODKEY,                       XK_minus,      scratchpad_show,        {0} },
	{ MODKEY|ShiftMask,             XK_minus,      scratchpad_hide,        {0} },
	{ MODKEY,                       XK_equal,      scratchpad_remove,      {0} },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY,                       XK_n,          togglealttag,           {0} },
	{ MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
	{ MODKEY,                       XK_F1,         mpdchange,              {.i = -1} },
	{ MODKEY,                       XK_F2,         mpdchange,              {.i = +1} },
	{ MODKEY,                       XK_Escape,     mpdcontrol,             {0} },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = dmenucmd } },
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigdwmblocks,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigdwmblocks,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigdwmblocks,   {.i = 3 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum                    function */
	{ "focusstack",              focusstack },
	{ "setmfact",                setmfact },
	{ "togglebar",               togglebar },
	{ "incnmaster",              incnmaster },
	{ "togglefloating",          togglefloating },
	{ "focusmon",                focusmon },
	{ "movestack",               movestack },
	{ "rotatestack",             rotatestack },
	{ "pushdown",                pushdown },
	{ "pushup",                  pushup },
	{ "incnstack",               incnstack },
	{ "rotatelayoutaxis",        rotatelayoutaxis },
	{ "setlayoutaxisex",         setlayoutaxisex },
	{ "mirrorlayout",            mirrorlayout },
	{ "setcfact",                setcfact },
	{ "tagmon",                  tagmon },
	{ "zoom",                    zoom },
	{ "incrgaps",                incrgaps },
	{ "incrigaps",               incrigaps },
	{ "incrogaps",               incrogaps },
	{ "incrihgaps",              incrihgaps },
	{ "incrivgaps",              incrivgaps },
	{ "incrohgaps",              incrohgaps },
	{ "incrovgaps",              incrovgaps },
	{ "togglegaps",              togglegaps },
	{ "defaultgaps",             defaultgaps },
	{ "setgaps",                 setgapsex },
	{ "view",                    view },
	{ "viewall",                 viewallex },
	{ "viewex",                  viewex },
	{ "toggleview",              toggleview },
	{ "self_restart",            self_restart },
	{ "cyclelayout",             cyclelayout },
	{ "mpdchange",               mpdchange },
	{ "mpdcontrol",              mpdcontrol },
	{ "toggleviewex",            toggleviewex },
	{ "tag",                     tag },
	{ "tagall",                  tagallex },
	{ "tagex",                   tagex },
	{ "toggletag",               toggletag },
	{ "toggletagex",             toggletagex },
	{ "togglealttag",            togglealttag },
	{ "fullscreen",              fullscreen },
	{ "killclient",              killclient },
	{ "xrdb",                    xrdb },
	{ "quit",                    quit },
	{ "setlayout",               setlayout },
	{ "setlayoutex",             setlayoutex },
};

