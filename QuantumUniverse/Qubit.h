#pragma once

#include "State.h"
#include "Basis.h"

struct Qubit : public State {
	Basis basis;
	Qubit();
	Qubit(const State& state, Basis basis_) : State(state), basis(basis_) {};
};

