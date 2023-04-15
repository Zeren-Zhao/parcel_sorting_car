#include "control.cpp"
#include "time.cpp"
int main(){
	
	wiringPiSetup();
	L298N Driver(26, 29, 27, 28);
	
	Driver.left();
	waittime(1000);
	Driver.forward();
	waittime(1000);
	Driver.right();
	waittime(1000);
	Driver.retreat();
	waittime(1000);
	Driver.stop();
	return 0;
	}
