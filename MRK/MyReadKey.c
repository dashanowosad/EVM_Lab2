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
	char buf;
	read (0, &buf, 1);
	fflush(stdout);
	switch(buf){
	
		case "l":{
			break;
		}
		case "s":{
                        break;
                }
		case "r":{
                        break;
                }
		case "t":{
                        break;
                }
		case "i":{
                        break;
                }
		case '':{
                        break;
                }
		case '':{
                        break;
                }
		case '':{
                        break;
                }
		case '':{
                        break;
                }
		case '':{
                        break;
                }
		case '':{
                        break;
                }
		case '':{
                        break;
                }

	}
}
