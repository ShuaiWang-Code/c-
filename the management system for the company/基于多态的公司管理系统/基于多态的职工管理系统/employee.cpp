#include "employee.h"


Employee::Employee(int id, string name, int did) //���캯��
{
	Employee::m_Id = id;
	Employee::m_Name = name;
	Employee::m_DepartId = did;
}

void Employee::showInfo()//virtualɾ
{
	cout << "ְԱ��ţ�" << Employee::m_Id
		<< "\tְ��������" << Employee::m_Name
		<< "\t��λ��" << Employee::getDepartName() 
		<< "\tְ��" << "��ɾ���̸�������" << endl;
}
string Employee::getDepartName() 
{
	return string("Ա��");
}
