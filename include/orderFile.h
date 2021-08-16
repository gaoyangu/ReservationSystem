#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"

using namespace std;

class OrderFile {
public:
	// ���캯��
	OrderFile();

	// �ַ�����ȡ
	pair<string, string> subString(string& s);

	//����ԤԼ��¼
	void updateOrder();

	int m_Size;
	map<int, map<string, string>> m_orderData;
};