#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "worker.h"

//Ա��
class Boss :public Worker
{
public:
	Boss(int id, string name, int depI);

	virtual void showInfo();

	virtual string getDeptName();

};
