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
	ret << number << "��";
	
	switch (stage){

	case StoneLevel::PRIMARY_LEVEL: 
		ret << "������ʯ";
		break;
	case StoneLevel::MIDDLE_LEVEL: 
		ret << "�н���ʯ";
		break;
	case StoneLevel::HIGH_LEVEL: 
		ret << "�߽���ʯ";
		break;
	default: 
		ret << "������ʯ";
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
