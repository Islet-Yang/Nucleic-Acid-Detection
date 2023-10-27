
/*************************************************************************
【文件名】DateTime.cpp
【功能模块和目的】  处理试管生产日期
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "DateTime.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************************
【函数名称】DateTime
【函数功能】初始化DateTime
【参数】unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
DateTime::DateTime(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second) 
	: Date(Year, Month, Day), Time(Hour, Minute, Second) {}

/*************************************************************************
【函数名称】DateTime
【函数功能】DateTime类的拷贝构造函数
【参数】const Date& aDate, const Time& aTime
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
DateTime::DateTime(const Date& aDate, const Time& aTime) 
	: Date(aDate), Time(aTime) {}

/*************************************************************************
【函数名称】~DateTime
【函数功能】DateTime析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
DateTime::~DateTime(){}

/*************************************************************************
【函数名称】operator  >
【函数功能】>运算符重载，用于日期时间的比较
【参数】const DateTime& aDateTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool DateTime::operator  >(const DateTime& aDateTime) const
{
	return (this->Date::operator>(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator>(aDateTime));
}

/*************************************************************************
【函数名称】operator  <
【函数功能】<运算符重载，用于日期时间的比较
【参数】const DateTime& aDateTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool DateTime::operator  <(const DateTime& aDateTime) const
{
	return (this->Date::operator<(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator<(aDateTime));
}

/*************************************************************************
【函数名称】operator  >=
【函数功能】>=运算符重载，用于日期时间的比较
【参数】const DateTime& aDateTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool DateTime::operator  >=(const DateTime& aDateTime) const
{
	return (this->Date::operator>(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator>=(aDateTime));
}

/*************************************************************************
【函数名称】operator  <=
【函数功能】<=运算符重载，用于日期时间的比较
【参数】const DateTime& aDateTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool DateTime::operator  <=(const DateTime& aDateTime) const
{
	return (this->Date::operator<(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator<=(aDateTime));
}

/*************************************************************************
【函数名称】operator  ==
【函数功能】==运算符重载，用于日期时间的比较
【参数】const DateTime& aDateTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool DateTime::operator ==(const DateTime& aDateTime) const
{
	return (this->Date::operator==(aDateTime)) && (this->Time::operator==(aDateTime));
}

/*************************************************************************
【函数名称】operator  !=
【函数功能】!=运算符重载，用于日期时间的比较
【参数】const DateTime& aDateTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool DateTime::operator !=(const DateTime& aDateTime) const
{
	return (this->Date::operator!=(aDateTime)) || (this->Time::operator!=(aDateTime));
}

/*************************************************************************
【函数名称】operator-
【函数功能】-运算符重载，用于日期时间的运算
【参数】const DateTime& aDateTime
【返回值】long long
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
long long DateTime::operator-(const DateTime& aDateTime) const
{
	return this->Date::operator-(aDateTime) * 86400 + this->Time::operator-(aDateTime);
}

/*************************************************************************
【函数名称】operator<<
【函数功能】<<运算符重载，用于输出时间日期
【参数】ostream& Stream, const DateTime& aDateTime
【返回值】ostream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ostream& operator<<(ostream& Stream, const DateTime& aDateTime) 
{
	Stream << static_cast<const Date&>(aDateTime)
		       << ' '
		       << static_cast<const Time&>(aDateTime);
	return Stream;
}

/*************************************************************************
【函数名称】operator>>
【函数功能】>>运算符重载，用于日期时间的输入
【参数】istream& Stream, DateTime& aDateTime
【返回值】istream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
istream& operator>>(istream& Stream, DateTime& aDateTime) 
{
	Stream >> static_cast<Date&>(aDateTime)
		       >> static_cast<Time&>(aDateTime);
	return Stream;
}
