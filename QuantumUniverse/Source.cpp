#include "Source.h"
#include "Universe.h"

vector <Qubit>* Source::encodeKey(const vector <bool>& key) {
	long long n = key.size();

	vector <bool> randomSequence = Universe::generateRandomBinarySequence(n);
	vector <Qubit>* result = new vector <Qubit>(n);

	for (unsigned i = 0; i < n; i++) {
		(*result)[i] = Qubit(usedBases[randomSequence[i]].getState(key[i]), usedBases[randomSequence[i]]);
		binaryMessage->push_back(key[i]);
		basesSequence->push_back(usedBases[randomSequence[i]].getName());
	}

	return result;
}

void Source::printName() {
	cout << "Alice: ";
}

