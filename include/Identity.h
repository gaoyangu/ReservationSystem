#pragma once
#include <iostream>
using namespace std;

// ��ݳ������
class Identity {
public:
	// �����˵� ���麯��
	virtual void operMenu() = 0;

	int m_Id;		// �˺�
	string m_Name;	// �û���
	string m_Pwd;	// ����
};
