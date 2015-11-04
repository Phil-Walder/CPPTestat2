
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

	inline bool operator<(Word const& rhs) const {
		return lowerWord() < rhs.lowerWord();
	};
	inline bool operator>(Word const& rhs){ return (rhs < *this); }
	inline bool operator>=(Word const& rhs){ return !(*this < rhs); }
	inline bool operator<=(Word const& rhs){ return !(rhs < *this); }
	inline bool operator==(Word const& rhs){ return !(*this < rhs) && !(rhs < *this); }
	inline bool operator!=(Word const& rhs){ return !(*this == rhs); }


};

#endif /* SRC_WORD_H_ */
