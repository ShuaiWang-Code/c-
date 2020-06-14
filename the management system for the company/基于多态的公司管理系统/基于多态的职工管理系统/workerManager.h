#pragma once         //防止头文件重复包含

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>


using namespace std;  //使用标准命名空间

#define FILENAME "empfile.txt"
class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	
	void ShowMenu();
	
	//退出0
	void ExitSystem();

	//添加员工
	void Add_Emp();
	
	void save();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;

	//判断文件是否为空
	bool m_FileIsEmpty;

	int get_EmpNum();

	//初始化
	void init_Emp();

	//显示职员
	void show_Emp();

	//删除职工   需要判断职工是否存在，存在返回所在数组索引，不存在返回-1
	void del_Emp();
	int IsExit(int id);

	//修改职工
	void mod_Emp();

	//查找
	void findEmp();

	//排序
	void sort_Emp();

	//清空文件
	void clean_Emp();

	//析构函数
	~WorkerManager();

};

