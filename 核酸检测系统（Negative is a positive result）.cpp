#include <iostream>
#include<string>
#include <stdexcept>

#include "View.hpp"
#include "Controller.hpp"

using namespace std;

int main()
{
	View myview;
	Controller mycontroller(myview);
	int choice;
	char mainswitch = '7';

	mycontroller.Load();
	myview.ViewStart();
	
	while (mainswitch != '0')
	{
		
		myview.View1();
		cin >> choice;

		switch (choice)
		{
			case 0 :
			{
				mycontroller.NewSubjectRegister();
				break;
			}//选择0，新用户注册
			case 1 :
			{
				mycontroller.Login();
				break;
			}//选择1，用户登录
			default :
			{
				break;
			}

		}
		myview.ViewEnd();
		cin >> mainswitch;//选择是否退出程序
	}

	myview.ViewExit();
	return 0;
}



