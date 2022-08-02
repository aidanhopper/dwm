/* See LICENSE file for copyright and license details. */ 
// #include "/home/aidan/.cache/wal/colors-wal-dwm.h"
/* appearance */
static const unsigned int gapsize   = 20;
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = gapsize;       /* horiz inner gap between windows */
static const unsigned int gappiv    = gapsize;       /* vert inner gap between windows */
static const unsigned int gappoh    = gapsize;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = gapsize;       /* vert outer gap between windows and screen edge */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font Mono:size=16" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=15";

static const char nord0[]  = "#2e3440"; // darks
static const char nord1[]  = "#3b4252"; 
static const char nord2[]  = "#434c5e";
static const char nord3[]  = "#4c566a";
static const char nord4[]  = "#d8dee9"; // lights
static const char nord5[]  = "#e5e9f0";
static const char nord6[]  = "#eceff4";
static const char nord7[]  = "#8fbcbb"; // blues
static const char nord8[]  = "#88c0d0";
static const char nord9[]  = "#81a1c1";
static const char nord10[] = "#5e81ac";
static const char nord11[] = "#bf616a"; // red
static const char nord12[] = "#d08770"; // orange
static const char nord13[] = "#ebcb8b"; // yellow
static const char nord14[] = "#a3be8c"; // green 
static const char nord15[] = "#b48ead"; // purple

static char const bg[] = "#2e3440"; 
static char const fg[] = "#d8dee9";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { fg,        bg,        bg},
	[SchemeSel]  = { "#eceff4",        nord1,     nord9},

};


/* tagging */
static const char *tags[] = { "  ", "  ", "  ", " ﭮ ", "  ", "  " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          		 instance    		title       	        tags mask     isfloating   monitor */
	{ "Gimp",         		 NULL,       		NULL,       	        1 << 2,       0,           -1 },
	{ "Chromium",      		 NULL,       		NULL,       	        1 << 1,       0,           -1 },
	{ "discord",      		 NULL,       		NULL,       	        1 << 3,       0,           -1 },
	{ "libreoffice", 		   NULL,          NULL,       	        1 << 2,       0,           -1 },
	{ NULL,  			         "libreoffice", NULL,       	        1 << 2,       0,           -1 },
	{ NULL,  			         NULL, 			    "LibreOffice",        1 << 2,       0,           -1 },
	{ "obs",      	  		 NULL,       		NULL,       	        1 << 4,       0,           -1 },
	{ "Lutris",      		   NULL,       		NULL,       	        1 << 4,       0,           -1 },
	{ "Steam",    	  		 NULL,       		NULL,       	        1 << 4,       0,           -1 },
	{ "Zathura", 	  		   NULL,       		NULL,       	        1 << 2,       0,           -1 },
	{ NULL,     	  		   NULL,          "Spotify",           	1 << 5,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]",      tile },    /* first entry is default */
	{ "[缾]",      NULL },    /* no layout function means floating behavior */
	{ "[]",      monocle },
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
static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", nord0, "-nf", nord4, "-sf", nord6, "-sb", nord3, NULL };
static const char *termcmd[]       = { "st", NULL };
static const char *webcmd[]        = { "chromium", NULL };
static const char *screenshotcmd[] = { "scrot", NULL };

static Key keys[] = {
	/* modifier                     key             function        argument */
	{ MODKEY,                       XK_r,           spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, 	spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      	spawn,          {.v = webcmd } },
	{ MODKEY|ShiftMask,             XK_o,      	spawn,          {.v = screenshotcmd } },
	{ MODKEY,                       XK_p,      	togglebar,      {0} },
	{ MODKEY,                       XK_j,      	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      	focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      	incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      	incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      	setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      	setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_n,      	zoom,           {0} },
	{ MODKEY,                       XK_Tab,    	view,           {0} },
	{ MODKEY,                       XK_q,      	killclient,     {0} },
	{ MODKEY,                       XK_t,      	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      	setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      	setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  	setlayout,      {0} },
	{ MODKEY,                       XK_c,      	togglefloating, {0} },
	{ MODKEY,                       XK_0,      	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  	focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 	tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8) { MODKEY|ShiftMask,             XK_q,           quit,           {0} },
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

