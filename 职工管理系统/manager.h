#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "worker.h"

//Ա��
class Manager :public Worker
{
public:
	Manager(int id, string name, int depI);

	virtual void showInfo();

	virtual string getDeptName();

};
