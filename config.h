static const char BROWSER[] = "firefox";
/* See LICENSE file for copyright and license details. */ 
// #include "/home/aidan/.cache/wal/colors-wal-dwm.h" appearance */

// #define CLICKABLE_BLOCKS
static unsigned int borderpx  = 3;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 0;        /* 0 means bottom bar */
static int gappov             = 15;
static const int horizpadbar        = 5;        /* horizontal padding for statusbar */
static const int vertpadbar         = 5;        /* vertical padding for statusbar */
static char font[]            = "JetBrainsMono Nerd Font:size=14";
static char dmenufont[]       = "monospace:size=15";
static const char *fonts[]          = { font };
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
 /*                    fg           bg           border   */
  [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

static char const bg[] = "#2e3440"; 
static char const fg[] = "#d8dee9";


static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
 
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "font",               STRING,  &font },
		{ "font",          STRING,  &dmenufont },
		{ "color0",        STRING,  &normbgcolor },
		{ "color0",    STRING,  &normbordercolor },
		{ "color7",        STRING,  &normfgcolor },
		{ "color8",         STRING,  &selbgcolor },
		{ "color8",     STRING,  &selbordercolor },
		{ "color15",         STRING,  &selfgcolor },
		// { "borderpx",          	INTEGER, &borderpx },
		// { "snap",          		  INTEGER, &snap },
		// { "showbar",          	INTEGER, &showbar },
		// { "topbar",          	  INTEGER, &topbar },
		// { "nmaster",          	INTEGER, &nmaster },
		// { "resizehints",       	INTEGER, &resizehints },
		// { "mfact",      	 	    FLOAT,   &mfact },
};



/* tagging */
static const char *tags[] = { " ??? ", " ??? ", " ??? ", " ??? ", " ??? ", " ??? " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class         instance       title          tags mask  isfloating  center  monitor */
	{ "Gimp",        NULL,       		NULL,       	 1 << 2, 0, 0, -1 },
	{ "Firefox",     NULL,          NULL,       	 1 << 1, 0, 0, -1 },
	{ "discord",     NULL,       		NULL,       	 1 << 3, 0, 0, -1 },
	{ "libreoffice", "libreoffice", "LibreOffice", 1 << 2, 0, 0, -1 },
	{ "obs",      	 NULL,       		NULL,       	 1 << 4, 0, 0, -1 },
	{ "Lutris",      NULL,       		NULL,       	 1 << 4, 0, 0, -1 },
	{ "Steam",    	 NULL,       		NULL,       	 1 << 4, 0, 0, -1 },
	{ "Zathura", 	   NULL,       		NULL,       	 1 << 2, 0, 0, -1 },
	{ "Spotify",     "spotify",     "Spotify",     1 << 5, 0, 1, -1 },
	{ "St",       	 "st",       		"st",       	 0,      0, 1, -1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[???]",      tile },    /* first entry is default */
	{ "[???]",      NULL },    /* no layout function means floating behavior */
	{ "[???]",      monocle },
	{ "[M]",      centeredmaster },
	{ "[F]",      centeredfloatingmaster },

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

#define STATUSBAR "dwmblocks"

/* commands */
static const char *termcmd[]       = { "st", NULL };
static const char *webcmd[]        = { BROWSER, NULL };
static const char *screenshotcmd[] = { "scrot", NULL };

#include <X11/XF86keysym.h>
#include "shift-tools.c"

static Key keys[] = {
	/* modifier                     key             function        argument */
	{ MODKEY,                       XK_r,           spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, 	spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      	spawn,          {.v = webcmd } },
	{ MODKEY|ShiftMask,             XK_o,      	spawn,          {.v = screenshotcmd } },
	{ MODKEY,                       XK_o, shiftviewclients,    { .i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,	shiftview,         { .i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,	shiftview,         { .i = -1 } },
	{ MODKEY,	                      XK_i, shiftviewclients,    { .i = -1 } },
	{ MODKEY,                       XK_p,      	togglebar,      {0} },
	{ MODKEY,                       XK_j,      	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      	focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask,                       XK_i,      	incnmaster,     {.i = +1 } },
	{ MODKEY|ControlMask,                       XK_d,      	incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      	setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      	setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_h,      shiftboth,      { .i = -1 }	},
	{ MODKEY|ControlMask,		XK_h,      shiftswaptags,  { .i = -1 }	},
	{ MODKEY|ControlMask,		XK_l,      shiftswaptags,  { .i = +1 }	},
	{ MODKEY|ShiftMask,             XK_l,      shiftboth,      { .i = +1 }	},
	{ MODKEY,                       XK_n,      	zoom,           {0} },
	{ MODKEY,                       XK_Tab,    	view,           {0} },
	{ MODKEY,                       XK_q,      	killclient,     {0} },
	{ MODKEY,                       XK_t,      	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      	setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_m,      	setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  	setlayout,      {0} },
	{ MODKEY,                       XK_c,      	togglefloating, {0} },
	{ MODKEY,                       XK_0,      	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  	focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 	tagmon,         {.i = +1 } },
	{ MODKEY, XK_v,                 spawn,		 SHCMD("$HOME/.local/bin/powermenu") }, 
	{ 0, XF86XK_AudioMute,		      spawn,		 SHCMD("pamixer -t; pkill -RTMIN+10 dwmblocks") }, 
	{ 0, XF86XK_AudioRaiseVolume,	  spawn,		 SHCMD("pamixer -i 3; pkill -RTMIN+10 dwmblocks") },
	{ 0, XF86XK_AudioLowerVolume,	  spawn,	   SHCMD("pamixer -d 3; pkill -RTMIN+10 dwmblocks") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8) 
  { MODKEY|ShiftMask,             XK_q,           quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

