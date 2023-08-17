#include "UniLink.h"
#include<iostream>
UniLink::UniLink(int size)
{
	total_Posts = size;
	allPost = new Post * [size];

}
void UniLink::Menu()
{
	cout << "\n*****************************************UNILINK SYSTEM***********************************************\n\n";
	int choice = 0,choice1=0,index=0,r=0;
	string userName={},pID={};
	while (true)
	{

		cout << "1. Log in.\n2. Quit.\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{	
			cout << "Enter username: ";
			cin >> userName;
			cout << "Logged in successfully.\n";
			while (true)
			{

				cout << "\t\t1. New Event Post.\n\t\t2. New Sale Post.\n\t\t3. New Job Post.\n\t\t4. Reply to Post.\n\t\t5. Display my post.\n\t\t6. Display All posts.\n";
				cout << "\t\t7. Close Post.\n\t\t8. Delete Post.\n\t\t9. Log out.\n";
				cin >> choice1;
				if ((choice1==1||choice1==2||choice1==3)&&index == total_Posts)
				{
					cout << "Posts limit reached.\nPlease delete a post to add a new post.\n";
					continue;
				}
				if (choice1 == 1)
				{

					allPost[index] = new Event;
					allPost[index]->input();
					index++;
					cout << "Event post added.\n";
					continue;
				}
				else if (choice1 == 2)
				{
					allPost[index] = new Sale;
					allPost[index]->input();
					index++;
					cout << "Sale Post added.\n";
					continue;
				}
				else if (choice1 == 3)
				{
					allPost[index] = new Job;
					allPost[index]->input();
					index++;
					cout << "Job post added.\n";
					continue;
				}
				else if (choice1 == 4)
				{
					cout << "Enter post ID to reply the post: ";
					cin >> pID;
					bool check = false;
					for (int i = 0; i < index; i++)
					{
						if (allPost[i]->getPostID() == pID)
						{
							cout << "Enter response: ";
							cin >> r;
							Reply rep(pID, r, userName);
							if ((allPost[i]->handleReply(rep)) == true)
								cout << "Reply added.\n";
							else
								cout << "Reply not added.\n";
							check = true;
						}
					}
					if (!check)
						cout << "Post Id not found.\n";
					continue;
				}
				else if (choice1 == 5)
				{
					cout << "Enter post ID to display: ";
					cin >> pID;
					bool check = false;
					for (int i = 0; i < index; i++)
					{
						if (allPost[i]->getPostID() == pID)
						{
							cout << allPost[i]->getPostDetails();
							cout << allPost[i]->getReplyDetails();
							check = true;
							break;
						}
					}
					if (!check)
						cout << "Post ID not found.\n";
					continue;
				}
				else if (choice1 == 6)
				{
					for (int i = 0; i < index; i++)
					{
						cout << allPost[i]->getPostDetails();
						cout << allPost[i]->getReplyDetails();
					}
					continue;
				}
				else if (choice1 == 7)
				{
					cout << "Enter post ID to close: ";
					cin >> pID;
					bool check = false;
					for (int i = 0; i < index; i++)
					{
						if (allPost[i]->getPostID() == pID)
						{
							allPost[i]->setStatus("Closed");
							cout << "Post closed.\n";
							check = true;
							break;
						}
					}
					if (!check)
						cout << "Post ID not found\n";
					continue;
				}
				else if (choice1 == 8)
				{
					cout << "Enter post ID to delete it: ";
					cin >> pID;
					bool check = false;
					for (int i = 0; i < index; i++)
					{
						check = false;
						if (allPost[i]->getPostID() == pID)
						{
							allPost[i] = allPost[index - 1];
							check = true;
							break;
						}
					}
					if (check)
					{
						index--;
					}
					else
						cout << "Post ID not found\n";
					continue;
				}
				else
				{
					cout << "Logged out.\n";
					break;
				}
			}
		}
		else
		{
			cout << "Exited.\n";
			break;
		}
	}
}