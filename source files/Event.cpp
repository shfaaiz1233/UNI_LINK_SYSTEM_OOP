#include "Event.h"
#include<iostream>
int Event::attendee_count = 0;
int Event::capacity = 11;
Event::Event(const string& tit, const string& desc, const string& crID, const string& st, const string& ven, const string& dt)
	:Post("", tit, desc, crID, st)
{
	this->ID = "EVE";
	char a = attendee_count + 49;
	string add = { '0','0',a};
	this->ID += add;
	attendee_count++;
	this->Venue = ven;
	this->date = dt;
	if (attendee_count == capacity)
		this->status = "CLOSED";
}
void Event::setter_for_Event(const string& tit, const string& desc, const string& crID, const string& st, const string& ven, const string& dt)
{
	this->Title = tit;
	this->Description = desc;
	this->creatorID = crID;
	this->Venue = ven;
	this->date = dt;
}
void Event::input()
{
	Post::input();
	cout << "Venue: ";
    getline(cin, Venue);
	cout << "Date: ";
	getline(cin, date);
}
string Event::getPostDetails()
{
	int cp = capacity;
	char a3 = (cp%10)+48;
	cp /= 10;
	char a2 = (cp % 10) + 48;
	cp /= 10;
	char a1 = cp + 48;
	string c = { a1,a2,a3};
	return Post::getPostDetails() + "Venue: " + Venue + "\nDate: " + date + "\nCapacity: "+c+"\n";
}
bool Event::handleReply(Reply& r)
{
	if (r.getValue() >= 0 && attendee_count<capacity && status == "OPEN")
	{
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
string Event::getReplyDetails()
{
	string temp = "Replies: \n";
	if (replySize == 0)
		temp += "Empty.\n";
	char a = 0;
	string res = {};
	for (int i = 0; i < replySize; i++)
	{
		a = replies[i].getValue() + 48;
		res = { a };
		temp += "Post ID: " + replies[i].getPostID() + "\nResponse: " + res + "\nResponder's ID: " + replies[i].getResponserID() + "\n";
	}
	return temp;
}
string Event::getPostID()
{
	return ID;
}
void Event::setStatus(const string& ss)
{
	this->status = ss;
}