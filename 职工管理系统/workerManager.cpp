#include"workerManager.h"

WorkerManager::WorkerManager()
{
	////��ʼ������

	//�ļ������ڵĴ���ʽ
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//�ļ����ڵ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;

		ifs.close();
	}

	//�ļ�������������
	int num = this->get_EmpNum();
//	cout << "ְ������Ϊ��" << num << endl;//���Դ���
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
/*
	for (int i = 0; i < this->m_EmpNum; i++)//���Դ���
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< "ְ��������" << this->m_EmpArray[i]->m_Name
			<< "ְ����λ��" << this->m_EmpArray[i]->m_DeptId << endl;
	}
	*/
}

void WorkerManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "***********��ӭʹ��ְ������ϵͳ��***********" << endl;
	cout << "***************0.�˳��������***************" << endl;
	cout << "***************1.���ְ����Ϣ***************" << endl;
	cout << "***************2.��ʾְ��ְ��***************" << endl;
	cout << "***************3.ɾ����ְְ��***************" << endl;
	cout << "***************4.�޸�ְ����Ϣ***************" << endl;
	cout << "***************5.����ְ����Ϣ***************" << endl;
	cout << "***************6.���ձ������***************" << endl;
	cout << "***************7.��������ĵ�***************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::add_Emp()
{
	cout << "���������ְ����������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;

		Worker ** newSpace= new Worker* [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				cout << "������������" << endl;
				break;
			}

			//ְ��ָ��Ҫ���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		//�����ļ���Ϊ��
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		//����д���ļ�
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs <<this->m_EmpArray[i]->m_Id << "   "
			<< this->m_EmpArray[i]->m_Name << "   "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId==2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		else
		{
			cout << "�ļ���ĳְ���ĸ�λ��������" << endl;
			exit(0);
		}

		this->m_EmpArray[index++] = worker;
	}

	ifs.close();
}

void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();

			cout << "ɾ���ɹ���" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
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

void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//���ҵ�ְ��
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname = "";
			int newSelet = 0;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newid;

			cout << "��������������" << endl;
			cin >> newname;

			cout << "�������λ��" << endl;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newSelet;

			Worker* worker = NULL;
			switch (newSelet)
			{
			case 1:
				worker = new Employee(newid, newname, newSelet);
				break;
			case 2:
				worker = new Manager(newid, newname, newSelet);
				break;
			case 3:
				worker = new Boss(newid, newname, newSelet);
				break;
			default:
				break;
			}

			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;
			//���浽�ļ���
			this->save();

			delete worker;
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		cout << "������ҵķ�����" << endl;
		cout << "1������ְ���ı�Ų���" << endl;
		cout << "2������ְ������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id = 0;
			cout << "����ְ���ı�ţ�" << endl;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			string name = "";
			cout << "����Ҫ���ҵ�������" << endl;
			cin >> name;

			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->m_Id
						<< "��ְ����Ϣ����:" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "ѡ������ķ�ʽ��" << endl;
		cout << "1����ְ������������" << endl;
		cout << "2����ְ���Ž�������" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				//����
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				//����
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶���ֵ�Ƿ���ȷ�����򽻻�����
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ����" << endl;
		this->save();
		this->show_Emp();
	}

}

void WorkerManager::clean_Emp()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
