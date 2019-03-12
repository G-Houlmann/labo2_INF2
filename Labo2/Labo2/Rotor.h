#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <algorithm>

class Rotor
{
public:
	Rotor();
	Rotor(const unsigned id, const char notch, const std::string wiring, char position);
	char rToL(char c);
	char lToR(char c);
	unsigned getNotch() const;
	unsigned getPosition() const;
	bool rotation();
	Rotor& operator=(const Rotor& rotor);
	~Rotor();

private:
	const unsigned id;
	const unsigned notch;
	const std::string wiring;
	unsigned position;
};

#endif //ROTOR_H
