#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int quantity;   
};

struct orders{
    char customer[50];
    char date[50];
    int numberofitems;
    struct items itm[50];
};
void generateBillHeader(char name[50], char date[30]){
    printf("D MART\n");
    printf("\nWelcome to the MART\n");
    printf("==========================================");
    printf("\n Date:%s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf("==========================================");
    printf("\n\n");
    printf("Items \t\t");
    printf("Quantity\t\t");
    printf("Total\t\t");
    printf("==========================================");
    printf("\n\n");
}
void generateBillBody(char item[30], int quantity, float price){
    printf("%s\t\t",item);
    printf("%d\t\t",quantity);
    printf("%.2f\t\t",quantity*price);
    printf("\n");
}
void generateBillFooter(float total){
    printf("\n");
    float dis=0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal+2*cgst;
    printf("==========================================");
    printf("Sub Total\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t","%d",dis);
    printf("\n\t\t\t--------");
    printf("\n Net Total\t\t\t%.2f","%",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("==========================================");
    printf("\n Grand Total\t\t\t%.2f",grandTotal);
    printf("==========================================");
}
int main(){
    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill='y',contFlag='y';
    char name[50];
    FILE *fp;
    while(contFlag =='y'){
        system("clear");
        float total=0;
        int invoiceFound=0;
        printf("\t=============D MART============");
        printf("\n\nPlease select your perfered operation");
        printf("\n1.Generate Invoice");
        printf("\n2.Show all Invoice");
        printf("\n3.Search Invoice");
        printf("\n4.Exit");
        printf("\n\nYour choice:\t");
        scanf("%d",&opt);
        fgetc(stdin);
        switch (opt)
        {
        case 1: 
        system("clear");
        printf("\nPlease enter the name of the customer:\t");;
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1]=0;
        strcpy(ord.date,__DATE__);
        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("please enter the item %d",i+1);
            fgets(ord.itm[i].item,20,stdin);
            printf("Please enter the quantity:\t");
            scanf("%d",&ord.itm[i].quantity);
            printf("Please enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].quantity * ord.itm[i].price;
        }

        generateBillHeader(ord.customer,ord.date);
        for(int i=0;i<ord.numberofitems;i++){
            generateBillBody(ord.itm[i].item,ord.itm[i].quantity,ord.itm[i].price);
        }
        generateBillFooter(total);

        printf("\nDo you want to save the invoice [y/n]:\t");
        scanf("%s",&saveBill);

        if(saveBill == 'y'){
            fp = fopen("RestaurantBill.dat","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            printf("\nSuccessfully saved");
            else 
            printf("\nError saving");
            fclose(fp);
        }
        break;

        case 2:
        system("clear");
        fp = fopen("RestaurantBill.dat","r");
        printf("\n  *****Your Previous Invoices*****\n");
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot = 0;
            generateBillHeader(order.customer,order.date);
            for(int i=0;i<order.numberofitems;i++){
                generateBillBody(order.itm[i].item,order.itm[i].quantity,order.itm[i].price);
                tot+=order.itm[i].quantity * order.itm[i].price;
            }
            generateBillFooter(tot);
        }
        fclose(fp);
        break;

        case 3:
        printf("Enter the name of the customer:\t");
        //fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)-1] = 0;
        system("clear");
        fp = fopen("RestaurantBill.dat","r");
        printf("\t*****Invoice of %s*****",name);
        while(fread(&order,sizeof(struct orders),1,fp)){
            float tot = 0;
            if(!strcmp(order.customer,name)){
            generateBillHeader(order.customer,order.date);
            for(int i=0;i<order.numberofitems;i++){
                generateBillBody(order.itm[i].item,order.itm[i].quantity,order.itm[i].price);
                tot+=order.itm[i].quantity * order.itm[i].price;
            }
            generateBillFooter(tot);
            invoiceFound = 1;
            }
        
        }
        if(!invoiceFound){
            printf("Sorry the invoice for %s doesnot exists",name);
        }
        fclose(fp);
        break;

    case 4:
    printf("\n\t\t Bye Bye :)\n\n");
    exit(0);
    break;

    default:
    printf("Sorry invalid option");
    break;
    }
    printf("\nDo you want to perform another operation?[y/n]:\t");
    scanf("%s",&contFlag);
    }
    printf("\n\t\t Bye Bye :)\n\n");
    printf("\n\n");

    return 0;
}