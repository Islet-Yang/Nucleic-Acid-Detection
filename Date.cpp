
/*************************************************************************
【文件名】Date.cpp
【功能模块和目的】  处理试管生产日期
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Date.hpp"

#include <iostream>
#include "Date.hpp"
#include <fstream>
#include <utility>

using namespace std;

unsigned int Date::MaxYear = 9999u;//最大年份
unsigned int Date::MinYear = 1900u;//最小年份
unsigned int Date::DaysInMonth[2][12] = { {31,28,31,20,31,30,31,31,30,31,30,31},
	{31,29,31,20,31,30,31,31,30,31,30,31} };//每月天数

/*************************************************************************
【函数名称】Date
【函数功能】实现日期的初始化
【参数】unsigned int Year, unsigned int Month, unsigned int Day
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Date::Date(unsigned int Year, unsigned int Month, unsigned int Day) :
	Year(m_Year), Month(m_Month), Day(m_Day)
{
	if (!Set(Year, Month, Day))
	{
		Set(1900u, 1u, 1u);
	}
}

/*************************************************************************
【函数名称】Date
【函数功能】日期的拷贝构造函数
【参数】const Date& Source
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Date::Date(const Date& Source) :
	Year(m_Year), Month(m_Month), Day(m_Day)
{
	m_Year = Source.m_Year;
	m_Month = Source.m_Month;
	m_Day = Source.m_Day;
}

/*************************************************************************
【函数名称】Set
【函数功能】设置日期
【参数】unsigned int Year, unsigned int Month, unsigned int Day
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::Set(unsigned int Year, unsigned int Month, unsigned int Day) 
{
	return SetYear(Year) && SetMonth(Month) && SetDay(Day);
}

/*************************************************************************
【函数名称】SetYear
【函数功能】设置日期的年份
【参数】unsigned int Year
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::SetYear(unsigned int Year) 
{
	bool IsRight = (MinYear <= Year) && (Year <= MaxYear);//判断年份是否越界
	m_Year = IsRight ? Year : m_Year;
	return IsRight;
}

/*************************************************************************
【函数名称】SetMonth
【函数功能】设置日期的月份
【参数】unsigned int Month
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::SetMonth(unsigned int Month)
{
	bool IsRight = (1 <= Month) && (Month <= 12);//判断月份是否越界
	m_Month = IsRight ? Month : m_Month;
	return IsRight;
}

/*************************************************************************
【函数名称】SetDay
【函数功能】设置日期的日
【参数】unsigned int Day
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::SetDay(unsigned int Day)
{
	bool IsRight = (1 <= Day) && ( Day <= DaysInMonth[static_cast<int>( IsLeapYear(Year) )][Month - 1] );
	//判断日是否越界
	m_Day = IsRight ? Day : m_Day;
	return IsRight;
}

/*************************************************************************
【函数名称】IsLeapYear
【函数功能】判断是否为闰年
【参数】unsigned int Year
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::IsLeapYear(unsigned int Year)
{
	return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

/*************************************************************************
【函数名称】IsLeapYear
【函数功能】判断是否为闰年
【参数】const Date& Source
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::IsLeapYear(const Date& Source) 
{
	return IsLeapYear(Source.m_Year);
}

/*************************************************************************
【函数名称】IsLeapYear
【函数功能】判断是否为闰年
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::IsLeapYear() const 
{
	return IsLeapYear(m_Year);
}

/*************************************************************************
【函数名称】IsValidDate
【函数功能】判断日期是否 有效
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::IsValidDate() const 
{
	return IsValidDate(Year, Month, Day);
}

/*************************************************************************
【函数名称】IsValidDate
【函数功能】判断日期是否有效
【参数】unsigned int Year, unsigned int Month, unsigned int Day
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::IsValidDate(unsigned int Year, unsigned int Month, unsigned int Day) 
{
	if (Year <= MinYear || Year >= MaxYear) return false;
	if (Month == 0 || Month > 12) return false;
	if (Day == 0 || Day > DaysInMonth[static_cast<int> ( IsLeapYear(Year) )][Month - 1])
		return false;
	return true;
}

/*************************************************************************
【函数名称】SetRange
【函数功能】设置最大年份和最小年份限制
【参数】unsigned int maxyear, unsigned int minyear
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Date::SetRange(unsigned int maxyear, unsigned int minyear)
{
	MaxYear = maxyear;
	MinYear = minyear;
}

/*************************************************************************
【函数名称】operator>
【函数功能】>的运算符重载，用于比较日期
【参数】const Date& aDate
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::operator> (const Date& aDate) const
{
	return (this->CountDay()) > aDate.CountDay();
}

/*************************************************************************
【函数名称】operator<
【函数功能】<的运算符重载，用于比较日期
【参数】const Date& aDate
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::operator< (const Date& aDate) const
{
	return ( this->CountDay() ) < aDate.CountDay();
}

/*************************************************************************
【函数名称】operator>=
【函数功能】>=的运算符重载，用于比较日期
【参数】const Date& aDate
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::operator>= (const Date& aDate) const
{
	return (this->CountDay()) >= aDate.CountDay();
}

/*************************************************************************
【函数名称】operator<=
【函数功能】<=的运算符重载，用于比较日期
【参数】const Date& aDate
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::operator<= (const Date& aDate) const
{
	return (this->CountDay()) <= aDate.CountDay();
}

/*************************************************************************
【函数名称】operator==
【函数功能】==的运算符重载，用于比较日期
【参数】const Date& aDate
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::operator== (const Date& aDate) const
{
	return (this->CountDay()) == aDate.CountDay();
}

/*************************************************************************
【函数名称】operator!=
【函数功能】!=的运算符重载，用于比较日期
【参数】const Date& aDate
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Date::operator!= (const Date& aDate) const
{
	return (this->CountDay()) != aDate.CountDay();
}

/*************************************************************************
【函数名称】operator=
【函数功能】=的运算符重载，用于日期赋值
【参数】const Date& Source
【返回值】Date&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Date& Date::operator=(const Date& Source) 
{
	if (this != &Source) 
	{
		m_Year = Source.m_Year;
		m_Month = Source.m_Month;
		m_Day = Source.m_Day;
	}
	return *this;
}

/*************************************************************************
【函数名称】operator+
【函数功能】+的运算符重载，用于日期运算
【参数】const Date& Source
【返回值】Date&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Date Date::operator+(const Date& Source)
{
	Date Res(*this);
	Res.m_Year += Day;
	Res.m_Month += m_Day / 30;
	Res.m_Day %= 30;
	Res.m_Year += m_Month / 12;
	Res.m_Month %= 12;
	return Res;
}

/*************************************************************************
【函数名称】operator-
【函数功能】-的运算符重载，用于日期运算
【参数】const Date& Source
【返回值】long long
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
long long Date::operator-(const Date& Source) const
{
	return (CountDay(*this) - CountDay(Source));
}

/*************************************************************************
【函数名称】CountDay
【函数功能】用于某一日期到基准日的天数差
【参数】const Date& Source
【返回值】unsigned int
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
unsigned int Date::CountDay(const Date& Source) {
	int Array[12] = { 0,1,-1,0,0,1,1,2,3,3,4,4 };//之后按每月均为30天计算，故而此数组为每个月份补差（总差）
	unsigned int count(0);
	int leap = (Source.m_Year - 1) / 4 - (Source.m_Year - 1) / 100 + (Source.m_Year - 1) / 400;
	int unleap = Source.m_Year - leap - 1;
	count = unleap * 365 + leap * 366 + (Source.m_Month - 1) * 30 + Array[Source.m_Month - 1] + Source.m_Day;
	if (IsLeapYear(Source.m_Year)) count++;//如果当年是闰年，还要再加一天
	return count;
}

/*************************************************************************
【函数名称】CountDay
【函数功能】用于某一日期到基准日的天数差
【参数】无
【返回值】unsigned int
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
unsigned int Date::CountDay() const
{
	return CountDay(*this);
}

/*************************************************************************
【函数名称】operator<<
【函数功能】<<运算符重载，用于输出日期
【参数】ostream& Stream, const Date& aDate
【返回值】ostream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ostream& operator<<(ostream& Stream, const Date& aDate)
{
	Stream << aDate.Year << ' ' << aDate.Month << ' ' << aDate.Day << ' ';
	return Stream;
}

/*************************************************************************
【函数名称】operator>>
【函数功能】<<运算符重载，用于日期输入
【参数】istream& Stream, Date& aDate
【返回值】istream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
istream& operator>>(istream& Stream, Date& aDate)
{
	char Temp;
	unsigned int Year;
	unsigned int Month;
	unsigned int Day;
	string WeekDayStr;
	Stream >> Year >> Temp
		>> Month >> Temp
		>> Day >> Temp;

	aDate.Set(Year, Month, Day);
	return Stream;
}

/*************************************************************************
【函数名称】~Date
【函数功能】日期类的析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Date::~Date() {}