#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"
using namespace std;
namespace sict {
	Text::Text() {
		str = nullptr;
		sStored = 0;
	}
	Text::Text(char* t) {
		std::ifstream fin(t);
		if (fin.is_open()) {
			std::string temp;
			while (getline(fin, temp)) {
				sStored++;
			}
			int i = sStored;
			str = new std::string[i];
			for (size_t i = 0; i < sStored; i++) {
				getline(fin, str[i]);
			}
			fin.close();
		}
		else {
			*this = Text();
		}
	}
	Text::~Text() {
		delete[] str;
		str = nullptr;
	}
	Text::Text(const Text& t) {
		*this = t;
	}
	Text& Text::operator=(const Text& t) {
		if (this != &t) {
			sStored = t.sStored;
			delete[] str;
			str = new std::string[sStored];
			for (size_t i = 0; i < sStored; i++) {
				str[i] = t.str[i];
			}
		}
		return *this;
	}
	size_t Text::size() const {
		return sStored;
	}
}


