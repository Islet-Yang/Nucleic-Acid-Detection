
/*************************************************************************
���ļ�����Date.hpp
������ģ���Ŀ�ġ�  �����Թ���������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <fstream>

using namespace std;

/*************************************************************************
��������Date
�����ܡ��ṩ���������ڲ����������ڱ����������Թܳ���ʱ���¼
���ӿ�˵����
CountDay�����ڼ���������֮��
IsLeapYear�������ж��Ƿ�Ϊ����
IsValidDate�������ж������Ƿ���Ч
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
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