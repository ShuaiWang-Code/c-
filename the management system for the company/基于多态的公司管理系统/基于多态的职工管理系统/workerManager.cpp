#include "workerManager.h"

WorkerManager::WorkerManager()
{
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	//1�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڵ���Ϊ��
	char ch;
	ifs >> ch;

	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�������������
	int num = this->get_EmpNum();
	//cout << "�ļ���ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ��е����ݴ浽����
	this->init_Emp();

	//��ӡ��������ʼ�����
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< "  ְ��������" << this->m_EmpArray[i]->m_Name
	//		<< "  ְ����λ��" << this->m_EmpArray[i]->m_DepartId << endl;
	//}

}

void WorkerManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ�� ***********" << endl;
	cout << "************* 0.�˳�������� ***************" << endl;
	cout << "************* 1.����ְ����Ϣ ***************" << endl;
	cout << "************* 2.��ʾְ����Ϣ ***************" << endl;
	cout << "************* 3.ɾ����ְְ�� ***************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ ***************" << endl;
	cout << "************* 5.����ְ����Ϣ ***************" << endl;
	cout << "************* 6.���ձ������ ***************" << endl;
	cout << "************* 7.��������ĵ� ***************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��~" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "�������Ա��������: " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//������ӵ��¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace= new Worker*[newSize];

		//��ԭ���ռ�����copy���¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;          //ְ�����       
			string name;	//ְ������
			int did;		//����ѡ��

			cout << "������� " << i + 1 << "����Ա���ı�ţ�" << endl;
			cin >> id;

			cout << "������� " << i + 1 << "����Ա����������" << endl;
			cin >> name;

			cout << "������� " << i + 1 << "����Ա���Ĳ���ѡ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//��ָ�뱣�浽������        �����ļ���ʼ���������ʳ�ʼ����this->m_EmpNum,Ϊ������ʵλ��
			newSpace[this->m_EmpNum + i] = worker;


		}
		//�ͷ�ԭ�пռ䣬����*�ռ�ָ��,��������
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;


		this->save();

		cout << "�ɹ����" << addNum << "��Ա����"<< endl;

	}
	else
	{
		cout << "������������" << endl;
	}
	//�����������������
	system("pause");
	system("cls");
}

//����
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�����ʽ���ļ� --д�ļ�
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
	int num = 0;//ͳ������
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
	//�ж��ļ��Ƿ�Ϊ�ջ򲻴���
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ��ID:" << endl;
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
			//ͬ������
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ�" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "�������޸�ְ���Ĺ��ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int newdid;

			cout << "�鵽" << id << "��ְ������������ְ������:" << endl;
			cin >> newid;
			cout << "������������:" << endl;
			cin >> newname;
			cout << "�������¸�λ:" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			this->save();
			//���浽�ļ�

		}
		else
		{
			cout << "ְ����Ӧ�Ĺ��Ų�����,���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ:"<< endl;
		cout << "1�����ձ�Ų���" << endl;
		cout << "2��������������" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int	id;
			cout << "�������ţ�" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				//zhaodaole
				cout << "���ҳɹ�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ�������" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�����Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}

			if (flag == false)
			{
				cout << " ���Ҳ�����" << endl;
			}
		}
		else
		{
			wcout << "�����ѯ��ʽ����"<< endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1�����������" << endl;
		cout << "2������Ž���" << endl;
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
	
			cout << "����ɹ�"<< endl;
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
			
			
			cout << "����ɹ�" << endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			cout << "�������" << endl;
			system("pause");
			system("cls");
		}
	}

}

void WorkerManager::clean_Emp()
{
	cout << "��ȷ���Ƿ����" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ�������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
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
		cout << "�������"<< endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()//�����ֶ����٣��ֶ��ͷ�
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

