#include "Enigma.h"
#include <iostream>

using namespace std;


int main() {
	string code = "MDXMDAORNSLZBJTCDSABGHLVWA";

	string map1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	string map2 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	string map3 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	string mapRef = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
	Rotor r1(1, 'R', map1, 'M');
	Rotor r2(2, 'K', map2, 'K');
	Rotor r3(3, 'F', map3, 'C');
	Reflector ref1("UKW-B", mapRef);
	Enigma theMachine;
	theMachine.setReflector(ref1);
	theMachine.setRotor(r1, 0);
	theMachine.setRotor(r2, 1);
	theMachine.setRotor(r3, 2);

	char c = 'A';

	cout << theMachine.decode(code) << endl;

	system("PAUSE");
	return 0;
}