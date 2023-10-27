
/*************************************************************************
【文件名】Time.hpp
【功能模块和目的】  处理试管生产日期
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
using namespace std;

/*************************************************************************
【类名】Time
【功能】提供基本的时间操作函数，本程序主要实现试管的出场时间表示
【接口说明】
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
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
