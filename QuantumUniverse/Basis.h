#pragma once

#include <vector>
#include <cassert>
#include <string>

using namespace std;

#include "State.h"

class Qubit;

class Basis
{
private:
	string name;
	int dimension;
	State first;
	State second;
public:
	Basis();
	Basis(vector <double>, vector <double>, string);
	Basis(State, State, string);
	int getDimension();
	State getState(bool bit);
	State determineState(Qubit qubit);
	bool getBit(Qubit qubit);
	string getName();

	bool operator==(const Basis& a) const {
		return (first == a.first && second == a.second);
	}
};

