#pragma once
#include <string>
#include <vector>

class Monster;
class Stone;

enum class ImmortalGrade{
	LIAN_QI,	//练气期
	ZHU_JI,		//筑基期
	JIE_DAN,	//结丹期
	YUAN_YIN,	//元婴期
	HUA_SHEN,	//化神期
	LIAN_XU,	//炼虚期
	HE_TI,		//合体期
	DA_CHENG,	//大成期
	DU_JIE		//渡劫期
};

class Immortal
{
public:
	Immortal(const std::string name = "无名", const std::string sect = "无派", ImmortalGrade grade = ImmortalGrade::LIAN_QI);
	void mining();	//采矿
	bool catchMonster(Monster &monster);	//捕捉妖兽

	int getPower() const;	//获得战力
	
	//贸易
	bool trade();		//卖掉所有的妖兽
	bool trade(const Monster &monster);	//卖掉指定的妖兽
	bool trade(const Monster &monster, Immortal &other);	//卖给其他修仙者指定的妖兽
	bool trade(const Monster &monsterSource, Immortal &other, const Monster &otherDest);	//和其他修仙者交换妖兽
	bool trade(Immortal &other, const Monster &monster);	//用灵石购买妖兽（其他人手上）

	friend std::ostream &operator<<(std::ostream &os, const Immortal &immortal);

	std::string getName() const;

private:
	std::string name;
	std::string sect;	 //门派
	ImmortalGrade grade;	 //等级
	std::vector <Stone> stones;		 //灵石资产
	std::vector <Monster> monsters;	 //妖兽资产
	bool alive;
	bool hasMonster(const Monster &monster);
	void deletMonster(const Monster &monster);
	bool hasStone(const Monster &monster);		//是否有买指定妖兽的钱
	void deletStone(const Monster &monster);	//卖出指定妖兽移除钱
};

std::ostream &operator<<(std::ostream &os, const Immortal &immortal);
std::ostream &operator<<(std::ostream &os, const ImmortalGrade &grade);