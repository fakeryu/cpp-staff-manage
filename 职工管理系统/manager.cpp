#pragma once
#include "manager.h"

Manager::Manager(int id, string name, int depI) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depI;
}

void Manager::showInfo() {
	cout << "���:" << this->m_Id
		<< "\t����:" << this->m_Name
		<< "\t����:" << this->getDeptName()
		<< "\tְ�ܣ���������" << endl;
}

string Manager::getDeptName() {
	return string("����");
}