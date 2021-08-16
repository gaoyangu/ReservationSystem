#include "orderFile.h"

// 构造函数
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId &&
			ifs >> stuName && ifs >> roomId && ifs >> status){
		map<string, string> m;
		m.insert(subString(date));
		m.insert(subString(interval));
		m.insert(subString(stuId));
		m.insert(subString(stuName));
		m.insert(subString(roomId));
		m.insert(subString(status));

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
		cout << "key = " << it->first << " value = " << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
			cout << mit->first << " " << mit->second << " ";
		}
		cout << endl;
	}*/
}
// 字符串截取
pair<string, string> OrderFile::subString(string& s) {
	int pos = s.find(":");
	string key;
	string value;
	if (pos != -1) {
		key = s.substr(0, pos);
		value = s.substr(pos + 1, s.size() - pos - 1);
		return make_pair(key, value);
	}
}
//更新预约记录
void OrderFile::updateOrder() {
	if (this->m_Size == 0) {
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}