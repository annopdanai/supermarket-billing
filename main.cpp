//Known errors
//1. Login system doesn't work

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

struct user{
    char username[30];
    char password[20];
};

int option;

void Login();
void Register();

int main()
{
    cout << "Welcome!" << endl;
    cout << "If you're guest, please register. If you're member, please login.\n" << endl;
    cout << "Option" << endl;
    cout << "1. Login" << endl; //Need to fix
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;

    cout << endl << "Enter your option: ";
    cin >> option;

    if (option == 1)
        Login();
    else if (option == 2)
        Register();
    else if (option == 3)
        exit(0);
    else
    {
        cout << "\nWrong choice\n\n";
        cout << "Press any key to continue... " << endl;
        getchar();
        getchar();
        if (system("CLS")) system("clear");
        main();
    }
}

void Login()
{
    char username[30],password[20];
<<<<<<< HEAD:main.c
    struct user u;
    FILE *file_userData = fopen("userData.txt", "r");
    if (file_userData == NULL)
=======
    struct user u{};
    FILE *file_userData = fopen("userData.txt", "r");
    if (file_userData == nullptr)
>>>>>>> develop-beam:main.cpp
    {
        fputs("Error at opening file!", stderr);
        exit(1);
    }
<<<<<<< HEAD:main.c
    printf("Please enter your login credentials below\n\n");
    printf("Username: ");
    scanf("%s",u.username);
    printf("\nPassword: ");
    scanf("%s",u.password);
    printf("\n");
=======
    cout << endl << "Please enter your login credentials below\n" << endl;
    cout << "Username: ";
    cin >> u.username;
    cout << "Password: ";
    cin >> u.password;
    //Line below is the cause of issue
>>>>>>> develop-beam:main.cpp
    while(fread(&u,sizeof(u),1,file_userData))
    {
        if(strcmp(username,"admin")==0 && strcmp(password,"password")==0)
        {
            cout << "\nSuccessful Login\n";
        }
        else if(strcmp(username,u.username)==0 && strcmp(password,u.password)==0)
        {
            cout << "\nSuccessful Login\n";
            cout << "\nUsername: %s << username\n";
            cout << "\nPassword: %s << password\n";
        }
        else
        {
            cout << "\nIncorrect Login Details\nPlease enter the correct credentials\n";
        }
    }
    fclose(file_userData);
}

void Register()
{
    FILE *file_userData = fopen("userData.txt", "a");
    struct user u{};
    
    cout << "\nStart registration process" << endl;
    cout << "Please enter your credentials below" << endl;

    cout << endl << "Username: ";
    cin >> u.username;

    cout << "Password: ";
    cin >> u.password;

    cout << "\n--- Registration complete ---" << endl;
    cout << "Username: " << u.username << endl;
    cout << "Password: " << u.password << endl << endl;

    fprintf(file_userData, "%s %s \n", u.username, u.password);
    fclose(file_userData);
    main();
}

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

fstream fp;
product produc;

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
}

void buy()
{
	int order_arr[50], quan[50], c = 0;
	float amount, total = 0;
	char ch = 'Y';
	menu();
	cout << "\n--------------------------------------------------";
	cout << "\n SELECT ORDER";
	cout << "\n--------------------------------------------------\n";
	do {
		cout << "\n\nEnter Product no.: ";
		cin >> order_arr[c];
		cout << "\nEnter Amount: ";
		cin >> quan[c];
		c++;
		cout << "\nAnything else you want? (y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	getchar();
	system("cls");
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
	getchar();
}
