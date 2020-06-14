#include "workerManager.h"

WorkerManager::WorkerManager()
{
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	//1文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在但是为空
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且有数据
	int num = this->get_EmpNum();
	//cout << "文件中职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中的数据存到数组
	this->init_Emp();

	//打印出来，初始化完成
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		<< "  职工姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "  职工岗位：" << this->m_EmpArray[i]->m_DepartId << endl;
	//}

}

void WorkerManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "********* 欢迎使用职工管理系统！ ***********" << endl;
	cout << "************* 0.退出管理程序 ***************" << endl;
	cout << "************* 1.增加职工信息 ***************" << endl;
	cout << "************* 2.显示职工信息 ***************" << endl;
	cout << "************* 3.删除离职职工 ***************" << endl;
	cout << "************* 4.修改职工信息 ***************" << endl;
	cout << "************* 5.查找职工信息 ***************" << endl;
	cout << "************* 6.按照编号排序 ***************" << endl;
	cout << "************* 7.清空所有文档 ***************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用~" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "输入添加员工的数量: " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算添加的新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker ** newSpace= new Worker*[newSize];

		//将原来空间数据copy到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;          //职工编号       
			string name;	//职工姓名
			int did;		//部门选择

			cout << "请输入第 " << i + 1 << "个新员工的编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << "个新员工的姓名：" << endl;
			cin >> name;

			cout << "请输入第 " << i + 1 << "个新员工的部门选择：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;

			Worker * worker = NULL;
			switch (did)
			{
			case 1:	worker = new Employee(id,name, 1);
				break;
			case 2:	worker = new Manager(id,name, 2);
				break;
			case 3:	worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将指针保存到数组里        后期文件初始有人数，故初始加上this->m_EmpNum,为数组真实位置
			newSpace[this->m_EmpNum + i] = worker;


		}
		//释放原有空间，更改*空间指向,更新人数
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;


		this->save();

		cout << "成功添加" << addNum << "个员工！"<< endl;

	}
	else
	{
		cout << "输入人数错误" << endl;
	}
	//按任意键返回主界面
	system("pause");
	system("cls");
}

//保存
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//输出方式打开文件 --写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepartId << " " << endl;
	}
	ofs.close();
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int num = 0;//统计人数
	while (ifs>>id && ifs>>name && ifs>> did)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker * worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::show_Emp()
{
	//判断文件是否为空或不存在
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		for (int i = 0;i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
			
	}
	system("pause");
	system("cls");

}

void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工ID:" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExit(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//同步更新
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到" << endl;
		}
	}

	system("pause");
	system("cls");
}
int WorkerManager::IsExit(int id) 
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入修改职工的工号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int newdid;

			cout << "查到" << id << "号职工，请输入新职工工号:" << endl;
			cin >> newid;
			cout << "请输入新姓名:" << endl;
			cin >> newname;
			cout << "请输入新岗位:" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newdid;

			Worker * worker = NULL;
			switch (newdid)
			{
			case 1:worker = new Employee(newid, newname, newdid);
				break;
			case 2:worker = new Manager(newid, newname, newdid);
				break;
			case 3:worker = new Boss(newid, newname, newdid);
				break;
			default:
				break;
			}
			//更新数组
			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			this->save();
			//保存到文件

		}
		else
		{
			cout << "职工对应的工号不存在,查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式:"<< endl;
		cout << "1、按照编号查找" << endl;
		cout << "2、按照姓名查找" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int	id;
			cout << "请输入编号：" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				//zhaodaole
				cout << "查找成功" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，不存在" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//加入是否查到的标志
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}

			if (flag == false)
			{
				cout << " 查找不存在" << endl;
			}
		}
		else
		{
			wcout << "输入查询方式有误"<< endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按编号升序" << endl;
		cout << "2、按编号降序" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int MinorMax = i;
				for (int j = i + 1; j < m_EmpNum; j++)
				{
					if (this->m_EmpArray[MinorMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinorMax = j;
					}
				}

				if (i != MinorMax)
				{
					Worker * worker = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[MinorMax];
					this->m_EmpArray[MinorMax] = worker;
				}
			
			}
	
			cout << "排序成功"<< endl;
			this->save();
			this->show_Emp();
		}
		else if (select == 2)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int MinorMax = i;
				for (int j = i + 1; j < m_EmpNum; j++)
				{
					if (this->m_EmpArray[MinorMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinorMax = j;
					}
				}
				if (i != MinorMax)
				{
					Worker * worker = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[MinorMax];
					this->m_EmpArray[MinorMax] = worker;
				}

			}
			
			
			cout << "排序成功" << endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			cout << "输入错误" << endl;
			system("pause");
			system("cls");
		}
	}

}

void WorkerManager::clean_Emp()
{
	cout << "请确认是否清空" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//删除后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
	}
	else if (select == 2)
	{
		system("cls");
		return;
	}
	else
	{
		cout << "输入错误"<< endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()//堆区手动开辟，手动释放
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

