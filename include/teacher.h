#pragma once
#include <iostream>
#include <vector>
#include "Identity.h"
#include "orderFile.h"
using namespace std;

// ��ʦ��
class Teacher : public Identity {
public:
	// Ĭ�Ϲ���
	Teacher();
	// �вι���
	Teacher(int id, string name, string pwd);
	// �˵�����
	virtual void operMenu();
	// �鿴����ԤԼ
	void showAllOrder();
	// ���ԤԼ
	void vaildOrder();
};