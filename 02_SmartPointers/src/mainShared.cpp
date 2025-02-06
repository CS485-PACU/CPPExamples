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
void testFunc(std::shared_ptr<Example> pcExample);

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

	// shared_ptr
	line();
	std::cerr << "Shared pointers\n";
	line();
	std::shared_ptr<Example> pcExampleShared(new Example(7));

	auto pcExampleSecondShared = pcExampleShared;

	std::cerr << "pExampleShared " << *pcExampleShared << std::endl;

	std::cerr << "pcExampleSecondShared " << *pcExampleSecondShared << std::endl;

	std::cerr << std::endl;

	std::cerr << "Set pcExampleShared to 9 - START" << std::endl;
	*pcExampleShared = 9;
	std::cerr << "Set pcExampleShared to 9 - END" << std::endl;

	std::cerr << "pExampleShared " << *pcExampleShared << std::endl;
	std::cerr << "pcExampleSecondShared " << *pcExampleSecondShared << std::endl;
	std::cerr << std::endl;


	std::cerr << "Set pcExampleSecondShared to null - START" << std::endl;
	pcExampleSecondShared = nullptr;
	std::cerr << "Set pcExampleSecondShared to null - STOP" << std::endl;

	std::cerr << "pExampleShared " << *pcExampleShared << std::endl;

	std::cerr << "Set pcExampleSecondShared to 100 - START\n";
	pcExampleSecondShared = std::make_shared<Example>(100);
	std::cerr << "Set pcExampleSecondShared to 100 - END\n";

	std::cerr << "Set pcExampleSecondShared to 200 - START\n";
	pcExampleSecondShared = std::make_shared<Example>(200);
	std::cerr << "Set pcExampleSecondShared to 200 - END\n";

	std::cerr << "pExampleShared " << *pcExampleShared << std::endl;

	std::cerr << "pcExampleSecondShared " << *pcExampleSecondShared << std::endl;

	std::cerr << "call testFunc - START" << std::endl;
	testFunc(pcExampleSecondShared);
	std::cerr << "call testFunc - END" << std::endl;
	std::cerr << "pcExampleSecondShared " << *pcExampleSecondShared << std::endl;

	return EXIT_SUCCESS;
}

//***************************************************************************
// Function: 		testFunc
//
// Description: show that a pointer is still "pass by reference"
//
// Parameters:  pcExample - shared pointer to Example
//
// Returned:    none
//***************************************************************************
void testFunc(std::shared_ptr<Example> pcExample){ 
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


