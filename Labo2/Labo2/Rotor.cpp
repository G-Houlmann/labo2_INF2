/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Rotor.cpp
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Fichier source de Rotor.h

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#include "Rotor.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int CHAR_SHIFT = 65;
const unsigned ALPHABET_LENGTH = 26;
const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Rotor::displayRotor(string positionInMachine) const {
	cout << "----------------------------" << endl << "Enigma machine - Transmitter"
		<< endl << "----------------------------" << endl
		<< positionInMachine << " rotor" << endl 
		<< setw(10) << left << "Rotor id" << ":" << id << endl
		<< setw(10) << left << "wiring" << ":" << wiring << endl
		<< setw(10) << left << "position" << ":" << char(position + 65) << endl
		<< setw(10) << left << "notch"  << ":" << char(notch + 65) << endl << endl;
}

Rotor::Rotor() : id(0), notch('a'), wiring(""), position(0){

}

Rotor::Rotor(const unsigned id, const char notch, const std::string wiring, 
        char position) : id(id), notch((unsigned)toupper(notch) - (unsigned)CHAR_SHIFT), wiring(wiring)
{
	this->position = (unsigned)toupper(position) - (unsigned)CHAR_SHIFT;
		 
} 

char Rotor::rToL(char c, bool b) {
	char newChar = wiring.at((position + (unsigned)c - (unsigned)CHAR_SHIFT) % ALPHABET_LENGTH);

    if (b) {
        cout << setw(10) << left << "rotor" << ": " << id << " (pos " << (char)(position + 65) << ")" << endl
             << setw(10) << left << "entry" << ": " << alphabet << endl
             << setw(10) << left << "wiring" << ": " << wiring << endl
             << setw(10) << left << "result" << ": " << newChar << "<=" << c << endl << endl;
    }

	return newChar;
}

char Rotor::lToR(char c, bool b) {
    char oldC = c;
	c = (char)wiring.find_first_of(c);
	if (position > (unsigned)c) c += ALPHABET_LENGTH;
	c -= position;
	char newChar =  c + CHAR_SHIFT;

	if (b) {
        cout << setw(10) << left << "rotor" << ": " << id << " (pos " << (char)(position + 65) << ")" << endl
             << setw(10) << left << "entry" << ": " << alphabet << endl
             << setw(10) << left << "wiring" << ": " << wiring << endl
             << setw(10) << left << "result" << ": " << oldC << "=>" << newChar << endl << endl;
	}

	return newChar;
}

bool Rotor::rotation()
{
	bool nextRotorRotate = position == notch;
	position = (position + 1) % ALPHABET_LENGTH;
	return nextRotorRotate;
}


Rotor& Rotor::operator=(const Rotor& rotor) {
	if (this != &rotor) {
		(unsigned&)id = rotor.id;
		(unsigned&)notch = rotor.notch;
		(std::string&)wiring = rotor.wiring;
		position = rotor.position;
	}
	return *this;
}


Rotor::~Rotor(){}


