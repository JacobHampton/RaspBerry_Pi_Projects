blink: blink.cpp
	g++ blink.cpp -o blink -lwiringPi

clean:
	rm *.o blink