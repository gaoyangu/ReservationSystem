#pragma once
#include <iostream>
#include <vector>
#include "Identity.h"
#include "orderFile.h"
using namespace std;

// 教师类
class Teacher : public Identity {
public:
	// 默认构造
	Teacher();
	// 有参构造
	Teacher(int id, string name, string pwd);
	// 菜单界面
	virtual void operMenu();
	// 查看所有预约
	void showAllOrder();
	// 审核预约
	void vaildOrder();
};