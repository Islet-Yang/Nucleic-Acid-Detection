
/*************************************************************************
���ļ�����Tube.cpp
������ģ���Ŀ�ġ�  ���������Թ���Ϣ�����ֳ���¼Ա�ͽ��¼��Ա���й�������Ϣ������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "Tube.hpp"
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <xstring>

using namespace std;

/*************************************************************************
���������ơ�ExceptionWrongSerialNumber
���������ܡ�������ʾ����ˮ�Ŵ���
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ExceptionWrongSerialNumber::ExceptionWrongSerialNumber()
	:invalid_argument("The sreial number is wrong.") {}

/*************************************************************************
���������ơ�Tube
���������ܡ�Tube�๹�캯��
��������unsigned int Year, unsigned int Month, unsigned int Day,
	unsigned int Hour, unsigned int Minute, unsigned int Second,
	unsigned int SerialNumber, unsigned int Count, string Result
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Tube::Tube(unsigned int Year, unsigned int Month, unsigned int Day,
	unsigned int Hour, unsigned int Minute, unsigned int Second,
	unsigned int SerialNumber, unsigned int Count, string Result )
	:m_SubjectCount(Count), m_TubeResult(Result), m_DateOfManufacture(Year, Month, Day, Hour, Minute, Second)
{
	m_SerialNumber = to_string(Year);

	//����if��Ϊ������λ��ʱ��λǰ����
	if (Month < 10)
	{
		m_SerialNumber += "0";
	}
	m_SerialNumber += to_string(Month);
	if (Day < 10)
	{
		m_SerialNumber += "0";
	}
	m_SerialNumber += to_string(Day);
	if (Hour < 10)
	{
		m_SerialNumber += "0";
	}
	m_SerialNumber += to_string(Hour);
	if (Minute < 10)
	{
		m_SerialNumber += "0";
	}
	m_SerialNumber += to_string(Minute);
	if (Second < 10)
	{
		m_SerialNumber += "0";
	}
	m_SerialNumber += (to_string(Second)+to_string(SerialNumber));
}

/*************************************************************************
���������ơ�~Tube
���������ܡ�Tube����������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Tube::~Tube(){}

/*************************************************************************
���������ơ�InputID
���������ܡ����Թ�����ӱ�����
��������const string& ID,unsigned int number
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Tube::InputID(const string& ID, unsigned int number)
{
	m_Include.at(number) = ID;
}

/*************************************************************************
���������ơ�InputSharedptr
���������ܡ�����Թ���Ϣ����vector����
��������shared_ptr<Tube> ptr
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Tube::InputSharedptr(shared_ptr <Tube> ptr)
{
	m_Tube.push_back(ptr);
}

/*************************************************************************
���������ơ�VerifySerialNumber
���������ܡ�������ˮ��
��������const string& SerialNumber
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Tube::VerifySerialNumber(const string& SerialNumber) const
{
	return SerialNumber == m_SerialNumber;//�����Թܱ��
}

/*************************************************************************
���������ơ�SaveToDocument
���������ܡ��������������ļ�
��������const string& SerialNumber,const string& Result, const string& DocumentName
������ֵ��shared_ptr<Tube>
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
shared_ptr <Tube> Tube::SaveToDocument(const string& SerialNumber, const string& Result, const string& DocumentName)
{
	fstream File(DocumentName.c_str());
	if (!File)
	{
		cerr << "�ļ��޷������򿪣������ļ���" << DocumentName << "����";
		exit(1);//�ļ��޷��򿪣��˳�����
	}
	cout << endl;
	auto TubeFinder = [&SerialNumber](shared_ptr <Tube>ptr)->bool { return (ptr->m_SerialNumber == (SerialNumber)); };
	auto itertube = find_if(m_Tube.begin(), m_Tube.end(), TubeFinder);
	
	if (itertube == m_Tube.end())
	{
		throw ExceptionWrongSerialNumber();//�Թܱ��δ�ҵ�������
	}
	
	//string AdminCount;
	//if (File.good())
	//{
	//	File >> AdminCount;//�ȶ�������Ա����
	//}

	for (unsigned int i = 0; i < (*itertube)->m_SubjectCount; i++)
	{
		string AdminCount;
		File >> AdminCount;
		while (File.good())
		{
			string id;
			string name;
			string password;
			string result;
			File >> name >> password >> id;
			if ( id == (*itertube)->m_Include.at(i) )
			{
				File.seekg(File.tellp());
				File << ' ' << Result;//�ҵ���Ա���ļ��е�λ�ã��ı����������
				File.seekg(0,ios::beg);
				break;
			}
			else
			{
				File >> result;
			}
		}
	}

	return *itertube;
}

/*************************************************************************
���������ơ�TransmitID
���������ܡ���һ����Թ��б����ߵ����֤��
��������unsigned int i
������ֵ��string*
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
string* Tube::TransmitID(unsigned int i) const
{
	if (i > m_SubjectCount)
	{
		return nullptr;//�����Թ����������ؿ�ָ��
	}
	else
	{
		string* Copy = new string(m_Include.at(i - 1));
		return Copy;//�������֤�ţ���������
	}
}

/*************************************************************************
���������ơ�operator<<
���������ܡ�����Թ���Ϣ
��������ostream& Stream, const Tube& aTube
������ֵ��ostream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ostream& operator<<(ostream& Stream, const Tube& aTube)
{
	Stream
		<< "This tube has " << aTube.m_SubjectCount << " Subjects\n"
		<< "Serial number:"
		<< aTube.m_SerialNumber
		<< "\nTest result:"
		<< aTube.m_TubeResult;

	return Stream;
}

/*************************************************************************
���������ơ� operator>>
���������ܡ������Թ���Ϣ
��������istream& Stream, const Tube& aTube
������ֵ��istream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
istream& operator>>(istream& Stream, const Tube& aTube) 
{
	unsigned int Year ;
	unsigned int Month;
	unsigned int Day;
	unsigned int Hour;
	unsigned int Minute;
	unsigned int Second;
	unsigned int SerialNumber;
	unsigned int Count;
	string Result;
	Stream >> Count
		>> Year >> Month >> Day
		>> Hour >> Minute >> Second
		>> SerialNumber;
	return Stream;
}

vector<shared_ptr<Tube>> Tube::m_Tube = {};