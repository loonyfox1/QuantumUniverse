#pragma once

#include <vector>

using namespace std;

#define STATE_EPS 1e-10

struct State
{
	int dimension;
	vector <double> ket;

	State();
	State(vector <double>);
	State(double a, double b);

	bool operator==(const State& a) const {
		return (fabs(ket[0] - a.ket[0]) < STATE_EPS && fabs(ket[1] - a.ket[1]) < STATE_EPS);
	}
};

