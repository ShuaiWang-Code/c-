#pragma once         //��ֹͷ�ļ��ظ�����

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>


using namespace std;  //ʹ�ñ�׼�����ռ�

#define FILENAME "empfile.txt"
class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	
	void ShowMenu();
	
	//�˳�0
	void ExitSystem();

	//���Ա��
	void Add_Emp();
	
	void save();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	int get_EmpNum();

	//��ʼ��
	void init_Emp();

	//��ʾְԱ
	void show_Emp();

	//ɾ��ְ��   ��Ҫ�ж�ְ���Ƿ���ڣ����ڷ����������������������ڷ���-1
	void del_Emp();
	int IsExit(int id);

	//�޸�ְ��
	void mod_Emp();

	//����
	void findEmp();

	//����
	void sort_Emp();

	//����ļ�
	void clean_Emp();

	//��������
	~WorkerManager();

};

