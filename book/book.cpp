/*
显示菜单
1封装函数显示界面 void showMenu()
2main函数中调用封装好的函数
*/

#include <iostream>
#include <string>
using namespace std;

#define PersonMax 1000    //最大记录人数

//设计联系人结构体
struct Person
{
	//姓名
	string p_name;
	//性别：1男2女
	int p_sex;
	//年龄
	int p_age;
	//电话
	string p_phone;
	//地址
	string p_address;
};
//设计通讯录的结构体
struct Book
{
	//通讯录中保存的联系人数组
	struct Person personArray[PersonMax];//结构体数组，数组的元素 都是 联系人结构体
	//通讯录当前的记录人数
	int p_num;
};

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" <<endl;
	cout << "*****  2、显示联系人  *****" <<endl;
	cout << "*****  3、删除联系人  *****" <<endl;
	cout << "*****  4、查找联系人  *****" <<endl;
	cout << "*****  5、修改联系人  *****" <<endl;
	cout << "*****  6、清空联系人  *****" <<endl;
	cout << "*****  0、退出通讯簿  *****" << endl;
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
	
	//创建结构体变量,当前人数为0
	Book book;
	book.p_num = 0;
	
	int select = 0;//创建用户输入变量  根据选项调用switch函数，只有0退出，其他选项则循环显示界面

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
				addPerson(&book);//1、添加联系人      addPerson(book);值传递不改变结构体，故采用地址传递可以修改实参
			break;
		case 2:
				showPerson(&book);// 2、显示联系人
			break;
		case 3:
				deletePerson(&book);//3、删除联系人
			break;
		case 4: findPerson(&book);//4、查找联系人
			break;
		case 5:modifyPerson(&book);// 5、修改联系人
			break;
		case 6: clearPerson(&book);//6、清空联系人
			break;
		case 0:// 0、退出通讯簿
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");//不会一闪而过
	return 0;
}

//1添加联系人
void addPerson(Book * book)
{
	//判断人满了没有
	if (book->p_num == PersonMax)
	{
		cout << "通信录已满，无法添加" << endl;
		return;
	}
	else
	{
		

		//显示联系人编号
		cout << "正在进行添加联系人操作......" << endl;
		cout << "请输入编号 " << book->p_num+1 << " 的信息"<< endl ;

		//姓名
		string name;
		cout << "请输入姓名：";
		cin >> name;
		book->personArray[book->p_num].p_name = name;

		//性别
		int sex = 0;
		cout << "请输入性别(1----男 2-----女)：";

		while (true)      //如果输入1和2则正确
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				book->personArray[book->p_num].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入性别：";
		}

		

		//年龄
		int age = 0;
		cout << "请输入年龄：";

		while (true)
		{
			cin >> age;
			if (age >= 1 && age <= 100)
			{
				book->personArray[book->p_num].p_age = age;
				break;
			}
			cout << "输入有误，请重新输入年龄：";

		}
		
		//电话
		string phone;
		cout << "请输入电话：";


		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				book->personArray[book->p_num].p_phone = phone;
				break;
			}
			cout << "输入有误，请重新输入电话：";

		}
		

		//地址
		string adrress;
		cout << "请输入地址：";
		cin >> adrress;
		book->personArray[book->p_num].p_address = adrress;

		cout << "添加成功！"<< endl;

		book->p_num++;

		system("pause");//请按任意键继续
		system("cls");//clear

		
	}
}

//2显示联系人
void showPerson(Book * book)
{
	//判断是否为0,
	if (book->p_num == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		system("cls");
		cout << "通讯录：\n" << endl;
		for (int i = 0; i < book->p_num; i++)
		{
			cout << "\t 编号：" << i+1 << "\t";
			cout << "姓名：" << book->personArray[i].p_name << "\t";
			cout << "性别：" << (book->personArray[i].p_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << book->personArray[i].p_age << "\t";
			cout << "电话：" << book->personArray[i].p_phone << "\t";
			cout << "地址：" << book->personArray[i].p_address << endl;
		}

	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，存在则返回数组索引，不存在返回-1
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

//删除联系人
void deletePerson(Book * book)
{
	cout << "请输入删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExit(book, name);

	if (ret == -1)
	{
		cout << "查无此人" << endl;
		system("pause");//请按任意键继续
		system("cls");
	}
	else 
	{
		for (int i = ret; i < book->p_num; i++)
		{
			book->personArray[i] = book->personArray[i + 1];//bug
		}
		book->p_num--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
}
//查找联系人
void findPerson(Book * book)
{
	cout << "请输入查找联系人姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExit(book, name);

	if (ret == -1)
	{
		cout << "查无此人" << endl;

	}
	else
	{
		cout << "已查到结果如下：" << endl;
		cout << "\t 编号：" << ret + 1 << "\t";
		cout << "姓名：" << book->personArray[ret].p_name << "\t";
		cout << "性别：" << (book->personArray[ret].p_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << book->personArray[ret].p_age << "\t";
		cout << "电话：" << book->personArray[ret].p_phone << "\t";
		cout << "地址：" << book->personArray[ret].p_address << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人信息
void modifyPerson(Book * book)
{
	cout << "请输入修改联系人的姓名" << endl;
	string name;
	cin >> name;

	int ret = isExit(book, name);

	if (ret == -1)
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string name;
		cout << "请输入姓名：";
		cin >> name;
		book->personArray[ret].p_name = name;

		int sex = 0;
		cout << "请输入性别(1----男 2-----女)：";

		while (true)      //如果输入1和2则正确
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				book->personArray[ret].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入性别：";
		}



		//年龄
		int age = 0;
		cout << "请输入年龄：";

		while (true)
		{
			cin >> age;
			if (age >= 1 && age <= 100)
			{
				book->personArray[ret].p_age = age;
				break;
			}
			cout << "输入有误，请重新输入年龄：";

		}

		//电话
		string phone;
		cout << "请输入电话：";


		while (true)
		{
			cin >> phone;
			if (phone.size() == 11)
			{
				book->personArray[ret].p_phone = phone;
				break;
			}
			cout << "输入有误，请重新输入电话：";

		}


		//地址
		string adrress;
		cout << "请输入地址：";
		cin >> adrress;
		book->personArray[ret].p_address = adrress;

		cout << "修改成功！" << endl;
		system("pause");
		system("cls");

	}

}

//清空联系人
void clearPerson(Book * book)
{
	cout << "确定清空吗？输入 Y or N" << endl;
	string selection;
	cin >> selection;

	if (selection == "Y")
	{
		book->p_num = 0;
		cout << "清空成功！" << endl;
	}
	else if (selection == "N")
	{
		cout << "取消成功" << endl;
	}
	else
	{
		cout << "输入非法，返回主界面" << endl;
	}
	system("pause");
	system("cls");
}