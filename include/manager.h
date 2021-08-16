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
	// 默认构造
	Manager();
	// 有参构造
	Manager(int id, string name, string pwd);
	// 菜单界面
	virtual void operMenu();
	// 添加账号
	void addPerson();
	// 查看账号
	void showPerson();
	// 查看机房信息
	void showComputer();
	// 清空预约记录
	void cleanFile();

	// 去重操作
	// 初始化容器
	void initVector();
	bool checkRepate(int id, int type);

	vector<Student> vStu;		// 学生信息
	vector<Teacher> vTea;		// 教师信息
	vector<ComputerRoom> vCom;	// 机房信息
};