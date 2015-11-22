/*
 * main.cpp
 *
 *  Created on: 11.11.2015
 *      Author: hsr
 */
#include "src/word.h"
#include "src/kwic.h"
#include <iostream>
#include <sstream>

int main(){
	//std::cout << "Type 'break' in a new line to terminate input:\n";
	std::istringstream in{"Ich bin\n"
						"Ein weitere\n"};
	kwic(in, std::cout);
}


