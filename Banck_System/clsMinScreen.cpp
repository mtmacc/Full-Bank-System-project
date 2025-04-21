#pragma once
#include <iostream>
#include <string>
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string subtatile = "")
	{
		cout << "\t\t\t\t\t\n_______________________________________________\n";
		cout << "\t\t\t\t\t\n\t\t\t\t\t" << Title << "\n";
		if (subtatile != "")
		{
			cout << "\t\t\t\t\t " << subtatile << endl;
		}
		cout << "\t\t\t\t\t\n_______________________________________________\n";
	}
};

