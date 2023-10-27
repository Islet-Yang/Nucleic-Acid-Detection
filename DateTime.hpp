
/*************************************************************************
【文件名】DateTime.hpp
【功能模块和目的】  处理试管生产日期
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "Time.hpp"
#include "Date.hpp"
#include <iostream>
#include <utility>

using namespace std;


/*************************************************************************
【类名】DateTime
【功能】继承于Date和Time，完成完整日期+时间的描述
【接口说明】
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
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

