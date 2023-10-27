
/*************************************************************************
���ļ�����Recorder.cpp
������ģ���Ŀ�ġ�  �����ֳ���¼Ա��Ϣ
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#include "Recorder.hpp"
#include "Tube.hpp"
#include <vector>
#include <memory>

using namespace std;

/*************************************************************************
���������ơ�Recorder
���������ܡ���ʼ��Recorder
��������const string& Name, const string& Password, const string& ID, const string& Result
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Recorder::Recorder(const string& Name, const string& Password, const string& ID, const string& Result) :
	Subject(Name, Password, ID, Result) {}

/*************************************************************************
���������ơ�~Recorder
���������ܡ�Recorder��������
����������
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
Recorder::~Recorder(){}

/*************************************************************************
���������ơ�IsRecorder
���������ܡ���ע���Ϊ�ֳ���¼Ա
����������
������ֵ��bool
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
bool Recorder::IsRecorder() const
{
	return true;
}

/*************************************************************************
���������ơ�InputSharedptr
���������ܡ���vector����������µ��ֳ���¼Ա
��������shared_ptr<Recorder> ptr
������ֵ����
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
void Recorder::InputSharedptr(shared_ptr<Recorder> ptr)
{
	m_Recorder.push_back(ptr);
}

/*************************************************************************
���������ơ�RecorderFinder
���������ܡ�ͨ������ID�ж��Ƿ�Ϊ�ֳ���¼Ա
��������const string& ID
������ֵ��shared_ptr<Recorder>
�������߼����ڡ�   �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/
shared_ptr<Recorder> Recorder::RecorderFinder(const string& ID)
{
	auto RecorderFinder = [&ID](shared_ptr <Recorder>ptr)->bool { return (ptr->VerifyID(ID)); };
	auto iterrecorder = find_if(m_Recorder.begin(), m_Recorder.end(), RecorderFinder);
	if (iterrecorder != m_Recorder.end())
	{
		return *iterrecorder;//�鵽Ϊ�ֳ���¼Ա���򷵻���ָ��
	}
	else
	{
		return nullptr;//û�鵽�����ؿ�ָ��
	}
}

vector<shared_ptr<Recorder>> Recorder::m_Recorder = {};

