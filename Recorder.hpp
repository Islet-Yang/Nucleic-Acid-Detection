
/*************************************************************************
【文件名】Recorder.hpp
【功能模块和目的】  储存现场记录员信息
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
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
【类名】Recorder
【功能】用于储存现场记录员的信息
【接口说明】InputSharedptr：用于向vector容器中加入信息
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn）
【更改记录】
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
