#pragma once
#include "boss.h"

Boss::Boss(int id, string name, int depI) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depI;
}

void Boss::showInfo() {
	cout << "编号:" << this->m_Id
		<< "\t姓名:" << this->m_Name
		<< "\t部门:" << this->getDeptName()
		<< "\t职能：全管" << endl;
}

string Boss::getDeptName() {
	return string("老板");
}