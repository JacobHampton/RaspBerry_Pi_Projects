#include <iostream>
#include <wiringPi.h>
#include <csignal>

bool RUNNING = true;

void blink_led(int led, int time){
	digitalWrite(led, HIGH);
	delay(time);
	digitalWrite(led, LOW);
	delay(time);
}

void my_handler(int s){
	std::cout << "Detected CTRL-C signal number" << s << '\n';
	RUNNING = false; 
}

int main() {
	std::signal(SIGINT, my_handler);
	wiringPiSetupGpio();

	int blue = 19;
	pinMode(blue, OUTPUT);

	int time = 1000;
	while(RUNNING){
		blink_led(blue, time);
	}
	
	return 0;
}
