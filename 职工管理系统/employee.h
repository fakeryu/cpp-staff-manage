#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "worker.h"

//Ա��
class Employee:public Worker
{
public:
	Employee(int id, string name, int depI);

	virtual void showInfo();

	virtual string getDeptName();

};
