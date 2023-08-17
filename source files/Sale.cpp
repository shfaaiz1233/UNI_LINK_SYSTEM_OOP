#include "Sale.h"
#include<iostream>
int Sale::post_number = 0;
Sale::Sale(const string& tit, const string& desc, const string& crID, const string& st , int a, int c)
:Post(" ",tit,desc,crID,st)
{
	this->ID = "SAL";
	char aa = post_number + 49;
	string add = { '0','0',aa };
	this->ID += add;
    post_number++;
	askingPrice = a;
	highestPrice = 0;
	minimumRaise = c;
}
bool Sale::handleReply(Reply& r)
{
	if (r.getValue() >=highestPrice && status == "OPEN")
	{
		highestPrice = r.getValue();
		Reply* temp = new Reply[replySize + 1];
		if (replies == nullptr)
		{
			replies = new Reply[replySize + 1];
			replies[replySize] = r;
			replySize++;
		}
		else
		{
			for (int i = 0; i < replySize; i++)
				temp[i] = replies[i];
			temp[replySize] = r;
			replySize++;
			delete[] replies;
			replies = new Reply[replySize];
			for (int i = 0; i < replySize; i++)
				replies[i] = temp[i];
		}
		delete[] temp;
		return true;
	}
	else
		return false;
}
string Sale::getPostDetails()
{
	int cp = minimumRaise;
	char a3 = (cp % 10) + 48;
	cp /= 10;
	char a2 = (cp % 10) + 48;
	cp /= 10;
	char a1 = cp + 48;
	string c = { a1,a2,a3 };
	if(highestPrice==0)
	return Post::getPostDetails() + "Minimum Offer: $" + c + "\nHighest Price: No Offer.\n";
	else
	{
		int cppp = highestPrice;
		char a33 = (cppp % 10) + 48;
		cppp /= 10;
		char a22 = (cppp % 10) + 48;
		cppp /= 10;
		char a11 = cppp + 48;
		string d = { a11,a22,a33 };
		return Post::getPostDetails() + "Minimum Offer: $" + c + "\nHighest Price: $"+d +"\n";
	}
}
string Sale::getReplyDetails()
{
	string temp = "Replies:\n";
	if (replySize == 0)
		temp += "Empty.\n";
	char a = 0,b=0,c=0;
	string res = {};
	for (int i = 0; i < replySize; i++)
	{
		a = (replies[i].getValue()/100) + 48;
		b = (replies[i].getValue() / 10) % 10 + 48;
		c = (replies[i].getValue() % 10) + 48;
		res = {a,b,c};
		temp += "Post ID: " + replies[i].getPostID() + "\nOffered Price: $" + res + "\nResponder's ID: " + replies[i].getResponserID() + "\n";
	}
	return temp;
}
void Sale::input()
{
	Post::input();
	cout << "Asking Price: $";
	cin >> this->askingPrice;
	cout << "Minimum Price: $";
	cin >> this->minimumRaise;
}
string Sale::getPostID()
{
	return ID;
}
void Sale::setStatus(const string& ss)
{
	this->status = ss;
}