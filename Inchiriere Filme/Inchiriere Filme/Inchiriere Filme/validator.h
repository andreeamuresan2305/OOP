#pragma once
#include <string>
#include "Film.h"
#include "template.h"
#include <vector>
#include <iostream>
#include <stdio.h>


using namespace std;

class ValidateException {
	VectDinNewDeleteT<string> msgs;
public:
	ValidateException(const VectDinNewDeleteT<string>& errors) :msgs{ errors } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend ostream& operator<<(ostream& out, const ValidateException& ex);
};

ostream& operator<<(ostream& out, const ValidateException& ex);

class Validator {
public:
	void validate(const Film& f);
	
};

void testValidator();