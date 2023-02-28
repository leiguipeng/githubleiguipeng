#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

void test01()
{
	Worker* worker = NULL;
	worker = new Employee(1, "11", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "22", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "33", 3);
	worker->showInfo();
	delete worker;

}
int main()
{
//	test01();
	//ʵ��������
	WorkerManager wm;
	int choice = 0;//�洢�û�ѡ��
	while (true)
	{
		wm.show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.del_Emp();
			break;
		case 4://�޸�ְ��
			wm.mod_Emp();
			break;
		case 5://����ְ��
			wm.find_Emp();
			break;
		case 6://����ְ��
			wm.sort_Emp();
			break;
		case 7://����ĵ�
			wm.clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}