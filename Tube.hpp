
/*************************************************************************
【文件名】Tube.hpp
【功能模块和目的】  储存所有试管信息，是现场记录员和结果录入员进行工作的信息储存器
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef TUBE_HPP
#define TUBE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Subject.hpp"
#include "DateTime.hpp"

using namespace std;

/*************************************************************************
【类名】Tube
【功能】用于储存试管信息，同时实现与现场记录员、结果录入员实现功能交互
【接口说明】
InputSharedptr:用于向vector容器中添加信息
VerifySerialNumber:查找流水号
SaveToDocument:将检测结果写入文件
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class ExceptionWrongSerialNumber :public invalid_argument
{
public:
	ExceptionWrongSerialNumber();
};

class Tube
{
public:
	Tube(const Tube& aTube) = delete;
	Tube& operator=(const Tube& aTube) = delete;

	Tube(unsigned int Year, unsigned int Month, unsigned int Day, 
		unsigned int Hour, unsigned int Minute, unsigned int Second,
		unsigned int SerialNumber, unsigned int Count, string Result="未检");
	~Tube();

	void InputID(const string& ID, unsigned int number);
	void InputSharedptr(shared_ptr <Tube> ptr);
	bool VerifySerialNumber(const string& SerialNumber) const;
	static shared_ptr <Tube> SaveToDocument(const string& SerialNumber, const string& Result, const string& DocumentName);
	string* TransmitID(unsigned int i) const;

	friend ostream& operator<< (ostream& Stream, const Tube& aTube);
	friend istream& operator>>(istream& Stream, const Tube& aTube);
	
private:
	string m_SerialNumber;
	string m_TubeResult;
	unsigned int m_SubjectCount;
	DateTime m_DateOfManufacture;
	array<string, 10> m_Include;

	static vector<shared_ptr<Tube>> m_Tube;
};

#endif /*Tube_hpp*/
