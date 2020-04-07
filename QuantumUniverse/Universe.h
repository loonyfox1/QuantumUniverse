#pragma once

#define _USE_MATH_DEFINES

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;
using namespace chrono;

#include "Source.h"
#include "Destination.h"
#include "Interceptor.h"
#include "Basis.h"

#define REV2ROOT 1./sqrt(2)
#define DIST_PARAMETER 0.5

class Universe {
private:
	Source* Alice;
	Destination* Bob;
	Interceptor* Eva;

	Basis createSpinBasis(double degree, string name);

public:
	Universe();
	bool runBB84(long long n, bool intercept);
	bool runBellsTheorem(long long n);
	static vector <bool> generateRandomBinarySequence(long long n);
};

