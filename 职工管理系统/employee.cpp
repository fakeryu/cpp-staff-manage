#pragma once
#include "employee.h"

Employee::Employee(int id, string name, int depI) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depI;
}

void Employee::showInfo() {
	cout << "���:" << this->m_Id
		<< "\t����:" << this->m_Name
		<< "\t����:" << this->getDeptName()
		<< "\tְ�ܣ��������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}