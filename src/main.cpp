#include <iostream>
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

// 登录功能
/*
* fileName:	操作文件名
* type:		操作身份类型
*/
void loginIn(string fileName, int type) {
	// 父类指针，用于指向子类对象
	Identity* person = NULL;

	// 读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	// 判断文件是否存在
	if (!ifs.is_open()) {
		cout << "[ERROR] 文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 准备接收用户信息
	int id = 0;
	string name;
	string pwd;

	// 判断身份
	if (type == 1) {
		cout << "[INFO] 请输入你的学号：" << endl;
	}
	else if (type == 2) {
		cout << "[INFO] 请输入您的职工号：" << endl;
	}
	else if (type == 3) {
		cout << "[INFO] 请输入您的管理员号：" << endl;	
	}
	cin >> id;
	cout << "[INFO] 请输入用户名：" << endl;
	cin >> name;
	cout << "[INFO] 请输入密码：" << endl;
	cin >> pwd;

	//从文件中读出的数据
	int fId = 0;
	string fName;
	string fPwd;
	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		if (fId == id && fName == name && fPwd == pwd) {
			if (type == 1) {
				cout << "[INFO] 学生验证登录成功！" << endl;
				person = new Student(id, name, pwd);
			}
			else if (type == 2) {
				cout << "[INFO] 教师验证登录成功！" << endl;
				person = new Teacher(id, name, pwd);
			}
			else if (type == 3) {
				cout << "[INFO] 管理员验证登录成功！" << endl;
				person = new Manager(id, name, pwd);
			}
			system("pause");
			system("cls");
			// 进入子菜单界面
			person->operMenu();
			delete person;
			return;
		}
	}
	cout << "[ERROR] 验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;	// 存储用户的选择
	while (true){
		cout << "======================  欢迎来到播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		
		cin >> select;
		switch (select){
		case 1:	// 学生代表
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:	// 老师
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:	// 管理员
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:	// 退出
			cout << "[INFO] 欢迎下次使用。" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "[ERROR] 输入有误！请重新选择。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}