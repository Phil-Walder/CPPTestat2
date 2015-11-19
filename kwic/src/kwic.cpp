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
#include <set>

std::vector<std::vector<Word>> read (std::istream &in){
	std::vector<std::vector<Word>> linesOfWords;


	std::string line{};
	while(std::getline(in, line, '\n')){
		if(line=="break"){break;}

		std::istringstream str{line};

		std::istream_iterator<Word> initer{str};
		std::istream_iterator<Word> eof{};
		std::vector<Word> wordLine{initer, eof};

		linesOfWords.push_back(wordLine);
	}
	return linesOfWords;
}
//set / multiset
/*std::vector<std::vector<Word>> sort (std::vector<std::vector<Word>> unsorted) const {
	std::vector<std::vector<Word>> sorted{};
	for_each(unsorted.begin(), unsorted.end(),
		[&sorted](std::vector<Word> line){
			std::sort(line.begin(), line.end());
			sorted.push_back(line);
		}
	);
	return sorted;
}*/

void write(std::vector<std::vector<Word>> linesOfWords, std::ostream &out){
	std::ostream_iterator<Word> const output(out, " ");

	std::multiset<std::vector<Word>> lines (linesOfWords.begin(), linesOfWords.end());
	int counter = 0;
	while(true){
		bool didOutput = false;
		std::for_each(lines.begin(), lines.end(), [&](std::vector<Word> line){
			if(line.size()<=counter){
				didOutput=true;
				std::rotate_copy(line.begin(),line.begin()+counter,line.end(),output);
				out << "\n";
			}
		});
		if(!didOutput)break;
		counter++;
	}
}

void kwic(std::istream &in, std::ostream &out){
	std::vector<std::vector<Word>> linesOfWords{};
	linesOfWords = read(in);
	write(linesOfWords, out);
}
