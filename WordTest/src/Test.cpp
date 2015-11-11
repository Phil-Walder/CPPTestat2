#include "cute.h"
#include "src/word.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <vector>
#include <iterator>
#include <algorithm>


void test_stream_input() {
	std::istringstream input{"compl33tely ~ weird !!??!! 4matted in_put"};
	Word word{};
	std::ostringstream out{};

	while(!input.eof()){
		input >> word;
		out << "," << word;
	}

	ASSERT_EQUAL(std::string{",compl,tely,weird,matted,in,put"}, out.str());


}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;

	s.push_back(CUTE(test_stream_input));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



