#include <iostream>
#include <cstring>
#include "String.h"
using namespace sict;
extern int INITIAL;

namespace sict {
	String::String(const char* s) {
		if (s[0] != '\0') {
			string = nullptr;
			string = new char[strlen(s) + 1];
			strcpy(string, s);
		}
		else {
			string = nullptr;
		}
	}

	void String::display(ostream& os) const {
		os << string;
	}

	String::~String() {
		delete[] string;
		string = nullptr;
	}

	ostream& operator<<(ostream& os, const String& s) {
		static int i = INITIAL;
		os << i++ << ": ";
		s.display(os);
		return os;
	}
}
