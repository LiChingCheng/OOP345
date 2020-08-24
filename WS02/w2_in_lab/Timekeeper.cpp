#include <iostream>
#include <cstring>
#include <chrono>
#include "Timekeeper.h"
using namespace std::chrono;
using namespace std;

namespace sict {

	Timekeeper::Timekeeper() {
		rRecorded = 0;
		for (int i = 0; i < MAX; i++) {
			record[i].message = nullptr;
			record[i].unit_of_time = nullptr;
		}
	}
	Timekeeper::~Timekeeper() {
		for (int i = 0; i < MAX; i++) {
			delete[] record[i].message;
		}
	}
	void Timekeeper::start() {
		t1 = steady_clock::now();
	}
	void Timekeeper::stop() {
		t2 = steady_clock::now();
	}
	void Timekeeper::recordEvent(const char* r){
		if (rRecorded < MAX) {
			record[rRecorded].message = new char[strlen(r) + 1];
			strcpy(record[rRecorded].message, r);
			record[rRecorded].unit_of_time = "milliseconds";
			record[rRecorded].tcount = (t2 - t1);
			rRecorded++;
		}
	}
	ostream& Timekeeper::report(ostream& os) {
		os << endl;
		os << "Execution Times:" << endl;
		for (int i = 0; i < rRecorded; i++) {
			os << record[i].message << " " << duration_cast<milliseconds>(record[i].tcount).count() << " "
				<< record[i].unit_of_time << endl;
		}
		return os;
	}
}


