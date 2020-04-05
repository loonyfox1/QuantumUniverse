#include "Interceptor.h"
#include "Universe.h"

vector <Qubit>* Interceptor::interceptKey(vector <Qubit>* key, bool intercept_) {
	intercept = intercept_;
	if (intercept) {
		long long n = key->size();

		vector <bool> randomSequence = Universe::generateRandomBinarySequence(n);
		for (unsigned i = 0; i < n; i++) {
			(*key)[i] = Qubit(usedBases[randomSequence[i]].determineState((*key)[i]), usedBases[randomSequence[i]]);
			basesSequence->push_back(usedBases[randomSequence[i]].getName());
		}
	}
	return key;
}

void Interceptor::printName() {
	cout << "Eva:   ";
}

bool Interceptor::getInterceptChoice() {
	return intercept;
}