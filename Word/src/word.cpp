#include "word.h"

#include <iostream>
#include <string>

std::string Word::lowerWord() const {
	std::string ret { word };
	std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
	return ret;
}

std::ostream& Word::print(std::ostream &out) const {
	out << word;
	return out;
}

std::istream& Word::read(std::istream &in) {
	std::string tempWord;
	while (in.good()) {
		char peek = in.peek();
		if (!std::isalpha(peek)) {
			if(!(tempWord == "")){
				word = tempWord;
				break;
			}
		}
		in >> peek;
		if(std::isalpha(peek)){
			tempWord += peek;
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream &out, Word const &word){
	return word.print(out);
}

std::istream& operator>>(std::istream &in, Word &word){
	return word.read(in);
}
