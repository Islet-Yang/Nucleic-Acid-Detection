
/*************************************************************************
���ļ�����Recorder.hpp
������ģ���Ŀ�ġ�  �����ֳ���¼Ա��Ϣ
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#ifndef RECORDER_HPP
#define RECORDER_HPP

#include "Subject.hpp"
#include "Tube.hpp"
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

/*************************************************************************
��������Recorder
�����ܡ����ڴ����ֳ���¼Ա����Ϣ
���ӿ�˵����InputSharedptr��������vector�����м�����Ϣ
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class Recorder :public Subject
{
public:
	Recorder(const string& Name, const string& Password, const string& ID, const string& Result);
	virtual ~Recorder();
	bool IsRecorder() const override;

	using Subject::Add;
	using Subject::Delete;

	void InputSharedptr(shared_ptr <Recorder> ptr);
	static shared_ptr <Recorder> RecorderFinder(const string& ID);

private:
	static vector <shared_ptr<Recorder>> m_Recorder;
};

#endif /*Recorder_hpp*/
