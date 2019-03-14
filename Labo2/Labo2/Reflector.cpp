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

const int CHAR_SHIFT = 65;

Reflector::Reflector() {

}

Reflector::Reflector(const std::string& name, const std::string& wiring) 
                     : name(name), wiring(wiring){

}


Reflector::~Reflector()
{
}

Reflector& Reflector::operator=(const Reflector& reflector) {
	if (this != &reflector) {
		(std::string&)name = reflector.name;
		(std::string&)wiring = reflector.wiring;
	}
	return *this;
}

char Reflector::convert(char c) const {
	return this->wiring[c - CHAR_SHIFT];
}