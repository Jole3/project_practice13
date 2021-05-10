#pragma once
#include <string>
#include <vector>

class Monster;
class Stone;

enum class ImmortalGrade{
	LIAN_QI,	//������
	ZHU_JI,		//������
	JIE_DAN,	//�ᵤ��
	YUAN_YIN,	//ԪӤ��
	HUA_SHEN,	//������
	LIAN_XU,	//������
	HE_TI,		//������
	DA_CHENG,	//�����
	DU_JIE		//�ɽ���
};

class Immortal
{
public:
	Immortal(const std::string name = "����", const std::string sect = "����", ImmortalGrade grade = ImmortalGrade::LIAN_QI);
	void mining();	//�ɿ�
	bool catchMonster(Monster &monster);	//��׽����

	int getPower() const;	//���ս��
	
	//ó��
	bool trade();		//�������е�����
	bool trade(const Monster &monster);	//����ָ��������
	bool trade(const Monster &monster, Immortal &other);	//��������������ָ��������
	bool trade(const Monster &monsterSource, Immortal &other, const Monster &otherDest);	//�����������߽�������
	bool trade(Immortal &other, const Monster &monster);	//����ʯ�������ޣ����������ϣ�

	friend std::ostream &operator<<(std::ostream &os, const Immortal &immortal);

	std::string getName() const;

private:
	std::string name;
	std::string sect;	 //����
	ImmortalGrade grade;	 //�ȼ�
	std::vector <Stone> stones;		 //��ʯ�ʲ�
	std::vector <Monster> monsters;	 //�����ʲ�
	bool alive;
	bool hasMonster(const Monster &monster);
	void deletMonster(const Monster &monster);
	bool hasStone(const Monster &monster);		//�Ƿ�����ָ�����޵�Ǯ
	void deletStone(const Monster &monster);	//����ָ�������Ƴ�Ǯ
};

std::ostream &operator<<(std::ostream &os, const Immortal &immortal);
std::ostream &operator<<(std::ostream &os, const ImmortalGrade &grade);