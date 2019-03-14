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
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const unsigned DISPLAY_SHIFT = 10;

void Rotor::displayRotor(string positionInMachine) const {
	cout 
		<< positionInMachine << " rotor" << endl 
		<< setw(DISPLAY_SHIFT) << left << "Rotor id" << ":" << id << endl
		<< setw(DISPLAY_SHIFT) << left << "wiring" << ":" << wiring << endl
		<< setw(DISPLAY_SHIFT) << left << "position" << ":" << char(position + CHAR_SHIFT) << endl
		<< setw(DISPLAY_SHIFT) << left << "notch"  << ":" << char(notch + CHAR_SHIFT) << endl << endl;
}

Rotor::Rotor() : id(0), notch('a'), wiring(""), position(0){

}

Rotor::Rotor(const unsigned id, const char notch, const std::string wiring, 
        char position) : id(id), 
		notch((unsigned)toupper(notch) - (unsigned)CHAR_SHIFT), wiring(wiring)
{
	this->position = (unsigned)toupper(position) - (unsigned)CHAR_SHIFT;
		 
} 

char Rotor::rToL(char c, bool b) {
	char newChar = wiring.at((position + (unsigned)c - (unsigned)CHAR_SHIFT) % ALPHABET_LENGTH);

    if (b) {
        cout << setw(DISPLAY_SHIFT) << left << "rotor" << ": " << id << " (pos " << (char)(position + CHAR_SHIFT) << ")" << endl
             << setw(DISPLAY_SHIFT) << left << "entry" << ": " << ALPHABET << endl
             << setw(DISPLAY_SHIFT) << left << "wiring" << ": " << wiring << endl
             << setw(DISPLAY_SHIFT) << left << "result" << ": " << newChar << "<=" << c << endl << endl;
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
        cout << setw(DISPLAY_SHIFT) << left << "rotor" << ": " << id << " (pos " << (char)(position + CHAR_SHIFT) << ")" << endl
             << setw(DISPLAY_SHIFT) << left << "entry" << ": " << ALPHABET << endl
             << setw(DISPLAY_SHIFT) << left << "wiring" << ": " << wiring << endl
             << setw(DISPLAY_SHIFT) << left << "result" << ": " << oldC << "=>" << newChar << endl << endl;
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


