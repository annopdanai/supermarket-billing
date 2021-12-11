//Login and registration system still not work
//but this is how it's supposed to look like
//TODO:Fix read/write file bug for login/register

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    struct user user;
    FILE *userData = fopen("userData.txt", "r");
    if (userData == NULL)
    {
        fputs("Error at opening file!", stderr);
        exit(1);
    }
    printf("Please enter your login credentials below\n\n");
    printf("Username: ");
    scanf("%s",user.username);
    printf("\nPassword: ");
    scanf("%s",user.password);
    printf("\n");
    while(fread(&user,sizeof(user),1,userData))
    {
        if(strcmp(username,"admin")==0 && strcmp(password,"password")==0)
        {
            printf("\nSuccessful Login\n");
        }
        else if(strcmp(username,user.username)==0 && strcmp(password,user.password)==0)
        {
            printf("\nSuccessful Login\n");
            printf("\nUsername: %s\n", username);
        }
        else
        {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
        }
    }
    fclose(userData);
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
