#include "Enigma.h"
#include <iostream>

using namespace std;


int main() {
	string str = "uisadfjaOSJFLKDSKJF... ";
	Enigma e;
	cout << e.decode(str);

	system("PAUSE");
	return 0;
}