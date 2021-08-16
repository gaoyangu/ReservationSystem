#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;

class Manager : public Identity{
public:
	// Ĭ�Ϲ���
	Manager();
	// �вι���
	Manager(int id, string name, string pwd);
	// �˵�����
	virtual void operMenu();
	// ����˺�
	void addPerson();
	// �鿴�˺�
	void showPerson();
	// �鿴������Ϣ
	void showComputer();
	// ���ԤԼ��¼
	void cleanFile();

	// ȥ�ز���
	// ��ʼ������
	void initVector();
	bool checkRepate(int id, int type);

	vector<Student> vStu;		// ѧ����Ϣ
	vector<Teacher> vTea;		// ��ʦ��Ϣ
	vector<ComputerRoom> vCom;	// ������Ϣ
};