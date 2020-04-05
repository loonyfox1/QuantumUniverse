#include <iostream>

using namespace std;

#include "Universe.h"

int main(int argc, char** argv)
{
	cout << "Create Universe..." << endl;
	Universe* universe = new Universe();

	long long n = 0;
	cout << "Enter length of message: ";
	cin >> n;

	bool inter = false;
	cout << "Enter Eva choice: ";
	cin >> inter;

	cout << endl << "Run BB84..." << endl;
	universe->runBB84(n, inter);

}

