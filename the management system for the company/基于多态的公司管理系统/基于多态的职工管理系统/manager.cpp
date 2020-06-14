#include "manager.h"

Manager::Manager(int id, string name, int did) //构造函数
{
	Manager::m_Id = id;
	Manager::m_Name = name;
	Manager::m_DepartId = did;
}

void Manager::showInfo()//virtual删
{
	cout << "职员编号：" << Manager::m_Id
		<< "\t职工姓名：" << Manager::m_Name
		<< "\t岗位：" << Manager::getDepartName()
		<< "\t职责：" << "完成老板教给的任务，分配给员工任务" << endl;
}
string Manager::getDepartName()
{
	return string("经理");
}
