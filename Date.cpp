
/*************************************************************************
���ļ�����Date.cpp
������ģ���Ŀ�ġ�  �����Թ���������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "Date.hpp"

#include <iostream>
#include "Date.hpp"
#include <fstream>
#include <utility>

using namespace std;

unsigned int Date::MaxYear = 9999u;//������
unsigned int Date::MinYear = 1900u;//��С���
unsigned int Date::DaysInMonth[2][12] = { {31,28,31,20,31,30,31,31,30,31,30,31},
	{31,29,31,20,31,30,31,31,30,31,30,31} };//ÿ������

/*************************************************************************
���������ơ�Date
���������ܡ�ʵ�����ڵĳ�ʼ��
��������unsigned int Year, unsigned int Month, unsigned int Day
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�Date
���������ܡ����ڵĿ������캯��
��������const Date& Source
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Date::Date(const Date& Source) :
	Year(m_Year), Month(m_Month), Day(m_Day)
{
	m_Year = Source.m_Year;
	m_Month = Source.m_Month;
	m_Day = Source.m_Day;
}

/*************************************************************************
���������ơ�Set
���������ܡ���������
��������unsigned int Year, unsigned int Month, unsigned int Day
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::Set(unsigned int Year, unsigned int Month, unsigned int Day) 
{
	return SetYear(Year) && SetMonth(Month) && SetDay(Day);
}

/*************************************************************************
���������ơ�SetYear
���������ܡ��������ڵ����
��������unsigned int Year
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::SetYear(unsigned int Year) 
{
	bool IsRight = (MinYear <= Year) && (Year <= MaxYear);//�ж�����Ƿ�Խ��
	m_Year = IsRight ? Year : m_Year;
	return IsRight;
}

/*************************************************************************
���������ơ�SetMonth
���������ܡ��������ڵ��·�
��������unsigned int Month
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::SetMonth(unsigned int Month)
{
	bool IsRight = (1 <= Month) && (Month <= 12);//�ж��·��Ƿ�Խ��
	m_Month = IsRight ? Month : m_Month;
	return IsRight;
}

/*************************************************************************
���������ơ�SetDay
���������ܡ��������ڵ���
��������unsigned int Day
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::SetDay(unsigned int Day)
{
	bool IsRight = (1 <= Day) && ( Day <= DaysInMonth[static_cast<int>( IsLeapYear(Year) )][Month - 1] );
	//�ж����Ƿ�Խ��
	m_Day = IsRight ? Day : m_Day;
	return IsRight;
}

/*************************************************************************
���������ơ�IsLeapYear
���������ܡ��ж��Ƿ�Ϊ����
��������unsigned int Year
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::IsLeapYear(unsigned int Year)
{
	return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

/*************************************************************************
���������ơ�IsLeapYear
���������ܡ��ж��Ƿ�Ϊ����
��������const Date& Source
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::IsLeapYear(const Date& Source) 
{
	return IsLeapYear(Source.m_Year);
}

/*************************************************************************
���������ơ�IsLeapYear
���������ܡ��ж��Ƿ�Ϊ����
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::IsLeapYear() const 
{
	return IsLeapYear(m_Year);
}

/*************************************************************************
���������ơ�IsValidDate
���������ܡ��ж������Ƿ� ��Ч
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::IsValidDate() const 
{
	return IsValidDate(Year, Month, Day);
}

/*************************************************************************
���������ơ�IsValidDate
���������ܡ��ж������Ƿ���Ч
��������unsigned int Year, unsigned int Month, unsigned int Day
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�SetRange
���������ܡ����������ݺ���С�������
��������unsigned int maxyear, unsigned int minyear
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Date::SetRange(unsigned int maxyear, unsigned int minyear)
{
	MaxYear = maxyear;
	MinYear = minyear;
}

/*************************************************************************
���������ơ�operator>
���������ܡ�>����������أ����ڱȽ�����
��������const Date& aDate
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::operator> (const Date& aDate) const
{
	return (this->CountDay()) > aDate.CountDay();
}

/*************************************************************************
���������ơ�operator<
���������ܡ�<����������أ����ڱȽ�����
��������const Date& aDate
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::operator< (const Date& aDate) const
{
	return ( this->CountDay() ) < aDate.CountDay();
}

/*************************************************************************
���������ơ�operator>=
���������ܡ�>=����������أ����ڱȽ�����
��������const Date& aDate
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::operator>= (const Date& aDate) const
{
	return (this->CountDay()) >= aDate.CountDay();
}

/*************************************************************************
���������ơ�operator<=
���������ܡ�<=����������أ����ڱȽ�����
��������const Date& aDate
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::operator<= (const Date& aDate) const
{
	return (this->CountDay()) <= aDate.CountDay();
}

/*************************************************************************
���������ơ�operator==
���������ܡ�==����������أ����ڱȽ�����
��������const Date& aDate
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::operator== (const Date& aDate) const
{
	return (this->CountDay()) == aDate.CountDay();
}

/*************************************************************************
���������ơ�operator!=
���������ܡ�!=����������أ����ڱȽ�����
��������const Date& aDate
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Date::operator!= (const Date& aDate) const
{
	return (this->CountDay()) != aDate.CountDay();
}

/*************************************************************************
���������ơ�operator=
���������ܡ�=����������أ��������ڸ�ֵ
��������const Date& Source
������ֵ��Date&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�operator+
���������ܡ�+����������أ�������������
��������const Date& Source
������ֵ��Date&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�operator-
���������ܡ�-����������أ�������������
��������const Date& Source
������ֵ��long long
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
long long Date::operator-(const Date& Source) const
{
	return (CountDay(*this) - CountDay(Source));
}

/*************************************************************************
���������ơ�CountDay
���������ܡ�����ĳһ���ڵ���׼�յ�������
��������const Date& Source
������ֵ��unsigned int
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
unsigned int Date::CountDay(const Date& Source) {
	int Array[12] = { 0,1,-1,0,0,1,1,2,3,3,4,4 };//֮��ÿ�¾�Ϊ30����㣬�ʶ�������Ϊÿ���·ݲ���ܲ
	unsigned int count(0);
	int leap = (Source.m_Year - 1) / 4 - (Source.m_Year - 1) / 100 + (Source.m_Year - 1) / 400;
	int unleap = Source.m_Year - leap - 1;
	count = unleap * 365 + leap * 366 + (Source.m_Month - 1) * 30 + Array[Source.m_Month - 1] + Source.m_Day;
	if (IsLeapYear(Source.m_Year)) count++;//������������꣬��Ҫ�ټ�һ��
	return count;
}

/*************************************************************************
���������ơ�CountDay
���������ܡ�����ĳһ���ڵ���׼�յ�������
����������
������ֵ��unsigned int
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
unsigned int Date::CountDay() const
{
	return CountDay(*this);
}

/*************************************************************************
���������ơ�operator<<
���������ܡ�<<��������أ������������
��������ostream& Stream, const Date& aDate
������ֵ��ostream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ostream& operator<<(ostream& Stream, const Date& aDate)
{
	Stream << aDate.Year << ' ' << aDate.Month << ' ' << aDate.Day << ' ';
	return Stream;
}

/*************************************************************************
���������ơ�operator>>
���������ܡ�<<��������أ�������������
��������istream& Stream, Date& aDate
������ֵ��istream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�~Date
���������ܡ����������������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Date::~Date() {}