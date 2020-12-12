#pragma once
// this is the header file for tests backend
#include "Import.h"
class Tests_backend
{
private:

public:
	// get the names of all the test to output buttons
	static void Get_tests_names(std::string* check);
	// gets the test data of the test to be played
	static structures::Block* Get_test_data(int TestID);
};

