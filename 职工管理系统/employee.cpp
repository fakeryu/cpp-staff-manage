#pragma once
#include "employee.h"

Employee::Employee(int id, string name, int depI) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depI;
}

void Employee::showInfo() {
	cout << "编号:" << this->m_Id
		<< "\t姓名:" << this->m_Name
		<< "\t部门:" << this->getDeptName()
		<< "\t职能：完成任务" << endl;
}

string Employee::getDeptName() {
	return string("员工");
}