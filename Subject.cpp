
/*************************************************************************
���ļ�����Subject.cpp
������ģ���Ŀ�ġ�  ����������������Ϣ����ȡ���洢�ļ����ṩ�ӿ�
����������������Ϣ��ͬʱ��������Ա���ֳ���¼Ա�ͽ��¼��Ա
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�ExceptionSubjectExist
���������ܡ������ͣ��������Ѵ���
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ExceptionSubjectExist::ExceptionSubjectExist()
	:invalid_argument("Subject exists."){}

/*************************************************************************
���������ơ�ExceptionAdminCannotDelete
���������ܡ�������ʾ������Ա���ܱ�ɾ��
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ExceptionAdminCannotDelete::ExceptionAdminCannotDelete()
	:invalid_argument("You are tryint to log off an administrator."){}

/*************************************************************************
���������ơ�ExceptionSubjectInexistence
���������ܡ�������ʾ����������Ϣ������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ExceptionSubjectInexistence::ExceptionSubjectInexistence()
	: invalid_argument("Subject isn't exist.") {}

/*************************************************************************
���������ơ�~Subject
���������ܡ�Subject����������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Subject::~Subject(){}

/*************************************************************************
���������ơ�IsRecorder
���������ܡ���ע��ݲ����ֳ���¼Ա
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::IsRecorder() const
{
	return false;
}

/*************************************************************************
���������ơ�IsKeyboarder
���������ܡ���ע��ݲ��ǽ��¼��Ա
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::IsKeyboarder() const
{
	return false;
}

/*************************************************************************
���������ơ�IsAdministrator
���������ܡ���ע��ݲ��ǹ���Ա
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::IsAdministrator() const
{
	return false;
}

/*************************************************************************
���������ơ�EnterResult
���������ܡ��û������¼��
��������const string& Result
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::EnterResult(const string& Result)
{
	m_Result = Result;//���½��
}

/*************************************************************************
���������ơ�ChangePassword
���������ܡ��޸�����
��������const string& NewPassword
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::ChangePassword(const string& NewPassword)
{
	m_Password = NewPassword;//��������
}

/*************************************************************************
���������ơ�ReadDocument
���������ܡ���ʼ��ʱ�����ļ��ж�ȡ�����û���Ϣ
��������const string& DocumentName
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::ReadDocument(const string& DocumentName)
{
	ifstream File(DocumentName ,ios_base::in);
	
	if (!File)
	{
		cerr << "�ļ��޷������򿪣������ļ���"<<DocumentName<<"����";
		//�ļ��޷��򿪣����˳�����
		exit(1);
	}
	
	m_All.clear();
	unsigned int AdminCount(0);//��ȡ����Ա����
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
			throw ExceptionSubjectExist();//�鿴�û��Ƿ��Ѿ�����
		}
		shared_ptr <Subject> pNewSubject = make_shared<Subject>(Name, Password, ID, Result);
		//���ù��캯�����½�������
		
		m_All.push_back(pNewSubject);
	} 

	File.close();
}

/*************************************************************************
���������ơ�const string& SearchID
���������ܡ�ͨ�����֤�����������ߣ���������ָ��
��������const string& SearchID
������ֵ��shared_ptr<Subject>
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
shared_ptr <Subject> Subject::Search(const string& SearchID)
{
	auto IDFinder = [&SearchID](shared_ptr <Subject>ptr)->bool {return (SearchID == ptr->m_ID); };
	auto IDiter = find_if(m_All.begin(), m_All.end(), IDFinder);

	if (IDiter == m_All.end())
	{
		throw ExceptionSubjectInexistence();
	}
	
	else return *IDiter;//�鵽�����Ϣ���򷵻���ָ��
}

/*************************************************************************
���������ơ�VerifySubject
���������ܡ������û������֤�ź�����
��������const string& ID, const string& password
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::VerifySubject(const string& ID, const string& password)
{
	return Subject::Search(ID)->VerifyPassword(password);//�������֤�ź�����
}

/*************************************************************************
���������ơ�VerifyID
���������ܡ��������֤��
��������const string& id
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::VerifyID(const string& id) const
{
	return m_ID == id;
}

/*************************************************************************
���������ơ�VerifyPassword
���������ܡ���������
��������const string& password
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::VerifyPassword(const string& password) const
{
	return m_Password == password;
}

/*************************************************************************
���������ơ�VerifyName
���������ܡ���������
��������const string& name
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Subject::VerifyName(const string& name) const
{
	return m_Name == name;
}

/*************************************************************************
���������ơ�shared_ptr<Subject>
���������ܡ�ָ�����ʱ����ָ����ָ���������
��������shared_ptr<Subject>
������ֵ��string*
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
string* Subject::AppointeeName(shared_ptr <Subject>) const
{
	string* name = new string(m_Name);
	return name;
}

/*************************************************************************
���������ơ�AppointeePassword
���������ܡ�ָ������ʱ����ָ����ָ���������
��������shared_ptr<Subject>
������ֵ��string*
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
string* Subject::AppointeePassword(shared_ptr <Subject>) const
{
	string* password=new string(m_Password);
	return password;
}

/*************************************************************************
���������ơ�AppointeeResult
���������ܡ�ָ������ʱ����ָ����ָ�������һ�κ�������
��������shared_ptr<Subject>
������ֵ��string*
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
string* Subject::AppointeeResult(shared_ptr<Subject>) const
{
	string* result=new string(m_Result);
	return result;
}

/*************************************************************************
���������ơ�Register
���������ܡ����û�ע�ᣬ��д���ļ�
��������const string& name, const string password, const string& ID,const string& DocumentName
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::Register(const string& name, const string password, const string& ID, const string& DocumentName)
{
	shared_ptr <Subject> pNewSubject = make_shared<Subject>(name, password, ID, "δ��");

	auto Finder = [&ID](shared_ptr <Subject>ptr)->bool {return (ptr->m_ID == ID); };
	auto iter = find_if(m_All.begin(), m_All.end(), Finder);

	if (iter != m_All.end())
	{
		throw ExceptionSubjectExist();//�鿴�û��Ƿ��Ѿ�����
	}

	m_All.push_back(pNewSubject);

	ofstream outFile(DocumentName, ios_base::app);
	if (!outFile.good())
	{
		cerr << "�ļ��޷������򿪣������ļ���" << DocumentName << "����";
		exit(1);//�޷����ļ�������
	}

	outFile << name << ' ' << password << ' ' << ID << ' ' << "δ��"<<endl;
}

/*************************************************************************
���������ơ�CheckResult
���������ܡ���ѯ��һ�κ�������
��������const string& ID
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::CheckResult(const string& ID) 
{
	cout << "����һ�κ�����Ϊ " << (Search(ID)->m_Result);
}

/*************************************************************************
���������ơ�operator<<
���������ܡ��û���Ϣ���
��������ostream& Stream, const Subject& aSubject
������ֵ��ostream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�operator>>
���������ܡ��û���Ϣ����
��������istream& Stream, Subject& aSubject
������ֵ��istream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
istream& operator>>(istream& Stream, Subject& aSubject)
{
	Stream >> aSubject.m_Name >> aSubject.m_ID >> aSubject.m_Password;
	return Stream;
}

/*************************************************************************
���������ơ�Subject
���������ܡ�Subject�๹�캯��
��������const string& Name, const string& Password, const string& ID,const string& Result
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Subject::Subject(const string& Name, const string& Password, const string& ID,const string& Result)
	:m_Name(Name),m_Password(Password),m_ID(ID),m_Result(Result)
{
	//���ع����ѽ���ReadDocument��Register��������ֹ���캯������ʱ���ظ�����
}

/*************************************************************************
���������ơ�Add
���������ܡ��½�һ��������
��������const string& Name, const string& Password, const string& ID,const string& Result
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::Add(const string& Name, const string& Password, const string& ID, const string& Result)
{
	Subject* NewSubject=new Subject(Name, Password, ID, Result);
}

/*************************************************************************
���������ơ�Delete
���������ܡ�ɾ��һ��������
��������const string& ID
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Subject::Delete(const string& ID)
{
	
	auto SubjectFinder = [&ID](shared_ptr<Subject>ptr)->bool {return (ID == ptr->m_ID); };
	if (Administrator::AdministratorFinder(ID))
	{
		throw ExceptionAdminCannotDelete();
	}//����Ա���ܱ�ɾ��
	auto itersubject = find_if(m_All.begin(), m_All.end(), SubjectFinder);
	m_All.erase(itersubject);
}

vector<shared_ptr<Subject>> Subject::m_All = {};