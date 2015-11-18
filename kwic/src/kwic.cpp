/*
 * kwic.cpp
 *
 *  Created on: 11.11.2015
 *      Author: hsr
 */
#include "kwic.h"
#include "src/word.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

std::vector<std::vector<Word>> read (std::istream &in){
	std::vector<std::vector<Word>> linesOfWords;

	std::string line{};
	while(std::getline(in, line, '\n')){
		std::vector<Word> wordLine{};
		std::istringstream str{line};
		while(str.good()){
			Word word{};
			str>>word;
			wordLine.push_back(word);
		}
		linesOfWords.push_back(wordLine);
	}
	return linesOfWords;
}

std::vector<std::vector<Word>> sort (std::vector<std::vector<Word>> unsorted){
	std::vector<std::vector<Word>> sorted{};
	for_each(unsorted.begin(), unsorted.end(),
		[&](std::vector<Word> line){
			std::sort(line.begin(), line.end());
			sorted.push_back(line);
		}
	);
	return sorted;
}

void write(std::vector<std::vector<Word>> linesOfWords, std::ostream &out){
	std::ostream_iterator<Word> const output(out, "\n");

	for_each(begin(linesOfWords), end(linesOfWords), [&](std::vector<Word> line){
		for(unsigned int i=1;i<=line.size();i++){
			std::rotate_copy(line.begin(),line.begin()+i,line.end(),output);
		}
	});
}

void kwic(std::istream &in, std::ostream &out){
	std::vector<std::vector<Word>> linesOfWords{};

	linesOfWords = read(in);
	write(sort(linesOfWords), out);
}
