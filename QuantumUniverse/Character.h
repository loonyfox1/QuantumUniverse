#pragma once

#include <string>
#include <iostream>

using namespace std;

#include "Qubit.h"

class Character
{
protected: 
	vector <Basis> usedBases;
	vector <string>* basesSequence;
	vector <bool>* binaryMessage;
public:
	Character();
	void setBases(const vector <Basis> bases);
	void crossBasesSequence(Character* pair);
	void crossBinaryMessage(Character* pair);
	vector <string>* getBasesSequence();
	vector <bool>* getBinaryMessage();
	void printMessage();
	void printBasesSequence();
	virtual void printName() = 0;

};

