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
		std::istringstream lineStream { line };
		std::istream_iterator<Word> initer { lineStream };
		std::istream_iterator<Word> eof { };
		std::vector<Word> wordLine { initer, eof };
		linesOfWords.push_back(wordLine);
	}
	return linesOfWords;
}

const std::set<std::vector<Word>> rotate(std::vector<std::vector<Word>> lines) {
	std::vector<std::vector<Word>> rotatedLines { };
	for_each(begin(lines), end(lines), [&rotatedLines](std::vector<Word> const line) {
		for(unsigned int i = 0; i < line.size(); i++) {
			std::vector<Word> rotationLine {};
			std::rotate_copy(
					begin(line), begin(line) + i,
					end(line), back_inserter(rotationLine));
			rotatedLines.push_back(rotationLine);
		}
	});
	std::set<std::vector<Word>> const sortedLines { rotatedLines.begin(), rotatedLines.end() };
	return sortedLines;
}

void write(std::set<std::vector<Word>> const sortedLines, std::ostream &out) {
	std::ostream_iterator<Word> const output(out, " ");

	for_each(sortedLines.begin(), sortedLines.end(), [&](std::vector<Word> line) {
		std::copy(line.begin(),line.end(),output);
		out << "\n";
	});
}

void kwic(std::istream &in, std::ostream &out) {
	std::vector<std::vector<Word>> linesOfWords { };
	linesOfWords = read(in);
	write(rotate(linesOfWords), out);
}
