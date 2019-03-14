/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Main.cpp
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Crée une machine Enigma et l'utilise pour décoder un message

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#include "Enigma.h"
#include <iostream>

using namespace std;


int main() {

	//Initializing wirings
	string map1 = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	string map2 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	string map3 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	string mapRef = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

	//Initializing rotors and reflector
	Rotor r1(1, 'R', map1, 'M');
	Rotor r2(2, 'K', map2, 'K');
	Rotor r3(3, 'F', map3, 'C');
	Reflector ref1("UKW-B", mapRef);

	//Initializing Enigma machine
	Enigma EnigmaMachine(r3, r2, r1, ref1);

	//Decoding the code
	string code = "MDXMDAORNSLZBJTCDSABGHLVWA";
	cout << EnigmaMachine.decode(code) << endl;

	system("PAUSE");
	return 0;
}