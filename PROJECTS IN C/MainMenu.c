
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};


void takeinput(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch)-1]=0;

}
void generateUsername(char email[50],char username[50]){
    for(int i=0;i<strlen(email);i++){
        if(email[i]='a')
        break;
        else
        username[i]=email[i];
    }
}
void takepassword(char pwd[50]){
    int i;
    char ch;
    while(1){
        ch = getch();
        if(ch==ENTER||ch==TAB){
            pwd[i]='\0';
            break;
        }
        else if(ch==BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");

            }
        }
        else{
            pwd[i++]=ch;
            printf("* \b");
        }
    }
}
void main(){

    system("color 0b");
    int opt;
    struct user user;
    printf("\n\t\t\t\t==========Welcome to authentication system==========");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");
    printf("\n\n Your choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);
    switch (opt)
    {
    case 1: printf("\nEnter your full name:\t");
        takeinput(user.fullName);
        printf("\nEnter your email:\t");
        takeinput(user.email);
        printf("\nEnter your contact number:\t");
        takeinput(user.phone);
        printf("\nEnter your password:\t");
        takepassword(user.password);
    
    default:
        break;
    }
}