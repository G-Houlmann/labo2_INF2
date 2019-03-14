/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Reflector.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Permet de créer et de gérer un reflecteur convertissant une lettre
			   en une autre en fonction de son Wiring

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#ifndef REFLECTOR_H
#define REFLECTOR_H
#endif // !REFLECTOR_H

#include <string>

class Reflector
{
public:
	Reflector();
	Reflector(const std::string& name, const std::string&);
	~Reflector();
	char convert(char c) const;
	Reflector& operator=(const Reflector& reflector);

private:
	const std::string name;
	const std::string wiring;
};

