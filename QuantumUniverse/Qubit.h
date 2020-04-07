#pragma once

#include "State.h"
#include "Basis.h"

class Qubit : public State {
public:
	Basis basis;
	Qubit();
	Qubit(const State& state, Basis basis_) : State(state), basis(basis_) {};
};

