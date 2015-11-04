#include "cute.h"
#include "src/word.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

void test_stream_input() {
	std::istringstream input{"Word is the word!"};

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



