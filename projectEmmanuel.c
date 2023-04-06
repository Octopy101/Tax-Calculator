#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 40//The maximum number of clients's in the system
#define SIZE 100 //Defines size of string 
#define RELIEF_S 650 //The tax relief for single clients
#define RELIEF_M 1100 //The tax relief for married clients

int Greetings(void);
int table(void);//Displays the taxtion table
float negative(float x); //Ensures no negative value is include in calculation
float gross(float a,float b,float d,float e);//calculates gross
float taxableIncome(float gross,int y);//calculates the taxable income
float tax( float taxableIncome);//calculates the tax
float net(float gross,float tax);//calculates the net pay
int check(int x);//Ensures that only the availed choices are selected
int check2(int x,int b);//Ensures that only created structures accessed

//Structure for holding clients details
typedef struct client{
   char fullname[SIZE];
   char MStatus[SIZE];
   float basicSalary;
   float medicalAllowance;
   float houseAllowance;
   float commuterAllowance;
   float gross;
   float taxableIncome;
   float tax;
   float net;
}client;

int main(){
    Greetings();
    table();
    client emp[MAXSIZE-1];//creates structs for each client in the system
    float b=0,c=0,d=0,e=0;
    int MStatus=1;
    int position=1;//shows the number of a client;

    printf("Fill in the data below: \n");
    printf("Client number: %d\n",position);
    printf("Client's name: ");
    fgets(emp[1].fullname,SIZE,stdin);
    emp[1].fullname[strcspn(emp[1].fullname, "\n")] = 0;
    fflush(stdin);
    printf("Basic salary: ");
    scanf("%f",&b);
    fflush(stdin);
    emp[1].basicSalary=negative(b);
    printf("Medical Allowance: ");
    scanf("%f",&e);
    fflush(stdin);
    emp[1].medicalAllowance=negative(e);
    printf("House Allowance: ");
    scanf("%f",&c);
    fflush(stdin);
    emp[1].houseAllowance=negative(c);
    printf("Commuter Allowance: ");
    scanf("%f",&d);
    fflush(stdin);
    emp[1].commuterAllowance=negative(d);
    printf("Marital Status:Enter\n\t(1)->Single Client\n\t(2)->Married client: ");
    scanf("%d",&MStatus);//stores the number selected above
    fflush(stdin);
    switch (MStatus)
    {
    case 1:
        strcpy(emp[1].MStatus,"Single Client");
        break;
    case 2:
        strcpy(emp[1].MStatus,"Married Client");
        break;
    default:
    //the loop ensures that only the availed choices are selected 
     do{
            printf("Invalid input!\n Re-enter (1)->Single Client or (2)->Married Client: ");
            scanf("%d",&MStatus);
            fflush(stdin);
            if(MStatus==1){
                strcpy(emp[1].MStatus,"Single Client");
            }else if(MStatus==2){
                strcpy(emp[1].MStatus,"Married Client");
            }
        }while(MStatus!=1 && MStatus!=2);
        break;
    };

    //calculation of gross pay,taxable income,tax and net pay
    emp[1].gross=gross(emp[1].basicSalary,emp[1].houseAllowance,emp[1].medicalAllowance,emp[1].commuterAllowance);
    emp[1].taxableIncome=taxableIncome(emp[1].gross,MStatus);
    emp[1].tax=tax(emp[1].taxableIncome);
    emp[1].net=net(emp[1].gross,emp[1].tax);
    

    int redo=1;//used to keep the system the loop below
    int choice;//stores the choice selected in the loop
 do{
    printf("\n Would you like to:\n 1->Display records of an individual client. \n 2->Display all records. \n 3->Enter a new client. \n 4->Exit program \n CHOICE: ");
    scanf("%d",&choice);
    choice=check(choice);
    switch (choice)
    {
    case 1:
        int answer;//stores the choice selected
        printf("Enter Client's Number: ");
        scanf("%d",&answer);
        answer=check2(answer,position);
            //displays records of clients individually
            printf("\n");
            printf("Name of employee:-->%s\n**************************\n",emp[answer].fullname);
            printf("Basic salary: Ksh.%.2f\n",emp[answer].basicSalary);
            printf("House Allowance: Ksh.%.2f\n", emp[answer].houseAllowance);
            printf("Medical Allowance: Ksh.%.2f\n", emp[answer].medicalAllowance);
            printf("Commuter Allowance: Ksh.%.2f\n", emp[answer].commuterAllowance);
            printf("Gross pay: Ksh.%.2f\n",emp[answer].gross);
            printf("Taxable-Income: Ksh.%.2f\n", emp[answer].taxableIncome);
            printf("Tax: Ksh.%.2f\n", emp[answer].tax);
            printf("Net Pay: Ksh.%.2f\n", emp[answer].net);
            printf("Martial Status: %s\n", emp[answer].MStatus);
        break;
    case 2:
        //displays all records in a table format
        printf("%-10s %-10s\t %-10s\t %-10s\t %-10s\t %-10s\t %-12s\t %-10s %-10s\n","No","Name","BasicSalary","HouseAllowance","MedicalAllowance","CommuterAllowance","MartialStatus","Tax","Net Pay");
        printf("______________________________________________________________________________________________________________________________________________\n");
        for(int x=1;x<=position;x++){
          printf("%-5d %-10s\t %-10.2f\t %-10.2f\t %-10.2f\t\t %-10.2f\t\t %-12s\t %-10.2f %-10.2f\n",x,emp[x].fullname,emp[x].basicSalary,emp[x].houseAllowance,emp[x].medicalAllowance,emp[x].commuterAllowance,emp[x].MStatus,emp[x].tax,emp[x].net);
        }
        break; 
    case 3:
        position++;//increments the current number of client to add a new client into the system
        fflush(stdin);
        printf("\nFill in data of the new client below: \n");
        printf("Client number: %d\n",position);
        printf("Client's name: ");
        fgets(emp[position].fullname,SIZE,stdin);
        emp[position].fullname[strcspn(emp[position].fullname, "\n")] = 0;  
        printf("Basic salary: ");
        scanf("%f",&b);
        fflush(stdin);
        emp[position].basicSalary=negative(b);
        printf("Medical Allowance: ");
        scanf("%f",&e);
        fflush(stdin);
        emp[position].medicalAllowance=negative(e);
        printf("House Allowance: ");
        scanf("%f",&c);
        fflush(stdin);
        emp[position].houseAllowance=negative(c);
        printf("Commuter Allowance: ");
        scanf("%f",&d);
        fflush(stdin);
        emp[position].commuterAllowance=negative(d);
        printf("Marital Status:Enter\n\t(1)->Single Client\n\t(2)->Married client: ");
        scanf("%d",&MStatus);
        fflush(stdin);
        switch (MStatus)
            {
                case 1:
                    strcpy(emp[position].MStatus,"Single Client");
                    break;
                case 2:
                    strcpy(emp[position].MStatus,"Married Client");
                    break;
                default:
                do{
                        printf("Invalid input!\n Re-enter (1)->Single Client or (2)->Married Client: ");
                        scanf("%d",&MStatus);
                        fflush(stdin);
                        if(MStatus==1){
                            strcpy(emp[position].MStatus,"Single Client");
                        }else if(MStatus==2){
                            strcpy(emp[position].MStatus,"Married Client");
                        }
                    }while(MStatus!=1 && MStatus!=2);
                    break;
            };
            //calculation of gross pay,taxable income,tax and net pay
            emp[position].gross=gross(emp[position].basicSalary,emp[position].houseAllowance,emp[position].medicalAllowance,emp[position].commuterAllowance);
            emp[position].taxableIncome=taxableIncome(emp[position].gross,MStatus);
            emp[position].tax=tax(emp[position].taxableIncome);
            emp[position].net=net(emp[position].gross,emp[position].tax);
        break;       
    case 4:
        redo=0;//terminates the program
        break;
    default:
        break;
    }
    }while(redo==1);

   printf("*********************************** Thank you for using our system, we hope to serve you again in the near future **************************************\nPROGRAM TERMINATED");
    return 0;
}
int Greetings(void){
    printf("********************************* TAXATION MANAGEMNET SYSTEM************************************\n");
    printf("Hello and Welcome to Taxation management system.\n");
    printf("             taxation table    \n");
}
int table(void){
    printf("Taxable income        rate in percentage\n-----------------------------------------\n");
    printf("0 - 5,0000                0\n");
    printf("5,000 - 10,000            6\n");
    printf("10,001 - 19,999           9\n");
    printf("20,000 - 29,999           12\n");
    printf("30,000 - 36,999           14\n");
    printf("Above 37,000              16\n");
    printf("\n");
}

float negative(float x){
    float y;
    if(x<0){
        do{
            printf("Cannot accept negative values, re-enter the amount: ");
            scanf("%f",&y);
        }while(y<0);
        return y;
    }else{
        return x;
    }
}
float gross(float a,float b,float d,float e){
    return a+b+d+e;
}
float taxableIncome(float gross,int y){
    if(y==1){
        return gross - (float)RELIEF_S;
    }else{
        return gross -(float)RELIEF_M;
    }
}
float tax( float taxableIncome){
    if(taxableIncome>=37000.00){
        return taxableIncome*0.16;
    }else if(taxableIncome>=36999.00||taxableIncome>=30000.00){
        return taxableIncome*0.14;
    }else if(taxableIncome>=29000.00||taxableIncome>=20000.00){
        return taxableIncome*0.12;
    }else if(taxableIncome>=19999.00||taxableIncome>=10001.00){
        return taxableIncome*0.09;
    }else if(taxableIncome>=10000.00||taxableIncome>=5000.00){
        return taxableIncome*0.06;
    }else{
        return taxableIncome*0.00;
    }
}
float net(float gross,float tax){
    return gross-tax;
}
int check(int x){
    int y;
    if(x!=1 && x!=2 && x!=3 && x!=4){
        do{
            printf("Invalid input, re-enter the choice: ");
            scanf("%d",&y);
        }while(y!=1 && y!=2 && y!=3 && y!=4);
        return y;
    }else{
        return x;
    }
}
int check2(int x,int b){
    int y;
    if(x>b){
        do{
            printf("Invalid Client's number!, Try again: ");
            scanf("%d",&y);
        }while(y>b);
        return y;
    }else{
        return x;
    }
}
