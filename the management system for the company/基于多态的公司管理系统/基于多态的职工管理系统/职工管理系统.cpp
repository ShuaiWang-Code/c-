#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main()
{
	//test:
	//Worker * worker11 = NULL;
	//worker11 = new Employee(1, "wangshuai", 1);
	//worker11->showInfo();
	//delete worker11;

	//worker11 = new Manager(2, "shuaishuai", 2);
	//worker11->showInfo();
	//delete worker11;

	//worker11 = new Boss(3,"wangwang", 3);
	//worker11->showInfo();
	//delete worker11;

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.ShowMenu();
		cout << "请输入您的选择： " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:      wm.ExitSystem();
			break;//退出系统

		case 1:		wm.Add_Emp();
			break;//添加职工

		case 2:		wm.show_Emp();
			break; //显示职工

		case 3:		wm.del_Emp();
		/*test
		{
			int ret = wm.IsExit(201834573);
			if (ret != -1)
			{
				cout << "find!" << endl;
			}
			else
			{
				cout << "no find!" << endl;
			}
		}*/
			break;//删除职工

		case 4:wm.mod_Emp();
			break;//修改职工

		case 5:wm.findEmp();
			break;//查找职工

		case 6:wm.sort_Emp();
			break;//排序职工

		case 7:wm.clean_Emp();
			break;//清空存储文件

		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}