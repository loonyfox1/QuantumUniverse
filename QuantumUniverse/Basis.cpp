#include "Basis.h"
#include "Qubit.h"

Basis::Basis() {}

Basis::Basis(vector <double> first_, vector <double> second_, string name_) {
	assert(first_.size() == second_.size());

	dimension = (int)first_.size();
	first = State(first_);
	second = State(second_);
	name = name_;
}

Basis::Basis(State first_, State second_, string name_) {
	assert(first_.dimension == second_.dimension);

	dimension = first_.dimension;
	first = first_;
	second = second_;
	name = name_;
}

int Basis::getDimension() {
	return dimension;
}

string Basis::getName() {
	return name;
}

State Basis::getState(bool bit) {
	if (bit == 0) {
		return first;
	}
	else {
		return second;
	}
}

State Basis::determineState(Qubit qubit) {
	double a = first.ket[0] * qubit.ket[0] + first.ket[1] * qubit.ket[1];
	double b = second.ket[0] * qubit.ket[0] + second.ket[1] * qubit.ket[1];
	State result(vector <double> {a* first.ket[0] + b * second.ket[0], a* first.ket[1] + b * second.ket[1]});

	return result;
}

bool Basis::getBit(Qubit qubit) {
	State result = determineState(qubit);

	if (result == qubit.basis.first) {
		return 0;
	}
	else if(result == qubit.basis.second) {
		return 1;
	}
}

