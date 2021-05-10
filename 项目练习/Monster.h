#pragma once
#include <string>
#include <iostream>

class Stone;

class Monster
{
public:
	Monster(int level = 1, const std::string type = "����");
	Stone getValue() const;

	friend std::ostream &operator<<(std::ostream &os, const Monster &monster);

	bool operator==(const Monster & monster);

	int getPower() const;		//���ս��

private:
	int level; //�ȼ�
	std::string type;	//����

};

std::ostream &operator<<(std::ostream &os, const Monster &monster);