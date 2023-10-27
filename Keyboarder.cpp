
/*************************************************************************
���ļ�����Keyboarder.cpp
������ģ���Ŀ�ġ�  ������¼��Ա��Ϣ
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "Keyboarder.hpp"
#include "Tube.hpp"
#include <fstream>


using namespace std;

/*************************************************************************
���������ơ�Keyboarder
���������ܡ���ʼ��Keyboarder
��������const string& Name, const string& Password, const string& ID, const string& Result
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Keyboarder::Keyboarder(const string& Name, const string& Password, const string& ID, const string& Result) :
	Subject(Name, Password, ID, Result){}

/*************************************************************************
���������ơ�~Keyboarder
���������ܡ�Keyboarder����������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Keyboarder::~Keyboarder() {}

/*************************************************************************
���������ơ�IsKeyboarder
���������ܡ���ע���Ϊ���¼��Ա
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Keyboarder::IsKeyboarder() const 
{
	return true;
}

/*************************************************************************
���������ơ�InputSharedptr
���������ܡ�������vector�����м����µĽ��¼��Ա
��������shared_ptr<Keyboarder> ptr
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Keyboarder::InputSharedptr(shared_ptr<Keyboarder> ptr)
{
	m_Keyboarder.push_back(ptr);
}

/*************************************************************************
���������ơ�KeyboarderFinder
���������ܡ�ͨ�����֤�Ų����û��Ƿ�Ϊ���¼��Ա
��������const string& ID
������ֵ��shared_ptr<Keyboarder>
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
shared_ptr<Keyboarder> Keyboarder::KeyboarderFinder(const string& ID)
{
	auto KeyboarderFinder = [&ID](shared_ptr <Keyboarder>ptr)->bool { return (ptr->VerifyID(ID)); };
	auto iterkeyboarder = find_if(m_Keyboarder.begin(), m_Keyboarder.end(), KeyboarderFinder);
	if (iterkeyboarder != m_Keyboarder.end())
	{
		return *iterkeyboarder;//�鵽�ǽ��¼��Ա���򷵻���ָ��
	}
	else
	{
		return nullptr;//û�鵽�����ؿ�ָ��
	}
}

vector<shared_ptr<Keyboarder>> Keyboarder::m_Keyboarder = {};
