#include "Enigma.h"
#include <iostream>

using namespace std;


int main() {

	string map1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	string map2 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	string map3 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	string mapRef = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
	Rotor r1(1, 'R', map1, 'M');
	Rotor r2(2, 'K', map2, 'K');
	Rotor r3(3, 'F', map3, 'C');
	Reflector ref1("UKW-B", mapRef);
	Enigma machineEnigma(r3, r2, r1, ref1);

	string code = "MDXMDAORNSLZBJTCDSABGHLVWA";
	cout << machineEnigma.decode(code) << endl;

	system("PAUSE");
	return 0;
}