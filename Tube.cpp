
/*************************************************************************
【文件名】Tube.cpp
【功能模块和目的】  储存所有试管信息，是现场记录员和结果录入员进行工作的信息储存器
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
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
【函数名称】ExceptionWrongSerialNumber
【函数功能】报错显示：流水号错误
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ExceptionWrongSerialNumber::ExceptionWrongSerialNumber()
	:invalid_argument("The sreial number is wrong.") {}

/*************************************************************************
【函数名称】Tube
【函数功能】Tube类构造函数
【参数】unsigned int Year, unsigned int Month, unsigned int Day,
	unsigned int Hour, unsigned int Minute, unsigned int Second,
	unsigned int SerialNumber, unsigned int Count, string Result
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Tube::Tube(unsigned int Year, unsigned int Month, unsigned int Day,
	unsigned int Hour, unsigned int Minute, unsigned int Second,
	unsigned int SerialNumber, unsigned int Count, string Result )
	:m_SubjectCount(Count), m_TubeResult(Result), m_DateOfManufacture(Year, Month, Day, Hour, Minute, Second)
{
	m_SerialNumber = to_string(Year);

	//以下if均为读进个位数时在位前补零
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
【函数名称】~Tube
【函数功能】Tube类析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Tube::~Tube(){}

/*************************************************************************
【函数名称】InputID
【函数功能】向试管中添加被试者
【参数】const string& ID,unsigned int number
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Tube::InputID(const string& ID, unsigned int number)
{
	m_Include.at(number) = ID;
}

/*************************************************************************
【函数名称】InputSharedptr
【函数功能】添加试管信息进入vector容器
【参数】shared_ptr<Tube> ptr
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Tube::InputSharedptr(shared_ptr <Tube> ptr)
{
	m_Tube.push_back(ptr);
}

/*************************************************************************
【函数名称】VerifySerialNumber
【函数功能】核验流水号
【参数】const string& SerialNumber
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Tube::VerifySerialNumber(const string& SerialNumber) const
{
	return SerialNumber == m_SerialNumber;//核验试管编号
}

/*************************************************************************
【函数名称】SaveToDocument
【函数功能】将检测结果保存进文件
【参数】const string& SerialNumber,const string& Result, const string& DocumentName
【返回值】shared_ptr<Tube>
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
shared_ptr <Tube> Tube::SaveToDocument(const string& SerialNumber, const string& Result, const string& DocumentName)
{
	fstream File(DocumentName.c_str());
	if (!File)
	{
		cerr << "文件无法正常打开，请检查文件“" << DocumentName << "”。";
		exit(1);//文件无法打开，退出程序
	}
	cout << endl;
	auto TubeFinder = [&SerialNumber](shared_ptr <Tube>ptr)->bool { return (ptr->m_SerialNumber == (SerialNumber)); };
	auto itertube = find_if(m_Tube.begin(), m_Tube.end(), TubeFinder);
	
	if (itertube == m_Tube.end())
	{
		throw ExceptionWrongSerialNumber();//试管编号未找到，报错
	}
	
	//string AdminCount;
	//if (File.good())
	//{
	//	File >> AdminCount;//先读进管理员数量
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
				File << ' ' << Result;//找到成员在文件中的位置，改变其核酸检测结果
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
【函数名称】TransmitID
【函数功能】逐一输出试管中被试者的身份证号
【参数】unsigned int i
【返回值】string*
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
string* Tube::TransmitID(unsigned int i) const
{
	if (i > m_SubjectCount)
	{
		return nullptr;//超过试管人数，返回空指针
	}
	else
	{
		string* Copy = new string(m_Include.at(i - 1));
		return Copy;//返回身份证号，用来查验
	}
}

/*************************************************************************
【函数名称】operator<<
【函数功能】输出试管信息
【参数】ostream& Stream, const Tube& aTube
【返回值】ostream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
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
【函数名称】 operator>>
【函数功能】输入试管信息
【参数】istream& Stream, const Tube& aTube
【返回值】istream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
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