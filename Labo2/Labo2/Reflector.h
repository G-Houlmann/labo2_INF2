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

private:
	std::string name;
	std::string wiring;
};

