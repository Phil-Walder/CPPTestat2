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


void test_streamInput() {
	std::istringstream input{"compl33tely ~ weird !!??!! 4matted in_put"};
	Word word{};
	std::ostringstream out{};
	while(!input.eof()){
		input >> word;
		out << word <<", ";
	}
	ASSERT_EQUAL(std::string{"compl, tely, weird, matted, in, put, "}, out.str());
}

void test_inputEnd(){
	std::istringstream input{"compl! ! ! ! ¨ 54ä"};
	Word word{};
	std::ostringstream out{};
	while(!input.eof()){
		input >> word;
		input >> word;
		out << "," << word;
	}
	ASSERT_EQUAL(std::string{",compl"}, out.str());
}

void test_rotate(){
	Word af{"af"};
	Word ced{"ced"};
	Word bend{"bend"};
	Word gof{"gof"};
	Word holli{"holli"};
	Word inja{"inja"};
	std::vector<std::vector<Word>> input{{af, ced, bend, },{holli, gof, inja}};
	auto out = rotate(input);
	std::set<std::vector<Word>> expected{
		{af, ced, bend},
		{bend, af, ced},
		{ced, bend, af},
		{gof, inja, holli},
		{holli, gof, inja},
		{inja, holli, gof}
	};
	ASSERT_EQUAL(expected, out);
}

void test_read(){
	std::istringstream input{"lala 5ack 4b!\nlala 5ack 4b!"};
	std::vector<std::vector<Word>> output{};
	Word lala{"lala"};
	Word ack{"ack"};
	Word b{"b"};
	std::vector<std::vector<Word>> expected{{lala, ack, b, },{lala, ack, b}};
	output = read(input);
	ASSERT_EQUAL(expected, output);
}

void test_emptyInputRead(){
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
	write(rotate(input), out);
	ASSERT_EQUAL(std::string{"ack \n"
							"autpot "
							 "la \n"
							 "la "
							 "autpot \n"
								}, out.str());
}

void test_errorConstruction(){
	ASSERT_THROWS(Word whitespace{" "}, std::invalid_argument);
}

void test_kwic(){
	std::istringstream input{"lol. haha3 wef 2! ! ! ! ! !3"};
	std::ostringstream out{};
	kwic(input, out);
	ASSERT_EQUAL(std::string{"haha wef lol \n"
							"lol haha wef \n"
							"wef lol haha \n"}, out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;

	s.push_back(CUTE(test_streamInput));
	s.push_back(CUTE(test_inputEnd));
	s.push_back(CUTE(test_read));
	s.push_back(CUTE(test_emptyInputRead));
	s.push_back(CUTE(test_write));
	s.push_back(CUTE(test_errorConstruction));
	s.push_back(CUTE(test_rotate));
	s.push_back(CUTE(test_kwic));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



