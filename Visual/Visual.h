#ifndef _VISUAL_
#define _VISUAL_
#include "../Const.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>

int mt_clrscr(void);
int mt_gotoXY(int X,int Y);
int mt_getscreensize(int *rows,int *cols);
int mt_setfgcolor(enum colors);
int mt_setbgcolor(enum colors);

#endif
