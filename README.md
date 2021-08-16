## 机房预约系统（C++）

学校现有几个规格不同的机房，由于使用时经常出现"撞车"现象，现开发一套机房预约系统，解决这一问题。

## 1. 技术点

- switch-case语句

- vector
- map
- string
- 封装、继承、多态
- 文件操作

## 2. 需求分析

[xmind：机房预约系统需求分析](./xmind/机房预约系统需求分析.pdf)

每个身份都需要进行验证后，进入子菜单

* 学生需要输入 ：学号、姓名、登录密码
* 老师需要输入：职工号、姓名、登录密码
* 管理员需要输入：管理员编号、管理员姓名、登录密码

默认管理员信息：

- 编号：1
- 姓名：admin
- 密码：123

预约状态：

- 审核中
- 预约成功
- 预约失败
- 取消的预约

机房信息：

- 机房编号
- 最大容量

## 3. 代办

- [ ] 管理员清空操作：输入随机数进行二次确认
- [ ] Qt实现

## 4. 备注

- txt文件使用ANSI编码

