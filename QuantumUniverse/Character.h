#pragma once

#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

#include "Qubit.h"

class Character
{
protected: 
	
public:
	vector <Basis> usedBases;
	vector <string>* basesSequence;
	vector <bool>* binaryMessage;

	Character();
	void setBases(const vector <Basis> sbases);
	vector <string>* getBasesSequence();
	vector <bool>* getBinaryMessage();
	void printMessage();
	void printBasesSequence();
	virtual void printName() = 0;

	template <typename C1, typename C2> 
	void crossSequences(Character* pair, C1* compare1, C2* compare2) {
		vector <string>* newBasesSequence = new vector <string>(0);
		vector <bool>* newBinaryMessage = new vector <bool>(0);
		vector <string>* newPairBasesSequence = new vector <string>(0);
		vector <bool>* newPairBinaryMessage = new vector <bool>(0);

		for (unsigned i = 0; i < compare1->size(); i++) {
			if ((*compare1)[i] == (*compare2)[i]) {
				newBasesSequence->push_back((*basesSequence)[i]);
				newBinaryMessage->push_back((*binaryMessage)[i]);
				newPairBasesSequence->push_back((*pair->basesSequence)[i]);
				newPairBinaryMessage->push_back((*pair->binaryMessage)[i]);
			}
		}

		vector <string>(0).swap(*basesSequence);
		vector <bool>(0).swap(*binaryMessage);
		vector <string>(0).swap(*pair->basesSequence);
		vector <bool>(0).swap(*pair->binaryMessage);

		basesSequence = newBasesSequence;
		binaryMessage = newBinaryMessage;
		pair->basesSequence = newPairBasesSequence;
		pair->binaryMessage = newPairBinaryMessage;
	}
};

