#include "manager.h"

// 默认构造
Manager::Manager() {

}
// 有参构造
Manager::Manager(int id, string name, string pwd){
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "[ERROR] 机房文件打开失败！" << endl;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum){
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs.close();
}
// 菜单界面
void Manager::operMenu() {
	int select = 0;	// 存储用户的选择
	while (true) {
		cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
		cout << "\t\t ---------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          1.添加账号            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          2.查看账号            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          3.查看机房            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          4.清空预约            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          0.注销登录            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t ---------------------------------\n";
		cout << "请选择您的操作： " << endl;

		cin >> select;
		switch (select) {
		case 1: // 添加账号
			this->addPerson();
			break;
		case 2: // 查看账号
			this->showPerson();
			break;
		case 3: // 查看机房信息
			this->showComputer();
			break;
		case 4: // 清空预约记录
			this->cleanFile();
			break;
		default:
			//delete person;
			cout << "[INFO] 注销成功。" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
// 添加账号
void Manager::addPerson() {
	cout << "请输入添加的账号类型：" << endl;
	cout << "1. 添加学生" << endl;
	cout << "2. 添加教师" << endl;

	string fileName;
	string tip;
	string errTip;
	ofstream ofs;
	int select = 0;

	while (true) {
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			errTip = "学号重复，请重新输入：";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "请输入职工编号：";
			errTip = "职工号重复，请重新输入：";
			break;
		}
		else {
			cout << "[ERROR] 输入有误！请重新输入。" << endl;
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
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "[INFO] 添加成功。" << endl;
	ofs.close();

	this->initVector();

	system("pause");
	system("cls");
}
// 查看账号
void printStudent(const Student& s) {
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(const Teacher& t) {
	cout << "职工编号：" << t.m_Id << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
void Manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1. 查看所有学生信息" << endl;
	cout << "2. 查看所有教师信息" << endl;

	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "所有学生的信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if (select == 2) {
		cout << "所有教师的信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
// 查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
// 清空预约记录
void Manager::cleanFile() {
	//todo: 输入随机数确认清空
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空预约成功！" << endl;
	system("pause");
	system("cls");
}
// 去重操作
// 初始化容器
void  Manager::initVector() {
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "[ERROR] 学生文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
		vStu.push_back(s);
	}
	cout << "当前的学生数量为：" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "[ERROR] 教师文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "当前的教师数量为：" << vTea.size() << endl;
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