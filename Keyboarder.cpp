
/*************************************************************************
【文件名】Keyboarder.cpp
【功能模块和目的】  储存结果录入员信息
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Keyboarder.hpp"
#include "Tube.hpp"
#include <fstream>


using namespace std;

/*************************************************************************
【函数名称】Keyboarder
【函数功能】初始化Keyboarder
【参数】const string& Name, const string& Password, const string& ID, const string& Result
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Keyboarder::Keyboarder(const string& Name, const string& Password, const string& ID, const string& Result) :
	Subject(Name, Password, ID, Result){}

/*************************************************************************
【函数名称】~Keyboarder
【函数功能】Keyboarder的析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Keyboarder::~Keyboarder() {}

/*************************************************************************
【函数名称】IsKeyboarder
【函数功能】标注身份为结果录入员
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Keyboarder::IsKeyboarder() const 
{
	return true;
}

/*************************************************************************
【函数名称】InputSharedptr
【函数功能】用来从vector容器中加入新的结果录入员
【参数】shared_ptr<Keyboarder> ptr
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Keyboarder::InputSharedptr(shared_ptr<Keyboarder> ptr)
{
	m_Keyboarder.push_back(ptr);
}

/*************************************************************************
【函数名称】KeyboarderFinder
【函数功能】通过身份证号查找用户是否为结果录入员
【参数】const string& ID
【返回值】shared_ptr<Keyboarder>
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
shared_ptr<Keyboarder> Keyboarder::KeyboarderFinder(const string& ID)
{
	auto KeyboarderFinder = [&ID](shared_ptr <Keyboarder>ptr)->bool { return (ptr->VerifyID(ID)); };
	auto iterkeyboarder = find_if(m_Keyboarder.begin(), m_Keyboarder.end(), KeyboarderFinder);
	if (iterkeyboarder != m_Keyboarder.end())
	{
		return *iterkeyboarder;//查到是结果录入员，则返回其指针
	}
	else
	{
		return nullptr;//没查到，返回空指针
	}
}

vector<shared_ptr<Keyboarder>> Keyboarder::m_Keyboarder = {};
