
/*************************************************************************
���ļ�����Controller.hpp
������ģ���Ŀ�ġ�  ���û����н������е�¼��ע���Լ�������Ա��¼����ʵ�ֵ�����
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
��������             Controller
�����ܡ�             ���û����н�����������������������
���ӿ�˵����         
	Load:���г�ʼ�����ļ�
	NewSubjectRegister:���û�ע��
	Login:�û���¼
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��         
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
