
/*************************************************************************
【文件名】Recorder.cpp
【功能模块和目的】  储存现场记录员信息
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Recorder.hpp"
#include "Tube.hpp"
#include <vector>
#include <memory>

using namespace std;

/*************************************************************************
【函数名称】Recorder
【函数功能】初始化Recorder
【参数】const string& Name, const string& Password, const string& ID, const string& Result
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Recorder::Recorder(const string& Name, const string& Password, const string& ID, const string& Result) :
	Subject(Name, Password, ID, Result) {}

/*************************************************************************
【函数名称】~Recorder
【函数功能】Recorder析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Recorder::~Recorder(){}

/*************************************************************************
【函数名称】IsRecorder
【函数功能】标注身份为现场记录员
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Recorder::IsRecorder() const
{
	return true;
}

/*************************************************************************
【函数名称】InputSharedptr
【函数功能】向vector容器中添加新的现场记录员
【参数】shared_ptr<Recorder> ptr
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Recorder::InputSharedptr(shared_ptr<Recorder> ptr)
{
	m_Recorder.push_back(ptr);
}

/*************************************************************************
【函数名称】RecorderFinder
【函数功能】通过查找ID判断是否为现场记录员
【参数】const string& ID
【返回值】shared_ptr<Recorder>
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
shared_ptr<Recorder> Recorder::RecorderFinder(const string& ID)
{
	auto RecorderFinder = [&ID](shared_ptr <Recorder>ptr)->bool { return (ptr->VerifyID(ID)); };
	auto iterrecorder = find_if(m_Recorder.begin(), m_Recorder.end(), RecorderFinder);
	if (iterrecorder != m_Recorder.end())
	{
		return *iterrecorder;//查到为现场记录员，则返回其指针
	}
	else
	{
		return nullptr;//没查到，返回空指针
	}
}

vector<shared_ptr<Recorder>> Recorder::m_Recorder = {};

