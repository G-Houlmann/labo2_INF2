#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <algorithm>

class Rotor
{
public:
	Rotor();
	Rotor(const unsigned id, const char notch, const std::string wiring, char position);
	void rotation(std::string currentWiring);
	char rToL(char c);
	char lToR(char c);
	Rotor& operator=(const Rotor& rotor);
	~Rotor();

private:
	const unsigned id;
	const char notch;
	const std::string wiring;
	int position;
};

#endif //ROTOR_H
