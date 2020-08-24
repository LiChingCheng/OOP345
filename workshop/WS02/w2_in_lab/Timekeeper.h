#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int MAX = 10;
namespace sict {
	class Timekeeper {
		int rRecorded;
		steady_clock::time_point t1;
		steady_clock::time_point t2;
		struct {
			char* message;
			const char* unit_of_time;
			steady_clock::duration tcount;
		} record[MAX];
	public:
		Timekeeper();
		~Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		ostream& report(ostream&);
	};
}
#endif // !SICT_TIMEKEEPER_H

