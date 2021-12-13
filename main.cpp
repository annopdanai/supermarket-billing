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

void login();
void register();

void save();
void menu();
void buy();

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
        login();
    else if (option == 2)
        register();
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

void login()
{
    char username[30],password[20];
    struct user u{};
    FILE *file_userData = fopen("userData.csv", "r");
    if (file_userData == nullptr)
    {
        fputs("Error at opening file!", stderr);
        exit(1);
    }
    cout << endl << "Please enter your login credentials below\n" << endl;
    cout << "Username: ";
    cin >> u.username;
    cout << "Password: ";
    cin >> u.password;
	
    char line[100];
    int buff_1, buff_2, status = 0;

    while(fgets(line, sizeof(line), file_userData))
    {
        buff_1 = 0;

        for(int i = 0; i < strlen(line); i++)
            {
                if(line[i] == ',')
                {
                    username[buff_1] = NULL;
                    break;
                }
                else
                {
                    username[buff_1] = line[i];
                    buff_1++;
                }
            }

        if(strcmp(username, u.username) == 0)
        {
            buff_1 = 0;
            buff_2 = 0;

            while(line[buff_2] != ',')
                buff_2++;

            buff_2++;
            while(line[buff_2] != '\n')
            {
                password[buff_1] = line[buff_2];
                buff_2++;
                buff_1++;
            }
            password[buff_1] = NULL;


            if(strcmp(u.password,password) == 0)
            {
                status = 1;
                break;
            }
            else
            {
                status = -1;
                break;
            }
        }
    }

    if(status == 1)
        printf("Log in successfully");
    else if(status == -1)
        printf("Password incorrect");
    else
        printf("Username incorrect");
    fclose(file_userData);
}

void register()
{
    FILE *file_userData = fopen("userData.csv", "a");
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

    fprintf(file_userData, "%s,%s\n", u.username, u.password);
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
	int getProduct()
	{
		return number;
	}

	float getPrice()
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
