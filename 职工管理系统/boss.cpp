#pragma once
#include "boss.h"

Boss::Boss(int id, string name, int depI) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depI;
}

void Boss::showInfo() {
	cout << "���:" << this->m_Id
		<< "\t����:" << this->m_Name
		<< "\t����:" << this->getDeptName()
		<< "\tְ�ܣ�ȫ��" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}