//***************************************************************************
// File name:  main.cpp
// Author:     Chadd Williams
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Example
// Purpose:    Demonstrate smart pointers
//***************************************************************************


#include <iostream>
#include <memory>
#include "../include/Example.h"

void line();
void testFunc(std::unique_ptr<Example> pcExample);

//***************************************************************************
// Function: 		main
//
// Description: demonstrate smart pointers
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{

	// unique_ptr
	line();
	std::cerr << "Unique pointers\n";
	line();

	std::unique_ptr<Example> pcExample(new Example(485));

	auto pcExampleAgain {std::make_unique<Example>(250)};

	std::cerr << *pcExample << std::endl;

	std::cerr << *pcExampleAgain << std::endl;

	std::cerr << "Set pcExample to null - START" << std::endl;
	pcExample = nullptr;
	std::cerr << "Set pcExample to null - DONE" << std::endl;

	line();

	std::cerr << "Set pcExampleAgain to new pointer - START" << std::endl;
	pcExampleAgain = std::make_unique<Example>(300);
	std::cerr << "Set pcExampleAgain to new pointer - DONE" << std::endl;

	//line();
	//std::cerr << "Set pcExampleAgain to pcThirdExample - START" << std::endl;
	//auto pcThirdExample = {std::make_unique<Example>(150)};
	//pcExampleAgain = pcThirdExample; // ERROR! Deleted function!
	//std::cerr << "Set pcExampleAgain to pcThirdExample - DONE" << std::endl;


	// a unique_ptr may not be passed to a function!
	// cctor for unique_ptr does not exist
	//testFunc(pcExample);
	//std::cerr << *pcExample << std::endl;

	return EXIT_SUCCESS;
}


//***************************************************************************
// Function: 		testFunc
//
// Description: show that a unique pointer cannot be passed to a function
//
// Parameters:  pcExample - unique pointer to Example
//
// Returned:    none
//***************************************************************************
void testFunc(std::unique_ptr<Example> pcExample){ 
	*pcExample = 99;
}
//***************************************************************************
// Function: 		line
//
// Description: draw a line
//
// Parameters:  None
//
// Returned:    none
//***************************************************************************
void line() {
	std::cerr << "--------------------------------------------\n";
}


