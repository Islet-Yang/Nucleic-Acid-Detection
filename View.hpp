
/*************************************************************************
【文件名】View.hpp
【功能模块和目的】  作为界面类，利用cout函数在控制台上搭建简易界面
【开发者及日期】           杨邦霁（ybj21@mails.tsinghua.edu.cn） 2022.7.15
【更改记录】
*************************************************************************/

#ifndef VIEW_HPP
#define VIEW_HPP
#include <string>

using namespace std;

/*************************************************************************
【类名】             View
【功能】             界面设计，实现用控制台实现简单界面
【接口说明】         均为借口，利用std::cout进行交互
【开发者及日期】     杨邦霁（ybj21@mails.tsinghua.edu.cn)
【更改记录】         
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
