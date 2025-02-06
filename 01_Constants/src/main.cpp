//***************************************************************************
// File name:   main.cpp
// Author:      
// Date:        
// Class:       
// Assignment:  
// Purpose:     
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "../include/ExampleClass.h"

//***************************************************************************
// Function:    main
//
// Description: Print hi!
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{
    ExampleClass cTheClass;
    ExampleClass cOtherClass(485, "AOO");
    ExampleClass cSameClass(cOtherClass);

    ExampleClass cEarlyClass(150, "CS150", false);
    ExampleClass cCS150Again(cEarlyClass);


    std::string cMessage = "hi!";
    std::cout << ">> " << cMessage << " << " << std::endl;  
    return EXIT_SUCCESS;
}