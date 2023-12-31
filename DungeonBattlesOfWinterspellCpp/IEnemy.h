#pragma once
#include <vector>
#include <string>
#include "ICreature.h"

class IEnemy : public ICreature {

private:
	std::string name;
	int health;
	bool hasSwiftness;
	std::string skillName;
	std::string skillDescription;
	int skillDamage;
	bool isDead;

public:
	virtual std::string GetName() = 0;
	virtual int GetHealth() = 0;
	virtual bool GetHasSwiftness() = 0;
	virtual std::string GetSkillName() = 0;
	virtual std::string GetSkillDescription() = 0;
	virtual int GetSkillDamage() = 0;
	virtual bool GetIsDead() = 0;
	virtual void TakeDamage(int hitPoints) {};

	virtual ~IEnemy() = default;
};
