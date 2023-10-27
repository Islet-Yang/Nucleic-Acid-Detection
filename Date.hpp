
/*************************************************************************
【文件名】Date.hpp
【功能模块和目的】  处理试管生产日期
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <fstream>

using namespace std;

/*************************************************************************
【类名】Date
【功能】提供基本的日期操作函数，在本程序用于试管出场时间记录
【接口说明】
CountDay：用于计算两日期之差
IsLeapYear：用于判断是否为闰年
IsValidDate：用于判断日期是否有效
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class Date
{
public:
	Date(unsigned int Year = 1900u, unsigned int Month = 1u, unsigned int Day = 1u);
	Date(const Date& Source);

	const unsigned int& Year;
	const unsigned int& Month;
	const unsigned int& Day;

	bool Set(unsigned int Year, unsigned int Month, unsigned int Day);
	bool SetYear(unsigned int Year);
	bool SetMonth(unsigned int Month);
	bool SetDay(unsigned int Day);

	static bool IsLeapYear(unsigned int Year);
	static bool IsLeapYear(const Date& Source);

	bool IsLeapYear() const;
	bool IsValidDate() const;
	static bool IsValidDate(unsigned int Year, unsigned int Month, unsigned int Day);
	static void SetRange(unsigned int MaxYear, unsigned int MinYear);

	bool operator> (const Date& aDate) const;
	bool operator< (const Date& aDate) const;
	bool operator>=(const Date& aDate) const;
	bool operator<=(const Date& aDate) const;
	bool operator==(const Date& aDate) const;
	bool operator!=(const Date& aDate) const;
	Date& operator=(const Date& Source);
	Date operator+(const Date& Source);
	long long operator-(const Date& Source) const;

	unsigned int CountDay() const;
	static unsigned int CountDay(const Date& Source);

	friend ostream& operator<<(ostream& Stream, const Date& aDate);
	friend istream& operator>>(istream& Stream, Date& aDate);

	virtual ~Date();

private:
	unsigned int m_Year;
	unsigned int m_Month;
	unsigned int m_Day;
	static unsigned int MaxYear;
	static unsigned int MinYear;
	static unsigned int DaysInMonth[2][12];
};

#endif /*Date_hpp*/