
/*************************************************************************
���ļ�����Administartor.hpp                 
������ģ���Ŀ�ġ�  ָ���ֳ���¼Ա�ͽ��¼��Ա���������Ա��Ϣ       
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��               
*************************************************************************/

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Subject.hpp"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

/*************************************************************************
��������  Administrator           
�����ܡ�  �̳���Subject�࣬���ڴ������Ա���ݲ�Ϊ��ɹ���Ա�Ĳ����ṩ���           
���ӿ�˵����
AppointRecorder:��������ֳ���¼Ա
AppointKeyboarder:����������¼��Ա
�������߼����ڡ�  �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��         
*************************************************************************/

class Administrator :public Subject
{
public:
	Administrator(const string& Name, const string& Password,
		const string& ID, const string& Result);
	virtual ~Administrator();
	bool IsAdministrator()const  override;

	using Subject::Add;
	using Subject::Delete;

	static shared_ptr<Administrator> AdministratorFinder(const string& ID);
	static void ReadAdministrator(const string& FileName);

	void AppointRecorder(const string& RecorderID) const;
	void AppointKeyboarder(const string& KeyboarderID) const;
private:
	static vector< shared_ptr<Administrator> > m_Admin;
};

#endif /*Administrator_hpp*/