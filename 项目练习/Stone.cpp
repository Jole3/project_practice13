#include <sstream>
#include "Stone.h"

Stone::Stone(int number, StoneLevel stage)
{
	this->number = number;
	this->stage = stage;
}

std::string Stone::str() const
{
	std::stringstream ret;
	ret << number << "块";
	
	switch (stage){

	case StoneLevel::PRIMARY_LEVEL: 
		ret << "初阶灵石";
		break;
	case StoneLevel::MIDDLE_LEVEL: 
		ret << "中阶灵石";
		break;
	case StoneLevel::HIGH_LEVEL: 
		ret << "高阶灵石";
		break;
	default: 
		ret << "其他灵石";
		break;
	}


	return ret.str();
}

bool Stone::operator==(const Stone & stone)
{
	if (number == stone.number) {
		return true;
	}

	return false;
}

Stone Stone::operator-(const Stone & other)
{
	number -= other.number;

	return Stone(number,StoneLevel::PRIMARY_LEVEL);
}

bool Stone::operator>(const Stone & other)
{
	if (number > other.number) {
		return true;
	}
	return false;
}

int Stone::getCount() const
{
	return number;
}

std::ostream & operator<<(std::ostream & os, const Stone & stone)
{
	os << stone.str();

	return os;
}

Stone operator+(Stone & stone, const Stone &other)
{
	if (other.stage == StoneLevel::PRIMARY_LEVEL) {
		stone.number += other.number;
	}
	else if (other.stage == StoneLevel::MIDDLE_LEVEL) {
		stone.number += other.number * 10;
	}
	else if (other.stage == StoneLevel::HIGH_LEVEL) {
		stone.number += other.number * 100;
	}

	return Stone(stone.number, StoneLevel::PRIMARY_LEVEL);
}
