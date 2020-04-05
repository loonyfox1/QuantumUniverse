#pragma once

#include <vector>

using namespace std;

#include "Character.h"

class Source :
	public Character
{
private:
public:
	vector <Qubit>* encodeKey(const vector <bool>&);
	void printName() override;
};

