#include "employee.h"


Employee::Employee(int id, string name, int did) //构造函数
{
	Employee::m_Id = id;
	Employee::m_Name = name;
	Employee::m_DepartId = did;
}

void Employee::showInfo()//virtual删
{
	cout << "职员编号：" << Employee::m_Id
		<< "\t职工姓名：" << Employee::m_Name
		<< "\t岗位：" << Employee::getDepartName() 
		<< "\t职责：" << "完成经理教给的任务" << endl;
}
string Employee::getDepartName() 
{
	return string("员工");
}
