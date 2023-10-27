
/*************************************************************************
【文件名】Controller.cpp
【功能模块和目的】  与用户进行交互，有登录、注册以及特殊人员登录功能实现的作用
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Controller.hpp"
#include "Subject.hpp"
#include "Administrator.hpp"
#include "Keyboarder.hpp"
#include "Recorder.hpp"
#include "Tube.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*************************************************************************
【函数名称】Controller
【函数功能】初始化控制台
【参数】View& view
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Controller::Controller(View& view) :m_view(view) {}

/*************************************************************************
【函数名称】Load
【函数功能】用来从文件中读取已有信息
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Controller::Load () const
{
	Subject::ReadDocument("Enroll.txt");//读取所有被试者信息
	Administrator::ReadAdministrator("Enroll.txt");//读取管理员信息
}

/*************************************************************************
【函数名称】NewSubjectRegister
【函数功能】处理新用户注册之后的交互工作
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Controller::NewSubjectRegister() const
{
	string name;
	string password;
	string ID;

	while (true)
	{
		m_view.View2_1_1();
		cin >> name;
		if (name.size() < 4 || name.size() > 8)
		{
			m_view.View2_1_2();
			continue;//名字字数不对，报错
		}
		break;
	}

	while (true)
	{
		m_view.View2_2_1();
		cin >> ID;
		if (ID.size() != 18)
		{
			m_view.View2_2_2();
			continue;//身份证号位数不对，报错
		}
		break;
	}

	while (true)
	{
		m_view.View2_3_1();
		cin >> password;
		if (password.size() != 6)
		{
			m_view.View2_3_2();
			continue;//密码位数不对，报错
		}
		break;
	}

	Subject::Register(name, password, ID, "Enroll.txt");//调用注册函数创建新成员
}

/*************************************************************************
【函数名称】Login
【函数功能】用来实现已有用户登录之后的种种功能
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Controller::Login() const
{
	string ID;
	string password;

	while (true)
	{
		m_view.View3_1();
		while (true)
		{
			cin >> ID;
			if (ID.size() != 18)
			{
				m_view.View2_2_2();
				continue;//身份证号位数不对，报错
			}
			break;
		}

		m_view.View3_2();
		while (true)
		{
			cin >> password;
			if (password.size() != 6)
			{
				m_view.View2_3_2();
				continue;//密码位数不对，报错
			}
			break;
		}

		if ( !Subject::VerifySubject(ID, password) )
		{
			m_view.View3_3();
			continue;//身份证号与密码核验失败，报错
		}
		break;
	}

	if ( (Administrator::AdministratorFinder(ID) == nullptr) && (Recorder::RecorderFinder(ID) == nullptr) && (Keyboarder::KeyboarderFinder(ID) == nullptr))
	{
		m_view.View4_1();
		Subject::CheckResult(ID);
		m_view.ViewEndl();
	}
	//普通成员，直接显示上一次核酸检测结果

	else
	{
		m_view.View4_2_1();

		if (Administrator::AdministratorFinder(ID) != nullptr)
		{
			m_view.View4_2_2();
		}

		if (Recorder::RecorderFinder(ID) != nullptr)
		{
			m_view.View4_2_3();
		}

		if (Keyboarder::KeyboarderFinder(ID) != nullptr)
		{
			m_view.View4_2_4();
		}
		m_view.View4_2_5();

		unsigned int choice(0);//用来选择身份
		cin >> choice;
		switch(choice)
		{
		case 0 :
		{
			if (Administrator::AdministratorFinder(ID) == nullptr) break;
			AdministratorLogIn( Administrator::AdministratorFinder(ID) );//进入管理员功能区
			break;
		}

		case 1 :
		{
			if (Recorder::RecorderFinder(ID) == nullptr) break;
			RecorderLogIn( Recorder::RecorderFinder(ID) );//进入现场记录员功能区
			break;
		}

		case 2 :
		{
			if (Keyboarder::KeyboarderFinder(ID) == nullptr) break;
			KeyboarderLogIn( Keyboarder::KeyboarderFinder(ID) );//进入结果录入员功能区
			break;
		}

		default :
		{
			m_view.View4_1();
			Subject::CheckResult(ID);
			m_view.ViewEndl();
			break;
		}

		}
	}
}

/*************************************************************************
【函数名称】AdministratorLogIn
【函数功能】用于实现管理员登录后的交互功能
【参数】shared_ptr<Administrator> pAdmin
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Controller::AdministratorLogIn(shared_ptr <Administrator> pAdmin) const
{
	int choice;
	m_view.View5_1();
	cin >> choice;

	switch (choice)
	{
		case 1 :
		{
			string RecorderID;
			m_view.View5_2();
			cin >> RecorderID;
			pAdmin->AppointRecorder(RecorderID);
			break;
		}//指定现场记录员

		case 2 :
		{
			string KeyboarderID;
			m_view.View5_3();
			cin >> KeyboarderID;
			pAdmin->AppointKeyboarder(KeyboarderID);
			break;
		}//指定结果录入员

		default :
		{
			break;
		}
	}

}

/*************************************************************************
【函数名称】RecorderLogIn
【函数功能】用于实现现场记录员登录后的交互功能
【参数】shared_ptr<Recorder> pAdmin
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Controller::RecorderLogIn(shared_ptr <Recorder> pRecorder) const
{
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	unsigned int Hour;
	unsigned int Minute;
	unsigned int Second;
	unsigned int SerialNumber;
	unsigned int Count;
	string Result = "未检";

	m_view.View6_1();
	cin >> Count;

	m_view.View6_2();
	cin >> Year
		>> Month
		>> Day
		>> Hour
		>> Minute
		>> Second;

	m_view.View6_3();
	cin >> SerialNumber;
	//完成输入试管编号信息的录入

	shared_ptr <Tube> pNewTube = make_shared<Tube>(Year, Month, Day, Hour, Minute, Second, SerialNumber, Count);
	//调用构造函数，新建一个试管

	for (unsigned int i = 0; i < Count; i++)
	{
		string NewID;
		m_view.View6_4(i);
		cin >> NewID;
		if (NewID.length() != 18)
		{
			m_view.View6_5();
			i--;
			continue;//身份证号位数不对，报错
		}
		pNewTube->InputID(NewID, i);//将身份信息录入试管
	}

	pNewTube->InputSharedptr(pNewTube);
}

/*************************************************************************
【函数名称】KeyboarderLogIn
【函数功能】用于实现结果录入员登录后的交互功能
【参数】shared_ptr<Keyboarder> pAdmin
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Controller::KeyboarderLogIn(shared_ptr <Keyboarder> pKeyboarder) const
{
	string SerialNumber;
	string Result;

	m_view.View7_1();
	cin >> SerialNumber;
	m_view.View7_2();
	cin >> Result;

	shared_ptr<Tube>LockTube = Tube::SaveToDocument(SerialNumber, Result, "Enroll.txt");
	//锁定试管

	unsigned int i(1);
	while (true)
	{
		string* IncludeID = LockTube->TransmitID(i);
		if (IncludeID == nullptr)
		{
			break;
		}
		i++;
		Subject::Search(*IncludeID)->EnterResult(Result);
		delete IncludeID;
	}//从试管调用信息，在程序的数据结构中更新核酸检测结果
}