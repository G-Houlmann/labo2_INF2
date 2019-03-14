/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Reflector.cpp
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Fichier source de Reflector.h

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#include "Reflector.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int CHAR_SHIFT = 65;

Reflector::Reflector() {

}

Reflector::Reflector(const std::string& name, const std::string& wiring) 
                     : name(name), wiring(wiring){

}


Reflector::~Reflector()
{
}

void Reflector::displayReflector() const {
	const unsigned SHIFT = 10;
	cout << "Reflector" << endl
		<< setw(SHIFT) << left << "reflector" << ":" << name << endl
		<< setw(SHIFT) << left << "wiring" << ":" << wiring << endl << endl;
}

Reflector& Reflector::operator=(const Reflector& reflector) {
	if (this != &reflector) {
		(std::string&)name = reflector.name;
		(std::string&)wiring = reflector.wiring;
	}
	return *this;
}

char Reflector::convert(char c, bool b) const {
	char newC = this->wiring[c - CHAR_SHIFT];

	if (b) {
		const unsigned SHIFT = 10;
		const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		cout << "reflector" << endl
			<< setw(SHIFT) << left << "entry" << ": " << ALPHABET << endl
			<< setw(SHIFT) << left << "wiring" << ": " << wiring << endl
			<< setw(SHIFT) << left << "result" << ": " << newC << "<=" 
                        << c << endl << endl;
	}
	return newC;
}