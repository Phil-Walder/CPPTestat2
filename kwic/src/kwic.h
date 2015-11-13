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


void kwic(std::istream &in, std::ostream &out);

void write(std::vector<std::vector<Word>> linesOfWords, std::ostream &out);
std::vector<std::vector<Word>> read (std::istream &in);

#endif /* KWIC_H_ */
