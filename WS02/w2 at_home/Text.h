#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
using namespace std;

namespace sict {
	class Text {
		std::string* str;
		size_t sStored;
	public:
		Text();
		Text(char*);
		~Text();
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		size_t size() const;
	};
}
#endif // !SICT_TEXT_H

