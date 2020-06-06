/*
��ʾ�˵�
1��װ������ʾ���� void showMenu()
2main�����е��÷�װ�õĺ���
*/

#include <iostream>
#include <string>
using namespace std;

#define PersonMax 1000    //����¼����

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string p_name;
	//�Ա�1��2Ů
	int p_sex;
	//����
	int p_age;
	//�绰
	string p_phone;
	//��ַ
	string p_address;
};
//���ͨѶ¼�Ľṹ��
struct Book
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[PersonMax];//�ṹ�����飬�����Ԫ�� ���� ��ϵ�˽ṹ��
	//ͨѶ¼��ǰ�ļ�¼����
	int p_num;
};

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" <<endl;
	cout << "*****  2����ʾ��ϵ��  *****" <<endl;
	cout << "*****  3��ɾ����ϵ��  *****" <<endl;
	cout << "*****  4��������ϵ��  *****" <<endl;
	cout << "*****  5���޸���ϵ��  *****" <<endl;
	cout << "*****  6�������ϵ��  *****" <<endl;
	cout << "*****  0���˳�ͨѶ��  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Book * book);
void showPerson(Book * book);
int isExit(Book * book, string name);
void deletePerson(Book * book);
void modifyPerson(Book * book);
void findPerson(Book * book);
void clearPerson(Book * book);

int main()
{
	
	//�����ṹ�����,��ǰ����Ϊ0
	Book book;
	book.p_num = 0;
	
	int select = 0;//�����û��������  ����ѡ�����switch������ֻ��0�˳�������ѡ����ѭ����ʾ����

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
				addPerson(&book);//1�������ϵ��      addPerson(book);ֵ���ݲ��ı�ṹ�壬�ʲ��õ�ַ���ݿ����޸�ʵ��
			break;
		case 2:
				showPerson(&book);// 2����ʾ��ϵ��
			break;
		case 3:
				deletePerson(&book);//3��ɾ����ϵ��
			break;
		case 4: findPerson(&book);//4��������ϵ��
			break;
		case 5:modifyPerson(&book);// 5���޸���ϵ��
			break;
		case 6: clearPerson(&book);//6�������ϵ��
			break;
		case 0:// 0���˳�ͨѶ��
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");//����һ������
	return 0;
}

//1�����ϵ��
void addPerson(Book * book)
{
	//�ж�������û��
	if (book->p_num == PersonMax)
	{
		cout << "ͨ��¼�������޷����" << endl;
		return;
	}
	else
	{
		

		//��ʾ��ϵ�˱��
		cout << "���ڽ��������ϵ�˲���......" << endl;
		cout << "�������� " << book->p_num+1 << " ����Ϣ"<< endl ;

		//����
		string name;
		cout << "������������";
		cin >> name;
		book->personArray[book->p_num].p_name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�(1----�� 2-----Ů)��";

		while (true)      //�������1��2����ȷ
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				book->personArray[book->p_num].p_sex = sex;
				break;
			}
			cout << "�������������������Ա�";
		}

		

		//����
		int age = 0;
		cout << "���������䣺";

		while (true)
		{
			cin >> age;
			if (age >= 1 && age <= 100)
			{
				book->personArray[book->p_num].p_age = age;
				break;
			}
			cout << "���������������������䣺";

		}
		
		//�绰
		string phone;
		cout << "������绰��";


		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				book->personArray[book->p_num].p_phone = phone;
				break;
			}
			cout << "������������������绰��";

		}
		

		//��ַ
		string adrress;
		cout << "�������ַ��";
		cin >> adrress;
		book->personArray[book->p_num].p_address = adrress;

		cout << "��ӳɹ���"<< endl;

		book->p_num++;

		system("pause");//�밴���������
		system("cls");//clear

		
	}
}

//2��ʾ��ϵ��
void showPerson(Book * book)
{
	//�ж��Ƿ�Ϊ0,
	if (book->p_num == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		system("cls");
		cout << "ͨѶ¼��\n" << endl;
		for (int i = 0; i < book->p_num; i++)
		{
			cout << "\t ��ţ�" << i+1 << "\t";
			cout << "������" << book->personArray[i].p_name << "\t";
			cout << "�Ա�" << (book->personArray[i].p_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << book->personArray[i].p_age << "\t";
			cout << "�绰��" << book->personArray[i].p_phone << "\t";
			cout << "��ַ��" << book->personArray[i].p_address << endl;
		}

	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ������򷵻����������������ڷ���-1
int isExit(Book * book, string name)
{
	for (int i = 0; i < book->p_num; i++)
	{
		if (book->personArray[i].p_name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void deletePerson(Book * book)
{
	cout << "������ɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExit(book, name);

	if (ret == -1)
	{
		cout << "���޴���" << endl;
		system("pause");//�밴���������
		system("cls");
	}
	else 
	{
		for (int i = ret; i < book->p_num; i++)
		{
			book->personArray[i] = book->personArray[i + 1];//bug
		}
		book->p_num--;
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}
//������ϵ��
void findPerson(Book * book)
{
	cout << "�����������ϵ��������" << endl;
	string name;
	cin >> name;

	int ret = isExit(book, name);

	if (ret == -1)
	{
		cout << "���޴���" << endl;

	}
	else
	{
		cout << "�Ѳ鵽������£�" << endl;
		cout << "\t ��ţ�" << ret + 1 << "\t";
		cout << "������" << book->personArray[ret].p_name << "\t";
		cout << "�Ա�" << (book->personArray[ret].p_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << book->personArray[ret].p_age << "\t";
		cout << "�绰��" << book->personArray[ret].p_phone << "\t";
		cout << "��ַ��" << book->personArray[ret].p_address << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ����Ϣ
void modifyPerson(Book * book)
{
	cout << "�������޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;

	int ret = isExit(book, name);

	if (ret == -1)
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string name;
		cout << "������������";
		cin >> name;
		book->personArray[ret].p_name = name;

		int sex = 0;
		cout << "�������Ա�(1----�� 2-----Ů)��";

		while (true)      //�������1��2����ȷ
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				book->personArray[ret].p_sex = sex;
				break;
			}
			cout << "�������������������Ա�";
		}



		//����
		int age = 0;
		cout << "���������䣺";

		while (true)
		{
			cin >> age;
			if (age >= 1 && age <= 100)
			{
				book->personArray[ret].p_age = age;
				break;
			}
			cout << "���������������������䣺";

		}

		//�绰
		string phone;
		cout << "������绰��";


		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				book->personArray[ret].p_phone = phone;
				break;
			}
			cout << "������������������绰��";

		}


		//��ַ
		string adrress;
		cout << "�������ַ��";
		cin >> adrress;
		book->personArray[ret].p_address = adrress;

		cout << "�޸ĳɹ���" << endl;
		system("pause");
		system("cls");

	}

}

//�����ϵ��
void clearPerson(Book * book)
{
	cout << "ȷ����������� Y or N" << endl;
	string selection;
	cin >> selection;

	if (selection == "Y")
	{
		book->p_num = 0;
		cout << "��ճɹ���" << endl;
	}
	else if (selection == "N")
	{
		cout << "ȡ���ɹ�" << endl;
	}
	else
	{
		cout << "����Ƿ�������������" << endl;
	}
	system("pause");
	system("cls");
}