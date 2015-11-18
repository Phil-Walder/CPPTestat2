/*
 * main.cpp
 *
 *  Created on: 11.11.2015
 *      Author: hsr
 */
#include "src/word.h"
#include "src/kwic.h"
#include <iostream>

int main(){
	std::cout << "Type 'break' in a new line to terminate input:\n";
	kwic(std::cin, std::cout);
}


