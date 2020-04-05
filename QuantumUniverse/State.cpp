#include "State.h"

State::State() {
}

State::State(vector <double> ket_) {
	dimension = ket_.size();
	ket = ket_;
}

State::State(double a, double b) {
	dimension = 2;
	ket = vector <double>{ a,b };
}
