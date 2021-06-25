#pragma once
#include "manager.h"

Manager::Manager(int id, string name, int depI) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depI;
}

void Manager::showInfo() {
	cout << "编号:" << this->m_Id
		<< "\t姓名:" << this->m_Name
		<< "\t部门:" << this->getDeptName()
		<< "\t职能：发放任务" << endl;
}

string Manager::getDeptName() {
	return string("经理");
}