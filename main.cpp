#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "password"

void buy(char username[]);
void save();
void admin_menu();
void user_menu(char username[]);

using namespace std;
fstream file;
class user
{
private:
    char username[20];
    char password[20];
public:
    void Register()
    {
        file.open("userData.txt", ios::app | ios::out);
        cout << "\nStart registration process" << endl;
        cout << "Please enter your credentials below" << endl;
        cout << endl << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        while (strcmp(username, ADMIN_USERNAME) == 0)
        {
            cout << "You can't register as admin" << endl;
            cout << endl << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;
        }
        cout << "\n--- Registration complete ---" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl << endl;

        file.write(reinterpret_cast<char*>(this), sizeof(*this));
        file.close();
    }

    int login()
    {
        char u[20];
        char pass[20];
        int status;
        cout << "\n\t\tPlease enter your login credentials below\n";
        cout << "\tUsername: ";
        cin >> u;
        cout << "\tPassword: ";
        cin >> pass;
        file.open("userData.txt", ios::in);
        file.seekg(0);
        file.read(reinterpret_cast<char*>(this), sizeof(*this));
        while (!file.eof())
        {
            if (strcmp(u, ADMIN_USERNAME) == 0)
            {
                if (strcmp(pass, ADMIN_PASSWORD) == 0)
                {
                    status = 2;
                    break;
                }
            }
            if (strcmp(username, u) == 0)
            {
                if (strcmp(password, pass) == 0)
                {
                    status = 1;
                    break;
                }
            }
            file.read(reinterpret_cast<char*>(this), sizeof(*this));

        }
        system("cls");
        if (status == 2)
            cout << "Logged in as admin",admin_menu();

        else if (status == 1)
        {
            cout << "Logged in as user: " << username;

            user_menu(username);

        }

        else
            cout << "Incorrect user or password";
        file.close();
        return 0;

    }


};

class product
{
    int number;
    char name[50];
    float price;

public:

    void create()
    {
        cout << endl << "Enter Product Number: ";
        cin >> number;
        cout << endl << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << endl << "Enter Price: ";
        cin >> price;
    }
    int getProduct() const
    {
        return number;
    }

    float getPrice() const
    {
        return price;
    }

    char* getName()
    {
        return name;
    }
};

product produc;
fstream fp;
void save()
{
    fp.open("item.txt", ios::out | ios::app);
    produc.create();
    fp.write((char*)&produc, sizeof(product));
    fp.close();
    system("cls");
    cout << endl << endl << "Product created";
}

void menu()
{
    system("cls");
    int option;
	for (;;)
	{
    fp.open("item.txt", ios::in);

    cout << endl << endl << "\t\tProduct MENU\n\n";
    cout << "-----------------------------------------------------\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "-----------------------------------------------------\n";
    while (fp.read((char*)&produc, sizeof(product)))
    {
        cout << produc.getProduct() << "\t\t" << produc.getName() << "\t\t" << produc.getPrice() << endl;
    }
    fp.close();



		cout << "\n\t----------------------------------------";
		cout << "\n\t1. Save";
		cout << "\n\t2. Back";
		cout << "\n\t----------------------------------------";

		cout << "\n\tOption: ";
		cin >> option;

		switch (option)
		{
		case 1: system("cls");
			save();
			break;

		case 2: system("cls");
			admin_menu();
			break;

		default:system("cls");
            cout << "Logged in as admin\n";
			cout << "Enter 1 - 2 only\n";

		}
}
}

void buy(char username[])
{
    int order_arr[50], quan[50], c = 0;
    float amount, total = 0;
    char ch = 'Y';

    fp.open("item.txt", ios::in);
    cout << "Logged in as user: " << username << endl ;
    cout << endl << endl << "\t\tProduct MENU\n\n";
    cout << "-----------------------------------------------------\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "-----------------------------------------------------\n";
    while (fp.read((char*)&produc, sizeof(product)))
    {
        cout << produc.getProduct() << "\t\t" << produc.getName() << "\t\t" << produc.getPrice() << endl;
    }

    fp.close();
    cout << "\n--------------------------------------------------";
    cout << "\n SELECT ORDER";
    cout << "\n--------------------------------------------------\n";
    do {
        cout << "\n\nEnter Product no. : ";
        cin >> order_arr[c];
        cout << "\nEnter Amount: ";
        cin >> quan[c];
        c++;
        cout << "\nAnything else you want? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    getchar();
    system("cls");

    cout << "Logged in as user: " << username << endl ;
    cout << "\nProduct No.\tProduct Name\tAmount \t\tPrice \t\tTotal ";
    for (int x = 0;x <= c;x++)
    {
        fp.open("item.txt", ios::in);
        fp.read((char*)&produc, sizeof(product));
        while (!fp.eof())
        {
            if (produc.getProduct() == order_arr[x])
            {
                amount = produc.getPrice() * quan[x];
                cout << "\n" << order_arr[x] << "\t\t" << produc.getName() << "\t\t" << quan[x] << "\t\t" << produc.getPrice() << "\t\t" << amount;
                total += amount;
            }
            fp.read((char*)&produc, sizeof(product));
        }
        fp.close();
    }


    cout << "\n\n\t\t\t\t\t\t\tTOTAL = " << total;

    cout << "\n\n\n\t--------------------------------------------------";
    cout << "\n\t|            Thank for your purchase             |";
    cout << "\n\t--------------------------------------------------";

    cout << "\n\nPress enter to continue";
    getchar();
    system("cls");
    cout << "Logged in as user: " << username << endl ;
    user_menu(username);
}
int main()
{
	system("cls");
	int option;

	for (;;)
	{

		cout << "\n\t----------------------------------------";
		cout << "\n\t1. Log in";
		cout << "\n\t2. Register";
		cout << "\n\t3. EXIT";
		cout << "\n\t----------------------------------------";

		cout << "\n\tOption: ";
		cin >> option;
        user u{};
		switch (option)
		{
		case 1: system("cls");
			u.login();
			break;

		case 2: system("cls");
			u.Register();
			break;

		case 3:
			exit(0);

		default:system("cls");
			cout << "Enter 1 - 3 only\n";

		}

	}
}

void admin_menu()
{
	int option;
	for (;;)
	{

		cout << "\n\t----------------------------------------";
		cout << "\n\t1. Menu";
		cout << "\n\t2. Save";
		cout << "\n\t3. Log out";
		cout << "\n\t----------------------------------------";

		cout << "\n\tOption: ";
		cin >> option;

		switch (option)
		{
		case 1: system("cls");
			menu();
			break;

		case 2: system("cls");
			save();
			break;

		case 3:
			main();

		default:system("cls");
            cout << "Logged in as admin\n";
			cout << "Enter 1 - 3 only\n";

		}

	}
}

void user_menu(char username[])
{
	int option;
	for (;;)
	{

		cout << "\n\t----------------------------------------";
		cout << "\n\t1. Buy";
		cout << "\n\t2. Log out";
		cout << "\n\t----------------------------------------";

		cout << "\n\tOption: ";
		cin >> option;

		switch (option)
		{
		case 1: system("cls");
			buy(username);
			break;

		case 2:
			main();

		default:system("cls");
            cout << "Logged in as user: " << username;
			cout << "\nEnter 1 - 2 only\n";
		}
	}
}
