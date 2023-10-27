
/*************************************************************************
【文件名】Time.cpp
【功能模块和目的】  处理试管生产日期
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Time.hpp"
#include <stdexcept>
#include <fstream>

/*************************************************************************
【函数名称】Time
【函数功能】Time类构造函数
【参数】unsigned int Hour, unsigned int Minute, unsigned int Second
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second) : Hour(m_Hour), Minute(m_Minute), Second(m_Second) 
{
    SetTime(Hour, Minute, Second);
}

/*************************************************************************
【函数名称】Time
【函数功能】Time类拷贝构造函数
【参数】const Time& aTime
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Time::Time(const Time& aTime) : Hour(m_Hour), Minute(m_Minute), Second(m_Second)
{
    SetTime(aTime.Hour, aTime.Minute, aTime.Second);
}

/*************************************************************************
【函数名称】operator=
【函数功能】赋值运算符重载，用于时间赋值
【参数】const Time& aTime
【返回值】Time&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Time& Time::operator=(const Time& aTime) 
{
    if (this != &aTime) 
    {
        SetTime(aTime.Hour, aTime.Minute, aTime.Second);
    }
    return *this;
}

/*************************************************************************
【函数名称】~Time
【函数功能】Time类析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Time::~Time(){}

/*************************************************************************
【函数名称】SetTime
【函数功能】设定时间
【参数】unsigned int Hour, unsigned int Minute, unsigned int Second
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Time::SetTime(unsigned int Hour, unsigned int Minute, unsigned int Second) 
{
    SetHour(Hour);
    SetMinute(Minute);
    SetSecond(Second);
}

/*************************************************************************
【函数名称】SetHour
【函数功能】设定小时
【参数】unsigned int Hour
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Time::SetHour(unsigned int Hour) 
{
    if (Hour >= 24) 
    {
        throw invalid_argument("Hour invalid.");
    }

    m_Hour = Hour;
}

/*************************************************************************
【函数名称】SetMinute
【函数功能】设定分钟
【参数】unsigned int Minute
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Time::SetMinute(unsigned int Minute)
{
    if (Minute >= 60)
    {
        throw invalid_argument("Minute invalid");
    }

    m_Minute = Minute;
}

/*************************************************************************
【函数名称】SetSecond
【函数功能】设定秒
【参数】unsigned int Second
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Time::SetSecond(unsigned int Second) {
    if (Second >= 60)
    {
        throw invalid_argument("Second invalid");
    }

    m_Second = Second;
}

/*************************************************************************
【函数名称】CountSecond
【函数功能】计算在当前一天中过去的秒数
【参数】无
【返回值】unsigned int
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
unsigned int Time::CountSecond() const
{
    return m_Hour * 3600 + m_Minute * 60 + m_Second;//一天经过秒数
}

/*************************************************************************
【函数名称】CountSecond
【函数功能】计算在当前一天中过去的秒数
【参数】const Time& aTime
【返回值】unsigned int
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
unsigned int Time::CountSecond(const Time& aTime)
{
    return aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator>
【函数功能】>运算符重载，用于时间比较
【参数】const Time& aTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Time::operator> (const Time& aTime) const
{
    return (this->CountSecond() ) > aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator<
【函数功能】<运算符重载，用于时间比较
【参数】const Time& aTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Time::operator< (const Time& aTime) const
{
    return (this->CountSecond()) < aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator<=
【函数功能】<=运算符重载，用于时间比较
【参数】const Time& aTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Time::operator<= (const Time& aTime) const
{
    return (this->CountSecond()) <= aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator>=
【函数功能】>=运算符重载，用于时间比较
【参数】const Time& aTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Time::operator>= (const Time& aTime) const
{
    return (this->CountSecond()) >= aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator==
【函数功能】==运算符重载，用于时间比较
【参数】const Time& aTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Time::operator== (const Time& aTime) const
{
    return (this->CountSecond()) == aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator!=
【函数功能】!=运算符重载，用于时间比较
【参数】const Time& aTime
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Time::operator!= (const Time& aTime) const
{
    return (this->CountSecond()) != aTime.CountSecond();
}

/*************************************************************************
【函数名称】operator-
【函数功能】-运算符重载，用于时间相差计算
【参数】const Time& aTime
【返回值】long long
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
long long Time::operator-(const Time& aTime) const 
{
    return static_cast<long long>(CountSecond()) - static_cast<long long>(aTime.CountSecond());
}

/*************************************************************************
【函数名称】operator<<
【函数功能】<<运算符重载，用于时间输出
【参数】ostream& Stream, const Time& aTime
【返回值】ostream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
ostream& operator<<(ostream& Stream, const Time& aTime) 
{
    Stream << aTime.Hour << ':' << aTime.Minute << ':' << aTime.Second;
    return Stream;
}

/*************************************************************************
【函数名称】operator>>
【函数功能】>>运算符重载，用于时间输入
【参数】istream& Stream, Time& aTime
【返回值】istream&
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
istream& operator>>(istream& Stream, Time& aTime)
{
    char Temp;
    Stream >> aTime.m_Hour >> Temp >> aTime.m_Minute >> Temp >> aTime.m_Second;
    return Stream;
}