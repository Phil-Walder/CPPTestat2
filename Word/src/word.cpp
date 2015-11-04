#include "word.h"

std::string Word::lowerWord() const{
	std::string ret{word};
	std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
	return ret;
}

