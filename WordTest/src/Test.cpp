#include "cute.h"
#include "src/word.h"
#include "src/kwic.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>


void test_stream_input() {
	std::istringstream input{"compl33tely ~ weird !!??!! 4matted in_put"};
	Word word{};
	std::ostringstream out{};
	while(!input.eof()){
		input >> word;
		out << word <<", ";
	}
	ASSERT_EQUAL(std::string{"compl, tely, weird, matted, in, put, "}, out.str());
}

void test_2timesInput(){
	std::istringstream input{"compl"};
	Word word{};
	std::ostringstream out{};
	while(!input.eof()){
		input >> word;
		input >> word;
		out << "," << word;
	}
	ASSERT_EQUAL(std::string{",compl"}, out.str());
}

void test_read(){
	std::istringstream input{"lala 5ack 4b!\nlala 5ack 4b!"};
	std::vector<std::vector<Word>> output{};
	Word lala{"lala"};
	Word ack{"ack"};
	Word b{"b"};
	std::vector<std::vector<Word>> expected{{lala, ack, b, },{lala, ack, b}};
	output=read(input);
	ASSERT_EQUAL(expected, output);
}

void test_read_emptyInput(){
	std::istringstream input{""};
	std::vector<std::vector<Word>> output{};
	std::vector<std::vector<Word>> expected{};
	output=read(input);
	ASSERT_EQUAL(expected, output);
}

void test_write(){
	Word autpot{"autpot"};
	Word la{"la"};
	Word ack{"ack"};
	std::vector<std::vector<Word>> input{{autpot, la},{ack}};
	std::ostringstream out{};
	write(input, out);
	ASSERT_EQUAL(std::string{"autpot "
							 "la \n"
							 "la "
							 "autpot \n"
							 "ack \n"}, out.str());
}

void test_errorConstruction(){
	ASSERT_THROWS(Word whitespace{" "}, std::invalid_argument);
}

void test_sort(){
	Word a{"a"};
	Word b{"b"};
	Word c{"c"};
	Word f{"f"};
	std::vector<std::vector<Word>> input {{f, b, c},{c, a}};
	std::vector<std::vector<Word>> output {};
	output = sort(input);
	std::vector<std::vector<Word>> expected{{b, c, f}, {a, c}};

	ASSERT_EQUAL(expected, output);
}

void test_sort_emptyInput(){
	std::vector<std::vector<Word>> input {};
	std::vector<std::vector<Word>> output {};
	output=sort(input);
	ASSERT_EQUAL(std::vector<std::vector<Word>>{}, output);
}

void test_kwic(){
	std::istringstream input{"lol. haha3 wef 2! ! ! ! ! !3"};
	std::ostringstream out{};
	kwic(input, out);
	ASSERT_EQUAL(std::string{"haha lol wef \n"
							"lol wef haha \n"
							"wef haha lol \n"}, out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;

	s.push_back(CUTE(test_stream_input));
	s.push_back(CUTE(test_2timesInput));
	s.push_back(CUTE(test_read));
	s.push_back(CUTE(test_read_emptyInput));
	s.push_back(CUTE(test_write));
	s.push_back(CUTE(test_errorConstruction));
	s.push_back(CUTE(test_kwic));

	s.push_back(CUTE(test_sort));
	s.push_back(CUTE(test_sort_emptyInput));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



