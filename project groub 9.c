#include<stdio.h>
#include <windows.h>
#include<conio.h>


//Function for calculating
int totaldate (void);
void interest  (void);
void totaldept (void);
int errordate (void);
void display (void);
void inputdata (void);
void showing (void);
void savedata (void);
void loaddata (void);
void planing (void);
int closing (void);
//Variable
char ch;
int i;
char choice,zh,xh;
float total_P=0,total_inter=0,D;
char filename[20];
char op;
int month;
int n[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
FILE *Table;
//Data of period
struct maindata
{
    float T,P;
    float inter,dept;
    int date_total;
    int date1[3],date2[3];
    int level;
}core[500];
int main ()
{
    //Variables called
    HANDLE fly = GetStdHandle(STD_OUTPUT_HANDLE);
    //Value For choice 2 First time
    i=-1;
    //Main menu
    do
    {              //Wellcome Display
                SetConsoleTextAttribute(fly,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                printf("\t$$$$_*_*_*_*\tWellcome TO Credit Calculated Programe\t*_*_*_*_$$$$\tVer.5.2");
                printf("\n\n\t\t\t_____!!! ******************* !!!_____");

        display();

        //Main menu Condition
        switch (ch)
         {
                //Created new profile
               case '1' : {     inputdata(); break;}
                //Showing total recent data
               case '2' : {     showing();   break;}
                //Savedata
               case '3' : {     savedata();  break;}
                //Load file
               case '4' : {     loaddata();   break;}
                //Plan for loaning money
               case '5' : {      planing();   break;}
                //Exit programe
               case '6' : {     if(closing())
                                {printf("\n\nThank For using............. \n\n\\ ^w^ / Bye Bye \\ ^w^ /\n\n");
                                return 0;}
                                system("cls");
                  break;}

                default :  {  printf("\n\nError !! Please choose again"); getche(); system("cls");}
          }
    }while (choice!='6');
}
int totaldate (void)
{
    int j,k;
    int total1=0,total2=0,total=0,x1=0,x2=0,delta=0;

    if (core[i].date1[2]==core[i].date2[2])
    {
        if (core[i].date1[1]==core[i].date2[1])
        {
            return total = core[i].date2[0]-core[i].date1[0]+1;
        }
        else if (core[i].date2[1]>core[i].date1[1])
        {
            if (core[i].date2[1] - core[i].date1[1]==1)
                return total = n[core[i].date1[1]-1]-core[i].date1[0]+1+core[i].date2[0];

            j=core[i].date2[1]-core[i].date1[1];

            for (k=2;k<=j;k++)
            {
                x1=x1+n[core[i].date1[1]+k-1];
            }

            return total = x1+n[core[i].date1[1]-1]-core[i].date1[0]+1+core[i].date2[0];
        }
    }

    else if (core[i].date1[2]<core[i].date2[2])
    {
        if (core[i].date2[2]-core[i].date1[2]>=1)
        {
             total1=12-core[i].date1[1];

            for (k=1;k<=total1;k++)
                x1=x1+n[core[i].date1[1]+k-1];

            total2=core[i].date2[1]-1;

            for (k=1;k<=total2;k++)
                x2=x2+n[core[i].date2[1]-k-1];

            delta=core[i].date2[2]-core[i].date1[2]-1;

            return total=x1+x2+n[core[i].date1[1]-1]-core[i].date1[0]+1+core[i].date2[0]+365*delta;
        }
    }
}
void interest  (void)
{

    if (zh=='1')
    core[i].inter=((core[i].T*D)*core[i].date_total)/36500.0;

    else
    core[i].inter=((core[0].T*D)*core[i].date_total)/36500.0;


}
void totaldept (void)
{

    core[i].dept=core[i].T-core[i].P+core[i].inter;

    if (core[i].dept<=0)
     {
          core[i].dept=0;
          core[i].P=core[i].T+core[i].inter;
     }


}
int errordate (void)
{
    if (core[i].date2[2]<core[i].date1[2])
        return 0;
    else if (core[i].date2[2]==core[i].date1[2])
    {
        if (core[i].date2[1]<core[i].date1[1])
            return 0;
        else if (core[i].date2[1]==core[i].date1[1])
        {
            if (core[i].date2[0]<core[i].date1[0])
                return 0;
            else if (core[i].date2[0]==core[i].date1[0])
                return 0;
        }
    }
    else
        return 1;
}
void display(void)
{
         printf("\n\n\tMain Menu");
         printf("\n\t\t\t\t\t           ***********\n1. Create new data\t\t\t\t*****************");
         printf("\n2. Display last data\t\t\t      ****** ******* ******");
         printf("\n3. Save data\t\t\t\t     ******   *****   ******");
         printf("\n4. Load data\t\t\t\t     ***********************");
         printf("\n5. Create Plan for loaning money\t      ***** **** **** *****");
         printf("\n6. Exit\t\t\t\t\t\t***** ***** *****");
        //In put For controling main manu
         printf("\n\t\t\t\t\t           ***********\n\nChoose your choice : ");
         ch=getche();
}
void inputdata (void)
{
                    //condition for dept =0
                    if ((core[i].dept==0)&&(i>=0))
                    {
                            printf("\n\n Warning : your data will be overwriting. Please save before create !!!!!");
                            printf("\n\n You have finished your payment. Do you want to creat the new one ?");
                            do
                                {   printf("\n\n\nContinue [Y/N] : ");
                                    choice=getche();
                                }
                            while((choice!='Y')&&(choice!='N'));
                            //Overwrite
                            if (choice=='Y')
                                i=-1;
                            //Back to main Menu
                            else
                                {
                                    system("cls");
                                    return 0;
                                }
                    }

                    //For first or overwrited data
                    if (i<0)
                    {
                            //Value For structural variables
                            i=0;

                            total_P=0;
                            total_inter=0;;

                            system("cls");

                            printf("\n\nChoose type of interest");
                            printf("\n\n1.Effective rate");
                            printf("\n\n2.Flat rate");

                            do
                            {
                                printf("\n\nChoose your choice : ");
                                zh=getche();
                            }
                            while ((zh!='1')&&(zh!='2'));

                            system("cls");

                            //In put principal money
                            printf("\n\n\n\nIn put your Principal money [Bath] : ");
                            scanf("%f",&core[i].T);

                            //In put Interest
                            printf("In put your Interest [%%] : ");
                            scanf("%f",&D);

                            //Input date
                            do{

                           do{
                            printf("In put your [day/month/year] of first payment: ");
                            scanf("%d/%d/%d",&core[i].date1[0],&core[i].date1[1],&core[i].date1[2]);
                             }while((core[i].date1[0]>n[core[i].date1[1]-1])||(core[i].date1[1]>12));
                           do{
                            printf("In put your [day/month/year] of last payment: ");
                            scanf("%d/%d/%d",&core[i].date2[0],&core[i].date2[1],&core[i].date2[2]);
                            }while((core[i].date2[0]>n[core[i].date2[1]-1])||(core[i].date2[1]>12));

                            }while(!errordate());

                            //In put Payment
                            printf("\nPayment [Bath]: ");
                            scanf("%f",&core[i].P);

                            //Calculating and Substitute variables value

                            core[i].date_total=totaldate();
                            interest();
                            totaldept();

                            //Out put Display
                            printf("\n\nPeriod <%d> \tTotal Date <%d>",i+1,core[i].date_total);
                            printf("\nPayment = %.2f \tInterest = %.2f \t True Payment =%.2f",core[i].P,core[i].inter,core[i].P-core[i].inter);
                            printf("\nDept = %.2f - %.2f = %.2f",core[i].T,core[i].P-core[i].inter,core[i].dept);

                            //Keep total payment and Interest
                            total_P+=core[i].P;
                            total_inter+=core[i].inter;


                            //Back to main menu if dept =0
                                if (core[i].dept==0)
                                    {
                                            printf("\n\nFinish all Payment");
                                            printf("\nPress any key to return to mainmanu.............");
                                            getch();
                                            system("cls");
                                            return 0;
                                    }

                                else
                                    {
                                        do
                                            {
                                                printf("\n\n\nContinue [Y/N] : ");
                                                choice=getche();
                                            }
                                        while((choice!='Y')&&(choice!='N'));
                                        if (choice=='N')
                                            {system("cls");
                                            return 0;}
                                    }
                        }
                            //looping condition
                            while (i>=0)
                                {
                                    i+=1;
                                    if (i%2==0)
                                    system("cls");

                                    core[i].T=core[i-1].dept;

                                    core[i].date1[0]=core[i-1].date2[0];
                                    core[i].date1[1]=core[i-1].date2[1];
                                    core[i].date1[2]=core[i-1].date2[2];

                                    printf("\n\nYour totally dept : %.2f",core[i].T);

                                    do{
                                    printf("\nIn put your [day/month/year] of previous payment: %d/%d/%d",core[i].date1[0],core[i].date1[1],core[i].date1[2]);

                                    do{
                                    printf("\nIn put your [day/month/year] of last payment: ");
                                    scanf("%d/%d/%d",&core[i].date2[0],&core[i].date2[1],&core[i].date2[2]);
                                    }while((core[i].date2[0]>n[core[i].date2[1]-1])||(core[i].date2[1]>12));
                                    }while(!errordate());

                                    printf("\nPayment [Bath]: ");
                                    scanf("%f",&core[i].P);

                                    core[i].date_total=totaldate();
                                    interest();
                                    totaldept();

                                    printf("\n\nPeriod <%d> \tTotal Date <%d>",i+1,core[i].date_total);
                                    printf("\nPayment = %.2f \tInterest = %.2f \t True Payment =%.2f",core[i].P,core[i].inter,core[i].P-core[i].inter);
                                    printf("\nDept = %.2f - %.2f = %.2f",core[i].T,core[i].P-core[i].inter,core[i].dept);

                                    total_P+=core[i].P;
                                    total_inter+=core[i].inter;

                                    if (core[i].dept==0)
                                        {
                                                    printf("\n\nFinish all Payment");
                                                    printf("\nPress any key to return to mainmanu.............");
                                                    getch();
                                                    system("cls");
                                                    return 0;
                                        }
                                    else
                                        {
                                        do
                                            {   printf("\n\n\nContinue [Y/N] : ");
                                                choice=getche();
                                            }
                                        while((choice!='Y')&&(choice!='N'));
                                        if (choice=='N')
                                            {system("cls");
                                            return 0;}
                                        }

                      }
        system("cls");

}
void showing (void)
{
                   int j;

                    //Error condition
                    if (i<0)
                    {
                        printf("\n\n!!  Empty data !! Please create or load new data");
                    }

                    if ((zh=='1')&&(i>=0))
                    printf("\n\nEffective rate interest [%%] : %.2f",D);
                    else if((zh=='2')&&(i>=0))
                    printf("\n\nFlat rate interest [%%] : %.2f",D);
                    if ((xh=='1')&&(i>=0))
                    printf("\nPayment/Month [Bath/Month] : %.2f",core[0].P);
                    else if ((xh=='2')&&(i>=0))
                    printf("\nTotal month [Month] : %d",i+1);

                    if (i>=0)
                    printf("\n\n|Period|previous date|last date|Total date| Principal money | Payment |Interest|  Dept  |");
                    //Process for displaying data
                    for (j=0;j<=i;j++)
                    {
                        printf("\n\n| %d | %d/%d/%d | %d/%d/%d | %d  |  %.2f  | %.2f | %.2f | %.2f |",j+1,core[j].date1[0],core[j].date1[1],core[j].date1[2],core[j].date2[0],core[j].date2[1],core[j].date2[2],core[j].date_total,core[j].T,core[j].P,core[j].inter,core[j].dept);

                        if (j==i)
                        printf("\n\nTotal Payment = %.2f\t\tTotal Interest = %.2f\n\nPrincipal Money = %.2f",total_P,total_inter,total_P-total_inter);

                    }

                    printf("\n\nPress any key to continue...................");
                    getch();

                    system("cls");


}
void savedata(void)
{
                                int j;

                                printf("\n\nPlease enter filename: ");
                                scanf("%s",filename);

                                if((Table=fopen(filename,"w"))==NULL)
                                {
                                    printf("\n\n!! Error saving file !!\n\nPress any key to return to Main Menu.....");
                                    getch();
                                    system("cls");
                                }
                                else
                                {
                                    if(i>=0)
                                    {

                                        fprintf(Table,"Percent interest [%%] =%.2f\n",D);

                                        if (zh=='1')
                                        fprintf(Table,"Effective rate :1\n");
                                        else
                                        fprintf(Table,"Flat rate :2\n");

                                        if (xh=='1')
                                        fprintf(Table,"Payment/Month |1\n");
                                        else if (xh=='2')
                                        fprintf(Table,"Total month |2\n");
                                        else
                                        fprintf(Table,"Total month |0\n");


                                        for(j=0;j <= i;j++)
                                            {


                                                fprintf(Table,"%d %.2f %d %d %d %d %d %d %d %.2f %.2f %.2f\n",j+1,core[j].T,core[j].date1[0],core[j].date1[1],core[j].date1[2],core[j].date2[0],core[j].date2[1],core[j].date2[2],core[j].date_total,core[j].P,core[j].inter,core[j].dept);
                                            }

                                        fclose(Table);
                                        printf("\n\n%s has been saved.\n\nPress any key to return to Main Menu",filename);
                                        getch();
                                        system("cls");
                                    }

                                    else
                                    {
                                        fclose(Table);
                                        printf("\n\n!! No data !! please create or load data !!!!");
                                        printf("\n\nPress any key to continue...................");
                                        getch();

                                        system("cls");


                                    }

                                }
}
void loaddata(void)
{
                            printf("\n\nPlease enter filename: ");
                            scanf("%s",filename);
                            if((Table=fopen(filename,"r"))==NULL)
                            {
                                printf("\n\n!! Error loading file ,Can't find your filename !!\n\nPress any key to return to Main Menu.....");
                                getch();
                                system("cls");
                            }
                            else
                            {       total_P=0;
                                    total_inter=0;;

                                    do{
                                    op=getc(Table);
                                    }
                                    while(op != '=');
                                    fscanf(Table,"%f",&D);

                                    do{
                                    op=getc(Table);
                                    }
                                    while(op != ':');
                                    zh=getc(Table);

                                    do{
                                    op=getc(Table);
                                    }
                                    while(op != '|');
                                    xh=getc(Table);

                                    i=0;

                                    while (!feof(Table))
                                    {

                                        fscanf(Table,"%d %f %d %d %d %d %d %d %d %f %f %f\n",&core[i].level,&core[i].T,&core[i].date1[0],&core[i].date1[1],&core[i].date1[2],&core[i].date2[0],&core[i].date2[1],&core[i].date2[2],&core[i].date_total,&core[i].P,&core[i].inter,&core[i].dept);
                                        total_P+=core[i].P;
                                        total_inter+=core[i].inter;
                                        i++;
                                    }   i--;

                                    fclose(Table);
                                    printf("\n\nLoading file finished...\n\nPress any key to return to Main Menu.");

                                    getch();
                                    system("cls");

                            }
}
void planing (void)
{
                            int j;

                                if (i>=0)
                            {
                                printf("\n\n Warning : your data will be overwriting. Please save before create !!!!!");
                                printf("\n\n You have finished your payment. Do you want to creat the new one ?");
                                do
                                    {   printf("\n\n\nContinue [Y/N] : ");
                                                choice=getche();
                                    }
                                while((choice!='Y')&&(choice!='N'));

                                if (choice=='Y')
                                    i=0;

                                system("cls");

                            }

                                if (i<0)
                                    choice='Y';

                                if ((i<=0)&&(choice=='Y'))
                                {
                                    system("cls");

                                    total_P=0;
                                    total_inter=0;;
                                    i=0;

                                printf("\n\nWhat would you want to know ?");
                                printf("\n\n1.Payment/Month");
                                printf("\n2.Total month to pay");

                                        do
                                    {
                                        printf("\n\nChoose your choice : ");
                                        xh=getche();

                                    }
                                    while ((xh!='1')&&(xh!='2'));

                                    printf("\n\nChoose type of interest");
                                    printf("\n\n1.Effective rate");
                                    printf("\n2.Flat rate");

                                    do
                                    {
                                        printf("\n\nChoose your choice : ");
                                        zh=getche();

                                    }
                                    while ((zh!='1')&&(zh!='2'));

                                    printf("\n\n");

                                    do{
                                        printf("In put your [1-28/month/year] of first payment: ");
                                        scanf("%d/%d/%d",&core[i].date1[0],&core[i].date1[1],&core[i].date1[2]);
                                        }while((core[i].date1[0]>28)||(core[i].date1[1]>12)||(core[i].date1[0]<1));

                                    printf("\n");

                                    if (xh=='1')
                                    {
                                        //In put principal money
                                        printf("In put your principal money [Bath] : ");
                                        scanf("%f",&core[i].T);

                                        //In put Interest
                                        printf("\nIn put your Interest [%%] : ");
                                        scanf("%f",&D);

                                        printf("\nIn put your total month to pay [Month] : ");
                                        scanf("%d",&month);

                                        do
                                        {
                                            if (zh=='1')
                                            {
                                                if (i>0)
                                                core[i].T=core[i-1].dept;

                                                core[i].inter=((core[i].T*D)*1)/1200.0;
                                                core[i].P=(core[0].T/month)+core[i].inter;
                                                core[i].dept=core[i].T-core[i].P+core[i].inter;
                                                if (core[i].T-core[i].P<0)
                                                {
                                                    core[i].P=core[i].T+core[i].inter;
                                                    core[i].dept=0;
                                                }
                                                total_P+=core[i].P;
                                                total_inter+=core[i].inter;
                                                //Avg payment per month
                                                if (core[i].dept==0)
                                                {
                                                    for (j=0;j<=i;j++)
                                                    {
                                                        if (j>=1)
                                                        core[j].T=core[j-1].dept;

                                                        core[j].P=total_P/(i+1);
                                                        core[j].dept=core[j].T-core[j].P+core[j].inter;
                                                        if (core[i].T-core[i].P<0)
                                                            {
                                                                core[i].P=core[i].T+core[i].inter;
                                                                core[i].dept=0;
                                                            }
                                                    }
                                                }
                                                i++;
                                            }
                                            if (zh=='2')
                                            {
                                                if (i>0)
                                                core[i].T=core[i-1].dept;

                                                core[i].inter=((core[0].T*D)*1)/1200.0;
                                                 core[i].P=(core[0].T/month)+core[i].inter;
                                                core[i].dept=core[i].T-core[i].P+core[i].inter;
                                                if (core[i].T-core[i].P<0)
                                                {
                                                    core[i].P=core[i].T+core[i].inter;
                                                    core[i].dept=0;
                                                }
                                                total_P+=core[i].P;
                                                total_inter+=core[i].inter;


                                                i++;
                                            }

                                            i--;

                                            core[i].date2[0]=core[i].date1[0];
                                            core[i].date2[2]=core[i].date1[2];
                                            core[i].date2[1]=core[i].date1[1]+1;

                                            if (core[i].date2[1]>12)
                                            {
                                                core[i].date2[1]=core[i].date2[1]-12;
                                                core[i].date2[2]=core[i].date2[2]+1;
                                            }

                                            core[i+1].date1[0]=core[i].date2[0];
                                            core[i+1].date1[1]=core[i].date2[1];
                                            core[i+1].date1[2]=core[i].date2[2];

                                            core[i].date_total=totaldate();
                                            i++;

                                        }while(core[i-1].dept>0);    i--;

                                    }

                                    if (xh=='2')
                                    {
                                        //In put principal money
                                        printf("In put your Principal money [Bath] : ");
                                        scanf("%f",&core[i].T);

                                        //In put Interest
                                        printf("\nIn put your Interest [%%] : ");
                                        scanf("%f",&D);

                                        printf("\nIn put your payment/month [Bath/Month] : ");
                                        scanf("%f",&core[i].P);

                                        do
                                        {
                                            if (zh=='1')
                                            {   if (i>0)
                                                {
                                                    core[i].P=core[i-1].P;
                                                    core[i].T=core[i-1].dept;
                                                }

                                                core[i].inter=((core[i].T*D)*1)/1200.0;
                                                core[i].dept=core[i].T-core[i].P+core[i].inter;
                                                if (core[i].T-core[i].P<0)
                                                {
                                                    core[i].P=core[i].T+core[i].inter;
                                                    core[i].dept=0;
                                                }
                                                total_P+=core[i].P;
                                                total_inter+=core[i].inter;


                                                i++;
                                            }
                                            if (zh=='2')
                                            {
                                                if (i>0)
                                                {
                                                    core[i].P=core[i-1].P;
                                                    core[i].T=core[i-1].dept;
                                                }

                                                core[i].inter=((core[0].T*D)*1)/1200.0;
                                                core[i].dept=core[i].T-core[i].P+core[i].inter;
                                                if (core[i].T-core[i].P<0)
                                                {
                                                    core[i].P=core[i].T+core[i].inter;
                                                    core[i].dept=0;
                                                }
                                                total_P+=core[i].P;
                                                total_inter+=core[i].inter;


                                                i++;
                                            }

                                            if (core[i-1].dept>core[i-1].T)
                                            {
                                                printf("\n\nError.... Can't find total month !!!!");
                                                printf("\t\tPress any key to return to main menu");
                                                getche();
                                                system("cls");
                                                return 0;

                                            }

                                            i--;
                                            core[i].date2[0]=core[i].date1[0];
                                            core[i].date2[2]=core[i].date1[2];
                                            core[i].date2[1]=core[i].date1[1]+1;

                                            if (core[i].date2[1]>12)
                                            {
                                                core[i].date2[1]=core[i].date2[1]-12;
                                                core[i].date2[2]=core[i].date2[2]+1;
                                            }

                                            core[i+1].date1[0]=core[i].date2[0];
                                            core[i+1].date1[1]=core[i].date2[1];
                                            core[i+1].date1[2]=core[i].date2[2];

                                            core[i].date_total=totaldate();
                                            i++;

                                        }while(core[i-1].dept>0);    i--;
                                    }
                         }
                        system("cls");
}
int closing (void)
{
                            do
                                {   printf("\n\nContinue [Y/N] : ");
                                    choice=getche();
                                }while((choice!='Y')&&(choice!='N'));
                            if (choice=='N')
                            return 0;
                            return 1;
}
