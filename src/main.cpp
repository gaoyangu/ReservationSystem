#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

// ��¼����
/*
* fileName:	�����ļ���
* type:		�����������
*/
void loginIn(string fileName, int type) {
	// ����ָ�룬����ָ���������
	Identity* person = NULL;

	// ���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	// �ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "[ERROR] �ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// ׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	// �ж����
	if (type == 1) {
		cout << "[INFO] ���������ѧ�ţ�" << endl;
	}
	else if (type == 2) {
		cout << "[INFO] ����������ְ���ţ�" << endl;
	}
	else if (type == 3) {
		cout << "[INFO] ���������Ĺ���Ա�ţ�" << endl;	
	}
	cin >> id;
	cout << "[INFO] �������û�����" << endl;
	cin >> name;
	cout << "[INFO] ���������룺" << endl;
	cin >> pwd;

	//���ļ��ж���������
	int fId = 0;
	string fName;
	string fPwd;
	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		if (fId == id && fName == name && fPwd == pwd) {
			if (type == 1) {
				cout << "[INFO] ѧ����֤��¼�ɹ���" << endl;
				person = new Student(id, name, pwd);
			}
			else if (type == 2) {
				cout << "[INFO] ��ʦ��֤��¼�ɹ���" << endl;
				person = new Teacher(id, name, pwd);
			}
			else if (type == 3) {
				cout << "[INFO] ����Ա��֤��¼�ɹ���" << endl;
				person = new Manager(id, name, pwd);
			}
			system("pause");
			system("cls");
			// �����Ӳ˵�����
			person->operMenu();
			delete person;
			return;
		}
	}
	cout << "[ERROR] ��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;	// �洢�û���ѡ��
	while (true){
		cout << "======================  ��ӭ�������ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		
		cin >> select;
		switch (select){
		case 1:	// ѧ������
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:	// ��ʦ
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:	// ����Ա
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:	// �˳�
			cout << "[INFO] ��ӭ�´�ʹ�á�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "[ERROR] ��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}