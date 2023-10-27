
/*************************************************************************
���ļ�����DateTime.hpp
������ģ���Ŀ�ġ�  �����Թ���������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "Time.hpp"
#include "Date.hpp"
#include <iostream>
#include <utility>

using namespace std;


/*************************************************************************
��������DateTime
�����ܡ��̳���Date��Time�������������+ʱ�������
���ӿ�˵����
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class DateTime :public Time,public Date
{
public:
	DateTime(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second);
	DateTime(const Date& aDate =Date(), const Time& aTime = Time());
    virtual ~DateTime();

    bool operator  >(const DateTime& aDateTime) const;
    bool operator  <(const DateTime& aDateTime) const;
    bool operator >=(const DateTime& aDateTime) const;
    bool operator <=(const DateTime& aDateTime) const;
    bool operator ==(const DateTime& aDateTime) const;
    bool operator !=(const DateTime& aDateTime) const;
    long long operator-(const DateTime& aDateTime) const;

    friend ostream& operator<<(ostream& Stream, const DateTime& aDateTime);
    friend istream& operator>>(istream& Stream, DateTime& aDateTime);

};

#endif /*DateTime_hpp*/

