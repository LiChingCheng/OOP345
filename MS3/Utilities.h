//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
#include <iostream>
//#include <vector>

namespace sict {
	class Utilities {
		size_t field;
		static char delimiter;
	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif // !SICT_UTILITIES_H