#include "Character.h"

Character::Character() {
	basesSequence = new vector <string>(0);
	binaryMessage = new vector <bool>(0);
}

void Character::setBases(const vector <Basis> bases) {
	usedBases = bases;
}

void Character::crossBasesSequence(Character* pair) {
	int i = 0;
	auto basesSequenceBegin = basesSequence->begin();
	auto binaryMessageBegin = binaryMessage->begin();
	auto pairBasesSequenceBegin = pair->basesSequence->begin();
	auto pairBinaryMessageBegin = pair->binaryMessage->begin();

	while (basesSequenceBegin + i != basesSequence->end()) {
		if ((*basesSequence)[i] != (*pair->basesSequence)[i]) {
			basesSequence->erase(basesSequenceBegin + i);
			binaryMessage->erase(binaryMessageBegin + i);
			pair->basesSequence->erase(pairBasesSequenceBegin + i);
			pair->binaryMessage->erase(pairBinaryMessageBegin + i);
		}
		else {
			i++;
		}

		if (i == 0) {
			basesSequenceBegin = basesSequence->begin();
			binaryMessageBegin = binaryMessage->begin();
			pairBasesSequenceBegin = pair->basesSequence->begin();
			pairBinaryMessageBegin = pair->binaryMessage->begin();

		}
	}
}

void Character::crossBinaryMessage(Character* pair) {
	int i = 0;
	while (binaryMessage->begin() + i != binaryMessage->end()) {
		if ((*binaryMessage)[i] != (*pair->binaryMessage)[i]) {
			basesSequence->erase(basesSequence->begin() + i);
			binaryMessage->erase(binaryMessage->begin() + i);
			pair->basesSequence->erase(pair->basesSequence->begin() + i);
			pair->binaryMessage->erase(pair->binaryMessage->begin() + i);
		}
		else {
			i++;
		}
	}
}

vector <string>* Character::getBasesSequence() {
	return basesSequence;
}

vector <bool>* Character::getBinaryMessage() {
	return binaryMessage;
}

void Character::printMessage() {
	printName();
	for (unsigned i = 0; i < binaryMessage->size(); i++) {
		cout << (*binaryMessage)[i];
	}
	cout << endl;
}

void Character::printBasesSequence() {
	printName();
	for (unsigned i = 0; i < basesSequence->size(); i++) {
		cout << (*basesSequence)[i];
	}
	cout << endl;
}