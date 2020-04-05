#include "Universe.h"

Universe::Universe() {
	Alice = new Source();
	Bob = new Destination();
	Eva = new Interceptor();
}

bool Universe::runBB84(long long n, bool intercept = Universe::generateRandomBinarySequence(1)[0]) {
	Basis verticalBasis(vector <double> {1, 0}, vector <double> {0, 1}, "V");
	Basis horizontalBasis (vector <double> {REV2ROOT, -REV2ROOT}, vector <double> {REV2ROOT, REV2ROOT}, "H");
	vector <Basis> usedBases {verticalBasis, horizontalBasis};

	Alice->setBases(usedBases);
	Bob->setBases(usedBases);
	Eva->setBases(usedBases);

	vector <Qubit>* encodedKey = Alice->encodeKey(generateRandomBinarySequence(n));
	encodedKey = Eva->interceptKey(encodedKey, intercept);
	Bob->decodeKey(encodedKey);

	Alice->crossBasesSequence(Bob);
	assert(*Alice->getBasesSequence() == *Bob->getBasesSequence());

	bool result = false;
	if (*Alice->getBinaryMessage() == *Bob->getBinaryMessage()) {
		cout << "The Trick worked well!" << endl;
	}
	else {
		cout << "Eva intercepted. Compare binary messages..." << endl;

		Alice->crossBinaryMessage(Bob);
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
