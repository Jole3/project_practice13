#include "Stone.h"
#include "Monster.h"
#include "Immortal.h"

using namespace std;

void testStone() {
	Stone stone(3,StoneLevel::PRIMARY_LEVEL);

	cout << stone << endl;
}

void testMonster() {
	Monster monster(3, "����");

	cout << monster << endl;
}

void testImmortal() {
	Immortal imm("Rock", "��ţ", ImmortalGrade::LIAN_QI);
	Immortal martin("Martin", "��ţ", ImmortalGrade::LIAN_QI);

	Monster monster(1, "����");
	Monster monster2(1, "����");
	Monster monster3(1, "�ݵ�");
	Monster monster4(2, "��˵");

	for (int i = 0; i < 100; i++) {
		imm.mining();
		martin.mining();
	}

	cout << imm << endl;

	imm.catchMonster(monster);

	cout << "����" << monster << "֮��" << endl;
	cout << imm << endl;


	imm.catchMonster(monster2);
	imm.catchMonster(monster3);

	cout << "����" << monster2 << "��" << monster3 << "֮��" << endl;
	cout << imm << endl;

	imm.trade(monster2);
	cout << "����" << monster2 << "��" << endl;
	cout << imm << endl;

	imm.trade();
	cout << "�����������޺�" << endl;
	cout << imm << endl;

	martin.catchMonster(monster);
	martin.catchMonster(monster3);

	cout << "-----------------" << endl;
	cout << martin << endl;

	martin.trade(monster, imm);
	cout << martin.getName() << "����" << monster << "��" << imm.getName() << "��" << endl;
	cout << martin << endl;
	cout << imm << endl;

	cout << "--------����---------" << endl;
	imm.trade(monster, martin, monster3);
	cout << martin.getName() << "��" << monster <<  "��" <<  imm.getName() << "����"  << monster3 << "��" << endl;
	cout << martin << endl;
	cout << imm << endl;

	martin.catchMonster(monster4);
	cout << "����" << monster4 << "֮��" << endl;
	cout << martin << endl;

	cout << "-----����-----" << endl;
	imm.trade(martin, monster4);

	cout << imm.getName() << "��" <<  martin.getName() << "���Ϲ�����" << monster4 << "��" << endl;
	cout << martin << endl;
	cout << imm << endl;
}

int main() {
	testStone();
	testMonster();
	testImmortal();

	return 0;
}