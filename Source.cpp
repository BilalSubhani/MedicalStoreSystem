#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void Mainmenu(int& number)
{
	cout << "_______________________________________________" << endl;
	cout << "\t" << "\t" << "WELCOME to Medical Store System" << endl;
	cout << "_______________________________________________" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "Press 1: To see all the (available/unavailable) medicines." << endl;
	cout << "Press 2: To add new medicines" << endl;
	cout << "Press 3: To delete medicines from the medicines list" << endl;
	cout << "Press 4: To edit the details of the medicines" << endl;
	cout << "Press 5: To search a medicine from the Medical Store Management System" << endl;
	cout << "Press 6: To check the details of a medicine." << endl;
	cout << "Press 7: To generate the bill of the purchased medicines" << endl;
	cout << "Press 0 to exit." << endl;
	cout << "Enter the desired number to perform desired task." << endl;
	cin >> number;
}
void userDetails(string& user_name, int& card_num)
{
	cout << "Enter the name of the user" << endl;
	getline(cin, user_name);
	cout << "Enter the card number of the user." << endl;
	cin >> card_num;
}

void medicineList(int& num, const int choice[], string  name[100], const string type[], const string avail[], const int cost[])
{
	cout << "The medicine list." << endl;
	cout << "\n";
	for (int k = 0; k <= num; k++)
	{
		cout << setw(5) << choice[k] << setw(15) << name[k] << setw(15) << type[k] << setw(15) << avail[k] << setw(15) << cost[k] << endl;
	}
}
void add_med(int& num, int choice[], string  name[100], string type[], string avail[], int cost[])
{
	num = num + 1;
	cout << "Enter the complete details of the medicine you want to add in following sequence." << endl;
	cout << "(1)Name (2)Type (3)Availability (4)Sale_cost" << endl;

	int static temp = 11;
	choice[num] = temp++;
	cin >> name[num] >> type[num] >> avail[num] >> cost[num];
	cout << endl;

	cout << "The updated list is:" << endl;
	medicineList(num, choice, name, type, avail, cost);
}
void delete_med(int& num, int choice[], string  name[100], string type[], string avail[], int cost[])
{
	int k, t = 0;
	string del;
	cout << "Enter the name of the medicine you want to delete." << endl;
	cin >> del;
	cout << "\n";
	for (k = 0; k < num; k++)
	{
		if (del == name[k])
		{
			t = 1;
			name[k] = '-';
			type[k] = '-';
			avail[k] = '-';
			cost[k] = 0;
		}
	}
	if (t == 0)
		cout << "The medicine is not in data." << endl;
	cout << "The updated list is:" << endl;
	medicineList(num, choice, name, type, avail, cost);
}
void edit_info(int& num, int choice[], string  name[100], string type[], string avail[], int cost[])
{
	int d, t = 0;
	string n;
	cout << "Enter the name medicine you want to edit: ";
	cin >> n;

	cout << "\n";
	for (d = 0; d < num; d++)
	{
		if (n == name[d])
		{
			t = 1;
			cout << "Enter the details." << endl;
			cout << "(1) Availibility" << endl;
			cin >> avail[d];
			cout << "(2) Sale cost" << endl;
			cin >> cost[d];
		}
	}
	if (t == 0)
		cout << "The medicine is not in data." << endl;
	cout << "The updated list is:" << endl;
	medicineList(num, choice, name, type, avail, cost);
}
void search(int& num, int choice[], string  name[100], string type[], string avail[], int cost[])
{
	int x, t = 0;
	string search;
	cout << "Enter the name of medicine you want to search: ";
	cin >> search;


	cout << "\n";
	for (x = 0; x < num; x++)
	{

		if (search == name[x])
		{
			t = 1;
			cout << setw(5) << choice[x] << setw(15) << name[x] << setw(15) << type[x] << setw(15) << avail[x] << setw(15) << cost[x] << endl;
		}
	}
	if (t == 0)
		cout << "The medicine is not in data." << endl;
}
void details(int& num, int choice[], string  name[100], string type[], string avail[], int cost[])
{
	int z, t = 0;
	string n;
	cout << "Enter the name of medicine you want the details for: ";
	cin >> n;
	cout << "\n";
	for (z = 0; z < num; z++)
	{
		if (n == name[z])
		{
			t = 1;
			cout << setw(5) << choice[z] << setw(15) << name[z] << setw(15) << type[z] << setw(15) << avail[z] << setw(15) << cost[z] << endl;
		}
	}
	if (t == 0)
		cout << "The medicine is not in data." << endl;
}

void billcalc(int& num, int choice[], string  name[100], string type[], string avail[], int cost[], string& UserName, int& cardNum)
{
	int total = 0, quantity, n;
	int  q = 1, k, t;

	while (q != 0)
	{
		if (q == 1)
		{
			cout << "\t" << "**************Bill**************************" << endl;
			cout << "\t" << "NAME:" << UserName << "\t" << "CARD DETAILS:" << cardNum << endl;
			cout << "\t" << "********************************************" << endl;
			cout << "Enter the choice of medicine you want to buy" << endl;
			medicineList(num, choice, name, type, avail, cost);
			cin >> n;

			for (k = 0; k < num; k++)
			{
				if (n == 0)
					cout << "Please enter the choice again." << endl;
				if (n == choice[k] && avail[k] == "Available")
				{
					cout << "Enter the quantity." << endl;
					cin >> quantity;
					t = cost[k];
					total = total + (quantity * t);
					cout << "CHOICE: " << n << "\t" << "QUANTITY: " << quantity << endl;
					cout << "The total is RS" << total << endl;
				}
				else if (n == choice[k] && avail[k] == "Unavailable")
				{
					cout << "The medicine is unavailable" << endl;
					break;
				}
			}
		}
		cout << "Do you want to buy more medicines?(enter 0 to exit or 1 to continue)" << endl;
		cin >> q;
	}
	cout << endl;
	cout << "Thank you! GET WELL SOON <3 :)" << endl;
}
int main()
{
	int i = 0, card, number = 10;                                       //Initialising number so it can further be used later.
	int choice[500];
	string name[500], type[500], avail[500];
	int cost[500];
	string UserName;

	ifstream in;
	in.open("medicines.txt");

	while (in.good())
	{
		in >> choice[i] >> name[i] >> type[i] >> avail[i] >> cost[i];
		i = i + 1;
	}
	i = i - 2;
	userDetails(UserName, card);
	cout << "\n";

	while (number != 0)
	{
		Mainmenu(number);
		switch (number)
		{
		case 1:
			medicineList(i, choice, name, type, avail, cost);
			break;
		case 2:
			add_med(i, choice, name, type, avail, cost);
			break;
		case 3:
			delete_med(i, choice, name, type, avail, cost);
			break;
		case 4:
			edit_info(i, choice, name, type, avail, cost);
			break;
		case 5:
			search(i, choice, name, type, avail, cost);
			break;
		case 6:
			details(i, choice, name, type, avail, cost);
			break;
		case 7:
			billcalc(i, choice, name, type, avail, cost, UserName, card);
			break;
		}
	}

	cout << "Thank you for using Medical Store System Software." << endl;


	in.close();

	system("pause");
	return 0;
}