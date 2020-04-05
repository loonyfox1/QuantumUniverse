#pragma once
#include "Character.h"
class Destination :
	public Character
{
private:
	
public:
	void decodeKey(vector <Qubit>* key);
	void printName() override;
};

