/* See LICENSE file for copyright and license details. */

/* constants */
#define TERMINAL    "st"
#define TERMCLASS   "St"
#define BROWSER     "librewolf"
#define STATUSBAR   "dwmblocks"

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 20;  /* vert inner gap between windows */
static const unsigned int gappoh         = 20;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 20;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { "monospace:size=10" };
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

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

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

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
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

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
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "", "", "", "", "", "", "", "_", "_" },
	[ALTERNATIVE_TAGS]    = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
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
	RULE(.class = "Gimp", .tags = 1 << 7)
	RULE(.class = "LibreWolf", .tags = 1 << 1)
	RULE(.class = "vesktop", .tags = 1 << 2)
	RULE(.class = "obs", .tags = 1 << 2)
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
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,        click_statuscmd,     NULL,             "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "[D]",      deck },
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "|||",      col },
	{ "(@)",      spiral },
	{ "[\\]",     dwindle },
    { "><>",      NULL },    /* no layout function means floating behavior */
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
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key                 function                argument */
    // basics
	{ MODKEY,                       XK_d,               spawn,                  {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,          spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,               togglebar,              {0} },
	{ MODKEY,                       XK_j,               focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,               focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_v,               switchcol,              {0} },
	{ MODKEY,                       XK_o,               incnmaster,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,               incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,               setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,               setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,               movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,               movestack,              {.i = -1 } },
	{ MODKEY,                       XK_space,           zoom,                   {0} },
	{ MODKEY,                       XK_a,               togglegaps,             {0} },
	{ MODKEY|ShiftMask,             XK_a,               defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,             view,                   {0} },
	{ MODKEY,                       XK_q,               killclient,             {0} },
    { MODKEY|ShiftMask,             XK_F5,              xrdb,                   {.v = NULL } },

    // layouts
	{ MODKEY,                       XK_t,               setlayout,              {.v = &layouts[0]} },   // tile
    { MODKEY|ShiftMask,             XK_t,               setlayout,              {.v = &layouts[1]} },   // bottomstack
    { MODKEY|ControlMask,           XK_t,               setlayout,              {.v = &layouts[2]} },   // bottomstackhorizontal  
    { MODKEY,                       XK_u,               setlayout,              {.v = &layouts[3]} },   // deck (master on left monocle on right)
	{ MODKEY|ShiftMask,             XK_u,               setlayout,              {.v = &layouts[4]} },   // monocle
	{ MODKEY,                       XK_i,               setlayout,              {.v = &layouts[5]} },   // centered master
	{ MODKEY|ShiftMask,             XK_i,               setlayout,              {.v = &layouts[6]} },   // centered floating master
	{ MODKEY|ControlMask,           XK_i,               setlayout,              {.v = &layouts[7]} },   // columns
	{ MODKEY,                       XK_y,               setlayout,              {.v = &layouts[8]} },   // spiral
	{ MODKEY|ShiftMask,             XK_y,               setlayout,              {.v = &layouts[9]} },   // dwindle
	{ MODKEY|ShiftMask,             XK_f,               setlayout,              {.v = &layouts[10]} },  // floating
                                                                                                       
	{ MODKEY|ShiftMask,             XK_space,           togglefloating,         {0} },
	{ MODKEY,                       XK_f,               togglefullscreen,       {0} },
	{ MODKEY,                       XK_s,               togglesticky,           {0} },
	{ MODKEY,                       XK_0,               view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,               tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_Left,            focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_Right,           focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,            tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,           tagmon,                 {.i = +1 } },

    // hotkeys
    { MODKEY,           			XK_minus,	        spawn,		            SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		        XK_minus,           spawn,                  SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			            XK_equal,           spawn,       		    SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,		        XK_equal,           spawn,           	    SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,			            XK_BackSpace,       spawn,	                {.v = (const char*[]){ "sysact", NULL } } },
	{ MODKEY|ShiftMask,		        XK_BackSpace,       spawn,                  {.v = (const char*[]){ "sysact", NULL } } },
    { MODKEY|ShiftMask,             XK_b,               spawn,                  SHCMD("boomer") },
    { 0,				            XK_Print,	        spawn,          	    SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,			        XK_Print,	        spawn,           	    {.v = (const char*[]){ "maimpick", NULL } } },
	{ MODKEY,			            XK_Print,	        spawn,       		    {.v = (const char*[]){ "dmenurecord", NULL } } },
	{ MODKEY|ShiftMask,		        XK_Print,           spawn,		            {.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
	{ MODKEY,			            XK_Delete,	        spawn,		            {.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
	{ MODKEY,			            XK_Scroll_Lock,     spawn,		            SHCMD("killall screenkey || screenkey &") },
    { MODKEY,			            XK_n,		        spawn,		            {.v = (const char*[]){ TERMINAL, "-e", "nvim", "-c", "VimwikiIndex", NULL } } },
	{ MODKEY|ShiftMask,	        	XK_n,		        spawn,		            SHCMD(TERMINAL " -e newsboat ; pkill -RTMIN+6 dwmblocks") },
	{ MODKEY,			            XK_m,		        spawn,		            {.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ MODKEY|ShiftMask,	        	XK_m,		        spawn,		            SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
    { MODKEY,			            XK_p,   	        spawn,		            {.v = (const char*[]){ "mpc", "toggle", NULL } } },
	{ MODKEY,			            XK_comma,	        spawn,		            {.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ MODKEY|ShiftMask,	        	XK_comma,	        spawn,		            {.v = (const char*[]){ "mpc", "seek", "0%", NULL } } },
	{ MODKEY,			            XK_period,	        spawn,		            {.v = (const char*[]){ "mpc", "next", NULL } } },
	{ MODKEY|ShiftMask,	        	XK_period,	        spawn,		            {.v = (const char*[]){ "mpc", "repeat", NULL } } },
    { MODKEY,                       XK_w,               spawn,                  {.v = (const char*[]){ BROWSER, NULL } } },


    /* { MODKEY|ShiftMask,             XK_q,          quit,                   {0} },*/
    /* { MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } }, */


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
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },

	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkStatusText,        0,                   Button4,        sigstatusbar,   {.i = 4 } },
	{ ClkStatusText,        0,                   Button5,        sigstatusbar,   {.i = 5 } },
	{ ClkStatusText,        ShiftMask,           Button1,        sigstatusbar,   {.i = 6 } },

	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

