#include "word.h"

std::string Word::lowerWord() const{
	std::string ret{word};
	std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
	return ret;
}

print(istream &in){
	char c;
	std::string word;
	while(stream goot){
		c << in;
		if(std::isalpha(c)){
			append to string
		}
		if(c == ' '){
			break;
		}
	}



}

std::ostream& operator<<(std::ostream &out, Word const &word){
	word.print(out);
	return out;
}
