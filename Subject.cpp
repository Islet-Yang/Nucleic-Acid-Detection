
/*************************************************************************
【文件名】Subject.cpp
【功能模块和目的】  储存所有受试者信息，读取并存储文件，提供接口
用来访问受试者信息，同时派生管理员、现场记录员和结果录入员
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Subject.hpp"
#include "Administrator.hpp"
#include <stdlib.h>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <stdexcept>

/*************************************************************************
【函数名称】ExceptionSubjectExist
【函数功能】报错发送：被试者已存在
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ExceptionSubjectExist::ExceptionSubjectExist()
	:invalid_argument("Subject exists."){}

/*************************************************************************
【函数名称】ExceptionAdminCannotDelete
【函数功能】报错显示：管理员不能被删除
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ExceptionAdminCannotDelete::ExceptionAdminCannotDelete()
	:invalid_argument("You are tryint to log off an administrator."){}

/*************************************************************************
【函数名称】ExceptionSubjectInexistence
【函数功能】报错显示：被试者信息不存在
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ExceptionSubjectInexistence::ExceptionSubjectInexistence()
	: invalid_argument("Subject isn't exist.") {}

/*************************************************************************
【函数名称】~Subject
【函数功能】Subject类析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Subject::~Subject(){}

/*************************************************************************
【函数名称】IsRecorder
【函数功能】标注身份不是现场记录员
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::IsRecorder() const
{
	return false;
}

/*************************************************************************
【函数名称】IsKeyboarder
【函数功能】标注身份不是结果录入员
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::IsKeyboarder() const
{
	return false;
}

/*************************************************************************
【函数名称】IsAdministrator
【函数功能】标注身份不是管理员
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::IsAdministrator() const
{
	return false;
}

/*************************************************************************
【函数名称】EnterResult
【函数功能】用户检测结果录入
【参数】const string& Result
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::EnterResult(const string& Result)
{
	m_Result = Result;//更新结果
}

/*************************************************************************
【函数名称】ChangePassword
【函数功能】修改密码
【参数】const string& NewPassword
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::ChangePassword(const string& NewPassword)
{
	m_Password = NewPassword;//更新密码
}

/*************************************************************************
【函数名称】ReadDocument
【函数功能】初始化时，从文件中读取所有用户信息
【参数】const string& DocumentName
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::ReadDocument(const string& DocumentName)
{
	ifstream File(DocumentName ,ios_base::in);
	
	if (!File)
	{
		cerr << "文件无法正常打开，请检查文件“"<<DocumentName<<"”。";
		//文件无法打开，则退出程序
		exit(1);
	}
	
	m_All.clear();
	unsigned int AdminCount(0);//读取管理员数量
	File >> AdminCount;
	
	while ( File.good() && ( !File.eof() ) )
	{
		string Name;
		string Password;
		string ID;
		string Result;
		
		File >> Name
			  >> Password
			  >> ID
			  >> Result;
		
		auto Finder = [&ID](shared_ptr <Subject>ptr)->bool {return (ptr->m_ID == ID); };
		auto iter = find_if(m_All.begin(), m_All.end(), Finder);

		if (iter != m_All.end())
		{
			throw ExceptionSubjectExist();//查看用户是否已经存在
		}
		shared_ptr <Subject> pNewSubject = make_shared<Subject>(Name, Password, ID, Result);
		//调用构造函数，新建被试者
		
		m_All.push_back(pNewSubject);
	} 

	File.close();
}

/*************************************************************************
【函数名称】const string& SearchID
【函数功能】通过身份证号搜索被试者，并返回其指针
【参数】const string& SearchID
【返回值】shared_ptr<Subject>
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
shared_ptr <Subject> Subject::Search(const string& SearchID)
{
	auto IDFinder = [&SearchID](shared_ptr <Subject>ptr)->bool {return (SearchID == ptr->m_ID); };
	auto IDiter = find_if(m_All.begin(), m_All.end(), IDFinder);

	if (IDiter == m_All.end())
	{
		throw ExceptionSubjectInexistence();
	}
	
	else return *IDiter;//查到身份信息，则返回其指针
}

/*************************************************************************
【函数名称】VerifySubject
【函数功能】核验用户的身份证号和密码
【参数】const string& ID, const string& password
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::VerifySubject(const string& ID, const string& password)
{
	return Subject::Search(ID)->VerifyPassword(password);//核验身份证号和密码
}

/*************************************************************************
【函数名称】VerifyID
【函数功能】核验身份证号
【参数】const string& id
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::VerifyID(const string& id) const
{
	return m_ID == id;
}

/*************************************************************************
【函数名称】VerifyPassword
【函数功能】核验密码
【参数】const string& password
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::VerifyPassword(const string& password) const
{
	return m_Password == password;
}

/*************************************************************************
【函数名称】VerifyName
【函数功能】核验姓名
【参数】const string& name
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Subject::VerifyName(const string& name) const
{
	return m_Name == name;
}

/*************************************************************************
【函数名称】shared_ptr<Subject>
【函数功能】指定身份时返回指针所指对象的姓名
【参数】shared_ptr<Subject>
【返回值】string*
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
string* Subject::AppointeeName(shared_ptr <Subject>) const
{
	string* name = new string(m_Name);
	return name;
}

/*************************************************************************
【函数名称】AppointeePassword
【函数功能】指定对象时返回指针所指对象的密码
【参数】shared_ptr<Subject>
【返回值】string*
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
string* Subject::AppointeePassword(shared_ptr <Subject>) const
{
	string* password=new string(m_Password);
	return password;
}

/*************************************************************************
【函数名称】AppointeeResult
【函数功能】指定对象时返回指针所指对象的上一次核酸检测结果
【参数】shared_ptr<Subject>
【返回值】string*
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
string* Subject::AppointeeResult(shared_ptr<Subject>) const
{
	string* result=new string(m_Result);
	return result;
}

/*************************************************************************
【函数名称】Register
【函数功能】新用户注册，并写入文件
【参数】const string& name, const string password, const string& ID,const string& DocumentName
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::Register(const string& name, const string password, const string& ID, const string& DocumentName)
{
	shared_ptr <Subject> pNewSubject = make_shared<Subject>(name, password, ID, "未检");

	auto Finder = [&ID](shared_ptr <Subject>ptr)->bool {return (ptr->m_ID == ID); };
	auto iter = find_if(m_All.begin(), m_All.end(), Finder);

	if (iter != m_All.end())
	{
		throw ExceptionSubjectExist();//查看用户是否已经存在
	}

	m_All.push_back(pNewSubject);

	ofstream outFile(DocumentName, ios_base::app);
	if (!outFile.good())
	{
		cerr << "文件无法正常打开，请检查文件“" << DocumentName << "”。";
		exit(1);//无法打开文件，报错
	}

	outFile << name << ' ' << password << ' ' << ID << ' ' << "未检"<<endl;
}

/*************************************************************************
【函数名称】CheckResult
【函数功能】查询上一次核酸检测结果
【参数】const string& ID
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::CheckResult(const string& ID) 
{
	cout << "您上一次核酸结果为 " << (Search(ID)->m_Result);
}

/*************************************************************************
【函数名称】operator<<
【函数功能】用户信息输出
【参数】ostream& Stream, const Subject& aSubject
【返回值】ostream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ostream& operator<<(ostream& Stream, const Subject& aSubject)
{
	Stream << aSubject.m_Name
		<< endl
		<< aSubject.m_ID
		<< endl
		<< aSubject.m_Password
		<< endl;

	return Stream;
}

/*************************************************************************
【函数名称】operator>>
【函数功能】用户信息输入
【参数】istream& Stream, Subject& aSubject
【返回值】istream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
istream& operator>>(istream& Stream, Subject& aSubject)
{
	Stream >> aSubject.m_Name >> aSubject.m_ID >> aSubject.m_Password;
	return Stream;
}

/*************************************************************************
【函数名称】Subject
【函数功能】Subject类构造函数
【参数】const string& Name, const string& Password, const string& ID,const string& Result
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Subject::Subject(const string& Name, const string& Password, const string& ID,const string& Result)
	:m_Name(Name),m_Password(Password),m_ID(ID),m_Result(Result)
{
	//查重工作已交由ReadDocument和Register函数，防止构造函数调用时误重复报错
}

/*************************************************************************
【函数名称】Add
【函数功能】新建一个被试者
【参数】const string& Name, const string& Password, const string& ID,const string& Result
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::Add(const string& Name, const string& Password, const string& ID, const string& Result)
{
	Subject* NewSubject=new Subject(Name, Password, ID, Result);
}

/*************************************************************************
【函数名称】Delete
【函数功能】删除一个被试者
【参数】const string& ID
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Subject::Delete(const string& ID)
{
	
	auto SubjectFinder = [&ID](shared_ptr<Subject>ptr)->bool {return (ID == ptr->m_ID); };
	if (Administrator::AdministratorFinder(ID))
	{
		throw ExceptionAdminCannotDelete();
	}//管理员被能被删除
	auto itersubject = find_if(m_All.begin(), m_All.end(), SubjectFinder);
	m_All.erase(itersubject);
}

vector<shared_ptr<Subject>> Subject::m_All = {};