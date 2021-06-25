#include "workManager.h"

WorkerManager::WorkerManager() {

	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����� ����Ϊ��
	char ch; 
	ifs >> ch; //��ȡ��һ���ַ�
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.����������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [num];
	//���ļ����ݴ�������
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "��ţ�" << this->m_EmpArray[i]->m_Id << "������"
			<< this->m_EmpArray[i]->m_Name << "���ű�ţ�"
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ifs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ� ��

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
	ofs.open(FILENAME, ios::out); //�������ʽ���ļ� -- д�ļ�
	//��ÿ��������д�뵽�ļ���
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
	cout << "*** ��ӭʹ��ְ������ϵͳ��***" << endl;
	cout << "*********** 0.�˳� **********" << endl;
	cout << "*********** 1.���� **********" << endl;
	cout << "*********** 2.��ʾ **********" << endl;
	cout << "*********** 3.ɾ�� **********" << endl;
	cout << "*********** 4.�޸� **********" << endl;
	cout << "*********** 5.���� **********" << endl;
	cout << "******** 6.��������� *******" << endl;
	cout << "********* 7.����ĵ� ********" << endl;
	cout << "*****************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum; // �¿ռ����� = ԭ����¼���� + ��������;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];// Worker* ����Ԫ������
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id; //ְ�����
			string name; //ְ������
			int dSelect; //����ѡ��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���" << i + 1 << "����ְ����λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//for (int i = 0; i < this->m_EmpNum; i++)
		//{
		//	cout << "��ţ�" << this->m_EmpArray[i]->m_Id << "������"
		//		<< this->m_EmpArray[i]->m_Name << "���ű�ţ�"
		//		<< this->m_EmpArray[i]->m_DeptId << endl;
		//}
		//���������ļ�
		this->save();

		//��ʾ
		cout << "�ɹ����" << addNum << "��ְ��" << endl;

	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//���ö�̬���ó���ӿ�
		this->m_EmpArray[i]->showInfo();
	}
}

void WorkerManager::Del_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}
	cout << "������ɾ��ְ����ţ�" << endl;
	int id = 0;
	cin >> id;

	int index = this->IsExist(id);
	if (index != -1)//
	{
		//����Ǩ��
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--; //���������м�¼��Ա����

		this->save();

		cout << "ɾ���ɹ�" << endl;

	}
	else {
		cout << "δ�ҵ���ְ����" << endl;
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}
	cout << "�������޸�ְ����ţ�" << endl;
	int id = 0;
	cin >> id;

	int index = this->IsExist(id);
	if (index != -1)//
	{
		
		int newId; //ְ�����
		string newName; //ְ������
		int dSelect; //����ѡ��

		cout << "������ְ����ţ�" << endl;
		cin >> newId;

		cout << "������ְ��������" << endl;
		cin >> newName;

		cout << "��ѡ��ְ����λ��" << endl;
		cout << "1.��ͨԱ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
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

		//������ְ��ְ�𣬱��浽������
		this->m_EmpArray[index] = worker;

		this->save();

		cout << "ɾ���ɹ�" << endl;

	}
	else {
		cout << "δ�ҵ���ְ����" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1.��ְ����Ų���" << endl;
	cout << "2.����������" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����������˱��" << endl;

		int wId = 0;
		cin >> wId;
		int index = this->IsExist(wId);
		if (index!=-1)
		{
			this->m_EmpArray[index]->showInfo();
		}
		else {
			cout << "δ�ҵ���ְ����" << endl;
		}
	}
	else if (select == 2) 
	{
		cout << "���������������" << endl;

		string wName = "";
		cin >> wName;

		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_Name == wName)
			{
				flag = true;
				cout << "���ҳɹ������Ϊ��"<< this->m_EmpArray[i]->m_Id<<"��Ϣ����:" << endl;
				this->m_EmpArray[i]->showInfo();
			}
		}
		if (!flag)
		{
			cout << "δ�ҵ���ְ����" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1.ְ�������������" << endl;
	cout << "2.ְ����Ž�������" << endl;

	int select = 0;
	cin >> select;

	//ѡ������
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
				//����
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
	cout << "����ɹ�" << endl;
	this->save();
	this->Show_Emp();
}

void WorkerManager::Clear_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select;
	cin>>select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //ɾ���ļ������´���
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
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "����ɹ�" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	//�ͷŶ���
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		//ɾ����������ָ��
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}