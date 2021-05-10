#pragma once
#include <string>
#include <iostream>

enum class StoneLevel {
	PRIMARY_LEVEL,
	MIDDLE_LEVEL,
	HIGH_LEVEL
};

class Stone
{
public:
	Stone(int number = 0, StoneLevel stage = StoneLevel::PRIMARY_LEVEL);
	std::string str() const;

	friend std::ostream & operator<<(std::ostream & os, const Stone & stone);
	friend Stone operator+(Stone & stone, const Stone &other);

	bool operator ==(const Stone &stone);

	Stone operator -(const Stone &other);
	bool operator >(const Stone &other);

	int getCount() const;

private:
	int number;	//��ʯ������
	StoneLevel stage;	//��ʯ�Ľ׶�
};

std::ostream &operator<<(std::ostream &os, const Stone &stone);
Stone operator +(Stone &stone, const Stone &other);