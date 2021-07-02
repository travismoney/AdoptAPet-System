#include <iostream> 
#include <string> 
#include <stdlib.h> 
#include <iomanip> 
#include <conio.h> 

using namespace std; 
					 
struct node {
	int itemCode;
	string itemType;
	string itemBrand;
	string itemSize;
	double itemCost;
	node *next;

	node(int data, string type, string brand, string size, double cost)
	{
		itemCode = data;
		itemType = type;
		itemBrand = brand;
		itemSize = size;
		itemCost = cost;
		next = NULL;
	}
};


struct Order {
	string customerName;
	string OrderName;
	string OrderBrand;
	int quantity;
	int receiptID;
	double OrderPrice;
	double totalPrice;
}Order[10];


struct Receipt
{
	int receiptNo, amount, day, month, year;
	string Name, item, colour, brandx;
	double totalCost, itemCost;
	Receipt *next;

};


class AdoptApet{
	node *head, *last; 
	Receipt *top; 

public: 
	int receiptID = 1;
	AdoptApet();
	~AdoptApet()
	{

	}
	
	void setPresetData(int x, string a, string b, string c, double d);// 
	void addAdoptApet(int, string, string, string, double); 
	void deleteAdoptApet(int); 
	void viewAdoptApet(); 

								
	void placeorder();
	void deleteorder();
	int empty(); 
	void editOrder();
	void sortSummaryAscendingly(); 
	void sortSummaryDescendingly(); 
	void customerReceipt(); 
	void summary(); 
	void weeklySummary(); 

						  
	void adminmenu(); 
	void customermenu();
						 
	void menu(); 
};

AdoptApet::AdoptApet() 
{
	last = NULL;
	head = NULL;
	top = NULL;
}


void AdoptApet::setPresetData(int x, string a, string b, string c, double d)
{
	node *p = new node(x, a, b, c, d);
	if (head == NULL)
	{
		head = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}

}

void AdoptApet::addAdoptApet(int Pos, string Type, string Brand, string Size, double Cost)
{
	node *p = new node(Pos, Type, Brand, Size, Cost);
	last->next = p;
	last = p;
}

void AdoptApet::deleteAdoptApet(int del)
{
	node *current; 
	node *trailCurrent; 
	bool found;
	if (head == NULL)
	{
		cout << "Cannot delete from an empty list." << endl;
	} 
	else
	{
		current = head;
		trailCurrent = current;
		found = false;
		while (current != NULL && !found) 
		{
			if (current->itemCode >= del) {
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->next;
			}
		}
		if (current == NULL) {
			cout << "The item to be deleted is not in the list."
				<< endl;
		}
		else if (current->itemCode == del)
										   
		{
			if (head == current)
			{
				head = head->next;
				if (head == NULL)
					last = NULL;
				delete current;
			}
			else
			{
				current = trailCurrent->next;
				trailCurrent->next = current->next;
				if (current == last)
					last = trailCurrent;
				delete current;
			}

		}
		else
		{
			cout << "The item to be deleted is not in the "
				<< "list." << endl;
		}
	} 
}

void AdoptApet::viewAdoptApet() {
	node *p = head;
	cout << "_______________________________________________________________________________________________________________________________" << endl;
	cout << left << setw(10) << "Code" <<
		left << setw(20) << "Item" <<
		left << setw(40) << "Brand" <<
		left << setw(10) << "Size" <<
		left << setw(10) << "Price(RM)" << endl;
	cout << "________________________________________________________________________________________________________________________________" << endl;
	while (p != NULL) {
		cout << left << setw(10) << p->itemCode <<
			left << setw(20) << p->itemType <<
			left << setw(30) << p->itemBrand <<
			left << setw(20) << p->itemSize <<
			left << setw(10) << p->itemCost << endl;
		p = p->next;
	}
}

void AdoptApet::placeorder() {

	int id, amount, choice1, day, month, year, confirm;
	double subtotal = 0.00, totalPurchase, tax = 0.06;
	string name;
	string design;
	string customer;
	string brandName;
	unsigned int counter = 0, loop;

	cout << endl << "Enter 0 to return to main menu.\n\n Place your order.\n";
	cout << "How many types of item do you want to order? ";
	while (!(cin >> loop))
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please try again\n";
		cout << ":-";
	}
	if (loop == 0)
	{
		system("cls");
	}
	else
	{
		while (counter < loop)
		{

		Code:
			node * p;
			p = head;
			viewAdoptApet();

			cout << endl << "Enter item code : "; 
			while (!(cin >> id))
			{

				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please try again\n";
				cout << ":-";
			}
			while (id != p->itemCode) {

				p = p->next;

				if (p == NULL) {

					cout << "Item code entered is not in the list.\nPlease enter the correct item code.\n ";
					system("pause");
					goto Code;

				}


			}

			if (id == p->itemCode) {

			Quantity:
				cout << endl << "Enter quantity :  ";
				while (!(cin >> amount))
				{
					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please try again\n";
					cout << "Enter quantity :  ";
				}

				if (amount == 0) {

					cout << "Quantity Can not be Zero. Try again.\n ";

					system("pause");
					system("cls");
					goto Quantity;

				}
				Order[counter].quantity = amount;
				Order[counter].OrderName = p->itemType;
				Order[counter].OrderBrand = p->itemBrand;
				Order[counter].OrderPrice = p->itemCost;
				Order[counter].totalPrice = p->itemCost*amount;

			}
			counter++;

		}
		cout << endl << "Enter your name : "; 
		cin.ignore();
		getline(cin, customer);

		cout << endl << "Enter today's date."; 
		cout << endl << "Year (yy) :";
		while (!(cin >> year))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please try again\n";
			cout << ":-";
		}
		if (year > 0)
		{
		Month:
			cout << endl << "Month (mm) : ";
			while (!(cin >> month))
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please try again\n";
				cout << ":-";
			}
			if (month < 1 || month > 12)
			{
				cout << "Invalid month";
				goto Month;

			}

		Day:
			cout << endl << "Day (dd) : ";
			while (!(cin >> day))
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Please try again\n";
				cout << ":-";
			}
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day <= 0 || day > 31)
				{
					cout << "Invalid input. Please try again\n";
					goto Day;
				}

			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day <= 0 && day>30)
				{
					cout << "Invalid input. Please try again\n";
					goto Day;
				}

			}
			else if (month == 2)
			{
				if (year % 4 == 0)
				{
					if (day <= 0 && day>29)
					{
						cout << "Invalid input. Please try again\n";
						goto Day;
					}

				}
				else if (year % 4 != 0)
				{
					if (day <= 0 && day>28)
					{
						cout << "Invalid input. Please try again\n";
						goto Day;
					}

				}
				else
				{
					cout << "Invalid date\n";
					goto Day;
				}
			}
		}



		for (unsigned int i = 0; i < loop; i++)
		{
			subtotal = subtotal + Order[i].totalPrice;
		}

		totalPurchase = subtotal + subtotal * tax;
		for (unsigned int i = 0; i< loop; i++)
		{
			cout << endl << " Item " << i+1;
			cout << endl << "Item Name : " << Order[i].OrderName;
			cout << endl << "Brand : " << Order[i].OrderBrand;
			cout << endl << "Price(RM) : " << Order[i].OrderPrice;
			cout << endl << "Quantity : " << Order[i].quantity;
			cout << endl << "Total (RM) : " << Order[i].totalPrice << endl;
		}
		cout << endl << endl << "Receipt no : " << receiptID << endl;
		cout << "Subtotal: RM " << subtotal << endl;
		cout << "Tax (6%):" << subtotal * tax << endl;
		cout << "Total: RM " << totalPurchase << endl;

	confirmation:
		cout << endl << " 1. Confirm order || 2. Cancel order" << endl; 
		cout << ": ";
		while (!(cin >> confirm))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please try again\n";
			cout << ":-";
		}
		if (confirm == 1)
		{
			for (counter = 0; counter < loop; counter++)
			{
				Receipt *z = new Receipt;
				z->receiptNo = receiptID;
				z->Name = customer;
				z->day = day;
				z->month = month;
				z->year = year;
				z->item = Order[counter].OrderName;
				z->brandx = Order[counter].OrderBrand;
				z->totalCost = Order[counter].totalPrice;
				z->amount = Order[counter].quantity;
				z->itemCost = Order[counter].OrderPrice;
				z->next = top;
				top = z;
			}

			receiptID++;
		}
		else if (confirm == 2)
		{
			cout << "The order was cancelled...\n" << endl;
		}

		else
		{
			cout << "Invalid input. Please try again\n";
			goto confirmation;
		}

	}

}

void AdoptApet::deleteorder()
{
	if (empty() == 1) {
		cout << "\nNo order has been made.\n";
	}
	else
	{
		Receipt *z = top;
		top = top->next;
		delete z;
		cout << " Latest order has been deleted\n";
	}


}

int AdoptApet::empty() {
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void AdoptApet::editOrder() {

	bool found = false;
	int searchReceipt, select;
	int id, amount, choice1, day, month, year;
	double subtotal = 0.00, totalPurchase, tax = 0.06;
	string name;
	Receipt *z;
	z = top;

	cout << endl << "Enter 0 to return to main menu.\n\n ";
	cout << "Enter receipt id to edit the order : "; 
	while (!(cin >> searchReceipt))
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please try again\n";
		cout << ":-";
	}
	if (searchReceipt == 0)
	{
		system("cls");
	}
	else
	{
		found = false;

		while (z != NULL)
		{
			if (z->receiptNo == searchReceipt)
			{
				cout << " Edit\n" << "1. Name || 2. Date || 3. Purchase details\n" << " Enter your choice : ";
				while (!(cin >> select))
				{

					cin.clear();
					cin.ignore();
					cout << "Invalid input. Please try again\n";
					cout << ":-";
				}
				if (select == 1)
				{

					cout << endl << "Enter name : "; 
					cin.ignore();
					getline(cin, name);
					z->Name = name;
					found = true;
					break;

				}
				else if (select == 2)
				{

					cout << endl << "Enter today's date."; 
					cout << endl << "Year (yy) :";
					while (!(cin >> year))
					{
						cin.clear();
						cin.ignore();
						cout << "Invalid input. Please try again\n";
						cout << ":-";
					}
					if (year > 0)
					{
					Month:
						cout << endl << "Month (mm) : ";
						while (!(cin >> month))
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid input. Please try again\n";
							cout << ":-";
						}
						if (month < 1 || month > 12)
						{
							cout << "Invalid month";
							goto Month;

						}

					Day:
						cout << endl << "Day (dd) : ";
						while (!(cin >> day))
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid input. Please try again\n";
							cout << ":-";
						}
						if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
						{
							if (day <= 0 || day > 31)
							{
								cout << "Invalid input. Please try again\n";
								goto Day;
							}

						}
						else if (month == 4 || month == 6 || month == 9 || month == 11)
						{
							if (day <= 0 && day>30)
							{
								cout << "Invalid input. Please try again\n";
								goto Day;
							}

						}
						else if (month == 2)
						{
							if (year % 4 == 0)
							{
								if (day <= 0 && day>29)
								{
									cout << "Invalid input. Please try again\n";
									goto Day;
								}

							}
							else if (year % 4 != 0)
							{
								if (day <= 0 && day>28)
								{
									cout << "Invalid input. Please try again\n";
									goto Day;
								}

							}
							else
							{
								cout << "Invalid date\n";
								goto Day;
							}
						}
					}

					z->day = day;
					z->month = month;
					z->year = year;
					found = true;
					break;
				}

				else if (select == 3)
				{

				Code:
					node * p;
					p = head;
					viewAdoptApet();

					cout << endl << "Enter item code : ";
					while (!(cin >> id))
					{

						cin.clear();
						cin.ignore();
						cout << "Invalid input. Please try again\n";
						cout << ":-";
					}
					while (id != p->itemCode) {

						p = p->next;

						if (p == NULL) {

							cout << "Item code entered is not in the list.\nPlease enter the correct item code.\n ";
							system("pause");
							goto Code;

						}


					}

					if (id == p->itemCode) {

					Quantity:
						cout << endl << "Enter quantity :  "; 
						while (!(cin >> amount))
						{
							cin.clear();
							cin.ignore();
							cout << "Invalid input. Please try again\n";
							cout << "Enter quantity :  ";
						}

						if (amount == 0) {

							cout << "Quantity Can not be Zero. Try again.\n ";

							system("pause");
							system("cls");
							goto Quantity;

						}

						z->amount = amount;
						z->item = p->itemType;
						z->brandx = p->itemBrand;
						z->itemCost = p->itemCost;
						z->totalCost = p->itemCost*amount;
						subtotal = subtotal + z->totalCost;

						found = true;
					}

					tax = subtotal * 0.06;
					totalPurchase = subtotal + tax;

					cout << endl << "Subtotal: RM " << subtotal << endl;
					cout << "Tax (6%):" << subtotal * tax << endl;
					cout << "Total: RM " << totalPurchase << endl;
				}


			}
			z = z->next;
		}

		if (found == false)
		{
			system("cls");
			cout << "Receipt not found" << endl;
		}
	}

}

void AdoptApet::customerReceipt()
{

	bool found = false;
	int searchreceipt;
	double tax, subtotal = 0.0, totalPurchase;

	Receipt *z;
	z = top;

	cout << "Enter receipt id you want view (Enter 0 to return to admin menu) : " << endl; 

	while (!(cin >> searchreceipt))
	{

		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please try again\n";
		cout << ":-";
	}

	system("cls");
	if (searchreceipt == 0)
	{
		cout << endl;
	}

	else
	{
		found = false;

		cout << endl;
		cout << "     --------------------------- The AdoptApet Company ----------------------------- " << endl;
		cout << "                                   Customer's Receipt                                " << endl;
		cout << endl << "Receipt No :" << searchreceipt << endl << endl;
		while (z != NULL)
		{
			if (z->receiptNo == searchreceipt)
			{
				cout << "Customer Name : " << z->Name << endl;
				cout << "Date : " << z->day << "/" << z->month << "/" << z->year << endl;
				break;

			}
			z = z->next;
		}

		cout << "___________________________________________________________________________________________" << endl;
		cout << left << setw(30) << "Item" <<
			left << setw(10) << "Brand" <<
			left << setw(10) << "Price(RM)" <<
			left << setw(10) << "Quantity" <<
			left << setw(10) << "Total (RM)" << endl;
		cout << "___________________________________________________________________________________________" << endl;

		while (z != NULL)
		{

			if (z->receiptNo == searchreceipt)
			{

				cout << left << setw(30) << z->item <<
					left << setw(10) << z->brandx <<
					left << setw(10) << z->itemCost <<
					left << setw(10) << z->amount <<
					left << setw(10) << z->totalCost << endl;
				subtotal = subtotal + z->totalCost;
				tax = subtotal * 0.06;
				totalPurchase = subtotal + tax;

				found = true;

			}

			z = z->next;


		}
		if (z == NULL)
		{
			cout << endl;
		}
		else
		{
			cout << "\n_________________________________________________________________________________________" << endl;
			cout << "Subtotal: RM " << subtotal << endl;
			cout << "Tax (6%):" << tax << endl;
			cout << "Total: RM " << totalPurchase << endl;
		}
		
		if (found == false)
		{
			system("cls");
			cout << "Receipt not found" << endl;
		}

	}


	system("pause");
	system("cls");
}

void AdoptApet::sortSummaryAscendingly()
{
	node *temphead;
	temphead = head;
	string tempname;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;

	for (int j = 0; j<counter; j++)
	{
		while (temphead->next)
		{
			if (temphead->itemType > temphead->next->itemType)
			{
				tempname = temphead->itemType;
				temphead->itemType = temphead->next->itemType;
				temphead->next->itemType = tempname;
			}
			temphead = temphead->next;
		}
		temphead = head;
	}

}

void AdoptApet::sortSummaryDescendingly()
{
	node * temphead = head;
	string tempname;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;

	for (int j = 0; j<counter; j++)
	{
		while (temphead->next)
		{
			if (temphead->itemType < temphead->next->itemType)
			{
				tempname = temphead->itemType;
				temphead->itemType = temphead->next->itemType;
				temphead->next->itemType = tempname;
			}
			else
			temphead = temphead->next;
		}
		temphead = head;
	}
}

void AdoptApet::weeklySummary() {

	node *p;
	p = head;
	int day, month, year;
	int sort;

	cout << "Enter starting date. ";
	cout << endl << "Year (yy) :";
	while (!(cin >> year))
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please try again\n";
		cout << ":-";
	}
	if (year > 0)
	{
	Month:
		cout << endl << "Month (mm) : ";
		while (!(cin >> month))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please try again\n";
			cout << ":-";
		}
		if (month < 1 || month > 12)
		{
			cout << "Invalid month";
			goto Month;

		}

	Day:
		cout << endl << "Day (dd) : ";
		while (!(cin >> day))
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Please try again\n";
			cout << ":-";
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 0 || day > 31)
			{
				cout << "Invalid input. Please try again\n";
				goto Day;
			}

		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 0 && day>30)
			{
				cout << "Invalid input. Please try again\n";
				goto Day;
			}

		}
		else if (month == 2)
		{
			if (year % 4 == 0)
			{
				if (day <= 0 && day>29)
				{
					cout << "Invalid input. Please try again\n";
					goto Day;
				}

			}
			else if (year % 4 != 0)
			{
				if (day <= 0 && day>28)
				{
					cout << "Invalid input. Please try again\n";
					goto Day;
				}

			}
			else
			{
				cout << "Invalid date\n";
				goto Day;
			}
		}
	}

Sort:
	cout << "1. Sort item name ascendingly" << endl;
	cout << "2. Sort item name descending" << endl;
	cout << "3. Unsorted" << endl;

	while (!(cin >> sort))
	{
		cin.clear();
		cin.ignore();
	}
	if (sort == 1)
	{
		sortSummaryAscendingly();
	}
	else if (sort == 2)
	{
		sortSummaryDescendingly();
	}
	else if (sort == 3)
	{
		cout << endl;
	}
	else
	{
		cout << "Invalid input. Please try again\n";
		goto Sort;
	}

	if (p == NULL)
		cout << "Empty. Please create a receipt.\n";
	else
	{
		cout << day << "/" << month << "/" << year << '-' << day + 6 << "/" << month << "/" << year << endl;
		cout << "_____________________________________________________________________________________" << endl <<
			left << setw(30) << "Item" <<
			left << setw(10) << "Quantity" <<
			left << setw(10) << "Total (RM)" <<
			left << setw(10) << "Date" << endl;

		cout << "-------------------------------------------------------------------------------------";

		while (p != NULL)
		{
			Receipt *z;
			z = top;
			int quantityX = 0;
			double totalX = 0.0;
			cout << endl << left << setw(30) << p->itemType;
			while (z != NULL)
			{
				if (z->day == day || z->day <= day + 6 && z->month == month && z->year == year)
				{
					if (z->item == p->itemType)
					{
						quantityX = quantityX + z->amount;
						totalX = totalX + z->totalCost;
					}
					else
					{
						quantityX = quantityX + 0;
						totalX = totalX + 0;
					}
				}

				z = z->next;
			}

			cout << left << setw(10) << quantityX <<
				left << setw(10) << totalX;

			p = p->next;

		}


	}


}

void AdoptApet::summary() {

	int sort;
	node *p;
	p = head;

Sort:
	cout << "1. Sort item name ascendingly" << endl;
	cout << "2. Sort item name descending" << endl;
	cout << "3. Unsorted" << endl;
	while (!(cin >> sort))
	{
		cin.clear();
		cin.ignore();
	}
	if (sort == 1)
	{
		sortSummaryAscendingly();
	}
	else if (sort == 2)
	{
		sortSummaryDescendingly();
	}
	else if (sort == 3)
	{
		cout << endl;
	}
	else
	{
		cout << "Invalid input. Please try again\n";
		goto Sort;
	}



	if (p == NULL)
		cout << "Empty. Please create a receipt.\n";
	else
	{

		cout << "_____________________________________________________________________________________" << endl <<
			left << setw(30) << "Item" <<
			left << setw(10) << "Quantity" <<
			left << setw(10) << "Total (RM)" << endl;
		cout << "-------------------------------------------------------------------------------------";

		while (p != NULL)
		{
			Receipt *z;
			z = top;
			int quantityX = 0;
			double totalX = 0.0;
			cout << endl << left << setw(30) << p->itemType;
			while (z != NULL)
			{
				if (z->item == p->itemType)
				{
					quantityX = quantityX + z->amount;
					totalX = totalX + z->totalCost;
				}
				else
				{
					quantityX = quantityX + 0;
					totalX = totalX + 0;
				}

				z = z->next;

			}

			cout << left << setw(10) << quantityX <<
				left << setw(10) << totalX << endl;

			p = p->next;

		}


	}


}

void AdoptApet::adminmenu()
{
	int password, choice;
	string Type;
	string Brand;
	string Size;
	double Cost;
	int Pos = 6;
	int del;

Password:
	cout << "Enter Password (Enter 0 to return to main menu) : "; // admin password = 1234
	while (!(cin >> password))
	{

		cin.clear();
		cin.ignore();
		cout << "Incorrect Password. Please try again.\n";
		cout << ":-";
	}
	if (password == 0)
	{
		cout << endl;
	}
	else if (password == 1234)
	{

		do
		{
			system("cls");
			cout << endl << endl << endl << "\t\tAdopt-A-Pet Centre";
			cout << endl << endl << "\t\t\t\tAdmin Menu    " << endl;
			cout << "\t\t\t************************" << endl;
			cout << "\t\t\t 1. View overall summary" << endl;
			cout << "\t\t\t 2. View weekly summary" << endl;
			cout << "\t\t\t 3. Edit order" << endl;
			cout << "\t\t\t 4. Delete latest order" << endl;
			cout << "\t\t\t 5. Add New Item" << endl;
			cout << "\t\t\t 6. Delete Item" << endl;
			cout << "\t\t\t 7. Search receipt" << endl;
			cout << "\t\t\t 8. Return to main menu" << endl;
			cout << "\t\t\t************************" << endl;
			cout << endl << endl << "\t\t\t Choose your option: ";
			while (!(cin >> choice))
			{
				cin.clear();
				cin.ignore();
				break;
			}

			switch (choice)
			{
			case 1:

				system("cls");
				summary();
				system("pause");
				break;

			case 2:

				system("cls");
				weeklySummary();
				system("pause");
				break;

			case 3:

				system("cls");
				editOrder();
				system("pause");

			case 4:

				deleteorder();
				system("pause");
				break;


			case 5:

				cout << endl << "Enter item details.\n";
				cout << endl << "Enter item type (Enter 0 to return to admin menu) : ";
				cin.ignore();
				getline(cin, Type);
				if (Type == "0")
				{
					system("pause");
					system("cls");
				}
				else
				{
					cout << endl << "Enter the brand of the item : "; 
					cin >> Brand;
					cout << endl << "Enter the size of the item : "; 
					cin >> Size;
					cout << endl << "Enter Cost : RM "; 
					cin >> Cost;
					cout << endl << "Item has been added successfully" << endl; 
					Pos++;
					addAdoptApet(Pos, Type, Brand, Size, Cost); 
				}

				break;

			case 6:

				system("cls");
				viewAdoptApet();
				cout << "Item code to be deleted :\n";
				cin >> del;
				deleteAdoptApet(del);
				cout << " Item has been deleted\n";
				system("pause");
				break;

			case 7:

				system("cls");
				customerReceipt();
				system("pause");
				break;

			case 8:

				system("cls");
				cout << endl << "You are returning to main menu" << endl;
				cout << endl;
				break;

			default:
				cout << endl << "\t\t\tInavlid input. Please try again.\n";
				break;

			}
		} while (choice != 8);

	}
	else
	{

		cout << endl << "Incorrect Password. Please try again.\n";
		goto Password;
	}
}

void AdoptApet::customermenu()
{
	int option;
	do {
		system("cls");
		cout << endl << endl << endl << "\t\tAdopt-A-Pet";
		cout << endl << endl << "\t\t\t\tCustomer Menu    " << endl;
		cout << "\t\t\t************************" << endl;
		cout << "\t\t\t 1. View Items" << endl;
		cout << "\t\t\t 2. Place order" << endl;
		cout << "\t\t\t 3. View receipt" << endl;
		cout << "\t\t\t 4. Edit order" << endl;
		cout << "\t\t\t 5. Exit to main menu" << endl;
		cout << "\t\t\t************************" << endl;
		cout << endl << endl << "\t\t\t Choose your option: ";
		while (!(cin >> option))
		{
			cin.clear();
			cin.ignore();
			break;
		}

		switch (option)
		{
		case 1:
			system("cls");
			viewAdoptApet();
			system("pause");
			break;

		case 2:
			system("cls");
			placeorder();
			system("pause");
			break;

		case 3:
			system("cls");
			customerReceipt();
			system("pause");
			break;

		case 4 :
			system("cls");
			editOrder();
			system("pause");

		case 5:
			system("cls");
			break;

		default:
			cout << endl << "\t\t\tInavlid input. Please try again.\n";
			system("pause");
			system("cls");
			break;
		} 
	} while (option != 5);

}

void AdoptApet::menu()
{

	int  menuOpt; 

	setPresetData(1, "Cat Food", "Whiskers", "1 KG", 15.00); 
	setPresetData(2, "Dog Food", "Doggo", "1 KG", 25.00); 
	setPresetData(3, "Dog Collar", "Dog's Friend", "1 UNIT", 5.00); 
	setPresetData(4, "Dog ID Tag", "Dog's Friend", "1 UNIT", 3.50); 
	setPresetData(5, "Dog Play Bone", "Dog's Friend", "1 UNIT", 9.00);
	do {
		system("cls");
		cout << endl << endl << "\t\t\t\t Main Menu:    " << endl;
		cout << "\t\t\t************************" << endl;
		cout << "\t\t\t 1. Customer menu" << endl;
		cout << "\t\t\t 2. Admin menu" << endl;
		cout << "\t\t\t 3. Exit Program" << endl;
		cout << "\t\t\t************************" << endl;
		cout << endl << endl << "\t\t\t Choose your option: ";
		while (!(cin >> menuOpt))
		{

			cin.clear();
			cin.ignore();
			break;
		}


		switch (menuOpt)
		{
		case 1:
			system("cls");
			customermenu();
			system("pause");
			break;

		case 2:
			system("cls");
			adminmenu();
			system("pause");
			break;

		case 3:
			system("cls");
			int confirm; 
			cout << "If you wish to continue to exit please enter 1..." << endl
				<< "otherwise, please enter any number other than 1 to go back to main menu." << endl;
			cout << "Enter your choice : ";
			cin >> confirm;
			if (confirm != 1)
			{
				menu();
			} 

			else
			{
				cout << endl << "\t\t\tYou are exiting this program...." << endl;
				cout << "\t\t-----------------------------------------------" << endl;
				cout << "\t\t\tThank You For Using This Program" << endl;
				cout << "\t\t-----------------------------------------------" << endl;
				system("pause");
			} 
			break; 

		default:
			cout << endl << "\t\t\tInavlid input. Please try again.\n";
			system("pause");
			system("cls");


		}
	} while (menuOpt != 3);

}

int main()
{
	AdoptApet program; 
	cout << "\t\t________________________________________________________________________________" << endl << endl;
	cout << "						        WELCOME TO ADOPT A PET                               " << endl << endl;
	cout << "\t\t________________________________________________________________________________" << endl << endl;
	cout << "Press Enter to continue..........." << endl;
	_getch();
	system("cls");
	program.menu(); 

}
