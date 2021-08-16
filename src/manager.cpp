#include "manager.h"

// Ĭ�Ϲ���
Manager::Manager() {

}
// �вι���
Manager::Manager(int id, string name, string pwd){
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "[ERROR] �����ļ���ʧ�ܣ�" << endl;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum){
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs.close();
}
// �˵�����
void Manager::operMenu() {
	int select = 0;	// �洢�û���ѡ��
	while (true) {
		cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          1.����˺�            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          2.�鿴�˺�            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          3.�鿴����            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          4.���ԤԼ            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          0.ע����¼            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "��ѡ�����Ĳ����� " << endl;

		cin >> select;
		switch (select) {
		case 1: // ����˺�
			this->addPerson();
			break;
		case 2: // �鿴�˺�
			this->showPerson();
			break;
		case 3: // �鿴������Ϣ
			this->showComputer();
			break;
		case 4: // ���ԤԼ��¼
			this->cleanFile();
			break;
		default:
			//delete person;
			cout << "[INFO] ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
// ����˺�
void Manager::addPerson() {
	cout << "��������ӵ��˺����ͣ�" << endl;
	cout << "1. ���ѧ��" << endl;
	cout << "2. ��ӽ�ʦ" << endl;

	string fileName;
	string tip;
	string errTip;
	ofstream ofs;
	int select = 0;

	while (true) {
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			errTip = "ѧ���ظ������������룺";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "������ְ����ţ�";
			errTip = "ְ�����ظ������������룺";
			break;
		}
		else {
			cout << "[ERROR] �����������������롣" << endl;
		}
	}

	ofs.open(fileName, ios::out | ios::app);
	int id = 0;
	string name;
	string pwd;

	cout << tip << endl;

	while (true){
		cin >> id;
		bool ret = checkRepate(id, select);
		if (ret) {
			cout << errTip << endl;
		}
		else{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "[INFO] ��ӳɹ���" << endl;
	ofs.close();

	this->initVector();

	system("pause");
	system("cls");
}
// �鿴�˺�
void printStudent(const Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printTeacher(const Teacher& t) {
	cout << "ְ����ţ�" << t.m_Id << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
void Manager::showPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1. �鿴����ѧ����Ϣ" << endl;
	cout << "2. �鿴���н�ʦ��Ϣ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "����ѧ������Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		cout << "���н�ʦ����Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
// �鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "������ţ�" << it->m_ComId << " �������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
// ���ԤԼ��¼
void Manager::cleanFile() {
	//todo: ���������ȷ�����
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "���ԤԼ�ɹ���" << endl;
	system("pause");
	system("cls");
}
// ȥ�ز���
// ��ʼ������
void  Manager::initVector() {
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "[ERROR] ѧ���ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
		vStu.push_back(s);
	}
	cout << "��ǰ��ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "[ERROR] ��ʦ�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ�Ľ�ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}
bool Manager::checkRepate(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else if (type == 2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	return false;
}