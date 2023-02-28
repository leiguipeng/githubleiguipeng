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
	//实例化对象
	WorkerManager wm;
	int choice = 0;//存储用户选择
	while (true)
	{
		wm.show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.mod_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://排序职工
			wm.sort_Emp();
			break;
		case 7://清空文档
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