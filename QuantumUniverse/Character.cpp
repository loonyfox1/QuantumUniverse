#include "Character.h"

Character::Character() {
	basesSequence = new vector <string>(0);
	binaryMessage = new vector <bool>(0);
}

void Character::setBases(const vector <Basis> bases) {
	usedBases = bases;
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