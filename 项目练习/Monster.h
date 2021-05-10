#pragma once
#include <string>
#include <iostream>

class Stone;

class Monster
{
public:
	Monster(int level = 1, const std::string type = "飞天");
	Stone getValue() const;

	friend std::ostream &operator<<(std::ostream &os, const Monster &monster);

	bool operator==(const Monster & monster);

	int getPower() const;		//获得战力

private:
	int level; //等级
	std::string type;	//种类

};

std::ostream &operator<<(std::ostream &os, const Monster &monster);