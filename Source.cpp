#include<iostream>
#include"UniLink.h"
int main()
{
	int a = 0;
	while (true)
	{
		cout << "Enter maximum posts: ";
		cin >> a;
		if (a <= 0)
		{
			cout << "Invalid input.\nTry again.\n";
			continue;
		}
		else
			break;
	}
	UniLink ul(a);
	ul.Menu();
	return 0;
}