
/*************************************************************************
【文件名】Administartor.cpp
【功能模块和目的】  指定现场记录员和结果录入员，储存管理员信息
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#include "Administrator.hpp"
#include "Recorder.hpp"
#include "Keyboarder.hpp"
#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

/*************************************************************************
【函数名称】  Administrator     
【函数功能】  初始化管理员    
【参数】const string& Name, const string& Password, const string& ID,const string& Result 
【返回值】   无      
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】       
*************************************************************************/
Administrator::Administrator(const string& Name, const string& Password, const string& ID, const string& Result):
	Subject(Name, Password, ID,Result){}

/*************************************************************************
【函数名称】IsAdministrator
【函数功能】确定是否为管理员
【参数】无
【返回值】bool
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
bool Administrator::IsAdministrator() const
{
	return true;
}

/*************************************************************************
【函数名称】~Administrator
【函数功能】Administrator类的析构函数
【参数】无
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
Administrator::~Administrator() {}

/*************************************************************************
【函数名称】AdministratorFinder
【函数功能】用来查找所属ID是否为管理员
【参数】const string& ID
【返回值】shared_ptr<Administrator>
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
shared_ptr <Administrator> Administrator::AdministratorFinder(const string& ID)
{
	auto AdminFinder = [&ID](shared_ptr <Administrator>ptr)->bool { return ( ptr->VerifyID(ID) ); };
	auto iteradmin = find_if(m_Admin.begin(), m_Admin.end(), AdminFinder);
	if (iteradmin != m_Admin.end())
	{
		return *iteradmin;//找到管理员，返回其指针
	}
	else
	{
		return nullptr;//未找到管理员，返回空指针
	}
}

/*************************************************************************
【函数名称】ReadAdministrator
【函数功能】用于读取文件以确定管理员
【参数】const string& FileName
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Administrator::ReadAdministrator(const string& FileName)
{
	ifstream File(FileName, ios_base::in);
	if (!File)
	{
		cerr << "Failed to open the information file.";//未能打开文件，退出程序
		exit(1);
	}

	m_Admin.clear();
	unsigned int AdminCount(0);//查看管理员人数
	File >> AdminCount;

	for (unsigned int i = 0; i < AdminCount; i++)
	{
		string Name;
		string Password;
		string ID;
		string Result;
		File >> (Name)
			>> (Password)
			>> (ID)
			>> (Result);
		shared_ptr <Administrator> pNewAdmin = 
			make_shared<Administrator>( Name,Password,ID,Result );//调用构造函数新建管理员
		
		m_Admin.push_back(pNewAdmin);
	}
}

/*************************************************************************
【函数名称】AppointRecorder
【函数功能】指定现场录入员
【参数】const string& RecorderID
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Administrator::AppointRecorder(const string& RecorderID) const
{
	shared_ptr <Recorder> pNewRecorder = make_shared<Recorder>
		(*AppointeeName(Search(RecorderID)), *AppointeePassword(Search(RecorderID)),
			RecorderID, *AppointeeResult(Search(RecorderID)) );//调用构造函数新建现场记录员

	pNewRecorder->InputSharedptr(pNewRecorder);

	delete AppointeeName(Search(RecorderID));
	delete AppointeePassword(Search(RecorderID));
	delete AppointeeResult(Search(RecorderID));
}

/*************************************************************************
【函数名称】AppointKeyboarder
【函数功能】指定结果录入员
【参数】const string& KeyboarderID
【返回值】无
【开发者及日期】   杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/
void Administrator::AppointKeyboarder(const string& KeyboarderID) const
{
	shared_ptr <Keyboarder> pNewKeyboarder = make_shared<Keyboarder>
		(*AppointeeName(Search(KeyboarderID)), *AppointeePassword(Search(KeyboarderID)),
			KeyboarderID, *AppointeeResult(Search(KeyboarderID)));//调用构造函数新建信息录入员

	pNewKeyboarder->InputSharedptr(pNewKeyboarder);

	delete AppointeeName(Search(KeyboarderID));
	delete AppointeePassword(Search(KeyboarderID));
	delete AppointeeResult(Search(KeyboarderID));
}

vector<shared_ptr<Administrator>> Administrator::m_Admin = {};