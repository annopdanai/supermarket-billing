#include <stdio.h>
#include <string.h>
char username;
char password;
char option;
char user;
char pass;

void Login();
void Register();
FILE *f;
int main()
{
    printf("Welcome!\n");
    printf("If you're guest, please register. If you're member, please login.\n\n");
    printf("Option\n");
    printf("1. Login\n");
    printf("2. Register\n");

    printf("Enter your option: ");
    scanf("%s", &option);
    
    if (option == '1')
        Login();
    else if (option == '2')
        Register();
    else
        printf("\nWrong username or password");
}

void Login()
{
    printf("Enter your username: ");
    scanf("%s", &username);

    printf("Enter your password: ");
    scanf("%s", &password);

    if (username == "admin"){
            if (password == "password"){
                printf("\nWelcome! You're currently logging in as admin.");
                }
            }

}

void Register()
{
    //register
}