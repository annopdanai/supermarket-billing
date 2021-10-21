#include <stdio.h>
#include <string.h>
FILE *f;
int main()
{
    char username[20];
    char password[20];

    if((f=fopen("shop.txt","w"))==NULL)
    {
        printf("...can not open file...");
        printf("\n...press any key to exit...");
    }

    printf("Please login to continue\n");
    printf("If you're guest, please use \"guest\" as username and password\n\n");

    printf("Enter your username: ");
    scanf("%s", &username);

    printf("Enter your password: ");
    scanf("%s", &password);

    if(strcmp(username,"guest")==0){
        if(strcmp(password,"guest")==0){
            printf("\nWelcome! You're currently logging in as guest.");
        }
    }

    else if (strcmp(username,"admin")==0){
            if(strcmp(password,"password")==0){
                printf("\nWelcome! You're currently logging in as admin.");
                }
            }
    else
        printf("\nWrong username or password");
}