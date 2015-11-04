#include "word.h"

#include <iostream>
#include <string>

std::string Word::lowerWord() const {
	std::string ret { word };
	std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
	return ret;
}

void Word::print(std::ostream &out) const {
	out << word;
}

void Word::read(std::istream &in) {
	char input;
	std::string tempWord;
	while (!in.eof() && in.good()) {
		in >> input;
		if (std::isalpha(input)) {
			tempWord += input;
		} else if (input == ' ') {
			if(!(tempWord == "")){
				word = tempWord;
				break;
			}
		}
	}
}

std::ostream& operator<<(std::ostream &out, Word const &word){
	word.print(out);
	return out;
}

std::istream& operator>>(std::istream &in, Word &word){
	word.read(in);
	return in;
}
