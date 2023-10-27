
/*************************************************************************
���ļ�����Administartor.cpp
������ģ���Ŀ�ġ�  ָ���ֳ���¼Ա�ͽ��¼��Ա���������Ա��Ϣ
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "Administrator.hpp"
#include "Recorder.hpp"
#include "Keyboarder.hpp"
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

/*************************************************************************
���������ơ�  Administrator     
���������ܡ�  ��ʼ������Ա    
��������const string& Name, const string& Password, const string& ID,const string& Result 
������ֵ��   ��      
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��       
*************************************************************************/
Administrator::Administrator(const string& Name, const string& Password, const string& ID, const string& Result):
	Subject(Name, Password, ID,Result){}

/*************************************************************************
���������ơ�IsAdministrator
���������ܡ�ȷ���Ƿ�Ϊ����Ա
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Administrator::IsAdministrator() const
{
	return true;
}

/*************************************************************************
���������ơ�~Administrator
���������ܡ�Administrator�����������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Administrator::~Administrator() {}

/*************************************************************************
���������ơ�AdministratorFinder
���������ܡ�������������ID�Ƿ�Ϊ����Ա
��������const string& ID
������ֵ��shared_ptr<Administrator>
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
shared_ptr <Administrator> Administrator::AdministratorFinder(const string& ID)
{
	auto AdminFinder = [&ID](shared_ptr <Administrator>ptr)->bool { return ( ptr->VerifyID(ID) ); };
	auto iteradmin = find_if(m_Admin.begin(), m_Admin.end(), AdminFinder);
	if (iteradmin != m_Admin.end())
	{
		return *iteradmin;//�ҵ�����Ա��������ָ��
	}
	else
	{
		return nullptr;//δ�ҵ�����Ա�����ؿ�ָ��
	}
}

/*************************************************************************
���������ơ�ReadAdministrator
���������ܡ����ڶ�ȡ�ļ���ȷ������Ա
��������const string& FileName
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Administrator::ReadAdministrator(const string& FileName)
{
	ifstream File(FileName, ios_base::in);
	if (!File)
	{
		cerr << "Failed to open the information file.";//δ�ܴ��ļ����˳�����
		exit(1);
	}

	m_Admin.clear();
	unsigned int AdminCount(0);//�鿴����Ա����
	File >> AdminCount;

	for (unsigned int i = 0; i < AdminCount; i++)
	{
		string Name;
		string Password;
		string ID;
		string Result;
		File >> (Name)
			>> (Password)
			>> (ID)
			>> (Result);
		shared_ptr <Administrator> pNewAdmin = 
			make_shared<Administrator>( Name,Password,ID,Result );//���ù��캯���½�����Ա
		
		m_Admin.push_back(pNewAdmin);
	}
}

/*************************************************************************
���������ơ�AppointRecorder
���������ܡ�ָ���ֳ�¼��Ա
��������const string& RecorderID
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Administrator::AppointRecorder(const string& RecorderID) const
{
	shared_ptr <Recorder> pNewRecorder = make_shared<Recorder>
		(*AppointeeName(Search(RecorderID)), *AppointeePassword(Search(RecorderID)),
			RecorderID, *AppointeeResult(Search(RecorderID)) );//���ù��캯���½��ֳ���¼Ա

	pNewRecorder->InputSharedptr(pNewRecorder);

	delete AppointeeName(Search(RecorderID));
	delete AppointeePassword(Search(RecorderID));
	delete AppointeeResult(Search(RecorderID));
}

/*************************************************************************
���������ơ�AppointKeyboarder
���������ܡ�ָ�����¼��Ա
��������const string& KeyboarderID
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Administrator::AppointKeyboarder(const string& KeyboarderID) const
{
	shared_ptr <Keyboarder> pNewKeyboarder = make_shared<Keyboarder>
		(*AppointeeName(Search(KeyboarderID)), *AppointeePassword(Search(KeyboarderID)),
			KeyboarderID, *AppointeeResult(Search(KeyboarderID)));//���ù��캯���½���Ϣ¼��Ա

	pNewKeyboarder->InputSharedptr(pNewKeyboarder);

	delete AppointeeName(Search(KeyboarderID));
	delete AppointeePassword(Search(KeyboarderID));
	delete AppointeeResult(Search(KeyboarderID));
}

vector<shared_ptr<Administrator>> Administrator::m_Admin = {};