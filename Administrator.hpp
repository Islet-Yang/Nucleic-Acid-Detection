
/*************************************************************************
【文件名】Administartor.hpp                 
【功能模块和目的】  指定现场记录员和结果录入员，储存管理员信息       
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】               
*************************************************************************/

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Subject.hpp"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

/*************************************************************************
【类名】  Administrator           
【功能】  继承于Subject类，用于储存管理员数据并为完成管理员的操作提供借口           
【接口说明】
AppointRecorder:完成任命现场记录员
AppointKeyboarder:完成任命结果录入员
【开发者及日期】  杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】         
*************************************************************************/

class Administrator :public Subject
{
public:
	Administrator(const string& Name, const string& Password,
		const string& ID, const string& Result);
	virtual ~Administrator();
	bool IsAdministrator()const  override;

	using Subject::Add;
	using Subject::Delete;

	static shared_ptr<Administrator> AdministratorFinder(const string& ID);
	static void ReadAdministrator(const string& FileName);

	void AppointRecorder(const string& RecorderID) const;
	void AppointKeyboarder(const string& KeyboarderID) const;
private:
	static vector< shared_ptr<Administrator> > m_Admin;
};

#endif /*Administrator_hpp*/