/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Cantarell:size=8" };
static const char dmenufont[]       = "Cantarell:size=8";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const char *const autostart[] = {
	"/home/ogir_ok/dwm/autostart.sh", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "Internet", "Messaging", "IDE", "Office", "Mail", "Media", "etc", "8", "9" };


static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",       NULL,       NULL,       0,            True,        -1 },
    { "guake",     NULL,       NULL,       0,            True,     -1 },
    { "Guake",     NULL,       NULL,       0,            True,     -1 },
	{ "firefox",    NULL,       NULL,       1,            False,       -1 },
	{ "Firefox",    NULL,       NULL,       1,            False,       -1 },
	{ "google-chrome",   NULL,       NULL,       1,            False,       -1 },
	{ "Google-chrome",   NULL,       NULL,       1,            False,       -1 },
	{ "gvim",       NULL,       NULL,       1 << 2,       False,       -1 },
	{ "Gvim",       NULL,       NULL,       1 << 2,       False,       -1 },
	{ "jetbrains-pycharm",       NULL,       NULL,       1 << 2,       False,       -1 },
	{ "Prospect Mail",   NULL,       NULL,       1 << 4,       False,       -1 },
	{ "prospect mail",   NULL,       NULL,       1 << 4,       False,       -1 },
	{ "Mail",   NULL,       NULL,       1 << 4,       False,       -1 },
	{ "Thunderbird",   NULL,       NULL,       1 << 4,       False,       -1 },
	{ "microsoft teams - preview",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Microsoft Teams - Preview",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "skype",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Skype",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "telegram-desktop",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "TelegramDesktop",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "slack",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Slack",      NULL,       NULL,       1 << 1,       False,       -1 },
	{ "zoom",      NULL,       NULL,       1 << 8,       False,       -1 },
	{ "Deluge",      NULL,       NULL,       1 << 6,       False,       -1 },
	{ "deluge",      NULL,       NULL,       1 << 6,       False,       -1 },
	{ "PacketTracer6",      NULL,       NULL,       0,       True,       -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };
static const char *gvimcmd[]  = { "gvim", NULL };
static const char *pycharmcmd[]  = { "pycharm", NULL };
static const char *chromiumcmd[]  = { "google-chrome-stable", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */
	{ Mod1Mask|ControlMask,         XK_y,      spawn,          {.v = gvimcmd } },
	{ Mod1Mask|ControlMask,         XK_u,      spawn,          {.v = pycharmcmd } },
	{ Mod1Mask|ControlMask,         XK_i,      spawn,          {.v = firefoxcmd } },
	{ Mod1Mask|ControlMask,         XK_o,      spawn,          {.v = chromiumcmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_grave,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

