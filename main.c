//Login and registration system still not work
//but this is how it's supposed to look like
//TODO:Fix read/write file bug for login/register

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
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
    printf("Welcome!\n");
    printf("If you're guest, please register. If you're member, please login.\n\n");
    printf("Option\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n"); // still not update in github

    printf("Enter your option: ");
    scanf("%d", &option);

    if (option == 1)
        Login();
    else if (option == 2)
        Register();
    else if (option == 3)
        exit(1);
    else
    {
        /*
         //Mac&Linux//
         printf("\nWrong choice\n\n");
         printf("Please input anything to continue ... \t");
         system("read")
        */
        
        //Windows//
        char buffer[20];
        printf("\nWrong choice\n\n");
        printf("Please input anything to continue ... \t");
        scanf("%s", buffer);
    }
    if (system("CLS")) system("clear");
    main();
}

void Login()
{
    char username[30],password[20];
    struct user u;
    FILE *file_userData = fopen("userData.txt", "r");
    if (file_userData == NULL)
    {
        fputs("Error at opening file!", stderr);
        exit(1);
    }
    printf("Please enter your login credentials below\n\n");
    printf("Username: ");
    scanf("%s",u.username);
    printf("\nPassword: ");
    scanf("%s",u.password);
    printf("\n");
    while(fread(&u,sizeof(u),1,file_userData))
    {
        if(strcmp(username,"admin")==0 && strcmp(password,"password")==0)
        {
            printf("\nSuccessful Login\n");
        }
        else if(strcmp(username,u.username)==0 && strcmp(password,u.password)==0)
        {
            printf("\nSuccessful Login\n");
            printf("\nUsername: %s\n", username);
        }
        else
        {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
        }
    }
    fclose(file_userData);
}

void Register()
{
    FILE *file_userData = fopen("userData.txt", "a");
    struct user u;
    
    printf("\nStart registration process\n");
    printf("Please enter your credentials below\n\n");

    printf("Username: ");
    scanf("%s",u.username);

    printf("Password: ");
    scanf("%s",u.password);

    printf("\n--- Registration complete ---\nUsername: %s Password: %s\n", u.username, u.password);

    printf("\n");
    fprintf(file_userData, "Username: %s Password: %s \n", u.username, u.password);
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
