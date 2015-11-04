#include "word.h"

#include <iostream>
#include <string>

std::string Word::lowerWord() const {
	std::string ret { word };
	std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
	return ret;
}

void const Word::print(std::ostream &out) {
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
			word = tempWord;
			break;
		}
	}
}
