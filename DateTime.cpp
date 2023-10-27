
/*************************************************************************
���ļ�����DateTime.cpp
������ģ���Ŀ�ġ�  �����Թ���������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "DateTime.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*************************************************************************
���������ơ�DateTime
���������ܡ���ʼ��DateTime
��������unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
DateTime::DateTime(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second) 
	: Date(Year, Month, Day), Time(Hour, Minute, Second) {}

/*************************************************************************
���������ơ�DateTime
���������ܡ�DateTime��Ŀ������캯��
��������const Date& aDate, const Time& aTime
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
DateTime::DateTime(const Date& aDate, const Time& aTime) 
	: Date(aDate), Time(aTime) {}

/*************************************************************************
���������ơ�~DateTime
���������ܡ�DateTime��������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
DateTime::~DateTime(){}

/*************************************************************************
���������ơ�operator  >
���������ܡ�>��������أ���������ʱ��ıȽ�
��������const DateTime& aDateTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool DateTime::operator  >(const DateTime& aDateTime) const
{
	return (this->Date::operator>(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator>(aDateTime));
}

/*************************************************************************
���������ơ�operator  <
���������ܡ�<��������أ���������ʱ��ıȽ�
��������const DateTime& aDateTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool DateTime::operator  <(const DateTime& aDateTime) const
{
	return (this->Date::operator<(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator<(aDateTime));
}

/*************************************************************************
���������ơ�operator  >=
���������ܡ�>=��������أ���������ʱ��ıȽ�
��������const DateTime& aDateTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool DateTime::operator  >=(const DateTime& aDateTime) const
{
	return (this->Date::operator>(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator>=(aDateTime));
}

/*************************************************************************
���������ơ�operator  <=
���������ܡ�<=��������أ���������ʱ��ıȽ�
��������const DateTime& aDateTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool DateTime::operator  <=(const DateTime& aDateTime) const
{
	return (this->Date::operator<(aDateTime)) || (this->Date::operator==(aDateTime) && this->Time::operator<=(aDateTime));
}

/*************************************************************************
���������ơ�operator  ==
���������ܡ�==��������أ���������ʱ��ıȽ�
��������const DateTime& aDateTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool DateTime::operator ==(const DateTime& aDateTime) const
{
	return (this->Date::operator==(aDateTime)) && (this->Time::operator==(aDateTime));
}

/*************************************************************************
���������ơ�operator  !=
���������ܡ�!=��������أ���������ʱ��ıȽ�
��������const DateTime& aDateTime
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool DateTime::operator !=(const DateTime& aDateTime) const
{
	return (this->Date::operator!=(aDateTime)) || (this->Time::operator!=(aDateTime));
}

/*************************************************************************
���������ơ�operator-
���������ܡ�-��������أ���������ʱ�������
��������const DateTime& aDateTime
������ֵ��long long
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
long long DateTime::operator-(const DateTime& aDateTime) const
{
	return this->Date::operator-(aDateTime) * 86400 + this->Time::operator-(aDateTime);
}

/*************************************************************************
���������ơ�operator<<
���������ܡ�<<��������أ��������ʱ������
��������ostream& Stream, const DateTime& aDateTime
������ֵ��ostream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
ostream& operator<<(ostream& Stream, const DateTime& aDateTime) 
{
	Stream << static_cast<const Date&>(aDateTime)
		       << ' '
		       << static_cast<const Time&>(aDateTime);
	return Stream;
}

/*************************************************************************
���������ơ�operator>>
���������ܡ�>>��������أ���������ʱ�������
��������istream& Stream, DateTime& aDateTime
������ֵ��istream&
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
istream& operator>>(istream& Stream, DateTime& aDateTime) 
{
	Stream >> static_cast<Date&>(aDateTime)
		       >> static_cast<Time&>(aDateTime);
	return Stream;
}
