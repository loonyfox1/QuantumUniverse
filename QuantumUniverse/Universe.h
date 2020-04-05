#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

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

public:
	Universe();
	bool runBB84(long long n, bool intercept);
	static vector <bool> generateRandomBinarySequence(long long n);
};

