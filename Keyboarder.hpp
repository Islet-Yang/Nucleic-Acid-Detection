
/*************************************************************************
【文件名】Keyboarder.hpp
【功能模块和目的】  储存结果录入员信息
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef KEYBOARDER_HPP
#define KEYBOARDER_HPP

#include "Subject.hpp"
#include "Tube.hpp"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

/*************************************************************************
【类名】Keyboarder
【功能】用于储存结果录入员的信息
【接口说明】InputSharedptr:用于向vector容器中储存信息
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
*************************************************************************/
class Keyboarder : public Subject
{
public:
	Keyboarder(const string& Name, const string& Password, const string& ID, const string& Result);
	virtual ~Keyboarder();

	bool IsKeyboarder() const override;
	void InputSharedptr(shared_ptr <Keyboarder> ptr);
	static shared_ptr <Keyboarder> KeyboarderFinder(const string& ID);

private:
	static vector <shared_ptr<Keyboarder>> m_Keyboarder;
};

#endif /*Keyboarder_hpp*/
