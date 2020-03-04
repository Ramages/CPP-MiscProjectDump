#include <iostream> //Printing
#include <windows.h> 

int x = 0, y = 0, cps;
bool click = false;
bool newCps = true;

void Clicker()
{
	while(newCps)
	{
		SHORT keyState = GetKeyState(VK_CAPITAL);
		bool isDown = keyState & 0x8000;

		if(GetKeyState(VK_CAPITAL))
		{
			click = true;
		}

		if(GetAsyncKeyState(VK_RBUTTON))
		{
			newCps = false;
		}

		if(isDown)
		{
			click = false;
		}

		if(click)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
			Sleep(1000/cps);
		}
	}
}

int main()
{
	while(cps != 420)
	{
		std::cout <<"Add CPS (or exit by choosing 420): ";
		std::cin >> cps;
		
		if(cps != 420)
		{
			newCps = true;
		}
		
		if(newCps)
		{
			Clicker();
		}
	}
	system("pause");
}