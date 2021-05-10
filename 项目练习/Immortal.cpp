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

	//灵石助攻的战力
	Stone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}

	ret += stone.getCount() * STONE_POWER_FACTOR;

	//妖兽助攻的战力
	Monster monster;
	for (int i = 0; i < monsters.size(); i++) {
		ret += monsters[i].getPower() * MONSTER_POWER_FACTOR;
	}

	return ret;
}

bool Immortal::trade()
{
	if (!alive) {				//判断修仙者是否还活着
		return false;
	}
	Stone stone;

	if (monsters.size()) {
		for (int i = 0; i < monsters.size(); i++) {
			stone = stone + monsters[i].getValue();		//把魔兽换成灵石
			
		}
		stones.push_back(stone);							//把灵石放进口袋里
		monsters.erase(monsters.begin(), monsters.end());	//把口袋的所有妖兽清除掉

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

	if (hasMonster(monster)) {			//判断是否有指定的妖兽
		stone = stone + monster.getValue();
		stones.push_back(stone);

		deletMonster(monster);		//把口袋的指定妖兽清除掉
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
		deletMonster(monster);		//把口袋的指定妖兽清除掉

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

	// 当前修仙者拥有的总的灵石数量
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}
	stone = stone - monster.getValue();
	
	//先删除灵石，再用最新的替换
	stones.erase(stones.begin(), stones.end());
	stones.push_back(stone);
}

std::ostream &operator<<(std::ostream &os, const Immortal &immortal) {
	Stone stone;

	os << "[修仙者]" << immortal.name
		<< (immortal.alive ? "[在修]" : "[以亡]")
		<< "\t门派:" << immortal.sect
		<< "\t级别:" << immortal.grade;

	for (int i = 0; i < immortal.stones.size(); i++) {
		stone = stone + immortal.stones[i];
	}
	os << "\t灵石:折合" << stone;

	os << "\t妖兽:";
	if (immortal.monsters.size() == 0) {
		os << "无";
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
		os << "练气期";
		break;
	case ImmortalGrade::ZHU_JI:
		os << "筑基期";
		break;
	case ImmortalGrade::JIE_DAN:
		os << "结丹期";
		break;
	case ImmortalGrade::YUAN_YIN:
		os << "元婴期";
		break;
	case ImmortalGrade::HUA_SHEN:
		os << "化神期";
		break;
	case ImmortalGrade::LIAN_XU:
		os << "炼虚期";
		break;
	case ImmortalGrade::HE_TI:
		os << "合体期";
		break;
	case ImmortalGrade::DA_CHENG:
		os << "大成期";
		break;
	case ImmortalGrade::DU_JIE:
		os << "渡劫期";
		break;
	}
	return os;
}