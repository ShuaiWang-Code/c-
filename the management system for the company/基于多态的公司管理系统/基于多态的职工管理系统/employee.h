#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee : public Worker
{
public:

	Employee(int id, string name, int did); //���캯��

	virtual void showInfo();//virtual��ɾ�ɲ�ɾ
	virtual string getDepartName();

};