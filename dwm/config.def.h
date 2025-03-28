
#include <X11/XF86keysym.h>

static const unsigned int borderpx  = 3;        
static const unsigned int snap      = 32;       
static const int showbar            = 1;        
static const int topbar             = 1;     
static const int gappx              = 0;   
static const char *fonts[]          = { "arial:size=15", "Noto Color Emoji:size=15" };
static const char dmenufont[]       = "arial:size=15";
static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#808080";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#4c566a";
static const char *colors[][3]      = {
	
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray2  },
};


static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	
	
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};


static const float mfact     = 0.55; 
static const int nmaster     = 1;    
static const int resizehints = 1;    
static const int lockfullscreen = 1; 

static const Layout layouts[] = {
	
	{ "[]=",      tile },    
	{ "><>",      NULL },    
	{ "[M]",      monocle },
};


#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


static const char *termcmd[]  = { "xterm", NULL };
static const char *dmenucmd[] = { "rofi", "-show", "drun", NULL }; 
static const char *fm[] = { "xterm", "-e", "ranger", NULL };
static const char *htop[] = { "xterm", "-e", "htop", NULL };
static const char *bluetui[] = { "xterm", "-e", "bluetui", NULL };
static const char *wifi[] = { "xterm", "-e", "impala", NULL };
static const char *stop[] = { "killall autostart.sh", NULL };
static const char *pulsemixer[] = { "xterm", "-e", "pulsemixer", NULL };

static const char *upvol[]      = { "/usr/bin/pactl",   "set-sink-volume", "0",      "+5%",      NULL };
static const char *downvol[]    = { "/usr/bin/pactl",   "set-sink-volume", "0",      "-5%",      NULL };
static const char *mutevol[]    = { "/usr/bin/pactl",   "set-sink-mute",   "0",      "toggle",   NULL };
static const char *brupcmd[] = { "brightnessctl", "set", "10%+", NULL };
static const char *brdowncmd[] = { "brightnessctl", "set", "10%-", NULL };
static const Key keys[] = {
	
	{ MODKEY|ShiftMask,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,                       XK_Escape,    spawn,          {.v = htop } },
	{ MODKEY|ShiftMask,                       XK_b,      spawn,          {.v = bluetui } },
	{ MODKEY|ShiftMask,                       XK_w,      spawn,          {.v = wifi } },
	{ MODKEY|ShiftMask,                       XK_v,      spawn,          {.v = pulsemixer } },
	{ MODKEY,                                 XK_e,      spawn,          {.v = fm } },
	{ MODKEY|ShiftMask,                       XK_e,      spawn,          {.v = stop } },
	{ MODKEY,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_h,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
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
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -3 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +3 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                       XF86XK_AudioMute, spawn, {.v = mutevol } },
	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
	{ 0, XF86XK_MonBrightnessUp,  spawn,          {.v = brupcmd} },
    { 0, XF86XK_MonBrightnessDown, spawn,          {.v = brdowncmd} },
};



static const Button buttons[] = {
	
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
