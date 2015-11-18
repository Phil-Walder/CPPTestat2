
#ifndef SRC_WORD_H_
#define SRC_WORD_H_

#include <iosfwd>
#include <string>
#include <algorithm>
#include <functional>

class Word{
	std::string word{};
public:
	std::string lowerWord() const;

	Word(std::string word):word{word}{};
	Word (){};

	inline bool operator<(Word const& rhs) const {
		return lowerWord() < rhs.lowerWord();
	};
	inline bool operator>(Word const& rhs) const { return (rhs < *this); }
	inline bool operator>=(Word const& rhs) const { return !(*this < rhs); }
	inline bool operator<=(Word const& rhs) const { return !(rhs < *this); }
	inline bool operator==(Word const& rhs) const { return !(*this < rhs) && !(rhs < *this); }
	inline bool operator!=(Word const& rhs) const { return !(*this == rhs); }

	std::ostream& print(std::ostream &out) const;
	std::istream& read(std::istream &in);

};

std::ostream& operator<<(std::ostream &out, Word const &word);
std::istream& operator>>(std::istream &in, Word &word);

#endif /* SRC_WORD_H_ */
