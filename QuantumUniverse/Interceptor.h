#pragma once
#include "Character.h"

class Interceptor : public Character
{
private:
	bool intercept;
public:
	vector <Qubit>* interceptKey(vector <Qubit>* key, bool intercept_);
	void printName() override;
	bool getInterceptChoice();
};

