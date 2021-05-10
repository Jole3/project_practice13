#include "Immortal.h"
#include "Stone.h"
#include "Monster.h"

#define IMMORTAL_POWER_FACTOR 1000
#define STONE_POWER_FACTOR 0.1
#define MONSTER_POWER_FACTOR 0.1

Immortal::Immortal(const std::string name, const std::string sect, ImmortalGrade grade)
{
	this->name = name;
	this->sect = sect;
	this->grade = grade;
	this->alive = true;
}

void Immortal::mining()
{
	Stone stone(100, StoneLevel::PRIMARY_LEVEL);
	stones.push_back(stone);
}

bool Immortal::catchMonster(Monster & monster)
{
	if (getPower() > monster.getPower()) {
		monsters.push_back(monster);

		return true;
	}
	else if (getPower() < monster.getPower()) {
		alive = false;

		return false;
	}
}

int Immortal::getPower() const
{
	int ret = ((int)grade + 1) * IMMORTAL_POWER_FACTOR;

	//��ʯ������ս��
	Stone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}

	ret += stone.getCount() * STONE_POWER_FACTOR;

	//����������ս��
	Monster monster;
	for (int i = 0; i < monsters.size(); i++) {
		ret += monsters[i].getPower() * MONSTER_POWER_FACTOR;
	}

	return ret;
}

bool Immortal::trade()
{
	if (!alive) {				//�ж��������Ƿ񻹻���
		return false;
	}
	Stone stone;

	if (monsters.size()) {
		for (int i = 0; i < monsters.size(); i++) {
			stone = stone + monsters[i].getValue();		//��ħ�޻�����ʯ
			
		}
		stones.push_back(stone);							//����ʯ�Ž��ڴ���
		monsters.erase(monsters.begin(), monsters.end());	//�ѿڴ����������������

		return true;
	}
	
	return false;
}

bool Immortal::trade(const Monster & monster)
{
	if (!alive) {
		return false;
	}
	Stone stone;

	if (hasMonster(monster)) {			//�ж��Ƿ���ָ��������
		stone = stone + monster.getValue();
		stones.push_back(stone);

		deletMonster(monster);		//�ѿڴ���ָ�����������
		return true;
	}

	return false;
}

bool Immortal::trade(const Monster & monster, Immortal & other)
{
	if (!alive) {
		return false;
	}
	Stone stone;

	if (hasMonster(monster) && other.hasStone(monster)) {
		stone = stone + monster.getValue();
		stones.push_back(stone);
		deletMonster(monster);		//�ѿڴ���ָ�����������

		other.deletStone(monster);
		other.monsters.push_back(monster);

		return true;
	}

	return false;
}

bool Immortal::trade(const Monster & monsterSource, Immortal & other, const Monster & otherDest)
{
	if (!alive) {
		return false;
	}
	
	if (hasMonster(monsterSource) && other.hasMonster(otherDest)) {
		monsters.push_back(otherDest);
		deletMonster(monsterSource);

		other.monsters.push_back(monsterSource);
		other.deletMonster(otherDest);

		return true;
	}

	return false;
}

bool Immortal::trade(Immortal & other, const Monster & monster)
{
	if (!alive) {
		return false;
	}
	Stone stone;

	if (hasStone(monster) && other.hasMonster(monster)) {
		deletStone(monster);
		monsters.push_back(monster);

		stone = stone + monster.getValue();
		other.stones.push_back(stone);
		other.deletMonster(monster);
	}
}

std::string Immortal::getName() const
{
	return name;
}

bool Immortal::hasMonster(const Monster & monster)
{
	for (int i = 0; i < monsters.size(); i++) {
		if (monsters[i] == monster) {
			return true;
		}
	}
	return false;
}

void Immortal::deletMonster(const Monster & monster)
{
	std::vector<Monster>::iterator it = monsters.begin();
	while (it != monsters.end())
	{
		if (*it == monster) {
			it = monsters.erase(it);
		}
		else {
			it++;
		}
	}
}

bool Immortal::hasStone(const Monster & monster)
{
	Stone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}

	if (stone > monster.getValue()) {
		return true;
	}
	return false;
}

void Immortal::deletStone(const Monster & monster)
{
	Stone stone;

	// ��ǰ������ӵ�е��ܵ���ʯ����
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}
	stone = stone - monster.getValue();
	
	//��ɾ����ʯ���������µ��滻
	stones.erase(stones.begin(), stones.end());
	stones.push_back(stone);
}

std::ostream &operator<<(std::ostream &os, const Immortal &immortal) {
	Stone stone;

	os << "[������]" << immortal.name
		<< (immortal.alive ? "[����]" : "[����]")
		<< "\t����:" << immortal.sect
		<< "\t����:" << immortal.grade;

	for (int i = 0; i < immortal.stones.size(); i++) {
		stone = stone + immortal.stones[i];
	}
	os << "\t��ʯ:�ۺ�" << stone;

	os << "\t����:";
	if (immortal.monsters.size() == 0) {
		os << "��";
	}
	else {
		for (int i = 0; i < immortal.monsters.size(); i++) {
			os << immortal.monsters[i] << " ";
		}
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, const ImmortalGrade &grade) {
	
	switch (grade) {
	case ImmortalGrade::LIAN_QI:
		os << "������";
		break;
	case ImmortalGrade::ZHU_JI:
		os << "������";
		break;
	case ImmortalGrade::JIE_DAN:
		os << "�ᵤ��";
		break;
	case ImmortalGrade::YUAN_YIN:
		os << "ԪӤ��";
		break;
	case ImmortalGrade::HUA_SHEN:
		os << "������";
		break;
	case ImmortalGrade::LIAN_XU:
		os << "������";
		break;
	case ImmortalGrade::HE_TI:
		os << "������";
		break;
	case ImmortalGrade::DA_CHENG:
		os << "�����";
		break;
	case ImmortalGrade::DU_JIE:
		os << "�ɽ���";
		break;
	}
	return os;
}