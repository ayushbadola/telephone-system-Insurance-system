#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
struct record
{
    int dur,calls;
    long long phone;
    float bill;
    char name[50],type[50];
};
struct data
{
    int age,adhar;
    char name[50],pre[50],amount[50],ged[7],citizen[10];
};
struct record r;
struct data d;
void insert_record();
void display_record();
void search_record();
void sort_record();
void delete_record();
void insert_data();
void display_data();
void search_data();
void main()
{
        int ch;
        system("cls");
        printf("\n-------------------------------------------");
        printf("\n-----------------wellcome------------------");
        printf("\n-------------------------------------------\n");
        printf("\nPress 1 for project one(telephone system)");
        printf("\nPress 2 for project one(Insurance system)");
        printf("\nPress any key for exit the program other than 1 and 2\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            int choice;
            while(choice!=6)
            {
                system("cls");
                printf("\n-------telephone record system-------\n");
                printf("\nPress 1 for insert record");
                printf("\nPress 2 for display record");
                printf("\nPress 3 for search record");
                printf("\nPress 4 for delete record");
                printf("\nPress 5 for sorted record");
                printf("\nPress 6 for exit the program\n");
                scanf("\n%d",&choice);
                switch(choice)
                {
                    case 1:
                        insert_record();
                        break;
                    case 2:
                        display_record();
                        break;
                    case 3:
                        search_record();
                        break;
                    case 4:
                        delete_record();
                        break;
                    case 5:
                        sorted_record();
                        break;
                    case 6:
                        exit(1);
                    default:
                        printf("\n\tyou enter the wrong choice");
                    }
                    printf("\n\n\tpress any key to main menu");
                    getch();
                }
            }
        else if(ch==2)
        {
            int chi;
            while(chi!=4)
            {
            printf("\n-------Insurance system-------\n");
            printf("\nPress 1 for insert record");
            printf("\nPress 2 for display record");
            printf("\nPress 3 for search record");
            printf("\nPress 4 for exit the program\n");
            scanf("%d",&chi);
            switch(chi)
            {
            case 1:
                insert_data();
                break;
            case 2:
                display_data();
                break;
            case 3:
                search_data();
                break;
            case 4:
                exit(1);
            default:
                printf("\n\tyou enter the wrong choice");
            }
            printf("\n\n\tpress any key to main menu");
            getch();
            }
        }
    }
void insert_record()
{
    FILE*fp;
    fp=fopen("telephone3.txt","ab+");
    if(fp==NULL)
    {
        printf("\nFile not exit");
        return;
    }
    printf("\n****************enter the new record******************");
    fflush(stdin);
    printf("\nenter the name\n");
    gets(r.name);
    fflush(stdin);
    printf("enter the phone number");
    scanf("%lld",&r.phone);
    int m;
    while(m!=3)
    {
        printf("Press 1 For Std\n2 For local\n3 for Isd");
        scanf("%d",&m);
        switch(m)
        {
        case 1:
            r.type[0]='S';
            r.type[1]='T';
            r.type[2]='D';
            r.type[3]='\0';
            break;
        case 2:
            r.type[0]='l';
            r.type[1]='o';
            r.type[2]='c';
            r.type[3]='a';
            r.type[4]='l';
            r.type[5]='\0';
            break;
        case 3:
            r.type[0]='I';
            r.type[1]='S';
            r.type[2]='D';
            r.type[3]='\0';
            break;
        default:
            printf("\n\tyou enter the wrong choice");
        }
        break;

    }
    fflush(stdin);
    printf("\nenter the  number of calls made by you\n");
    scanf("%d",&r.calls);
    printf("\nenter the duration of call(seconds)\n");
    scanf("%d",&r.dur);
    float bill;
    if(r.dur<=33)
    {
        bill=50.0;
        r.bill=bill;
        printf("Dear user %s your bill for phone no. %lld is %.2f",r.name,r.phone,r.bill);
        //printf("%f",bill);
    }
    else if(r.dur>33&&r.dur<=200)
    {
        bill=(r.dur)*1.5;
        r.bill=bill;
        printf("Dear user %s your bill for phone no. %lld is %.2f",r.name,r.phone,r.bill);

    }
    else if(r.dur>200&&r.dur<=600)
    {
        bill=(r.dur)*3.5;
        r.bill=bill;
        printf("Dear user %s your bill for phone no. %lld is %.2f",r.name,r.phone,r.bill);

    }
    else
    {
        bill=(r.dur)*5.5;
        r.bill=bill;
        printf("Dear user %s your bill for phone no. %lld is %.2f",r.name,r.phone,r.bill);
    }
    fwrite(&r,sizeof(r),1,fp);
    printf("\n\t record submitted");
    fclose(fp);
}
void display_record()
{
    FILE*fp;
    fp=fopen("telephone3.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the file!!!");
        return;
    }
    printf("\n\n\t----telephone details are as follows----");
    printf("\nname\t\tphone num\ttype\t\tcalls\t\tduration\tbill");
    while(fread(&r,sizeof(r),1,fp)==1)
    {
        printf("\n%s\t\t%lld\t\t%2s\t\t%d\t\t%d\t\t%f",r.name,r.phone,r.type,r.calls,r.dur,r.bill);
    }
    fclose(fp);
}
void search_record()
{
    int f=0;
    long long ph;
    FILE*fp;
    fp=fopen("telephone3.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the file!!!");
        return;
    }
    display_record();
    printf("\n\n\tenter telephone number which you want to search:");
    scanf("%lld",&ph);
    fflush(stdin);
    while(fread(&r,sizeof(r),1,fp)>0 && f==0)
    {
        if(r.phone==ph)
        {
            f=1;
            printf("\nrecord found");
            printf("\nname\t\tphone num\ttype\t\tcalls\t\tduration\tbill");
            printf("\n%s\t\t%lld\t\t%2s\t\t%d\t\t%d\t\t%f",r.name,r.phone,r.type,r.calls,r.dur,r.bill);
        }
    }
    if(f==0)
    {
        printf("\nrecord not found!!!!");
    }
    fclose(fp);
}
void delete_record()
{
    char names[50];
    unsigned f=0;
    FILE *fp,*ft;
    fp=fopen("telephone3.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tCannot open the file!!!");
        return;
    }
    printf("\n\t----previous stored data----");
    display_record();
    printf("\n\n\tenter name which you want to delete");
    fflush(stdin);
    scanf("%s",names);
    ft=fopen("telephone12.txt","ab+");
    while(fread(&r,sizeof(r),1,fp)==1)
    {
        if(strcmp(names,r.name)!=0)
        {

            fwrite(&r,sizeof(r),1,ft);
        }
        else
        {
            f=1;
        }
    }
    if(f==0)
    {
        printf("\n\n\tno such record found!!!");
    }
    else{
        printf("\nrecord deleted");
    }
    fclose(fp);
    fclose(ft);
    fp=fopen("telephone3.txt","wb");
    ft=fopen("telephone12.txt","rb");
    while(fread(&r,sizeof(r),1,ft)==1)
    {
            fwrite(&r,sizeof(r),1,fp);
    }
    fclose(fp);
    fclose(ft);
    display_record();
}
void sorted_record()
{
    struct record temp;
    struct record arr[100];
    int i,j,k=0;
    FILE*fp;
    fp=fopen("telephone3.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tfile not found");
    }
    i=0;
    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
    {
        i++;
        k++;
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-i-1;j++)
        {
            if(arr[j].dur<arr[j+1].dur)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n\t\tafter sorting of call duration in decinding order\n");
    printf("\nname\t\tphone num\ttype\t\tcalls\t\tduration\tbill");
    for(i=0;i<k;i++)
    {
        printf("\n%s\t\t%lld\t\t%2s\t\t%d\t\t%d\t\t%f",arr[i].name,arr[i].phone,arr[i].type,arr[i].calls,arr[i].dur,arr[i].bill);
    }
    fclose(fp);
}
insert_data()
{
    FILE*fp;
    fp=fopen("emp1.txt","ab+");
    if(fp==NULL)
    {
        printf("\nFile not exit");
        return;
    }
    printf("\t Previous stored record");
    display_data();
    printf("\n enter the new record");
    fflush(stdin);
    printf("\nenter the name\n");
    gets(d.name);
    fflush(stdin);
    printf("\nenter the age");
    scanf("%d",&d.age);
    fflush(stdin);
    printf("\nenter the adhar number");
    scanf("%d",&d.adhar);
    int choice;
    printf("\npress 1 for male");
    printf("\npress any key female");
    printf("\nenter your choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
        d.ged[0]='m';
        d.ged[1]='a';
        d.ged[2]='l';
        d.ged[3]='e';
        d.ged[4]='\0';
    }
    else
    {
        d.ged[0]='f';
        d.ged[1]='e';
        d.ged[2]='m';
        d.ged[3]='a';
        d.ged[4]='l';
        d.ged[5]='e';
        d.ged[6]='\0';
    }
    int cg;
    printf("\nPress 1 if you are indian");
    printf("\nPress any key if you are not indian");
    printf("\nenter your choice:");
    scanf("%d",&cg);
    if(cg==1)
    {
        d.citizen[0]='Y';
        d.citizen[1]='E';
        d.citizen[2]='S';
        d.citizen[3]='\0';
    }
    else
    {
        d.citizen[0]='N';
        d.citizen[1]='0';
        d.citizen[2]='\0';
    }
    if(d.age>=25 && d.age<=45 && choice==1 && cg==1)
    {
        printf("premium is Rs 4K/month and policy amount is 5Lakh");
        d.pre[0]='4';
        d.pre[1]='k';
        d.pre[2]='\0';
        d.amount[0]='5';
        d.amount[1]='L';
        d.amount[2]='a';
        d.amount[3]='k';
        d.amount[4]='h';
        d.amount[5]='\0';
    }
    else if(d.age>=25 && d.age<=45 && cg==1 && choice!=1)
    {
        printf("premium is Rs 3K/month and policy amount is 3 Lakh");
        d.pre[0]='3';
        d.pre[1]='k';
        d.pre[2]='\0';
        d.amount[0]='3';
        d.amount[1]='L';
        d.amount[2]='a';
        d.amount[3]='k';
        d.amount[4]='h';
        d.amount[5]='\0';
    }
    else if(d.age<25 && d.age>45 && cg==1)
    {
        printf("premium is 2K/month and policy amount 2 Lakh");
        d.pre[0]='2';
        d.pre[1]='k';
        d.pre[2]='\0';
        d.amount[0]='2';
        d.amount[1]='L';
        d.amount[2]='a';
        d.amount[3]='k';
        d.amount[4]='h';
        d.amount[5]='\0';
    }
    else
    {
        printf("no premium and no amount possible for this category");
        d.pre[0]='0';
        d.amount[0]='0';
    }
    fwrite(&d,sizeof(d),1,fp);
    printf("\n\t record submitted");
    fclose(fp);
}
void display_data()
{
    FILE*fp;
    fp=fopen("emp1.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the file!!!");
        return;
    }
    printf("\n\n\t----insurance details are as follows----");
    printf("\nname\t\t\tage\t\tadhar no\tgender\t\tindian\t\tpremium\t\tamount");
    while(fread(&d,sizeof(d),1,fp)==1)
    {
        printf("\n%s\t\t\t%d\t\t%2d\t\t%6s\t\t%3s\t\t%5s\t\t%2s",d.name,d.age,d.adhar,d.ged,d.citizen,d.pre,d.amount);
    }
    fclose(fp);
}
void search_data()
{
    int f=0,adh;
    FILE*fp;
    fp=fopen("emp1.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the file!!!");
        return;
    }
    printf("\n\n\tenter adhar number which you want to search:");
    scanf("%d",&adh);
    fflush(stdin);
    while(fread(&d,sizeof(d),1,fp)>0 && f==0)
    {
        if(d.adhar==adh)
        {
            f=1;
            printf("\nrecord found");
            printf("\nname\t\t\tage\t\tadhar no\tgender\t\tindian\t\tpremium\t\tamount");
            printf("\n%s\t\t\t%d\t\t%2d\t\t%6s\t\t%3s\t\t%5s\t\t%2s",d.name,d.age,d.adhar,d.ged,d.citizen,d.pre,d.amount);
        }
    }
    if(f==0)
    {
        printf("\nrecord not found!!!!");
    }
    fclose(fp);
}


