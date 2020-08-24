//Li-Ching, Cheng 143292175 SEE

#include "Utilities.h"

namespace sict {
	char Utilities::delimiter = '\0';

	Utilities::Utilities() : field{ 0u } {};

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		size_t max;
		size_t deliAT = str.find(delimiter, next_pos);;
		size_t theEnd = std::string::npos;
		std::string temp;
		if (deliAT != theEnd) {
			temp = str.substr(next_pos, (deliAT - next_pos));
			max = temp.size();
		}
		else {
			temp = str.substr(next_pos);
			max = temp.size();
		}
		max = temp.size();
		if (max > getFieldWidth()) {
			setFieldWidth(max);
		}
		if (temp.empty()) {
			std::string s = "No message";
			throw s;
		}
		return temp;
	}

	const char Utilities::getDelimiter() const {
		return delimiter;
	}

	size_t Utilities::getFieldWidth() const {
		return field;
	}

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	void Utilities::setFieldWidth(size_t f) {
		field = f;
	}
}