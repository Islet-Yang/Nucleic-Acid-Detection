
/*************************************************************************
���ļ�����Time.hpp
������ģ���Ŀ�ġ�  �����Թ���������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
using namespace std;

/*************************************************************************
��������Time
�����ܡ��ṩ������ʱ�������������������Ҫʵ���Թܵĳ���ʱ���ʾ
���ӿ�˵����
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class Time
{
public:
	const unsigned int& Hour;
	const unsigned int& Minute;
	const unsigned int& Second;

	Time(unsigned int Hour = 0, unsigned int Minute = 0, unsigned int Second = 0);
	Time(const Time& aTime);
	Time& operator=(const Time& aTime);
	virtual ~Time();

	void SetTime(unsigned int Hour, unsigned int Minute, unsigned int Second);
	void SetHour(unsigned int Hour);
	void SetMinute(unsigned int Minute);
	void SetSecond(unsigned int Second);

	unsigned int CountSecond() const;
	static unsigned int CountSecond(const Time& aTime);
	bool operator> (const Time& aTime) const;
	bool operator< (const Time& aTime) const;
	bool operator>=(const Time& aTime) const;
	bool operator<=(const Time& aTime) const;
	bool operator==(const Time& aTime) const;
	bool operator!=(const Time& aTime) const;
	long long operator-(const Time& aTime) const;

	friend ostream& operator<<(ostream& Stream, const Time& aTime);
	friend istream& operator>>(istream& Stream, Time& aTime);

private:
	unsigned int m_Hour;
	unsigned int m_Minute;
	unsigned int m_Second;
};

#endif /*Time_hpp*/
