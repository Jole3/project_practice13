#include "Stone.h"
#include "Monster.h"
#include "Immortal.h"

using namespace std;

void testStone() {
	Stone stone(3,StoneLevel::PRIMARY_LEVEL);

	cout << stone << endl;
}

void testMonster() {
	Monster monster(3, "蛟龙");

	cout << monster << endl;
}

void testImmortal() {
	Immortal imm("Rock", "奇牛", ImmortalGrade::LIAN_QI);
	Immortal martin("Martin", "奇牛", ImmortalGrade::LIAN_QI);

	Monster monster(1, "蛟龙");
	Monster monster2(1, "飞天");
	Monster monster3(1, "遁地");
	Monster monster4(2, "传说");

	for (int i = 0; i < 100; i++) {
		imm.mining();
		martin.mining();
	}

	cout << imm << endl;

	imm.catchMonster(monster);

	cout << "捕获" << monster << "之后" << endl;
	cout << imm << endl;


	imm.catchMonster(monster2);
	imm.catchMonster(monster3);

	cout << "捕获" << monster2 << "和" << monster3 << "之后" << endl;
	cout << imm << endl;

	imm.trade(monster2);
	cout << "卖出" << monster2 << "后" << endl;
	cout << imm << endl;

	imm.trade();
	cout << "卖出所有妖兽后" << endl;
	cout << imm << endl;

	martin.catchMonster(monster);
	martin.catchMonster(monster3);

	cout << "-----------------" << endl;
	cout << martin << endl;

	martin.trade(monster, imm);
	cout << martin.getName() << "卖出" << monster << "给" << imm.getName() << "后" << endl;
	cout << martin << endl;
	cout << imm << endl;

	cout << "--------交换---------" << endl;
	imm.trade(monster, martin, monster3);
	cout << martin.getName() << "用" << monster <<  "和" <<  imm.getName() << "交换"  << monster3 << "后" << endl;
	cout << martin << endl;
	cout << imm << endl;

	martin.catchMonster(monster4);
	cout << "捕获" << monster4 << "之后" << endl;
	cout << martin << endl;

	cout << "-----交易-----" << endl;
	imm.trade(martin, monster4);

	cout << imm.getName() << "从" <<  martin.getName() << "手上购买了" << monster4 << "后" << endl;
	cout << martin << endl;
	cout << imm << endl;
}

int main() {
	testStone();
	testMonster();
	testImmortal();

	return 0;
}