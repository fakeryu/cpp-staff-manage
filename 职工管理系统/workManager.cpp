#include "workManager.h"

WorkerManager::WorkerManager() {

	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在 数据为空
	char ch; 
	ifs >> ch; //读取第一个字符
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.存在有数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [num];
	//将文件数据存入数据
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "编号：" << this->m_EmpArray[i]->m_Id << "姓名："
			<< this->m_EmpArray[i]->m_Name << "部门编号："
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ifs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件 读

	int num = 0;
	int id;
	string name;
	int dId;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;

	ifs.close();
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出方式打开文件 -- 写文件
	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

void WorkerManager::Show_Menu() {
	cout << "*****************************" << endl;
	cout << "*** 欢迎使用职工管理系统！***" << endl;
	cout << "*********** 0.退出 **********" << endl;
	cout << "*********** 1.新增 **********" << endl;
	cout << "*********** 2.显示 **********" << endl;
	cout << "*********** 3.删除 **********" << endl;
	cout << "*********** 4.修改 **********" << endl;
	cout << "*********** 5.查找 **********" << endl;
	cout << "******** 6.按编号排序 *******" << endl;
	cout << "********* 7.清空文档 ********" << endl;
	cout << "*****************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum; // 新空间人数 = 原来记录人数 + 新增人数;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];// Worker* 数组元素类型
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id; //职工编号
			string name; //职工部门
			int dSelect; //部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择第" << i + 1 << "个新职工岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空
		this->m_FileIsEmpty = false;

		//for (int i = 0; i < this->m_EmpNum; i++)
		//{
		//	cout << "编号：" << this->m_EmpArray[i]->m_Id << "姓名："
		//		<< this->m_EmpArray[i]->m_Name << "部门编号："
		//		<< this->m_EmpArray[i]->m_DeptId << endl;
		//}
		//保存数据文件
		this->save();

		//提示
		cout << "成功添加" << addNum << "名职工" << endl;

	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Show_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//利用多态调用程序接口
		this->m_EmpArray[i]->showInfo();
	}
}

void WorkerManager::Del_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	cout << "请输入删除职工编号：" << endl;
	int id = 0;
	cin >> id;

	int index = this->IsExist(id);
	if (index != -1)//
	{
		//数据迁移
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--; //更新数组中记录人员个数

		this->save();

		cout << "删除成功" << endl;

	}
	else {
		cout << "未找到该职工！" << endl;
	}

	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	cout << "请输入修改职工编号：" << endl;
	int id = 0;
	cin >> id;

	int index = this->IsExist(id);
	if (index != -1)//
	{
		
		int newId; //职工编号
		string newName; //职工部门
		int dSelect; //部门选择

		cout << "请输入职工编号：" << endl;
		cin >> newId;

		cout << "请输入职工姓名：" << endl;
		cin >> newName;

		cout << "请选择职工岗位：" << endl;
		cout << "1.普通员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> dSelect;

		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new Employee(newId, newName, 1);
			break;
		case 2:
			worker = new Manager(newId, newName, 2);
			break;
		case 3:
			worker = new Boss(newId, newName, 3);
			break;
		default:
			break;
		}

		//将创建职工职责，保存到数组中
		this->m_EmpArray[index] = worker;

		this->save();

		cout << "删除成功" << endl;

	}
	else {
		cout << "未找到该职工！" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	cout << "请输入查找方式：" << endl;
	cout << "1.按职工编号查找" << endl;
	cout << "2.按姓名查找" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "请输入查找人编号" << endl;

		int wId = 0;
		cin >> wId;
		int index = this->IsExist(wId);
		if (index!=-1)
		{
			this->m_EmpArray[index]->showInfo();
		}
		else {
			cout << "未找到该职工！" << endl;
		}
	}
	else if (select == 2) 
	{
		cout << "请输入查找人姓名" << endl;

		string wName = "";
		cin >> wName;

		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == wName)
			{
				flag = true;
				cout << "查找成功，编号为："<< this->m_EmpArray[i]->m_Id<<"信息如下:" << endl;
				this->m_EmpArray[i]->showInfo();
			}
		}
		if (!flag)
		{
			cout << "未找到该职工！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入查找方式：" << endl;
	cout << "1.职工编号升序排列" << endl;
	cout << "2.职工编号降序排列" << endl;

	int select = 0;
	cin >> select;

	//选择排序
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		int minOrMax = i;
		for (int j = i+1; j < this->m_EmpNum; j++)
		{
			if (select==1)
			{
				if (this->m_EmpArray[minOrMax] > this->m_EmpArray[j])
				{
					minOrMax = j;
				}
			}
			else {
				//降序
				if (this->m_EmpArray[minOrMax] < this->m_EmpArray[j])
				{
					minOrMax = j;
				}
			}
		}

		if (i != minOrMax)
		{
			Worker* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax] = this->m_EmpArray[i];
		}
	}
	cout << "排序成功" << endl;
	this->save();
	this->Show_Emp();
}

void WorkerManager::Clear_File() {
	cout << "确认清空：" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select;
	cin>>select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清除成功" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	//释放堆区
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		//删除堆区数组指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}