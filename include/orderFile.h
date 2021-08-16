#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "globalFile.h"

using namespace std;

class OrderFile {
public:
	// 构造函数
	OrderFile();

	// 字符串截取
	pair<string, string> subString(string& s);

	//更新预约记录
	void updateOrder();

	int m_Size;
	map<int, map<string, string>> m_orderData;
};