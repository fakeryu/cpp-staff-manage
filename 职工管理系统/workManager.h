#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>  //�������������ͷ�ļ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;  //ʹ�ñ�׼�����ռ�

class WorkerManager {
public:
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void ExitSystem();

	//��ӹ���
	void Add_Emp();

	//�����ļ�
	void save();

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����ְ������ж�ְ���Ƿ���ڣ������ڷ��ع�ְ��������λ�ã������ڷ���-1
	int IsExist(int id);

	//�༭ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����
	void Sort_Emp();

	//����ļ�
	void Clear_File();

	~WorkerManager();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};