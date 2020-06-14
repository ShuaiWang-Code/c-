#include "boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = did;
}
void Boss::showInfo()
{
	cout << "职员编号：" << Boss::m_Id
		<< "\t职工姓名：" << Boss::m_Name
		<< "\t岗位：" << Boss::getDepartName()
		<< "\t职责：" << "管理公司所有事务" << endl;
}

string Boss::getDepartName()
{
	return string("老板");
}