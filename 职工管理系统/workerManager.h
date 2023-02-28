#pragma once
//防止头文件重复包含输入输出流的头文件
#include<iostream>
#include<string>
using namespace std;
//使用标准的命名空间
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>

#define FILENAME "empFile.txt"

class WorkerManager
{
public:

	WorkerManager();
	~WorkerManager();
	//展示菜单
	void show_Menu();
	//退出功能
	void exitSystem();
	//添加职工
	void add_Emp();
	//保存文件
	void save();
	//统计文件中的人数
	int get_EmpNum();
	//初始化职工
	void init_Emp();
	//展示职工信息
	void show_Emp();
	//删除职工
	void del_Emp();
	//根据职工编号判断职工是否存在
	int isExist(int id);
	//修改职工的功能
	void mod_Emp();
	//查找职工
	void find_Emp();
	//排序方法
	void sort_Emp();
	//清空数据
	void clean_Emp();
public:
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//判断文件是否为空的标志
	bool m_FileIsEmpty;

};