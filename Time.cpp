
/*************************************************************************
���ļ�����Time.cpp
������ģ���Ŀ�ġ�  �����Թ���������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "Time.hpp"
#include <stdexcept>
#include <fstream>

/*************************************************************************
���������ơ�Time
���������ܡ�Time�๹�캯��
��������unsigned int Hour, unsigned int Minute, unsigned int Second
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second) : Hour(m_Hour), Minute(m_Minute), Second(m_Second) 
{
    SetTime(Hour, Minute, Second);
}

/*************************************************************************
���������ơ�Time
���������ܡ�Time�࿽�����캯��
��������const Time& aTime
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Time::Time(const Time& aTime) : Hour(m_Hour), Minute(m_Minute), Second(m_Second)
{
    SetTime(aTime.Hour, aTime.Minute, aTime.Second);
}

/*************************************************************************
���������ơ�operator=
���������ܡ���ֵ��������أ�����ʱ�丳ֵ
��������const Time& aTime
������ֵ��Time&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�~Time
���������ܡ�Time����������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Time::~Time(){}

/*************************************************************************
���������ơ�SetTime
���������ܡ��趨ʱ��
��������unsigned int Hour, unsigned int Minute, unsigned int Second
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Time::SetTime(unsigned int Hour, unsigned int Minute, unsigned int Second) 
{
    SetHour(Hour);
    SetMinute(Minute);
    SetSecond(Second);
}

/*************************************************************************
���������ơ�SetHour
���������ܡ��趨Сʱ
��������unsigned int Hour
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�SetMinute
���������ܡ��趨����
��������unsigned int Minute
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
���������ơ�SetSecond
���������ܡ��趨��
��������unsigned int Second
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Time::SetSecond(unsigned int Second) {
    if (Second >= 60)
    {
        throw invalid_argument("Second invalid");
    }

    m_Second = Second;
}

/*************************************************************************
���������ơ�CountSecond
���������ܡ������ڵ�ǰһ���й�ȥ������
����������
������ֵ��unsigned int
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
unsigned int Time::CountSecond() const
{
    return m_Hour * 3600 + m_Minute * 60 + m_Second;//һ�쾭������
}

/*************************************************************************
���������ơ�CountSecond
���������ܡ������ڵ�ǰһ���й�ȥ������
��������const Time& aTime
������ֵ��unsigned int
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
unsigned int Time::CountSecond(const Time& aTime)
{
    return aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator>
���������ܡ�>��������أ�����ʱ��Ƚ�
��������const Time& aTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Time::operator> (const Time& aTime) const
{
    return (this->CountSecond() ) > aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator<
���������ܡ�<��������أ�����ʱ��Ƚ�
��������const Time& aTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Time::operator< (const Time& aTime) const
{
    return (this->CountSecond()) < aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator<=
���������ܡ�<=��������أ�����ʱ��Ƚ�
��������const Time& aTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Time::operator<= (const Time& aTime) const
{
    return (this->CountSecond()) <= aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator>=
���������ܡ�>=��������أ�����ʱ��Ƚ�
��������const Time& aTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Time::operator>= (const Time& aTime) const
{
    return (this->CountSecond()) >= aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator==
���������ܡ�==��������أ�����ʱ��Ƚ�
��������const Time& aTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Time::operator== (const Time& aTime) const
{
    return (this->CountSecond()) == aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator!=
���������ܡ�!=��������أ�����ʱ��Ƚ�
��������const Time& aTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Time::operator!= (const Time& aTime) const
{
    return (this->CountSecond()) != aTime.CountSecond();
}

/*************************************************************************
���������ơ�operator-
���������ܡ�-��������أ�����ʱ��������
��������const Time& aTime
������ֵ��long long
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
long long Time::operator-(const Time& aTime) const 
{
    return static_cast<long long>(CountSecond()) - static_cast<long long>(aTime.CountSecond());
}

/*************************************************************************
���������ơ�operator<<
���������ܡ�<<��������أ�����ʱ�����
��������ostream& Stream, const Time& aTime
������ֵ��ostream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ostream& operator<<(ostream& Stream, const Time& aTime) 
{
    Stream << aTime.Hour << ':' << aTime.Minute << ':' << aTime.Second;
    return Stream;
}

/*************************************************************************
���������ơ�operator>>
���������ܡ�>>��������أ�����ʱ������
��������istream& Stream, Time& aTime
������ֵ��istream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
istream& operator>>(istream& Stream, Time& aTime)
{
    char Temp;
    Stream >> aTime.m_Hour >> Temp >> aTime.m_Minute >> Temp >> aTime.m_Second;
    return Stream;
}