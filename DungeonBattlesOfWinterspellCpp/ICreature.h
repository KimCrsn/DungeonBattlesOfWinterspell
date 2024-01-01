#pragma once
#include <string>

class ICreature {
private:
	std::string name;

public:
	std::string GetName(){
		return name;
	}

	virtual bool IsPlayableCharacter() const = 0;
	virtual ~ICreature() = default;
};

