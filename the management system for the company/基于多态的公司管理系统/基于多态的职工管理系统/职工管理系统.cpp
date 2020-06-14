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
		cout << "����������ѡ�� " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:      wm.ExitSystem();
			break;//�˳�ϵͳ

		case 1:		wm.Add_Emp();
			break;//���ְ��

		case 2:		wm.show_Emp();
			break; //��ʾְ��

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
			break;//ɾ��ְ��

		case 4:wm.mod_Emp();
			break;//�޸�ְ��

		case 5:wm.findEmp();
			break;//����ְ��

		case 6:wm.sort_Emp();
			break;//����ְ��

		case 7:wm.clean_Emp();
			break;//��մ洢�ļ�

		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}