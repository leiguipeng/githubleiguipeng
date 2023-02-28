#pragma once
//��ֹͷ�ļ��ظ����������������ͷ�ļ�
#include<iostream>
#include<string>
using namespace std;
//ʹ�ñ�׼�������ռ�
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
	//չʾ�˵�
	void show_Menu();
	//�˳�����
	void exitSystem();
	//���ְ��
	void add_Emp();
	//�����ļ�
	void save();
	//ͳ���ļ��е�����
	int get_EmpNum();
	//��ʼ��ְ��
	void init_Emp();
	//չʾְ����Ϣ
	void show_Emp();
	//ɾ��ְ��
	void del_Emp();
	//����ְ������ж�ְ���Ƿ����
	int isExist(int id);
	//�޸�ְ���Ĺ���
	void mod_Emp();
	//����ְ��
	void find_Emp();
	//���򷽷�
	void sort_Emp();
	//�������
	void clean_Emp();
public:
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

};