#pragma once  //防止头文件重复包含
#include<iostream>  //包含输入输出流头文件
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;  //使用标准命名空间

class WorkerManager {
public:
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出功能
	void ExitSystem();

	//添加功能
	void Add_Emp();

	//保存文件
	void save();

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//按照职工编号判断职工是否存在，若存在返回公职在数据中位置，不存在返回-1
	int IsExist(int id);

	//编辑职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序
	void Sort_Emp();

	//清空文件
	void Clear_File();

	~WorkerManager();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;

};