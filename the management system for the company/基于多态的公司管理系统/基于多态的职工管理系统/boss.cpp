#include "boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = did;
}
void Boss::showInfo()
{
	cout << "ְԱ��ţ�" << Boss::m_Id
		<< "\tְ��������" << Boss::m_Name
		<< "\t��λ��" << Boss::getDepartName()
		<< "\tְ��" << "����˾��������" << endl;
}

string Boss::getDepartName()
{
	return string("�ϰ�");
}