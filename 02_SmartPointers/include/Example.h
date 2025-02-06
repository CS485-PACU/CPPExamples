//***************************************************************************
// File name:   Example.h
// Author:      
// Date:        1/6/2025
// Class:       CS 485
// Assignment:  
// Purpose:     Demonstrate smart pointers
//***************************************************************************

#pragma once
#include <iostream>
#include <memory>

class Example {
	public:

		// default ctor
		Example();

		// overloaded ctor
		Example(int value);

		// cctor (copy constructor)
		Example(const Example &rcObj);

		// dtor
		~Example();

		// copy assignment operator
		Example& operator=(const Example &rcObj);

		// int assignment operator
		Example& operator=(int RHS);

		friend std::ostream& operator<<(std::ostream& rcOut, const Example &rcObj);

	private:
		std::unique_ptr<int> mpInt;
		int mID;
		static int counter;
};