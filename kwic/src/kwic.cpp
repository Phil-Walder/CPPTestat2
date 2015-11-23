/*
 * kwic.cpp
 *
 *  Created on: 11.11.2015
 *      Author: hsr
 */
#include "kwic.h"
#include "src/word.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

std::vector<std::vector<Word>> read(std::istream &in) {
	std::vector<std::vector<Word>> linesOfWords;

	std::string line { };
	while (std::getline(in, line, '\n')) {
		std::istringstream lineStream{line};
		std::istream_iterator<Word> initer { lineStream };
		std::istream_iterator<Word> eof { };
		std::vector<Word> wordLine { initer, eof };
		linesOfWords.push_back(wordLine);
	}
	return linesOfWords;
}

void write(std::vector<std::vector<Word>> lines, std::ostream &out) {
	std::ostream_iterator<Word> const output(out, " ");

	std::vector<std::vector<Word>> rotations { };
	for_each(begin(lines), end(lines), [&rotations](std::vector<Word> const line) {
		for(unsigned int i = 0; i < line.size(); i++) {
			std::vector<Word> rotationLine {};
			std::rotate_copy(
					begin(line), begin(line) + i,
					end(line), back_inserter(rotationLine));
			rotations.push_back(rotationLine);
		}
	});
	std::set<std::vector<Word>> const sortedLines { rotations.begin(), rotations.end() };

	for_each(sortedLines.begin(), sortedLines.end(), [&](std::vector<Word> line) {
		std::copy(line.begin(),line.end(),output);
		out << "\n";
	});
}

void kwic(std::istream &in, std::ostream &out) {
	std::vector<std::vector<Word>> linesOfWords { };
	linesOfWords = read(in);
	write(linesOfWords, out);
}
