
/*************************************************************************
���ļ�����Subject.hpp
������ģ���Ŀ�ġ�  ����������������Ϣ����ȡ���洢�ļ����ṩ�ӿ�
����������������Ϣ��ͬʱ��������Ա���ֳ���¼Ա�ͽ��¼��Ա
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
��������ExceptionSubjectExists
�����ܡ�����ʼ��������ԭ�ж����ظ�ʱ����
���ӿ�˵����
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class ExceptionSubjectExist :public invalid_argument
{
public:
	ExceptionSubjectExist();
};

/*************************************************************************
��������ExceptionAdminCannotDelete
�����ܡ�����ͼɾ������Աʱ����
���ӿ�˵����
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class  ExceptionAdminCannotDelete :public invalid_argument
{
public:
	ExceptionAdminCannotDelete();
};

/*************************************************************************
��������ExceptionSubjectInexistence
�����ܡ������������󲻴���ʱ����
���ӿ�˵����
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class  ExceptionSubjectInexistence :public invalid_argument
{
public:
	ExceptionSubjectInexistence();
};

/*************************************************************************
��������Subject
�����ܡ����������û���Ϣ��ͬʱ�ṩ���û���Ϣ�����Ľ��
���ӿ�˵����
	ChangePassword:��������
	ReadDocument:��ȡ�ļ�
	Search:ͨ��ID���ұ�����
	VerifySubject:�������֤�Ŷ�Ӧ�������Ƿ���ȷ
	VerifyName:���鱻��������
	VerifyPassword:���鱻��������
	VerifyID:���鱻�������֤��
	Register:�û�ע�Ტ¼���ļ�
	CheckResult:�����û���һ�κ�������
	AppointeeName:����ָ���ߵ�����
	AppointeeResult������ָ���ߵ���һ�κ�������
	AppointeePassword:����ָ���ߵ�����
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
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
	virtual void Add(const string& Name, const string& Password, const string& ID, const string& Result="δ��");
	virtual void Delete(const string& ID);
	
private:
	static vector <shared_ptr<Subject>> m_All;
	string m_Name;
	string m_Password;
	string m_ID;
	string m_Result;
};

#endif /*Subject_hpp*/