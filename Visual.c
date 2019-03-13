#include "Mysimplecomputer.h"


int mt_clrscr(void){
printf("\E[H\E[2J");
return 0;
}

int mt_gotoXY(int X,int Y){
printf("\E[%d;%dH",X,Y);
mt_setfgcolor(8);
return 0;
}

int mt_getscreensize(int *rows,int *cols){
struct winsize ws;
	if (!ioctl(1,TIOCGWINSZ,&ws)){
		(*rows) = ws.ws_row;
		(*cols) = ws.ws_col;
		return 0;
	}
	else return -1;
}

int mt_setfgcolor(enum colors A){
	if (A >= 8) printf("\E[37m");
	else printf("\E[3%dm", A);
return 0;
}

int mt_setbgcolor(enum colors B){
	if (B >= 8) printf("\E[00m");
	else printf("\E[4%dm", B);
return 0;
}

