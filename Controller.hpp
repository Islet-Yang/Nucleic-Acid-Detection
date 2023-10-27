
/*************************************************************************
【文件名】Controller.hpp
【功能模块和目的】  与用户进行交互，有登录、注册以及特殊人员登录功能实现的作用
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "View.hpp"
#include "Administrator.hpp"
#include "Recorder.hpp"
#include "Keyboarder.hpp"
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

/*************************************************************************
【类名】             Controller
【功能】             与用户进行交互，解耦界面类与可重用类
【接口说明】         
	Load:运行初始加载文件
	NewSubjectRegister:新用户注册
	Login:用户登录
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】         
*************************************************************************/

class Controller
{
public:
	Controller(View& view);

	void Load() const;
	void NewSubjectRegister() const;
	void Login() const;
	void AdministratorLogIn(shared_ptr <Administrator> pAdmin) const;
	void RecorderLogIn(shared_ptr <Recorder> pRecorder) const;
	void KeyboarderLogIn(shared_ptr <Keyboarder> pKeyboarder) const;

private:
	View m_view;
};

#endif /*Controller.hpp*/
