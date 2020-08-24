#ifndef SICT_TEXT_H
#define SICT_TEXT_H
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
		size_t size() const;
	};
}
#endif // !SICT_TEXT_H

