#include "MyReadKey.h"

int rk_mytermsave(void){

	tcgetattr(0, &tty);
	savetty = tty;
	return 0;
}

int rk_mytermrestore(void){
	tcsetattr(0, TCSAFLUSH, &savetty);
	return 0;
}

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint){
	if (((regime < 0) || (regime > 1)) && ((vtime < 0) || (vtime > 1)) && ((vmin < 0) || (vmin > 1)) && ((echo < 0) || (echo > 1)) && ((sigint < 0) || (sigint > 1))){
		return -1;
	}
	else {
		tcgetattr(0,&tty);
		
		if (regime == 1) tty.c_lflag  |= ICANON;
		else tty.c_lflag &= ~ICANON;

		if (echo == 1) tty.c_lflag |= ECHO;
		else tty.c_lflag &= ~ECHO;

		if (sigint == 1) tty.c_lflag |= ISIG;
		else tty.c_lflag &= ~ISIG;

		tty.c_cc[VMIN] = vmin;
		tty.c_cc[VTIME] = vtime;
		tcsetattr(0,TCSAFLUSH, &tty);
		return 0;
	}

}

int rk_readkey (enum keys *key){
	char buf[5];
	read(0, &buf, 4);
	buf[4] = 0;

	if (strncmp(buf, "l", 1) == 0)
		*key = l;
	else if (strncmp(buf, "s", 1) == 0)
                *key = s;
	else if (strncmp(buf, "r", 1) == 0)
                *key = r;
	else if (strncmp(buf, "t", 1) == 0)
                *key = t;
	else if (strncmp(buf, "i", 1) == 0)
                *key = i;
	else if (strcmp(buf, "\E[15") == 0)
                *key = F5;
	else if (strcmp(buf, "\E[17") == 0)
                *key = F6;
	else if (strcmp(buf, "\E[D") == 0)
                *key = LEFT;
	else if (strcmp(buf, "\E[C") == 0)
                *key = RIGHT;
	else if (strcmp(buf, "\E[A") == 0)
                *key = UP;
	else if (strcmp(buf, "\E[B") == 0)
                *key = DOWN;
	else if (strcmp(buf, "\n") == 0)
                *key = ENTER;
	else 
                *key = NONE;
	return 0;	
}
