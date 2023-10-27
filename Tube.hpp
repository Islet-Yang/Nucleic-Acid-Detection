
/*************************************************************************
���ļ�����Tube.hpp
������ģ���Ŀ�ġ�  ���������Թ���Ϣ�����ֳ���¼Ա�ͽ��¼��Ա���й�������Ϣ������
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#ifndef TUBE_HPP
#define TUBE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <memory>
#include <stdexcept>
#include "Subject.hpp"
#include "DateTime.hpp"

using namespace std;

/*************************************************************************
��������Tube
�����ܡ����ڴ����Թ���Ϣ��ͬʱʵ�����ֳ���¼Ա�����¼��Աʵ�ֹ��ܽ���
���ӿ�˵����
InputSharedptr:������vector�����������Ϣ
VerifySerialNumber:������ˮ��
SaveToDocument:�������д���ļ�
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn��
�����ļ�¼��
*************************************************************************/
class ExceptionWrongSerialNumber :public invalid_argument
{
public:
	ExceptionWrongSerialNumber();
};

class Tube
{
public:
	Tube(const Tube& aTube) = delete;
	Tube& operator=(const Tube& aTube) = delete;

	Tube(unsigned int Year, unsigned int Month, unsigned int Day, 
		unsigned int Hour, unsigned int Minute, unsigned int Second,
		unsigned int SerialNumber, unsigned int Count, string Result="δ��");
	~Tube();

	void InputID(const string& ID, unsigned int number);
	void InputSharedptr(shared_ptr <Tube> ptr);
	bool VerifySerialNumber(const string& SerialNumber) const;
	static shared_ptr <Tube> SaveToDocument(const string& SerialNumber, const string& Result, const string& DocumentName);
	string* TransmitID(unsigned int i) const;

	friend ostream& operator<< (ostream& Stream, const Tube& aTube);
	friend istream& operator>>(istream& Stream, const Tube& aTube);
	
private:
	string m_SerialNumber;
	string m_TubeResult;
	unsigned int m_SubjectCount;
	DateTime m_DateOfManufacture;
	array<string, 10> m_Include;

	static vector<shared_ptr<Tube>> m_Tube;
};

#endif /*Tube_hpp*/
