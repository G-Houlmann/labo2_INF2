#include "Enigma.h"
#include <iostream>

using namespace std;


int main() {
	
	string map1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	string map2 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	string map3 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	Rotor r1(1, 'b', map1, 'N');
	Rotor r2(2, 'b', map2, 'K');
	Rotor r3(2, 'b', map3, 'C');

	char c = 'A';

	cout << r1.rToL('A') << endl;
	cout << r2.rToL('W') << endl;
	cout << r3.rToL('J') << endl;


	system("PAUSE");
	return 0;
}