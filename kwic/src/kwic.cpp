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
		int count = 0;
		while(std::getline(in, line, '\n')){
			std::istringstream str{line};
			while(str.good()){
				Word word{};
				str>>word;
				linesOfWords[count].push_back(word);
			}
			count++;
		}
		return linesOfWords;
}

void write(std::vector<std::vector<Word>> linesOfWords, std::ostream &out){
	std::ostream_iterator<Word> const output(out, "\n");

	for_each(begin(linesOfWords), end(linesOfWords), [&](std::vector<Word> line){
		for(unsigned int i=0;i<line.size();i++){
			std::rotate_copy(line.begin(),line.begin()+1,line.end(),output);
		}
	});
}

void kwic(std::istream &in, std::ostream &out){
	std::vector<std::vector<Word>> linesOfWords{};

	linesOfWords=read(in);

	write(linesOfWords, out);
}
