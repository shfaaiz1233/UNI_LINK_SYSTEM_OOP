#include "Job.h"
#include<iostream>
int Job::job_number = 0;
Job::Job( const string& tit , const string& desc, const string& crID, const string& st, int a, int b)
	:Post(" ",tit,desc,crID,st)
{
	this->ID = "JOB";
	char aa = job_number + 49;
	string add = { '0','0',aa };
	this->ID += add;
	job_number++;
	status = "OPEN";
	proposed_price = a;
	lowest_offer = b;
}
string Job::getPostDetails()
{
	char a = (proposed_price / 100) + 48;
	char b = (proposed_price / 10) % 10 + 48;
	char c = (proposed_price % 10) + 48;
	string s1 = { a,b,c };
	a = (lowest_offer / 100) + 48;
	b = (lowest_offer / 10) % 10 + 48;
	c = (lowest_offer % 10) + 48;
	string s2 = { a,b,c };
	return Post::getPostDetails() + "Proposed Price: " + s1 + "\nLowest offer: " + s2 + "\n";
}
bool Job::handleReply(Reply& r)
{
	if (r.getValue() <= lowest_offer&& status=="OPEN")
	{
		lowest_offer = r.getValue();
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
void Job::input()
{
	Post::input();
	cout << "Proposed price: $";
	cin >> proposed_price;
	cout << "Lowest Offer: $";
	cin >> lowest_offer;
}
string Job::getReplyDetails()
{
	string temp ="Replies:\n";
	if (replySize == 0)
		temp += "Empty.\n";
	char a = 0, b = 0, c = 0;
	string res = {};
	for (int i = 0; i < replySize; i++)
	{
		a = (replies[i].getValue() / 100) + 48;
		b = (replies[i].getValue() / 10) % 10 + 48;
		c = (replies[i].getValue() % 10) + 48;
		res = { a,b,c };
		temp += "Post ID: " + replies[i].getPostID() + "\nOffered Price: $" + res + "\nResponder's ID: " + replies[i].getResponserID() + "\n";
	}
	return temp;
}
string Job::getPostID()
{
	return ID;
}
void Job::setStatus(const string& ss)
{
	this->status = ss;
}