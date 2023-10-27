
/*************************************************************************
【文件名】Subject.hpp
【功能模块和目的】  储存所有受试者信息，读取并存储文件，提供接口
用来访问受试者信息，同时派生管理员、现场记录员和结果录入员
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

using namespace std;

/*************************************************************************
【类名】ExceptionSubjectExists
【功能】当初始化对象与原有对象重复时报错
【接口说明】
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class ExceptionSubjectExist :public invalid_argument
{
public:
	ExceptionSubjectExist();
};

/*************************************************************************
【类名】ExceptionAdminCannotDelete
【功能】当试图删除管理员时报错
【接口说明】
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class  ExceptionAdminCannotDelete :public invalid_argument
{
public:
	ExceptionAdminCannotDelete();
};

/*************************************************************************
【类名】ExceptionSubjectInexistence
【功能】当所搜索对象不存在时报错
【接口说明】
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class  ExceptionSubjectInexistence :public invalid_argument
{
public:
	ExceptionSubjectInexistence();
};

/*************************************************************************
【类名】Subject
【功能】管理所有用户信息，同时提供与用户信息交互的借口
【接口说明】
	ChangePassword:更改密码
	ReadDocument:读取文件
	Search:通过ID查找被试者
	VerifySubject:核验身份证号对应的密码是否正确
	VerifyName:核验被试者名字
	VerifyPassword:核验被试者密码
	VerifyID:核验被试者身份证号
	Register:用户注册并录入文件
	CheckResult:给出用户上一次核酸检测结果
	AppointeeName:返回指定者的名字
	AppointeeResult：返回指定者的上一次核酸检测结果
	AppointeePassword:返回指定者的密码
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class Subject
{
public:
	Subject() = delete;
	Subject(const Subject&) = delete;
	Subject& operator=(const Subject&) = delete;
	Subject(const string& Name, const string& Password, const string& ID, const string& Result);

	virtual ~Subject();
	virtual bool IsRecorder () const;
	virtual bool IsKeyboarder() const;
	virtual bool IsAdministrator() const;

	void EnterResult(const string& Result);
	void ChangePassword(const string& NewPassword);
	static void ReadDocument(const string& DocumentName);
	static shared_ptr<Subject> Search(const string& SearchID);

	static bool VerifySubject(const string& ID, const string& password) ;
	bool VerifyPassword(const string& password) const;
	bool VerifyID(const string& id) const;
	bool VerifyName(const string& name) const;

	string* AppointeeName(shared_ptr <Subject>) const;
	string* AppointeePassword(shared_ptr <Subject>) const;
	string* AppointeeResult(shared_ptr <Subject>) const;

	static void Register(const string& name, const string password, const string& ID, const string& DocumentName);
	static void CheckResult(const string& ID) ;

	friend ostream& operator<<(ostream& Stream, const Subject& aSubject);
	friend istream& operator>>(istream& Stream, Subject& aSubject);

protected:
	virtual void Add(const string& Name, const string& Password, const string& ID, const string& Result="未检");
	virtual void Delete(const string& ID);
	
private:
	static vector <shared_ptr<Subject>> m_All;
	string m_Name;
	string m_Password;
	string m_ID;
	string m_Result;
};

#endif /*Subject_hpp*/