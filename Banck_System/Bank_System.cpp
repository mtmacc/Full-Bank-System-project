#include <iostream>
#include<iomanip>
#include <ctime>
#include"clsLoginScreen.h"
#include"clsLoginRegister.h"
#include"clsCurrencyList.h"
#include"clsFindCurrency.h"
using namespace std;

int main()
{
    
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
        
    }

    return 0;
}