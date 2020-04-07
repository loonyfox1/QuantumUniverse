#include "Universe.h"

Universe::Universe() {
	Alice = new Source();
	Bob = new Destination();
	Eva = new Interceptor();
}

bool Universe::runBB84(long long n, bool intercept = Universe::generateRandomBinarySequence(1)[0]) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	Basis verticalBasis = createSpinBasis(0, "V");
	Basis horizontalBasis = createSpinBasis(M_PI/2, "H"); 
	vector <Basis> usedBases {verticalBasis, horizontalBasis};

	Alice->setBases(usedBases);
	Bob->setBases(usedBases);
	Eva->setBases(usedBases);

	vector <Qubit>* encodedKey = Alice->encodeKey(generateRandomBinarySequence(n));
	encodedKey = Eva->interceptKey(encodedKey, intercept);
	Bob->decodeKey(encodedKey);

	Alice->crossSequences(Bob, Alice->getBasesSequence(), Bob->getBasesSequence());
	assert(*Alice->getBasesSequence() == *Bob->getBasesSequence());

	bool result = false;
	if (*Alice->getBinaryMessage() == *Bob->getBinaryMessage()) {
		cout << "The Trick worked well!" << endl;
	}
	else {
		cout << "Eva intercepted. Compare binary messages..." << endl;

		Alice->crossSequences(Bob, Alice->getBinaryMessage(), Bob->getBinaryMessage());
		assert(*Alice->getBinaryMessage() == *Bob->getBinaryMessage());
	}
	if (n <= 100) {
		Alice->printBasesSequence();
		Alice->printMessage();
		Bob->printMessage();
		Bob->printBasesSequence();
	}

	long long m = Alice->getBinaryMessage()->size();
	cout << endl << "Coincidences " << m << "/" << n << " = " << double(m) / double(n) << endl;
	cout << "Does really Eva intercept? " << intercept << endl;

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cout << "It took me " << time_span.count() << " seconds." << endl;

	return result;
}

bool Universe::runBellsTheorem(long long n) {
	Basis verticalBasis = createSpinBasis(0, "V");
	Basis rigthBasis = createSpinBasis(M_PI / 3., "R");
	Basis leftBasis = createSpinBasis(M_PI / 3. * 4., "L");
	vector <Basis> usedBases{ verticalBasis, rigthBasis, leftBasis };

	Alice->setBases(usedBases);
	Bob->setBases(usedBases);
	Eva->setBases(usedBases);

	return true;
}

Basis Universe::createSpinBasis(double theta, string name) {
	double degree = theta / 2.;
	Basis result(State(cos(degree), -sin(degree)), 
				 State(sin(degree), cos(degree)), name);
	return result;
}

vector <bool> Universe::generateRandomBinarySequence (long long n) {
	vector <bool> randomSequence;
	randomSequence.resize(n);

	random_device rd;
	mt19937 generator(rd());
	bernoulli_distribution distribution(DIST_PARAMETER);

	std::generate(randomSequence.begin(), randomSequence.end(),
		[&generator, &distribution] { return distribution(generator); });

	return randomSequence;
}
