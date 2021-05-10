#include "Monster.h"
#include "Stone.h"

#define MONSTER_POWER_FACTOR 1000

Monster::Monster(int level, const std::string type)
{
	this->level = level;
	this->type = type;
}

Stone Monster::getValue() const
{
	int value[] = { 100,200,500,1000,2000,5000,10000,20000,100000 };

	return Stone(value[level - 1], StoneLevel::PRIMARY_LEVEL);
}

bool Monster::operator==(const Monster & monster)
{
	if (type == monster.type && level == monster.level) {
		return true;
	}
	return false;
}

int Monster::getPower() const
{
	int ret = level * MONSTER_POWER_FACTOR;

	return ret;
}

std::ostream & operator<<(std::ostream &os, const Monster & monster)
{
	os << monster.level << "¼¶" << monster.type << "ÑýÊÞ";

	return os;
}
