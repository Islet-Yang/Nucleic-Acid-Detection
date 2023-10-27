
/*************************************************************************
���ļ�����View.hpp
������ģ���Ŀ�ġ�  ��Ϊ�����࣬����cout�����ڿ���̨�ϴ���׽���
�������߼����ڡ�           �������ybj21@mails.tsinghua.edu.cn�� 2022.7.15
�����ļ�¼��
*************************************************************************/

#ifndef VIEW_HPP
#define VIEW_HPP
#include <string>

using namespace std;

/*************************************************************************
��������             View
�����ܡ�             ������ƣ�ʵ���ÿ���̨ʵ�ּ򵥽���
���ӿ�˵����         ��Ϊ��ڣ�����std::cout���н���
�������߼����ڡ�     �������ybj21@mails.tsinghua.edu.cn)
�����ļ�¼��         
*************************************************************************/

class View
{
public:
	void ViewStart();
	void View1() const;
	void View2_1_1() const;
	void View2_1_2() const;
	void View2_2_1() const;
	void View2_2_2() const;
	void View2_3_1() const;
	void View2_3_2() const;

	void ViewError(const string& DocumentName) const;

	void View3_1() const;
	void View3_2() const;
	void View3_3() const;

	void View4_1() const;
	void View4_2_1() const;
	void View4_2_2() const;
	void View4_2_3() const;
	void View4_2_4() const;
	void View4_2_5() const;

	void View5_1() const;
	void View5_2() const;
	void View5_3() const;

	void View6_1() const;
	void View6_2() const;
	void View6_3() const;
	void View6_4(unsigned int i) const;
	void View6_5() const;

	void View7_1() const;
	void View7_2() const;

	void ViewEnd() const;
	void ViewExit() const;
	void ViewEndl() const;
};

#endif /*View.hpp*/
