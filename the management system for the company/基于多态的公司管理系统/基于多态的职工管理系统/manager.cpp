#include "manager.h"

Manager::Manager(int id, string name, int did) //���캯��
{
	Manager::m_Id = id;
	Manager::m_Name = name;
	Manager::m_DepartId = did;
}

void Manager::showInfo()//virtualɾ
{
	cout << "ְԱ��ţ�" << Manager::m_Id
		<< "\tְ��������" << Manager::m_Name
		<< "\t��λ��" << Manager::getDepartName()
		<< "\tְ��" << "����ϰ�̸������񣬷����Ա������" << endl;
}
string Manager::getDepartName()
{
	return string("����");
}
