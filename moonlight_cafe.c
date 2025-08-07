#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max_data 1
#define max_staff 1
#define max_credit 1
#define max_order 20
#define max_admin 1
#define place_order 2

 typedef struct CAFE{
    char name[50];
    char address[50];
    char phoneno[50];
    char emailid[50];
    int logincode;
    int accountno;
    int password;
    char feedback[50];
    int staff_code;
    int salary;
    char post[50];
    char new_name[50];
    char new_address[50];
    char new_phoneno[50];
    char new_emailid[50];
 } cafe;

 typedef struct credit{
   char creditnum[50];
   char pin[50];
   int amount;
   char debitnum[20];
   char UPI_ID[20];
 } CR;

 typedef struct order{
    int id;
   char item_name[20];
   int prices;
 } ORD;

 typedef struct admin{
   char name[50];
   char password[50];
 }ADM;

 cafe cf[max_data];

 CR credit[max_credit];

 ADM admin[max_admin]={
   "mubarak","cse@2653",
 };

 ORD ord[max_order]={
   {1,"Espresso", 80},
    {2, "Cappuccino", 120},
    {3, "Latte", 130},
    {4, "Hot Chocolate", 100},
    {5, "Masala Chai", 60},
    {6, "Green Tea", 70},
    {7, "Iced Coffee", 110},
    {8, "Cold Coffee", 120},
    {9, "Iced Tea", 90},
    {10, "Lemonade", 80},
    {11, "Chocolate Milkshake", 130},
    {12, "Veg Sandwich", 100},
    {13, "Cheese Sandwich", 120},
    {14, "Veg Burger", 150},
    {15, "French Fries", 90},
    {16, "Garlic Bread", 80},
    {17, "Brownie", 70},
    {18, "Chocolate Cake", 150},
    {19, "Muffin", 60},
    {20, "Donut", 70},
};

int  total_bill=0;

 void createaccount();
 void displaycustomer();
 void order();
 int logincode();
 void customerreview();
 void displaymenu();
 int bill();
 int writemenu();
 void staffdetail();
 void user_side();
 void admin_side();
 int payment();
 void credit_card();
 void debit_card();
 void UPI();
 void update_details();
 



 int main(){
   srand(time(NULL));
   int option;
   printf("WELCOME TO MOONLIGHT CAFE!\n");
   printf("MAKE A CHOICE:\n1.USER SIDE\n2.ADMIN SIDE\n");
   scanf("%d",&option);
   getchar();

   if(option==1){
      user_side();
   }
   else if(option==2){
      admin_side();
   }
   else{
      printf("INVALID CHOICE..");
   }
  
      

 }


 void user_side(){
   
   int userchoice;
   do{
         printf("ENTER YOUR CHOICE:1.CREATE ACCOUNT\n2.DISPLAY CUSTOMER\n3.DISPLAY MENU\n4.PLACE ORDER\n5.PAYMENT\n6.CUSTOMER REVIEW\n7.UPDATE DETAILS\n8.EXIT");
         scanf("%d",&userchoice);
         getchar();
         switch(userchoice){
            case 1:createaccount();
                  break;
            case 2:displaycustomer();
                  break;
            case 3:displaymenu();
                  break;
            case 4:order();  
                  break;              
            case 5:payment();
                  break;
            case 6:customerreview();    
                  break; 
            case 7:update_details(); 
                  break;         
            case 8:printf("EXITING THE MENU...");
                   break;
         }
   } while(userchoice!=8);

 }


 void admin_side(){
   char name_1[20];
   char pass[20];
   printf("ENTER YOUR NAME & PASSWORD:");
   scanf("%s %s",name_1,pass);
   for(int i=0;i<max_admin;i++){
      if(strcmp(name_1,admin[i].name)==0 && strcmp(pass,admin[i].password)==0){
      int adminchoice;
   do{
      printf("ENTER YOUR CHOICE:1.STAFF DETAIL\n2.WRITE MENU\n3.EXIT");
      scanf("%d",&adminchoice);
      getchar();//REMOVE BUFFER AFTER INPUT 
      switch(adminchoice){
         case 1:staffdetail();
            break;
         case 2:writemenu();
            break;
         case 3:printf("EXITING THE MENU....");
            break;
      }
   }while(adminchoice!=3);
}
   else{
      printf("INVALID CREDENTIALS!!");
   }
}
}
 

 void createaccount(){
    for(int i=0;i<max_data;i++){
      printf("_______WELCOME TO OUR SHOP_______\n");
      printf("ENTER YOUR NAME:");
      scanf("%s",cf[i].name);
      printf("ENTER YOUR ADDRESS:");
      scanf("%s",cf[i].address);
      printf("ENTER YOUR NUMBER:");
      scanf("%s",cf[i].phoneno);
      printf("ENTER YOUR EMAIL ID:");
      scanf("%s",cf[i].emailid);
      cf[i].logincode=logincode();
      printf("YOUR LOGIN CODE:%d",cf[i].logincode);
 }
 }

 int logincode(){
    return rand()% 100000;
 }

 void displaycustomer(){
    int code;
    printf("ENTER YOUR LOGIN CODE:");
    scanf("%d",&code);
    for(int i=0;i<max_data;i++){
      if(code==cf[i].logincode){
         printf("1.NAME:%s\n2.NUMBER:%d\n3.ADDRESS:%s\n4.EMAIL ID:%s",cf[i].name,&cf[i].phoneno,cf[i].address,cf[i].emailid);
    }
 }
}

void customerreview(){
   for(int i=0;i<max_data;i++){
      int choice;
      printf("PLEASE GIVE US FEEDBACK\nGIVE US RATINGS:......\n");
      printf("1.poor\n2 Below average\n3.Average\n4.good\n5.Excellent\n");
      scanf("%d",&choice);
      switch(choice){
      case 1:
         printf("YOU HAVE GIVEN POOR RATINGS!!\n");
         printf("ENTER YOUR FEEDBACK:");
         scanf("%s",cf[i].feedback);
            break;
      case 2:printf("YOU HAVE GIVEN BELOW AVERAGE RATINGS!!\n");
         printf("ENTER YOUR FEEDBACK:");
         scanf("%s",cf[i].feedback);
            break;
      case 3:
         printf("YOU HAVE GIVEN AVERAGE RATINGS!!\n");
         printf("ENTER YOUR FEEDBACK:");
         scanf("%s",cf[i].feedback);
            break;
      case 4:
         printf("YOU HAVE GIVEN GOOD RATINGS!!\n");
         printf("ENTER YOUR FEEDBACK:");
         scanf("%s",cf[i].feedback);
            break;
      case 5:
         printf("YOU HAVE GIVEN EXCELLENT RATINGS!!\n");
         printf("ENTER YOUR FEEDBACK:");
         scanf("%s",cf[i].feedback);
            break;

   }
}
}

void displaymenu(){
   FILE *pfile=fopen("MENU.txt","r");
   char text[100];

   if(pfile==NULL){
      printf("ERROR OPENING FILE!!\n");
   }

   while(fgets(text,sizeof(text),pfile)!=NULL)
   {
      printf("%s",text);

   }  
}

//ADMIN FUNCTIONS:

int writemenu(){
    char text[100];
    FILE *pfile=fopen("MENU.txt","a");
     if(pfile==NULL){
        printf("ERROR OPENING FILE"); 
        return 1;
     }

     printf("ENTER YOUR MENU:");
     gets(text);//takes input
     fputs(text,pfile);//prints input to file

    fprintf(pfile,"%s",text);
     printf("WRITTEN SUCCESFULLY!");
     fclose(pfile);
     return 0;
} 

void staffdetail(){
    char name[100];
   char phoneno[100];
    char email[100];

    

    FILE *pfile=fopen("STAFF.txt","a");

    if(pfile==NULL){
        printf("ERROR OPENING FILE!!");
    }

    for (int i = 0; i < max_staff; i++) {
        printf("ENTER YOUR NAME:");
        fgets(name,sizeof(name),stdin);

        printf("ENTER YOUR NUMBER:");
        scanf("%s",phoneno);
        getchar();// it will remove buffer line

        printf("ENTER YOUR EMAIL ID:");
        fgets(email,sizeof(email),stdin);

        cf[i].staff_code=logincode();
        printf("YOUR CODE:%d\n",cf[i].staff_code);
        fprintf( pfile,"Name: %sPHONE NUMBER: %s\nEMAIL:%s\n PASS CODE:%d\n",name,phoneno,email,cf[i].staff_code);//print data in the file 
 
      printf("ENTER YOUR POST:\n");
      scanf("%s",cf[i].post);

      if(strcmp(cf[i].post,"MANAGER")==0||strcmp(cf[i].post,"manager")==0){
         printf("YOUR SALARY=50K+PERKS");
      }
      else if(strcmp(cf[i].post,"ACCOUNTANT")==0||strcmp(cf[i].post,"accountant")==0){
         printf("YOUR SALARY=40K+PERKS");
      }
      else if (strcmp(cf[i].post,"CHEF")==0||strcmp(cf[i].post,"chef")==0){
         printf("YOUR SALARY=30K+PERKS");
      }
      else if (strcmp(cf[i].post,"MANAGER")==0||strcmp(cf[i].post,"manager")==0){
         printf("YOUR SALARY=15K+PERKS");      
   
      }
      else{
      printf("POST NOT AVAILABLE:");
      }
   }
}


void order(){
   int size=sizeof(ord)/sizeof(ord[0]);
   int id[place_order];
   int count=0; 
   printf("......DISPLAYING MENU.......\n");
   for(int i=0;i<size;i++){
            printf("%d.\"%s\" = %drs\n", ord[i].id, ord[i].item_name, ord[i].prices);//loop to display menu
   }

   for(int j=0;j<place_order;j++){// loop to take orders
    printf("ENTER YOUR ORDER:\n");
    scanf("%d",&id[j]);
    
   }

    for(int i=0;i<size;i++){    
       for(int j=0;j<place_order;j++){// loop to match order id to entered id
              if(id[j]==ord[i].id){
                 
                  printf("YOU ORDERED  %s=%dRs\n",ord[i].item_name,ord[i].prices);
                  total_bill=total_bill+ord[i].prices;
                  
                 
         }
      }
   }
    printf("______________ORDER RECIEPT___________\n");
      time_t currentTime;
      time(&currentTime); 
      printf("YOUR TOTAL BILL :%d RS\n",total_bill); // Get current system time
      printf("date\ttime: %s", ctime(&currentTime));
     printf("_________________________________\n");
}

int payment(){
   int pay;
   printf("ENTER OPTION TO PAY:\n");
   printf("1.CREDIT CARD\n2.DEBIT CARD\n3.UPI\n");
   scanf("%d",&pay);
   switch(pay){
      case 1:
         credit_card();
         break;
      case 2:
         debit_card();
         break;   
      case 3:
         UPI();
         break;

   }

}

void credit_card(){
   char choice[50];
  for(int i=0;i<max_credit;i++){
   printf("ENTER CREDIT CARD NUMBER:");
   scanf("%s",credit[i].creditnum);
   printf("ENTER YOUR PIN:");
   scanf("%s",credit[i].pin);
   printf("Initiating payment of Rs %d to MOONLIGHT CAFE from CREDIT CARD %s...\n",total_bill, credit[i].creditnum);
   printf("PAYING RS %d TO CAFE\n",total_bill);
   printf("DO YOU WANT TO PAY RS %d (Y/N)?",total_bill);
   scanf("%s",choice);
    
   if(strcmp(choice,"Y")==0||strcmp(choice,"y")==0)
   {
      printf("_______PAYMENT RECIEPT________\n");
      printf("PAYMENT SUCCESFUL!!\n"); 
      time_t currentTime;
      time(&currentTime);  // Get current system time
      printf("date&time: %s",ctime(&currentTime));
   }
   else if(strcmp(choice,"N")==0||strcmp(choice,"n")==0)
   {
      printf("PAYMENT CANCELLED..");
      
   }
   else
   {
      printf("INVALID CHOICE!!");
   }
}
}
void debit_card(){
   char choice[50];
   for(int i=0;i<max_credit;i++){
      printf("ENTER DEBIT CARD NUMBER:");
      scanf("%s",credit[i].debitnum);
      printf("ENTER YOUR PIN:");
      scanf("%s",credit[i].pin);
      printf("Initiating payment of Rs %d to MOONLIGHT CAFE from DEBIT CARD %s...\n", total_bill, credit[i].debitnum);
      printf("DO YOU WANT TO PAY RS %d (Y/N)?",total_bill);
      scanf("%s",choice);
    
   if(strcmp(choice,"Y")==0||strcmp(choice,"y")==0)
   {
      printf("_______PAYMENT RECIEPT________\n");
      printf("PAYMENT SUCCESFUL!!\n");   
      time_t currentTime;
      time(&currentTime);  // Get current system time
      printf("date\ttime: %s", ctime(&currentTime));
   }
   else if(strcmp(choice,"N")==0||strcmp(choice,"n")==0)
   {
      printf("PAYMENT CANCELLED..");
      
   }
   else
   {
      printf("INVALID CHOICE!!");
   }
}
}

void UPI(){
   char choice[50];
   for(int i=0;i<max_credit;i++){
      printf("ENTER UPI ID:");
      scanf("%s",credit[i].UPI_ID);
      printf("ENTER YOUR PIN:");
      scanf("%s",credit[i].pin);
      printf("Initiating payment of Rs %d to MOONLIGHT CAFE from UPI ID %s...\n", total_bill, credit[i].UPI_ID);
      printf("PAYING RS %d TO CAFE\n",total_bill);
      printf("DO YOU WANT TO PAY RS %d (Y/N)?",total_bill);
      scanf("%s",choice);
    
   if(strcmp(choice,"Y")==0||strcmp(choice,"y")==0)
   {
      printf("_______PAYMENT RECIEPT________\n");
      printf("PAYMENT SUCCESFUL!!\n");  
      time_t currentTime;
      time(&currentTime);  // Get current system time
      printf("date&time: %s", ctime(&currentTime));
   }
   else if(strcmp(choice,"N")==0||strcmp(choice,"n")==0)
   {
      printf("PAYMENT CANCELLED..");
      
   } 
   else
   {
      printf("INVALID CHOICE!!");
   }
}

}

void update_details(){
   int choose;
   for(int i=0;i<max_data;i++){
   printf("WHAT DO YOU WANT UPDATE:1.NAME\n2.ADDRESS\n3.PHONE NO:\n4.EMAIL ID\n");
   scanf("%d",&choose);
   if(choose==1){
      printf("YOUR NAME IS %s\n",cf[i].name);
      printf("ENTER NAME YOU WANT TO CHANGE:");
      scanf("%s",cf[i].new_name);
      getchar();
      printf("YOUR UPDATED NAME IS %s\n",cf[i].new_name);
   }
   else if(choose==2){
      printf("YOUR ADDRESS IS %s\n",cf[i].address);
      printf("ENTER ADDRESS YOU WANT TO CHANGE:\n");
      scanf("%s",cf[i].new_address);
      getchar();
      printf("YOUR UPDATED ADDRESS IS %s\n",cf[i].new_address);
   }
   if(choose==3){
      printf("YOUR PHONE NO IS %s\n",cf[i].phoneno);
      printf("ENTER PHONE NO YOU WANT TO CHANGE:");
      scanf("%s",cf[i].new_phoneno);
      getchar();
      printf("YOUR UPDATED PHONE NO IS %s\n",cf[i].new_phoneno);
   }
   if(choose==4){
   printf("YOUR EMAIL ID IS %s\n",cf[i].emailid);
   printf("ENTER EMAIL ID YOU WANT TO CHANGE:");
   scanf("%s",cf[i].new_phoneno);
   printf("YOUR UPDATED EMAIL ID IS %s\n",cf[i].new_phoneno);
}
}
}