#include<iostream>
#include<fstream>
using namespace std;

void display()
{
	cout << "-------------------------------------------------------------------" << endl;
	cout << "                              WELCOME                              " << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "                 ******************************                    " << endl;
	cout << "                   Auction Management System                       " << endl;
	cout << "                 ******************************                    " << endl;
	cout << endl;
}

void menu()
{
	cout << "------------------------------" << endl;
	cout << "For Selling: (Press 1)" << endl;
	cout << "For Buying: (Press 2)" << endl;
	cout << "To Exit: (Press 3)" << endl;
	cout << "------------------------------" << endl;
}

void menu1()
{
	cout << "------------------------------" << endl;
	cout << "To signup (Press 1):" << endl;
	cout << "To signin (Press 2):" << endl;
	cout << "To signout (Press 3):" << endl;
	cout << "To exit (Press 4):" << endl;
	cout << "------------------------------" << endl;
}

void menu2()
{
	cout << "------------------------------" << endl;
	cout << "To change password (Press 1):" << endl;
	cout << "To post items (Press 2):" << endl;
	cout << "To modify post items (Press 3):" << endl;
	cout << "To view post items (Press 4):" << endl;
	cout << "To change item status to sell/close items (Press 5):" << endl;
	cout << "To signout (Press 6):" << endl;
	cout << "------------------------------" << endl;
}

void menu3()
{
	cout << "------------------------------" << endl;
	cout << "To edit item name: (Press 1)" << endl;
	cout << "To edit item description: (Press 2)" << endl;
	cout << "To edit deadline to bid: (Press 3)" << endl;
	cout << "To edit minimum bid value: (Press 4)" << endl;
	cout << "To exit: (Press 5)" << endl;
	cout << "------------------------------" << endl;
}

void menu4()
{
	cout << "------------------------------" << endl;
	cout << "To view available items: (Press 1)" << endl;
	cout << "To place bid: (Press 2): " << endl;
	cout << "To view list of bid items: (Press 3)" << endl;
	cout << "To view list of bought items: (Press 4)" << endl;
	cout << "To signout: (Press 5)" << endl;
	cout << "------------------------------" << endl;
}

void write(char[], char[], char[], char[], char[], char[]);
void write1(char[], char[], int);
void write2(char[], char[], char[], char[], char[], char[], char[]);
void write3(char[], int[], int[], int[], int);
void signin(char[], char[]);
int sizeArray(char*);
int sizeArray1(char*);
int sizeArray2(char*);
void readFile(char[], char*, int);
void readFile1(char[], char*, int);
void readFile2(char[], int*, int);
bool check(char*);

int main()
{
	char file1[11] = { "Seller.txt" }, file2[10] = { "Buyer.txt" }, file3[12] = { "Item.txt" }, file4[8] = { "Bid.txt" };
	char first[10], last[10], username[16], CNIC[16], password[9], confirm[9], user[16], pass[9];
	char profile1[100], itemName[15], descript[50], postDate[11], deadDate[11], itemStatus[2] = { 'A' };
	char ID[5], minBID[10], item1[100];
	int s1, s2, s3, s4, s5, n = 0, num = 0, max, count = 0;
	int buyerID[5], total[5], maxBID[5], bid1[100], price[100];
	int size = sizeArray(file1);
	int size1 = sizeArray1(file3);
	int size2 = sizeArray2(file4);
	char* profile = new char[size];
	char* item = new char[size1];
	int* bid = new int[size2];

	display();
	menu();
	cin >> s1;
	while (s1 != 3)
	{
		if (s1 == 1)
		{
			//Seller:-
			menu1();
			cin >> s2;
			while (s2 != 4)
			{
				if (s2 == 1)
				{
					cout << "------------------------------" << endl;
					cout << "Seller " << n + 1 << ":" << endl;
					cout << "Enter First name: ";
					cin >> first;
					cout << "Enter Last name: ";
					cin >> last;
					cout << "Enter Username: ";
					cin >> username;
					cout << "Enter CNIC (xxxxx-xxxxxxx-x): ";
					cin >> CNIC;
					cout << "Enter Password: ";
					cin >> password;
					cout << "Enter Confirm Password: ";
					cin >> confirm;
					cout << "------------------------------" << endl;
					write(file1, first, last, username, password, CNIC);
				}
				else if (s2 == 2)
				{
					cout << "------------------------------" << endl;
					signin(user, pass);
					cout << "------------------------------" << endl;
					menu2();
					cin >> s3;
					while (s3 != 6)
					{
						if (s3 == 1)
						{
							readFile(file1, profile, size);
							for (int i = 0; i < size; i++)
							{
								profile1[i] = profile[i];
							}
							int z = 0, st = 0;
							while (z < size)
							{
								if (profile1[z] == '.')
								{
									st = z;
								}
								z++;
							}
							st = st + 1;
							z = 0;
							for (int i = st; i < size; i++)
							{
								password[z] = profile1[i];
								z++;
							}
							password[z] = '\0';
							z = 0;
							cout << "------------------------------" << endl;
							cout << "Enter password: ";
							cin >> pass;
							cout << "Confirm password: ";
							cin >> confirm;
							cout << "------------------------------" << endl;
							for (int i = st; confirm[z] != '\0'; i++)
							{
								profile1[i] = confirm[z];
								z++;
							}
							z = 0;
							write1(file1, profile1, size);
						}
						else if (s3 == 2)
						{
							num = num + 1;
							cout << "------------------------------" << endl;
							cout << "Item ID: " << num << endl;
							cout << "Item status: Available " << endl;
							cout << "Item name: ";
							cin >> itemName;
							cout << "Description: ";
							cin >> descript;
							cout << "Posting Date (DD/MM/YYYY): ";
							cin >> postDate;
							cout << "Deadline to bid (DD/MM/YYYY): ";
							cin >> deadDate;
							cout << "Minimum bid value: Rs.";
							cin >> minBID;
							cout << "------------------------------" << endl;
							write2(file3, ID, itemName, itemStatus, descript, deadDate, minBID);
						}
						else if (s3 == 3)
						{
							readFile1(file3, item, size1);
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							int z1 = 0, st1 = 0;
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z1] = item1[i];
								z1++;
								st1++;
							}
							ID[z1] = '\0';
							z1 = 0;
							st1 = st1 + 1;
							for (int i = st1; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z1] = item1[i];
								z1++;
								st1++;
							}
							itemName[z1] = '\0';
							z1 = 0;
							st1 = st1 + 1;
							for (int i = st1; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z1] = item1[i];
								z1++;
								st1++;
							}
							itemStatus[z1] = '\0';
							z1 = 0;
							st1 = st1 + 1;
							for (int i = st1; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z1] = item1[i];
								z1++;
								st1++;
							}
							descript[z1] = '\0';
							z1 = 0;
							st1 = st1 + 1;
							for (int i = st1; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z1] = item1[i];
								z1++;
								st1++;
							}
							deadDate[z1] = '\0';
							z1 = 0;
							st1 = st1 + 1;
							for (int i = st1; i < size1; i++)
							{
								minBID[z1] = item1[i];
								z1++;
							}
							minBID[z1] = '\0';
							menu3();
							cin >> s4;
							while (s4 != 5)
							{
								cout << "------------------------------" << endl;
								if (s4 == 1)
								{
									cout << "Item name: ";
									cin >> itemName;
								}
								else if (s4 == 2)
								{
									cin.ignore();
									cout << "Description: ";
									cin.getline(descript, 50);
								}
								else if (s4 == 3)
								{
									cout << "Deadline to bid (DD/MM/YYYY): ";
									cin >> deadDate;
								}
								else if (s4 == 4)
								{
									cout << "Minimum bid value: Rs.";
									cin >> minBID;
								}
								else if (s4 == 5)
									break;
								cout << "------------------------------" << endl;
								menu3();
								cin >> s4;
							}
							write2(file3, ID, itemName, itemStatus, descript, deadDate, minBID);
						}
						else if (s3 == 4)
						{
							readFile1(file3, item, size1);
							cout << "------------------------------" << endl;
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							int z2 = 0, st2 = 0;
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z2] = item1[i];
								z2++;
								st2++;
							}
							ID[z2] = '\0';
							cout << "Item ID: ";
							for (int i = 0; ID[i] != '\0'; i++)
							{
								cout << ID[i];
							}
							cout << endl;
							z2 = 0;
							st2 = st2 + 1;
							for (int i = st2; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z2] = item1[i];
								z2++;
								st2++;
							}
							itemName[z2] = '\0';
							cout << "Item Name: ";
							for (int i = 0; itemName[i] != '\0'; i++)
							{
								cout << itemName[i];
							}
							cout << endl;
							z2 = 0;
							st2 = st2 + 1;
							for (int i = st2; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z2] = item1[i];
								z2++;
								st2++;
							}
							itemStatus[z2] = '\0';
							cout << "Item Status: ";
							for (int i = 0; itemStatus[i] != '\0'; i++)
							{
								cout << itemStatus[i];
							}
							cout << endl;
							z2 = 0;
							st2 = st2 + 1;
							for (int i = st2; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z2] = item1[i];
								z2++;
								st2++;
							}
							descript[z2] = '\0';
							z2 = 0;
							st2 = st2 + 1;
							for (int i = st2; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z2] = item1[i];
								z2++;
								st2++;
							}
							deadDate[z2] = '\0';
							z2 = 0;
							st2 = st2 + 1;
							for (int i = st2; i < size1; i++)
							{
								minBID[z2] = item1[i];
								z2++;
							}
							minBID[z2] = '\0';
							cout << "Starting price to bid: Rs.";
							for (int i = 0; minBID[i] != '\0'; i++)
							{
								cout << minBID[i];
							}
							cout << endl;
							readFile2(file4, bid, size2);
							for (int i = 0; i < size2; i++)
							{
								cout << "Total bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								i++;
								cout << "Buyer ID: ";
								cout << bid[i] << " ";
								cout << endl;
								i++;
								cout << "Maximum bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								break;
							}
							cout << "------------------------------" << endl;
						}
						else if (s3 == 5)
						{
							readFile1(file3, item, size1);
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							int z3 = 0, st3 = 0;
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z3] = item1[i];
								z3++;
								st3++;
							}
							ID[z3] = '\0';
							z3 = 0;
							st3 = st3 + 1;
							for (int i = st3; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z3] = item1[i];
								z3++;
								st3++;
							}
							itemName[z3] = '\0';
							z3 = 0;
							st3 = st3 + 1;
							for (int i = st3; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z3] = item1[i];
								z3++;
								st3++;
							}
							itemStatus[z3] = '\0';
							z3 = 0;
							st3 = st3 + 1;
							for (int i = st3; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z3] = item1[i];
								z3++;
								st3++;
							}
							descript[z3] = '\0';
							z3 = 0;
							st3 = st3 + 1;
							for (int i = st3; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z3] = item1[i];
								z3++;
								st3++;
							}
							deadDate[z3] = '\0';
							z3 = 0;
							st3 = st3 + 1;
							for (int i = st3; i < size1; i++)
							{
								minBID[z3] = item1[i];
								z3++;
							}
							minBID[z3] = '\0';
							cout << "------------------------------" << endl;
							cout << "Enter status (S or C): ";
							cin >> itemStatus;
							cout << "------------------------------" << endl;
							write2(file3, ID, itemName, itemStatus, descript, deadDate, minBID);
						}
						else if (s3 == 6)
						{
						    cout << "You have logged out." << endl;
							break;
						}
						menu2();
						cin >> s3;
					}
				}
				else if (s2 == 3)
				{
				     cout << "You have logged out." << endl;
                }
				else if (s2 == 4)
				{
					break;
				}
				menu1();
				cin >> s3;
			}
			menu();
			cin >> s1;
		}
		else if (s1 == 2)
		{
			//Buyer:-
			menu1();
			cin >> s4;
			while (s4 != 4)
			{
				if (s4 == 1)
				{
					cout << "------------------------------" << endl;
					cout << "Buyer " << n + 1 << ":" << endl;
					cout << "Enter First name: ";
					cin >> first;
					cout << "Enter Last name: ";
					cin >> last;
					cout << "Enter Username: ";
					cin >> username;
					cout << "Enter CNIC (xxxxx-xxxxxxx-x): ";
					cin >> CNIC;
					cout << "Enter Password: ";
					cin >> password;
					cout << "Enter Confirm Password: ";
					cin >> confirm;
					cout << "------------------------------" << endl;
					write(file2, first, last, username, CNIC, password);
				}
				else if (s4 == 2)
				{
					cout << "------------------------------" << endl;
					signin(user, pass);
					cout << "------------------------------" << endl;
					menu4();
					cin >> s5;
					while (s5 != 5)
					{
						if (s5 == 1)
						{
							readFile1(file3, item, size1);
							cout << "------------------------------" << endl;
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							int z4 = 0, st4 = 0;
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z4] = item1[i];
								z4++;
								st4++;
							}
							ID[z4] = '\0';
							cout << "Item ID: ";
							for (int i = 0; ID[i] != '\0'; i++)
							{
								cout << ID[i];
							}
							cout << endl;
							z4 = 0;
							st4 = st4 + 1;
							for (int i = st4; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z4] = item1[i];
								z4++;
								st4++;
							}
							itemName[z4] = '\0';
							cout << "Item Name: ";
							for (int i = 0; itemName[i] != '\0'; i++)
							{
								cout << itemName[i];
							}
							cout << endl;
							z4 = 0;
							st4 = st4 + 1;
							for (int i = st4; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z4] = item1[i];
								z4++;
								st4++;
							}
							itemStatus[z4] = '\0';
							z4 = 0;
							st4 = st4 + 1;
							for (int i = st4; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z4] = item1[i];
								z4++;
								st4++;
							}
							descript[z4] = '\0';
							cout << "Description: ";
							for (int i = 0; descript[i] != '\0'; i++)
							{
								cout << descript[i];
							}
							cout << endl;
							z4 = 0;
							st4 = st4 + 1;
							for (int i = st4; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z4] = item1[i];
								z4++;
								st4++;
							}
							deadDate[z4] = '\0';
							cout << "Deadline to bid: ";
							for (int i = 0; deadDate[i] != '\0'; i++)
							{
								cout << deadDate[i];
							}
							cout << endl;
							z4 = 0;
							st4 = st4 + 1;
							for (int i = st4; i < size1; i++)
							{
								minBID[z4] = item1[i];
								z4++;
							}
							minBID[z4] = '\0';
							readFile2(file4, bid, size2);
							for (int i = 0; i < size2; i++)
							{
								cout << "Total bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								i++;
								cout << "Buyer ID: ";
								cout << bid[i] << " ";
								cout << endl;
								i++;
								cout << "Maximum bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								break;
							}
							cout << "------------------------------" << endl;
						}
						else if (s5 == 2)
						{
							readFile1(file3, item, size1);
							int z5 = 0, st5 = 0;
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z5] = item1[i];
								z5++;
								st5++;
							}
							ID[z5] = '\0';
							z5 = 0;
							st5 = st5 + 1;
							for (int i = st5; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z5] = item1[i];
								z5++;
								st5++;
							}
							itemName[z5] = '\0';
							z5 = 0;
							st5 = st5 + 1;
							for (int i = st5; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z5] = item1[i];
								z5++;
								st5++;
							}
							itemStatus[z5] = '\0';
							z5 = 0;
							st5 = st5 + 1;
							for (int i = st5; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z5] = item1[i];
								z5++;
								st5++;
							}
							descript[z5] = '\0';
							z5 = 0;
							st5 = st5 + 1;
							for (int i = st5; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z5] = item1[i];
								z5++;
								st5++;
							}
							deadDate[z5] = '\0';
							z5 = 0;
							st5 = st5 + 1;
							for (int i = st5; i < size1; i++)
							{
								minBID[z5] = item1[i];
								z5++;
							}
							minBID[z5] = '\0';
							if (check(itemStatus))
							{
								cout << "------------------------------" << endl;
								cout << "Item Name: ";
								for (int i = 0; itemName[i] != '\0'; i++)
								{
									cout << itemName[i];
								}
								cout << endl;
								cout << "Description: ";
								for (int i = 0; descript[i] != '\0'; i++)
								{
									cout << descript[i];
								}
								cout << endl;
								cout << "Starting price: ";
								for (int i = 0; minBID[i] != '\0'; i++)
								{
									cout << minBID[i];
								}
								cout << endl;
								for (int i = 0; i < 25; i++)
								{
									cout << "Bid " << i + 1 << ": ";
									cin >> price[i];
									if (price[i] == -1)
									{
										break;
									}
									max = price[i];
									count++;
								}
								int y = 0;
								total[y] = count;
								maxBID[y] = max;
								cout << "Enter the buyers ID who won the bid: ";
								cin >> buyerID[y];
								cout << "------------------------------" << endl;
								write3(file4, total, buyerID, maxBID, y);
							}
						}
						else if (s5 == 3)
						{
							readFile1(file3, item, size1);
							cout << "------------------------------" << endl;
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							int z6 = 0, st6 = 0;
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z6] = item1[i];
								z6++;
								st6++;
							}
							ID[z6] = '\0';
							cout << "Item ID: ";
							for (int i = 0; ID[i] != '\0'; i++)
							{
								cout << ID[i];
							}
							cout << endl;
							z6 = 0;
							st6 = st6 + 1;
							for (int i = st6; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z6] = item1[i];
								z6++;
								st6++;
							}
							itemName[z6] = '\0';
							cout << "Item Name: ";
							for (int i = 0; itemName[i] != '\0'; i++)
							{
								cout << itemName[i];
							}
							cout << endl;
							z6 = 0;
							st6 = st6 + 1;
							for (int i = st6; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z6] = item1[i];
								z6++;
								st6++;
							}
							itemStatus[z6] = '\0';
							cout << "Item Status: ";
							for (int i = 0; itemStatus[i] != '\0'; i++)
							{
								cout << itemStatus[i];
							}
							cout << endl;
							z6 = 0;
							st6 = st6 + 1;
							for (int i = st6; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z6] = item1[i];
								z6++;
								st6++;
							}
							descript[z6] = '\0';
							z6 = 0;
							st6 = st6 + 1;
							for (int i = st6; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z6] = item1[i];
								z6++;
								st6++;
							}
							deadDate[z6] = '\0';
							z6 = 0;
							st6 = st6 + 1;
							for (int i = st6; i < size1; i++)
							{
								minBID[z6] = item1[i];
								z6++;
							}
							minBID[z6] = '\0';
							cout << "Starting price to bid: Rs.";
							for (int i = 0; minBID[i] != '\0'; i++)
							{
								cout << minBID[i];
							}
							cout << endl;
							readFile2(file4, bid, size2);
							for (int i = 0; i < size2; i++)
							{
								cout << "Total bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								i++;
								i++;
								cout << "Maximum bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								break;
							}
							cout << "------------------------------" << endl;
						}
						else if (s5 == 4)
						{
							readFile1(file3, item, size1);
							cout << "------------------------------" << endl;
							for (int i = 0; i < size1; i++)
							{
								item1[i] = item[i];
							}
							int z7 = 0, st7 = 0;
							for (int i = 0; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								ID[z7] = item1[i];
								z7++;
								st7++;
							}
							ID[z7] = '\0';
							cout << "Item ID: ";
							for (int i = 0; ID[i] != '\0'; i++)
							{
								cout << ID[i];
							}
							cout << endl;
							z7 = 0;
							st7 = st7 + 1;
							for (int i = st7; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemName[z7] = item1[i];
								z7++;
								st7++;
							}
							itemName[z7] = '\0';
							cout << "Item Name: ";
							for (int i = 0; itemName[i] != '\0'; i++)
							{
								cout << itemName[i];
							}
							cout << endl;
							z7 = 0;
							st7 = st7 + 1;
							for (int i = st7; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								itemStatus[z7] = item1[i];
								z7++;
								st7++;
							}
							itemStatus[z7] = '\0';
							z7 = 0;
							st7 = st7 + 1;
							for (int i = st7; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								descript[z7] = item1[i];
								z7++;
								st7++;
							}
							descript[z7] = '\0';
							z7 = 0;
							st7 = st7 + 1;
							for (int i = st7; i < size1; i++)
							{
								if (item1[i] == '.')
								{
									break;
								}
								deadDate[z7] = item1[i];
								z7++;
								st7++;
							}
							deadDate[z7] = '\0';
							z7 = 0;
							st7 = st7 + 1;
							for (int i = st7; i < size1; i++)
							{
								minBID[z7] = item1[i];
								z7++;
							}
							minBID[z7] = '\0';
							cout << "Starting price to bid: Rs.";
							for (int i = 0; minBID[i] != '\0'; i++)
							{
								cout << minBID[i];
							}
							cout << endl;
							readFile2(file4, bid, size2);
							for (int i = 0; i < size2; i++)
							{
								cout << "Total bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								i++;
								i++;
								cout << "Maximum bid placed: ";
								cout << bid[i] << " ";
								cout << endl;
								break;
							}
							cout << "------------------------------" << endl;
						}
						else if (s5 == 4)
						{
						    cout << "You have logged out." << endl;
							break;
						}
						menu4();
						cin >> s5;
					}
				}
                else if (s4 == 3)
				{
				    cout << "You logged out." << endl;
				}
				else if (s4 == 4)
				{
				    break;
                }
				menu1();
				cin >> s4;
			}
		}
		else if (s1 == 3)
		{
		    break;
        }
		menu();
		cin >> s1;
	}
	return 0;
}

void write(char file1[], char first[], char last[], char username[], char password[], char CNIC[])
{
	ofstream fout;
	fout.open(file1);
	for (int i = 0; first[i] != '\0'; i++)
	{
		fout << first[i];
	}
	fout << "." << endl;
	for (int i = 0; last[i] != '\0'; i++)
	{
		fout << last[i];
	}
	fout << "." << endl;
	for (int i = 0; username[i] != '\0'; i++)
	{
		fout << username[i];
	}
	fout << "." << endl;
	for (int i = 0; CNIC[i] != '\0'; i++)
	{
		fout << CNIC[i];
	}
	fout << "." << endl;
	for (int i = 0; password[i] != '\0'; i++)
	{
		fout << password[i];
	}
	fout << "@" << endl;
}

void write1(char file1[], char profile1[], int size)
{
	ofstream fout;
	fout.open("Seller.txt");
	for (int i = 0; i < size; i++)
	{
		fout << profile1[i];
		if (profile1[i] == '.')
			fout << endl;
	}
	fout.close();
}

void write2(char file3[], char ID[], char itemName[], char itemStatus[], char descript[], char deadDate[], char minBID[])
{
	ofstream fout;
	fout.open(file3);
	for (int i = 0; ID[i] != '\0'; i++)
	{
		fout << ID[i];
	}
	fout << "." << endl;
	for (int i = 0; itemName[i] != '\0'; i++)
	{
		fout << itemName[i];
	}
	fout << "." << endl;
	for (int i = 0; itemStatus[i] != '\0'; i++)
	{
		fout << itemStatus[i];
	}
	fout << "." << endl;
	for (int i = 0; descript[i] != '\0'; i++)
	{
		fout << descript[i];
	}
	fout << "." << endl;
	for (int i = 0; deadDate[i] != '\0'; i++)
	{
		fout << deadDate[i];
	}
	fout << "." << endl;
	for (int i = 0; minBID[i] != '\0'; i++)
	{
		fout << minBID[i];
	}
	fout << "@" << endl;
}

void write3(char file4[], int total[], int buyerID[], int maxBID[], int y)
{
	ofstream fout;
	fout.open(file4);
	fout << total[y] << endl;
	fout << buyerID[y] << endl;
	fout << maxBID[y] << endl;
}

void signin(char user[], char pass[])
{
	cout << "Enter:-" << endl;
	cout << "Username: ";
	cin >> user;
	cout << "Password: ";
	cin >> pass;
}

int sizeArray(char* file1)
{
	ifstream fin;
	fin.open(file1);
	char ch;
	int c = 0;
	while (fin >> ch)
	{
		c++;
		if (fin.eof())
			break;
	}
	fin.close();
	return c;
}

int sizeArray1(char* file3)
{
	ifstream fin;
	fin.open(file3);
	char ch;
	int c = 0;
	while (fin >> ch)
	{
		c++;
	}
	fin.close();
	return c;
}

int sizeArray2(char* file4)
{
	ifstream fin;
	fin.open(file4);
	int num = 0, c = 0;
	while (fin >> num)
	{
		c++;
		if (fin.eof())
			break;
	}
	fin.close();
	return c;
}

void readFile(char file1[], char* profile, int s)
{
	ifstream fin;
	fin.open(file1);
	for (int i = 0; i < s; i++)
		fin >> profile[i];
	fin.close();
}

void readFile1(char file3[], char* item, int s)
{
	ifstream fin;
	fin.open(file3);
	for (int i = 0; i < s; i++)
		fin >> item[i];
	fin.close();
}

void readFile2(char file4[], int* bid, int s)
{
	ifstream fin;
	fin.open(file4);
	for (int i = 0; i < s; i++)
		fin >> bid[i];
	fin.close();
}

bool check(char* itemStatus)
{
	for (int i = 0; itemStatus[i] != '\0'; i++)
	{
		if (itemStatus[i] == 'A' || i == 0)
		{
			return true;
		}
		else if (itemStatus[i] != 'A')
		{
			return false;
		}
	}
}