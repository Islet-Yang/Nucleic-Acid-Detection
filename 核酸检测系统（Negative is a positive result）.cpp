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
			}//ѡ��0�����û�ע��
			case 1 :
			{
				mycontroller.Login();
				break;
			}//ѡ��1���û���¼
			default :
			{
				break;
			}

		}
		myview.ViewEnd();
		cin >> mainswitch;//ѡ���Ƿ��˳�����
	}

	myview.ViewExit();
	return 0;
}



