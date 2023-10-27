
/*************************************************************************
���ļ�����Controller.cpp
������ģ���Ŀ�ġ�  ���û����н������е�¼��ע���Լ�������Ա��¼����ʵ�ֵ�����
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�Controller
���������ܡ���ʼ������̨
��������View& view
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Controller::Controller(View& view) :m_view(view) {}

/*************************************************************************
���������ơ�Load
���������ܡ��������ļ��ж�ȡ������Ϣ
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Controller::Load () const
{
	Subject::ReadDocument("Enroll.txt");//��ȡ���б�������Ϣ
	Administrator::ReadAdministrator("Enroll.txt");//��ȡ����Ա��Ϣ
}

/*************************************************************************
���������ơ�NewSubjectRegister
���������ܡ��������û�ע��֮��Ľ�������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
			continue;//�����������ԣ�����
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
			continue;//���֤��λ�����ԣ�����
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
			continue;//����λ�����ԣ�����
		}
		break;
	}

	Subject::Register(name, password, ID, "Enroll.txt");//����ע�ắ�������³�Ա
}

/*************************************************************************
���������ơ�Login
���������ܡ�����ʵ�������û���¼֮������ֹ���
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
				continue;//���֤��λ�����ԣ�����
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
				continue;//����λ�����ԣ�����
			}
			break;
		}

		if ( !Subject::VerifySubject(ID, password) )
		{
			m_view.View3_3();
			continue;//���֤�����������ʧ�ܣ�����
		}
		break;
	}

	if ( (Administrator::AdministratorFinder(ID) == nullptr) && (Recorder::RecorderFinder(ID) == nullptr) && (Keyboarder::KeyboarderFinder(ID) == nullptr))
	{
		m_view.View4_1();
		Subject::CheckResult(ID);
		m_view.ViewEndl();
	}
	//��ͨ��Ա��ֱ����ʾ��һ�κ�������

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

		unsigned int choice(0);//����ѡ�����
		cin >> choice;
		switch(choice)
		{
		case 0 :
		{
			if (Administrator::AdministratorFinder(ID) == nullptr) break;
			AdministratorLogIn( Administrator::AdministratorFinder(ID) );//�������Ա������
			break;
		}

		case 1 :
		{
			if (Recorder::RecorderFinder(ID) == nullptr) break;
			RecorderLogIn( Recorder::RecorderFinder(ID) );//�����ֳ���¼Ա������
			break;
		}

		case 2 :
		{
			if (Keyboarder::KeyboarderFinder(ID) == nullptr) break;
			KeyboarderLogIn( Keyboarder::KeyboarderFinder(ID) );//������¼��Ա������
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
���������ơ�AdministratorLogIn
���������ܡ�����ʵ�ֹ���Ա��¼��Ľ�������
��������shared_ptr<Administrator> pAdmin
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
		}//ָ���ֳ���¼Ա

		case 2 :
		{
			string KeyboarderID;
			m_view.View5_3();
			cin >> KeyboarderID;
			pAdmin->AppointKeyboarder(KeyboarderID);
			break;
		}//ָ�����¼��Ա

		default :
		{
			break;
		}
	}

}

/*************************************************************************
���������ơ�RecorderLogIn
���������ܡ�����ʵ���ֳ���¼Ա��¼��Ľ�������
��������shared_ptr<Recorder> pAdmin
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
	string Result = "δ��";

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
	//��������Թܱ����Ϣ��¼��

	shared_ptr <Tube> pNewTube = make_shared<Tube>(Year, Month, Day, Hour, Minute, Second, SerialNumber, Count);
	//���ù��캯�����½�һ���Թ�

	for (unsigned int i = 0; i < Count; i++)
	{
		string NewID;
		m_view.View6_4(i);
		cin >> NewID;
		if (NewID.length() != 18)
		{
			m_view.View6_5();
			i--;
			continue;//���֤��λ�����ԣ�����
		}
		pNewTube->InputID(NewID, i);//�������Ϣ¼���Թ�
	}

	pNewTube->InputSharedptr(pNewTube);
}

/*************************************************************************
���������ơ�KeyboarderLogIn
���������ܡ�����ʵ�ֽ��¼��Ա��¼��Ľ�������
��������shared_ptr<Keyboarder> pAdmin
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
	//�����Թ�

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
	}//���Թܵ�����Ϣ���ڳ�������ݽṹ�и��º�������
}