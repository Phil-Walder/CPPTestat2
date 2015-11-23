/*
 * kwic.h
 *
 *  Created on: 11.11.2015
 *      Author: hsr
 */

#ifndef KWIC_H_
#define KWIC_H_
#include "src/word.h"
#include <iosfwd>
#include <vector>
#include <set>

std::vector<std::vector<Word>> read (std::istream &in);
const std::set<std::vector<Word>> rotate(std::vector<std::vector<Word>> lines);
void write(std::set<std::vector<Word>> const linesOfWords, std::ostream &out);


void kwic(std::istream &in, std::ostream &out);

#endif /* KWIC_H_ */
