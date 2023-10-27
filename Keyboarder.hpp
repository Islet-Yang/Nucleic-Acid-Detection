
/*************************************************************************
���ļ�����Keyboarder.hpp
������ģ���Ŀ�ġ�  ������¼��Ա��Ϣ
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
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
��������Keyboarder
�����ܡ����ڴ�����¼��Ա����Ϣ
���ӿ�˵����InputSharedptr:������vector�����д�����Ϣ
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
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
