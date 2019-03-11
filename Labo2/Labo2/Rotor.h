#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <algorithm>

class Rotor
{
public:
	Rotor(unsigned id, const char notch, const std::string baseWiring);
	void rotation(std::string currentWiring);
	char rToL(char c);
	char lToR(char c);
	void setCurrentWiring(std::string baseWiring, unsigned nextPos);
	~Rotor();

private:
	const unsigned id;
	const char notch;
	const std::string baseWiring;
	std::string currentWiring;
	int position;
};

#endif //ROTOR_H
