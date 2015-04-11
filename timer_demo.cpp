#include <iostream>
#include <cstdlib>

#include "timer_exception.h"
#include "timer.h"

using namespace std;

int main() {
	Timer t;
	try {
		t.end();
		throw "You're not checking in 'end' that the timer has been started";
	} catch (TimerException e) {
		cerr << "Exception thrown properly -- " << e << endl;
	}

	t.start();

	try {
		t.start();
		throw "You're not checking in 'start' that the timer has already been started";
	} catch (TimerException e) {
		cerr << "Exception thrown properly  -- " << e << endl;
	}

	try {
		cout << t.hours() << endl;
		throw "You're not checking that the timer had been 'ended' before calling the 'get' functions";
	} catch (TimerException e) {
		cerr << "Exception thrown properly  -- " << e << endl;
	}

	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < 10000; j++)
			1234567 / 98765432.0;

	t.end();

	cout << "--------------------------------------------" << endl;
	cout << "The values of the individual 'get' functions" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "hours  : " << t.hours() << endl;
	cout << "minutes: " << t.minutes() << endl;
	cout << "seconds: " << t.seconds() << endl;
	cout << "ticks  : " << t.ticks() << endl;

	cout << endl;
	cout << "The duration printed using <<: " << t << endl;

	return 0;
}


