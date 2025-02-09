//***************************************************************************
// File name:   Calculator.h
// Author:      chadd williams
// Date:        1/27/25
// Class:       CS 485
// Assignment:  Unit test example
// Purpose:     Provide a class to unit test
//***************************************************************************

#pragma once

#include <unordered_map>
#include <string>

class Calculator {

	public:

		Calculator();
		Calculator(double value);
		Calculator(const Calculator &rcOther);

		Calculator& operator=(double value);
		Calculator& operator=(Calculator cOther);

		~Calculator();

		Calculator& operator+=(double rhs);
		Calculator& operator+=(const std::string &rcKey);
		Calculator& operator+=(const Calculator &rcRHS);

		friend Calculator operator+(Calculator cLHS, const Calculator &rcRHS);
		friend Calculator operator+(Calculator cLHS, double rhs);

		double operator()() const;

		void clear();

		// https://en.cppreference.com/w/cpp/language/operators#Array_subscript_operator

		const double& operator[](const std::string &rcKey) const;
		double store(const std::string &rcKey);

	private:
		double *mpRunningTotal = nullptr;
		//https://en.cppreference.com/w/cpp/container/unordered_map
		std::unordered_map<std::string, double> mcVars;

};