#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Manager : public Worker
{
public:

	Manager(int id, string name, int did); //构造函数

	virtual void showInfo();//virtual可删可不删
	virtual string getDepartName();
};