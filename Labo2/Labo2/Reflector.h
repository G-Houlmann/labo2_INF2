#ifndef REFLECTOR_H
#define REFLECTOR_H
#endif // !REFLECTOR_H

#include <string>

class Reflector
{
public:
	Reflector(const std::string& name, const std::string&);
	~Reflector();
	char convert(char c) const;

private:
	const std::string name;
	const std::string wiring;
};

