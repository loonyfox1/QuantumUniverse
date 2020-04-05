#include "Destination.h"
#include "Universe.h"

void Destination::decodeKey(vector <Qubit>* key) {
	long long n = key->size();

	vector <bool> randomSequence = Universe::generateRandomBinarySequence(n);
	for (unsigned i = 0; i < n; i++) {
		binaryMessage->push_back(usedBases[randomSequence[i]].getBit((*key)[i]));
		basesSequence->push_back(usedBases[randomSequence[i]].getName());
	}
}

void Destination::printName() {
	cout << "Bob:   ";
}
