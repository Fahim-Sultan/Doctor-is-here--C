#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
struct doctor
{
    char name[50];
     char address[50];
     int phone;
     char fname[100];
     char lname[20];
     char username[20];
     char password[20];
    struct doctor *next;
}*head;
typedef struct doctor doc;

///6. MY DOCTORS lIST Service

void insert(int n)
{
    doc *tmp,*end;
    int num,i;
    head=(doc*)malloc(sizeof(doc));
    if(head==NULL)
    {
        printf("Error!\n");
    }
    else
    {
         system("CLS");
        printf("Doctor 1: \n");
        printf("Enter Name: ");
        fflush(stdin);
        scanf("%[^\n]%*c",head->name);
        printf("Enter address: ");
        fflush(stdin);
        scanf("%[^\n]%*c",head->address);
        printf("Enter phone number: ");
        scanf("%d",&num);
        head->phone=num;
        head->next=NULL;
        tmp=head;

        for(i=2; i<=n; i++)
        {
            end=(doc*)malloc(sizeof(doc));
            if(end==NULL)
            {
                printf("Memory not allocated\n");
            }
            else
            {
                printf("Doctor %d: \n",i);
                printf("Enter Name: ");
                fflush(stdin);
                scanf("%[^\n]%*c",end->name);
                printf("Enter address: ");
                fflush(stdin);
                scanf("%[^\n]%*c",end->address);
                printf("Enter phone number: ");
                scanf("%d",&num);
                end->phone=num;
                end->next=NULL;
                tmp->next=end;
                tmp=end;
            }
        }
    }
}

/// Doctor's Info Adding

void insertEnd()
{
    doc *end,*tmp;
    int num;
    end=(doc*)malloc(sizeof(doc));
    if(end==NULL)
    {
        printf("Error\n");
    }
    else
    {
        printf("\n\nEnter New doctor info: \n\n");
        printf("Enter Name: ");
        fflush(stdin);
        scanf("%[^\n]%*c",end->name);
        printf("Enter address: ");
        fflush(stdin);
        scanf("%[^\n]%*c",end->address);
        printf("Enter phone number: ");
        scanf("%d",&num);
        end->phone=num;
        end->next=NULL;
        tmp=head;
        while(tmp->next!=NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = end;
    }
}

/// My Doctors List Function

void display()
{
    doc *tmp;
    int i=1;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        tmp=head;
        printf("\nMy Doctors :  \n\n");
        while(tmp!=NULL)
        {
            printf("Doctor %d\n",i);
            printf("Doctor's name: %s\n",tmp->name);
            printf("Doctor's address: %s\n",tmp->address);
            printf("Doctor's Phone: %d\n",tmp->phone);
            tmp=tmp->next;
            i++;
        }
        printf("\n");
    }
}


/// Welcome Page

void well()
{
    printf("\t\t\t\t\t\t\t\t **********^^^^^^^^^^^^^^^^^^***********");
    printf("\n\t\t\t\t\t\t\t\t =========/    Wellcome To   \\==========\n\t\t\t\t\t\t\t\t ********/ Doctor Is Here App \\*********\n");
    printf("\t\t\t\t\t\t\t\t ^^^^^^^/----------------------\\^^^^^^^^\n");
}

/// Sign up page
int l_in();
int SignUp()
{
    FILE *log;
    int i;
    log=fopen("login.txt","w");
    struct doctor p;
    int d = sizeof(p);
   printf("Enter first name :");
    scanf("%s",p.fname);

    printf("Enter last name :");
    scanf("%s",p.lname);

    printf("Enter user name :");
    scanf("%s",p.username);

    printf("Enter password :");
    scanf("%s",p.password);
   fwrite(&p,d,1,log);
   fputs(p.username,log);
   fputs(p.password,log);
    fclose(log);
  system("CLS");

    for(i=0; i<3; i++)
    {
        system("COLOR 2F");
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....Successfully Created Account.....");
      Sleep(600);
      system("cls");
      Sleep(500);
    }
 system("COLOR 0F");
  printf("\n\t\tGive proper Info to Sign In\n");
    l_in();
}

///Sign in side

int l_in()
{
    int i;
    char username[200],password[20];
    FILE *log;
    log=fopen("login.txt","r");
    struct doctor p;
    printf("User ID :");
    scanf("%s",&username);
     printf("Password :");
    scanf("%s",&password);
    while(fread(&p,sizeof(p),1,log))
    {
        if(strcmp(username,p.username)==0 && strcmp(password,p.password)==0 ){

            system("CLS");
    for(i=0; i<2; i++)
    {
        system("COLOR 2F");
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....Successfully.....");
      printf("\n\t\t\t\t\t\t\t\t                      .....Creation Done.....");
      Sleep(600);
      system("cls");
      Sleep(500);
    }
 system("COLOR 0F");
        }
        else{
               system("CLS");
    for(i=0; i<3; i++)
    {
        system("COLOR 47");
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....WRONG INFO.....");
      printf("\n\t\t\t\t\t\t\t\t                      .....ENTER CORRECT ONE.....");
      Sleep(600);
      system("cls");
      Sleep(500);
    }
 system("COLOR 0F");
        l_in();

        }
    }
    fclose(log);
}


int app();    // Some small error fixed
int lh();         // Some small error fixed
int k();                // Some small error fixed

/// For Guest Who have no Id and in a hurry

void guest()
{
    int p,y,i;
    printf("Dear guest Choose one Service's :-)");
    lh();
    k();
    printf("\t\t\t\t\t\t\t\t **********^^^^^^^^^^^^^^^^^^************\n");
     printf("\t\t\t\t\t\t\t\t// Do You Want To Make any Appointment\? \\\\  \n \t\t\t\t\t\t\t\t||If Yes (Press->1) and No for (Press->2)||\n ");
    printf(" \t\t\t\t\t\t\t\t\t       Press :");
     scanf("  %d",&p);
     system("CLS");
    printf("\n");
    if(p == 1){
    app();
    printf("\t\t\t\t\t\t\t\t/====Are you Satisfied with our services!====\\\n \t\t\t\t\t\t\t\t\\__ Please sign up and give us feedback :-)__/\n");
    printf("\t\t\t\t\t\t\t\t/========Give feedback (press-->1) And=======\\\n\t\t\t\t\t\t\t\t|****______| Not for (press-->2) |_______****|");
    printf("\n\t\t\t\t\t\t\t\t\t\t  Press :");
    scanf("%d",&y);
    if(y==1){
    SignUp();
     for(i=0; i<3; i++)
          {
            system("COLOR 81");
               printf("\n\t\t\t\t\t\t_____________/ THANK YOU FOR YOUR SURVEY.STAY HEALTHY :)\\____________________\n");
             Sleep(650);
            system("cls");
            Sleep(450);
         }
    }
    else if(y==2){
              for(i=0; i<3; i++)
    {
        system("COLOR 71");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  ________________/ THANK YOU FOR YOUR SURVEY.STAY HEALTHY :)\\_____________________\n");
      Sleep(600);
      system("cls");
      Sleep(500);
    }
    return ;
    }
    }
    else{
        printf("Thank You for your survey.Be Healthy :)\n\n");

    printf("\t\t\t\t\t\t\t\t/====Are you Satisfied with our services!====\\\n \t\t\t\t\t\t\t\t\\__ Please sign up and give us feedback :-)__/\n");
    printf("\t\t\t\t\t\t\t\t/========Give feedback (press-->1) And=======\\\n\t\t\t\t\t\t\t\t|****______| Not for (press-->2) |_______****|");
    scanf("%d",&y);
    if(y==1){
    SignUp();
       for(i=0; i<3; i++)
          {
            system("COLOR 81");
               printf("\n\t\t\t\t\t\t_____________/ THANK YOU FOR YOUR SURVEY.STAY HEALTHY :)\\____________________\n");
             Sleep(650);
            system("cls");
            Sleep(450);
         }
    }
    else{
                     for(i=0; i<3; i++)
    {
        system("COLOR 71");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 ________________/ THANK YOU FOR YOUR SURVEY.STAY HEALTHY :)\\_____________________\n");
      Sleep(500);
      system("cls");
      Sleep(500);
    }

    }
    }
}


int gazi();    // some small error fixed
int emMir();      // some small error fixed
int emu();           // some small error fixed
int emG();              // some small error fixed
int me();                  // some small error fixed
int d();                     // some small error fixed
int bnk();                // some small error fixed
int more();             // some small error fixed
int mirp();          // some small error fixed
int gul();         // some small error fixed
int Utt();     // some small error fixed

/// Our Services List

 int lh()
{
    int y,c,n,p,are,i;
    char LOH[30];
    char BB[30];
    char Am[30];
    char med[40];
    char em[50];
    printf("\n\t\t\t\t\t\t\t\t    Our Services Are :\n");
    printf("\t\t\t\t\t\t\t\t   ---------------------\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
    printf("\t\t\t\t\t ||\t 1\t     ||\t \t \t \t \t||\t2\t||\n");
    printf("\t\t\t\t\t |  List Of Hospitals | \t \t \t\t|  Blood Banks \t |\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
    printf("\t\t\t\t\t ||\t 3\t     ||\t \t \t \t \t||\t4\t||\n");
    printf("\t\t\t\t\t |  Ambulance Booking | \t \t \t\t|  E-Medicine \t |\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
     printf("\t\t\t\t\t ||\t 5\t     ||\t \t \t \t \t||\t6\t||\n");
    printf("\t\t\t\t\t |    Emergency       | \t \t \t\t| My Doctor list |\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");

    printf("\"Enter Your Choice (as number)\":");
    scanf("%d",&y);
    switch(y)
    {
         case 1:
             system("CLS");
             printf("\nHospitals In Dhaka\n");
             printf("------------------\n");
             printf("\n1.Gazipur \n2.Uttara \n3.Gulshan\n4.mirpur\n");
        printf("Enter Your Area: ");
        scanf("%d",&are);
        if(are == 1){
            gazi();
        }
        else if(are==2){
                Utt();
        }
        else if(are ==3){
                gul();
        }
        else if(are == 4){
                mirp();
        }
        else {
                    int i;
                for(i=0; i<3; i++)
                   {
                      system("COLOR C1");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....Wrong input! Try again.....");
                         Sleep(600);
                        system("cls");
                        Sleep(500);
                           }
                     system("COLOR 0F");
                       more();
                              }
                    break;
    case 2:
        system("CLS");
            bnk();
            break;
    case 3:
        system("CLS");
            d();
            break;
    case 4:
        system("CLS");
        me();
        break;
    case 5:
        system("CLS");
        printf("1. Gazipur\n2. Uttara\n3. Mirpur\n4. Gulshan");
        printf("\nEnter your area :");
        scanf("%d",&p);
        if(p==1){
            emG();
            printf("\nContract as your desire hospitals :-)\n");
        }
        else if(p==2){
                 emu();
            printf("\nContract as your desire hospitals :-)\n");
        }
        else if(p==3){
                 emMir();
            printf("\nContract as your desire hospitals :-)\n");
        }
        else{
                  emG();
            printf("\nContract as your desire hospitals :-)\n");
        }
        break;
    case 6:
        system("CLS");

        while(1){
        printf("1. Insert Doctor\n");
        printf("2. Insert new doctor\n");
        printf("3. Display Doc List\n");
        printf("4. Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        if(c==1)
        {
             system("CLS");
            printf("Enter Number of Doctor\n");
            scanf("%d",&n);
             insert(n);
             break;
        }
       else if(c==2)
        {
            system("cls");
            insertEnd();
            break;
        }
      else if(c==3)
        {
            system("cls");
            display();
            break;
        }
        else{
                printf("Thank You :-)");
                break;
        }
    }
     break;
    default:
                for(i=0; i<3; i++)
                   {
                      system("COLOR C1");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....Wrong input! Try again.....");
                         Sleep(600);
                        system("cls");
                        Sleep(500);
                    }
               system("COLOR 0F");
        more();
        break;
   }
}


int b();     //Small error fixed

/// if user's called wrong Service list command,then it will ask for new command

int more(){
int i,y,p;
   int are,n,c;
    char LOH[30];
    char BB[30];
    char Am[30];
    char med[40];
    char em[50];
    printf("\n\t\t\t\t\t\t\t\t    Our Services Are :\n");
    printf("\t\t\t\t\t\t\t\t   ---------------------\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
    printf("\t\t\t\t\t ||\t 1\t     ||\t \t \t \t \t||\t2\t||\n");
    printf("\t\t\t\t\t |  List Of Hospitals | \t \t \t\t|  Blood Banks \t |\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
    printf("\t\t\t\t\t ||\t 3\t     ||\t \t \t \t \t||\t4\t||\n");
    printf("\t\t\t\t\t |  Ambulance Booking | \t \t \t\t|  E-Medicine \t |\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");
     printf("\t\t\t\t\t ||\t 5\t     ||\t \t \t \t \t||\t6\t||\n");
    printf("\t\t\t\t\t |    Emergency       | \t \t \t\t| My Doctor list |\n");
    printf("\t\t\t\t\t ---------------------- \t \t \t \t------------------\n");

    printf("\"Enter Your Choice (as number)\":");
    scanf("%d",&y);
     system("CLS");
    switch(y)
    {
         case 1:
             printf("\nHospitals In Dhaka\n");
             printf("------------------\n");
             printf("\n1.Gazipur \n2.Uttara \n3.Gulshan\n4.mirpur\n");
        printf("Enter Your Area: ");
        scanf("%d",&are);
        if(are == 1){
            gazi();
        }
        else if(are==2){
                Utt();
        }
        else if(are ==3){
                gul();
        }
        else if(are == 4){
                mirp();}
                else{

              for(i=0; i<3; i++)
                {
                 system("COLOR C1");
                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....Wrong Input.....");
                 Sleep(600);
                system("cls");
                   Sleep(500);
                   }
                   system("COLOR 0F");

                     more();
                }
                  break;

    case 2:
            bnk();
            break;
    case 3:
            d();
            break;
    case 4:
        me();
        break;

      case 5:
        system("CLS");
        printf("1. Gazipur\n2. Uttara\n3. Mirpur\n4. Gulshan");
        printf("\nEnter your area :");
        scanf("%d",&p);
        if(p==1){
            emG();
            printf("\nContract as your desire hospitals :-)\n");
        }
        else if(p==2){
                 emu();
            printf("\nContract as your desire hospitals :-)\n");
        }
        else if(p==3){
                 emMir();
            printf("\nContract as your desire hospitals :-)\n");
        }
        else{
                  emG();
            printf("\nContract as your desire hospitals :-)\n");
        }
        break;
          case 6:
        system("CLS");

        while(1){
        printf("1. Insert Doctor\n");
        printf("2. Insert new doctor\n");
        printf("3. Display Doc List\n");
        printf("4. Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        if(c==1)
        {
             system("CLS");
            printf("Enter Number of Doctor\n");
            scanf("%d",&n);
             insert(n);
             break;
        }
       else if(c==2)
        {
            system("cls");
            insertEnd();
            break;
        }
      else if(c==3)
        {
            system("cls");
            display();
            break;
        }
        else{
                printf("Thank You :-)");
                break;
        }
    }
     break;
    default:
        printf("Wrong input! Try again\n");
        more();
        break;
    }
}

/// 1. List Of Hospitals start
/// List of hospitals in Gazipur Area and details

int gazi(){
    int y;
      printf("\n *****Here's are the all hospitals name around Gazipur area *****\n\n");
       printf("1.Bangladesh Institute of Health Science Hospital, Tongi, Gazipur{Ashraf Setu Shopping Complex,Dhaka-Mymensingh Hwy,Tongi} .\n\t\t\t\t\t\t\t\t\t\t\t  {ph- 8801783-917151}\n");
             printf("2.Catharsis Hospitals {1800 SHILMOON,Jaydevpur}.\n\t\t\t\t  {01777646576, 01880884417}\n\n");

              printf("Select Hospital Near Your Location : ");
              scanf("%d",&y);
                if(y==1){
                printf("\nAvailable Services of \"Bangladesh Institute of Health Science Hospital\"\n ");
                printf("1. Clinical Lab.\n");
                printf("2. Radiology & Imaging.\n");
                printf("3. Rehablitation.\n");
                printf("4. Physiotherapy Center.\n");
                printf("5. Vaccination center.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://www.bihsh.org.bd/c_lab.php/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://www.bihsh.org.bd/imagine.php/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://www.bihsh.org.bd/rehabilitation.php/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
                }
               else if(y==2){
                printf("\nAvailable Services of \"Bangladesh Institute of Health Science Hospital\"\n ");
                printf("1. Cardiology.\n");
                printf("2. Physiotherapy.\n");
                printf("3. Dialysis.\n");
                printf("4. Pathology.\n");
                printf("5. Opthalmology.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://www.catharsismedical.com/cardiology-dpt//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://www.catharsismedical.com/physiotherapy-department//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://www.catharsismedical.com/dialysis-department//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://www.catharsismedical.com/pathology-lab-department//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://www.catharsismedical.com/ophthalmology-department//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
                }
                 else b();     ///wrong input and will take new command
}

/// List of hospitals in Mirpur Area and details

int mirp(){
    int y;
     printf("\n *****Here's are the all hospitals name around Mirpur area *****\n\n");
    printf("1.Delta Health Care{11,Central Mosque, Bus Stand Mirpur, Dhaka 1216} .\n\t\t\t\t\t\t\t  {ph-01407075714,01407075715}\n");
             printf("2.Bangladesh Eye Hospitals {Sumi Tower, 66 Zoo Road, Dhaka 1216}.\n\t\t\t\t  {01847422010}\n");
             printf("3.Kidney Foundation {Plot No. - 5/2, Road No.-1,(Main Road), Section-2, Mirpur,Dhaka-1216. }\n\t\t\t\t\t\t  {ph- 02-44807448}\n");
             printf("4.MEDINOVA  Hospital { House 71/A, Road 5/A, Dhanmondi R/A, Dhaka 1209, Bangladesh}.\n\t\t\t\t\t\t  {01796-222222}\n");


            printf("Select Hospital Near Your Location : ");
            scanf("%d",&y);
            if(y==1){
                printf("\nAvailable Services of \"Delta Health Care\"\n");
                printf("1. Obstetric.\n");
                printf("2. Dermatology.\n");
                printf("3. Anaesthesia.\n");
                printf("4. ENT.\n");
                printf("5. Neuro surgery.\n");
                printf("6. Respiratory Medicine.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/obstetric-gynecology/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/dermatology/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/anaesthesia-pain-medicine/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/ent-head-neck-surgery/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/neuro-surgery/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/respiratory-medicine/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
           else if(y==2){
                printf("\nAvailable Services of \"Bangladesh Eye Hospitals\"\n");
                printf("1. Vitrieo Retina.\n");
                printf("2. Cornea.\n");
                printf("3. Glaucoma.\n");
                printf("4. Pediatric Opthalmology.\n");
                printf("5. Uveitis.\n");
                printf("6. Cataract.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://bdeyehospital.com/#/subspecialties/58e62599097f3837a40a4060/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://bdeyehospital.com/#/subspecialties/58e625f8097f3837a40a4062/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://bdeyehospital.com/#/subspecialties/58e625db097f3837a40a4061/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://bdeyehospital.com/#/subspecialties/58e62655097f3837a40a4064/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://bdeyehospital.com/#/subspecialties/58e62676097f3837a40a4067/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer https://bdeyehospital.com/#/subspecialties/58e6256e097f3837a40a405f/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }


            }
            else if(y==3){
                printf("Available Services of \"Kidney Foundation\"\n");
                printf("1. Clinical Nephrology.\n");
                printf("2. Clinical Urology.\n");
                printf("3. Dialysis.\n");
                printf("4. Kedney Transplatation.\n");
                printf("5. CAPD.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://www.kidneyfoundationbd.com/facilities/clinical-nephrology/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://www.kidneyfoundationbd.com/facilities/clinical-urology/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://www.kidneyfoundationbd.com/facilities/dialysis-facilities/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://www.kidneyfoundationbd.com/facilities/transplantation-facility/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://www.kidneyfoundationbd.com/facilities/capd-facility/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
              else if(y==4){
                printf("Available Services of \"Medinova Hospital\"\n");
                printf("1. Radiology Imaging.\n");
                printf("2. Cardiology.\n");
                printf("3. Respiratory.\n");
                printf("4. Immunization_Vaccination.\n");
                printf("5. Neuro-science.\n");
                printf("6. Diabetic Side.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://medinova.com.bd/index.php/our-technology-services/radiology-imaging//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://medinova.com.bd/index.php/our-technology-services/cardiology//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://medinova.com.bd/index.php/our-technology-services/respiratory-care//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://deltahealthcaremirpurltd.com/department/ent-head-neck-surgery/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://medinova.com.bd/index.php/our-technology-services/immunization_vaccination///");
                  printf("Website loaded successfully :\n");
                }
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer http://medinova.com.bd/index.php/our-technology-services/diabetic-clinic//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
             else b();     ///wrong input and take new command
}


/// List of hospitals in Gulshan Area and details

int gul(){
    int y;
     printf("\n *****Here's are the all hospitals name around Gulshan area *****\n\n");
    printf("1.Z H SIKDER WOMEN’S MEDICAL COLLEGE JOURNAL{40 Felicity, 104 Rd 104, Dhaka 1212} .\n\t\t\t\t\t\t\t  {ph- 02-9181005-8}\n");
             printf("2.Shahabuddin Medical College {House-12 Rd No 113/A, Dhaka 1212}.\n\t\t\t\t  {01915-055555}\n");
             printf("3.RAHETID {C/A,Zahed Plaza,3rd Floor,30 Gulshan North Ave,Dhaka 1212 }\n\t\t\t\t\t\t  {ph-01787694510}\n");
             printf("4.Ever-care Hospital {Plot:81 Block: E,Dhaka 1229}.\n\t\t\t\t\t\t  {09666710678}\n");
             printf("5.Banani Clinic Ltd. {Rd No 13C, Dhaka 1212}.\n\t\t\t\t\t\t {01611443345}\n");
             printf("6.Square Hospital {18/F, Bir Uttam Qazi Nuruzzaman Sarak West, Panthapath, Dhaka 1205}.\n\t\t\t\t\t\t\t\t  {09610010616}\n");
             printf("7.Shomorita Hospital {89/1 Panthapath, Dhaka 1215}.\n\t\t\t\t\t\t\t\t  {9131901}\n");

            printf("Select Hospital Near Your Location : ");
            scanf("%d",&y);
            if(y==1){
                printf("Available Services of \"Z H SIKDER WOMEN’S MEDICAL COLLEGE JOURNAL\"\n");
                printf("1. Cardiology.\n");
                printf("2. Neorousergery.\n");
                printf("3. Nuclear Medicine.\n");
                printf("4. Phychiatry.\n");
                printf("5. Radiology And Imaging.\n");
                printf("6. Nephrology.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://www.sikdermedical.com/cardiac-surgery//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://www.sikdermedical.com/neurosurgery//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://www.sikdermedical.com/nuclear-medicine//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://www.sikdermedical.com/psychiatry//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://www.sikdermedical.com/radiology-and-imaging//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer https://www.sikdermedical.com/nephrology//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
            else if(y==2){
                printf("Available Services of \"Shahabuddin Medical College\"\n");
                printf("1. Drug Test.\n");
                printf("2. 4D Ultrasonogram.\n");
                printf("3. ETT (Exercise Tolerance Test).\n");
                printf("4. Open Dental X-ray.\n");

                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://shahabuddinmedical.org/hospital/facilities//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://shahabuddinmedical.org/hospital/facilities//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://shahabuddinmedical.org/hospital/facilities//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://shahabuddinmedical.org/hospital/facilities//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
               else if(y==3){
                printf("Available Services of \"RAHETID\"\n");
                printf("1. Laparoscopic.\n");
                printf("2. Colorectal Surgery.\n");
                printf("3. Endoscopy.\n");
                printf("4. Endocrinology.\n");
                printf("5. Orthopaedics.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://www.rahetidhospital.com/laparoscopic-general-surgery/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://www.rahetidhospital.com/colorectal-surgery/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://www.rahetidhospital.com/endoscopy-and-colonoscopy/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://www.rahetidhospital.com/endocrinology/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://www.rahetidhospital.com/orthopaedics/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
             else if(y==4){
                printf("Available Services of \"Ever-care Hospital\"\n");
                printf("1. Cardiology.\n");
                printf("2. Fertility Center.\n");
                printf("3. Gastoentarology.\n");
                printf("4. Neurology.\n");
                printf("5. Orthopaedics.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://www.evercarebd.com/cardiology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://www.evercarebd.com/fertility-centre//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://www.evercarebd.com/gastroenterology-hepatology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://www.evercarebd.com/neurology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://www.evercarebd.com/orthopaedics//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
             else if(y==5){
                printf("Available Services of \"Banani Clinic Ltd.\"\n");
                printf("1. Cardiology.\n");
                printf("2. Gastoentarology.\n");
                printf("3. Kidney.\n");
                printf("4. Phyciatry.\n");
                printf("5. Urology.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://www.bshlbd.com/consultation-services/cardiology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://www.bshlbd.com/consultation-services/gastroenterology-hepatology//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://www.bshlbd.com/consultation-services/nephrology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://www.bshlbd.com/consultation-services/psychiatry//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://www.bshlbd.com/consultation-services/urology//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
            else if(y==6){
                printf("Available Services of \"Square Hospitals\"\n");
                printf("1. Urology center.\n");
                printf("2. Kidney and Dialysis.\n");
                printf("3. Neuroscience Center.\n");
                printf("4. Orthopedicts.\n");
                printf("5. Fertility Center.\n");
                 printf("6. Respiratory center.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://www.squarehospital.com/page/131/square-advanced-urology-center-/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://www.squarehospital.com/page/132/square-children-kidney-&-dialysis-centre-/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://www.squarehospital.com/page/129/square-neuroscience-centre/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://www.squarehospital.com/page/5/square-orthopedics-&-trauma-centre/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://www.squarehospital.com/page/1/square-fertility-centre/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer https://www.squarehospital.com/page/8/square-respiratory-and-sleep-medicine-centre/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
            else if(y==7){
                printf("Available Services of \"Shomorita Hospital\"\n");
                printf("1. Stroke Unit.\n");
                printf("2. Coronary Care Unit.\n");
                printf("3. CT Scan.\n");
                printf("4. Radiology.\n");
                printf("5. Opthalmology.\n");
                 printf("6. ENT.\n");
                 printf("7. Plastic Surgery.\n");
                 printf("8.Pediatric.\n");
                 printf("9. Rehabilitation.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/prof-sgm-chowdhury-stroke-unit//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/coronary-care-unit//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/ct-scan-multi-slice//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/radiology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/ophthalmology//");
                  printf("Website loaded successfully :\n");}
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/ear-nose-and-throat//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==7){
                                        printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/plastic-surgery//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==8){
                                        printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/pediatric-clinic//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==9){
                                        printf("Loading Website :\n");
                 system("explorer http://www.samoritahospital.org/rehabilitation-therapy//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
        }
         else b();   ///wrong input and take new command
}


/// List of hospitals in Uttara Area and details

int Utt(){
    int y;
     printf("\n *****Here's are the all hospitals name around Tongi & Uttara area *****\n\n");
    printf("1.Uttara Crescent Diagnostic & Consultation Center{40 Rabindra Sarani} .\n\t\t\t\t\t\t\t  {ph- 01917704150-51}\n");
             printf("2.Appolo Hospital {Bashundhar r/a}.\n\t\t\t\t  {(02) 8401661- 5}\n");
             printf("3.Ahsania Mission Cancer and General Hospital {Plot-03,Embankment Drive Way Sector-10 }\n\t\t\t\t\t\t  {ph- 01531291810}\n");
             printf("4.Shin Shin Japan Hospital {17 Gareeb-e-Nawaz Ave,Dhaka 1230}.\n\t\t\t\t\t\t  {(02)-48962921}\n");
             printf("5.Dhaka Eye Care Hospital {32 Rabindra Sarani, Dhaka 1230}.\n\t\t\t\t\t\t {01716845974, 01716845917}\n");
             printf("6.Aichi Hospital Ltd. {Plot- 35 & 37, Sector-08,Abdullahpur Main Road, Dhaka 1230}.\n\t\t\t\t\t\t\t\t  {01689956599}\n");
             printf("7.Japan East West Medical COllege {Aichi Nagar,JBCS Sarani,Horirampur,Turag}.\n\t\t\t\t\t\t\t\t  {09611222666}\n");

             printf("\nSelect Hospital Near Your Location : ");
             scanf("%d",&y);
             if(y==1){
                printf("Available Services of \"Uttara Crescent Diagnostic & Consultation Center\"\n");
                printf("1. Dialysis Unit.\n");
                printf("2. Dental care.\n");
                printf("3. Laser skin care.\n");
                printf("4. Physiotherapy Center.\n");
                printf("5. Vaccination center.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://www.uchbd.com/service/22/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://www.uchbd.com/service/15/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://www.uchbd.com/service/14/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://www.uchbd.com/service/8/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://www.uchbd.com/service/16/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!\n");
                }
            }
           else if(y==2){
                printf("Available Services of \"Appolo Hospital\"\n");
                printf("1. Heart Care.\n");
                printf("2. Eye-Ear Care.\n");
                printf("3. Anesthesia Care.\n");
                printf("4. Cancer Care.\n");
                printf("5. Lab test.\n");
                int a;
                printf("Enter Your necessity.. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://bangalore.apollohospitals.com/jayanagar/specialities/heart-institute//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://bangalore.apollohospitals.com/jayanagar/specialities/cancer-institute//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://bangalore.apollohospitals.com/jayanagar/specialities/anesthesia//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://bangalore.apollohospitals.com/jayanagar/specialities/apollo-diagnostics//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://bangalore.apollohospitals.com/jayanagar/specialities/apollo-diagnostics//");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!");
                }
            }
            else if(y==3){
                printf("Available Services of \"Ahsania Mission Cancer and General Hospital\"\n");
                printf("1. Cancer care.\n");
                printf("2. Eye Care.\n");
                printf("3. Physiotherapy.\n");
                printf("4. Histopathology lab.\n");
                printf("5. ECHO Cardiography.\n");
                printf("6. Nuclear Medicine.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://amcghbd.org/cancer-care//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://amcghbd.org/eye-care//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://amcghbd.org/physiotherapy//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer http://amcghbd.org/histopathology-lab//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer http://amcghbd.org/eco-cardiography//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==6){
                                        printf("Loading Website :\n");
                 system("explorer http://amcghbd.org/nuclear-medicine-2//");
                  printf("Website loaded successfully :\n");}
                else{
                    printf("Wrong Input!");
                }
            }
            else if(y==4){
                printf("Available Services of \"Shin Shin Japan Hospital\" ");
                printf("1. Orthopaedics.\n");
                printf("2. ENT.\n");
                printf("3. Cardiology.\n");
                printf("4. Neuro surgery.\n");
                printf("5. Kidney & Urology.\n");
                printf("6. Dental.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://simecinstitute.edu.bd/shinshin/department/orthopaedics//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://simecinstitute.edu.bd/shinshin/department/ent//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://simecinstitute.edu.bd/shinshin/department/cardiology//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                 printf("Loading Website :\n");
                 system("explorer http://simecinstitute.edu.bd/shinshin/department/neuro-medicine//");
                  printf("Website loaded successfully :\n");}
                 else if(a==5){
                                 printf("Loading Website :\n");
                 system("explorer http://simecinstitute.edu.bd/shinshin/department/kidney-urology//");
                  printf("Website loaded successfully :\n");}
                 else if(a==6){
                                 printf("Loading Website :\n");
                 system("explorer http://simecinstitute.edu.bd/shinshin/department/dental//");
                  printf("Website loaded successfully :\n");}
                else{
                    printf("Wrong Input!");
                }
            }
           else if(y==5){
                printf("Available Services of \"Dhaka Eye Care Hospital\"\n ");
                printf("1. Cornea & External Disease.\n");
                printf("2. Vitreo-Retina.\n");
                printf("3. Neuro-ophthalmology.\n");
                printf("4. LASIK & Refractive Surgery.\n");
                printf("5. Glaucoma.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://dhakaeyecarehospital.org/specialities/details/cornea-and-external-disease/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://dhakaeyecarehospital.org/specialities/details/vitreo-retina/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://dhakaeyecarehospital.org/specialities/details/neuro-ophthalmology/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==4){
                                    printf("Loading Website :\n");
                 system("explorer https://dhakaeyecarehospital.org/specialities/details/lasik-and-refractive-surgery/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==5){
                                        printf("Loading Website :\n");
                 system("explorer https://dhakaeyecarehospital.org/specialities/details/glaucoma/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!");
                }
            }
            else if(y==6){
                printf("Available Services of \"Aichi Hospital Ltd.\"\n");
                printf("1. Plastic Surgery.\n");
                printf("2. Cardiology.\n");
                printf("3. ENT.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer http://aichihospital.com/plastic-surgery//");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer http://aichihospital.com/cardiology//");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer http://aichihospital.com/ent//");
                  printf("Website loaded successfully :\n");
                }

                else{
                    printf("Wrong Input!");
                }
            }
           else if(y==7){
                printf("Available Services of \"Japan East West Medical COllege\"\n ");
                printf("1. Renal/Kidney Screening.\n");
                printf("2. Liver Check up.\n");
                printf("3. Smoker Health Check-up.\n");
                int a;
                printf("Enter Your necessity. We will take you to the website  :");
                scanf("%d",&a);
                if(a==1){
                     printf("Loading Website :\n");
                 system("explorer https://jewmch.com/renal-kidney-screening/");
                  printf("Website loaded successfully :\n");
                }
                else if(a==2){
                            printf("Loading Website :\n");
                 system("explorer https://jewmch.com/liver-check-up-package-one/");
                  printf("Website loaded successfully :\n");
                    }
                else if(a==3){
                                 printf("Loading Website :\n");
                 system("explorer https://jewmch.com/smoker-health-checkup/");
                  printf("Website loaded successfully :\n");
                }
                else{
                    printf("Wrong Input!");
                }
            }
             else b();   ///wrong input and take new command
}

/// If User's Called wrong command list of hospitals,then it will ask new command

//  List of services

int cas();   //small error fixed

int b(){
    char LOH[30];
    char BB[30];
    char Am[30];
    char med[40];
    char em[50];
    system("CLS");
    printf("\nInvalid Input! try again.\n\n");
    printf("1.List Of Hospitals\n");
    printf("2.Blood Banks\n");
    printf("3.Ambulance Booking\n");
    printf("4.E-Medicine\n");
    printf("5.Emergency\n");
    printf("6.My Doctor List\n");
    cas();
}

// Here take new input

int cas(){
    int y,are,p,c,n;
      printf("\n\"Enter Your Choice (as number)\":");
    scanf("%d",&y);
   switch(y)
    {
         case 1:
             system("CLS");
             printf("\nHospitals In Dhaka\n");
             printf("------------------\n");
             printf("\n1.Gazipur \n2.Uttara \n3.Gulshan\n4.mirpur\n");
        printf("Enter Your Area: ");
        scanf("%d",&are);
        if(are == 1){
            gazi();
        }
        else if(are==2){
                Utt();
        }
        else if(are ==3){
                gul();
        }
        else if(are == 4){
                mirp();
        }
        else {
                int i;
                for(i=0; i<3; i++)
                   {
                      system("COLOR C1");
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t                 .....Wrong input! Try again.....");
                         Sleep(600);
                        system("cls");
                        Sleep(500);
                           }
                     system("COLOR 0F");
                       more();
        }
        break;
        case 2:
        system("CLS");
            bnk();
            break;
            case 3:
             system("CLS");
            d();
            break;
    case 4:
           system("CLS");
           me();
            break;
    case 5:
          system("CLS");
          printf("1. Gazipur\n2. Uttara\n3. Mirpur\n4. Gulshan");
             printf("\nEnter your area :");
            scanf("%d",&p);
            if(p==1){
            emG();
            printf("\nContract as your desire hospitals :-)\n");
              }
        else if(p==2){
                 emu();
            printf("\nContract as your desire hospitals :-)\n");
                    }
        else if(p==3){
                 emMir();
            printf("\nContract as your desire hospitals :-)\n");
                   }
        else{
                emG();
            printf("\nContract as your desire hospitals :-)\n");
               }
    break;
    case 6:
        system("CLS");

        while(1){
        printf("1. Insert Doctor\n");
        printf("2. Insert new doctor\n");
        printf("3. Display Doc List\n");
        printf("4. Exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        if(c==1)
        {
             system("CLS");
            printf("Enter Number of Doctor\n");
            scanf("%d",&n);
             insert(n);
             break;
        }
       else if(c==2)
        {
            system("cls");
            insertEnd();
            break;
        }
      else if(c==3)
        {
            system("cls");
            display();
            break;
        }
        else{
                printf("\nThank You :-)");
                break;
        }
    }
     break;
       default:
        printf("\nWrong Input! Try again");
        more();
        break;
    }
}

///2. Blood Bank List

int bnk();  //short error fixed

int bnk(){
printf("****All Blood Bank merge list****\n");
printf("---------------------------------\n");
printf("Here's all the Contact number list.\n\n");
printf("***Bangladesh Thalassemia Foundation***.\n1. 01755587479\n2.    0248316116\n3. 028318177\n4.    029334862\n\n");
printf("***Quantum Foundation***.\n1. 01740630856\n2.    01714010869\n3. 01717144724\n\n");
printf("***Lab One Blood Bank***.\n1. 01922117676\n2.    01922117677\n3. 01922117676\n");
}
int c();

///3. Ambulance booking side

void am(){
int b;
printf("-------------\n");
printf("|Select one:");
scanf("%d",&b);
printf("-------------\n");
switch(b){
case 1:
    printf("Contract Number Of AC Services:\n");
    printf("1. 01714360988\n2. 01919992229\n3. 01720-382537\n4. 01715-385498\n5. 01732-587070\n6. 01771775570\n7. 01911558782");
    break;
case 2:
    printf("Contract Number Of Non-AC Services:\n");
    printf("1. 01714360988\n2. 01714360988\n3. 01732-587070\n4. 01790-509607 ");
    break;
case 3:
    printf("Contract Number Of Freezing-van Services:\n");
    printf("1. 01911558782\n2. 01771775570\n3. 01732-587070\n4. 01710070011\n5. 01790509607");
    break;
case 4:
    printf("Contract Number Of ICU-Ambulance Services:\n");
    printf("1. 01710070011\n2. 01715-385498\n3. 01919-382537\n4. 01732-587070 ");
    break;
case 5:
    printf("Contract Number Of Cheap Services:\n");
    printf("1. 01720-382537\n2. 01715-385498\n3. 01919-382537\n4. 01732-587070\n5. 01715834829\n6. 01886229184. ");
    break;

default:
    printf("Invalid Input !try again.\n");
    c();     //Ambulance catagory called

}
}

/// Ambulance Catagory

int c(){

printf("1. AC\n2. Non-AC\n3. Freezing Van\n4. ICU Ambulance\n5. Cheap Services\n");
am();         //Ambulance service function
}

/// If user's command wrong input,then sorting the list for further process

int d(){
printf("****All type of Ambulance Services list****\n");
printf("    -----------------------------------\n");
printf("1. AC\n2. Non-AC\n3. Freezing Van\n4. ICU Ambulance\n5. Cheap Services\n");
am();                    //Ambulance service function called
}

///4. Emergency Medicine service

int me(){
printf("Visit the site to buy Medicine\n");
system("explorer https://www.pharmacy.com.bd//");
system("CLS");
printf("\n\t Wellcome back :)\n");
}

///Emergency Side start
///5. Emergency Side for Mirpur area

int emMir()
{
     printf("\t\t\t\t\t\t______/Here is  all emergency unit holding hospitals list in Mirpur area\\______\n\n");

     printf("\n1.Delta Health Care{11,Central Mosque, Bus Stand Mirpur, Dhaka 1216} .\n");

       printf("\t\t\t\t\t ^---{{ph-01407075714,01407075715}---^\n");

             printf("\n2.Bangladesh Eye Hospitals {Sumi Tower, 66 Zoo Road, Dhaka 1216}.\n");
             printf("\t\t\t\t\t\t ^---{ph-01847422010}---^\n");

             printf("\n3.Kidney Foundation {Plot No. - 5/2, Road No.-1,(Main Road), Section-2, Mirpur,Dhaka-1216. }\n");
             printf("\t\t\t\t\t\t\t ^---{ph-02-44807448}---^\n");

             printf("\n4.MEDINOVA  Hospital { House 71/A, Road 5/A, Dhanmondi R/A, Dhaka 1209, Bangladesh}.\n");
             printf("\t\t\t\t\t\t ^---{ph-01796-222222}---^\n");

              printf("\n5.Mirpur General Hospital & Diagnostic Centre { House 71/A, Road 5/A, Dhanmondi R/A, Dhaka 1209, Bangladesh}.\n");
              printf("\t\t\t\t\t\t\t\t\t ^---{ph-01785906599}---^\n");

              printf("\n6.Mirpur Adhunik Hospital And Diagnostic Center { House 71/A, Road 5/A, Dhanmondi R/A, Dhaka 1209, Bangladesh}.\n");
              printf("\t\t\t\t\t\t\t\t\t ^---{ph-01796-222222}---^\n");

              printf("\n7.DR. AZMAL HOSPITAL LTD. { House 71/A, Road 5/A, Dhanmondi R/A, Dhaka 1209, Bangladesh}.\n");
              printf("\t\t\t\t\t\t  ^---{ph-09612304304}---^\n");

              printf("\n8.Kingston Hospital { House 71/A, Road 5/A, Dhanmondi R/A, Dhaka 1209, Bangladesh}.\n");
              printf("\t\t\t\t\t\t\t\t ^---{ph-01952989866}---^\n");
}

/// Emergency Side for Gazipur area

int emG()
{
     printf("\t\t\t\t\t\t______/Here is  all emergency unit holding hospitals list in Gazipur area\\______\n");

     printf("\n1.Bangladesh Institute of Health Science Hospital, Tongi, Gazipur{Ashraf Setu Shopping Complex,Dhaka-Mymensingh Hwy,Tongi} .\n");
             printf("\n2.Catharsis Hospitals {1800 SHILMOON,Jaydevpur}.\n\t\t\t\t  {01777646576, 01880884417}\n");
             printf("\t\t\t\t\t ^---{ph- 01783-917151}---^\n");
             printf("\n3.Police line hospital { police line hospital, Gazipur}\n");
             printf("\t\t\t\t\t ^---{ph- 01771911352}---^\n");

             printf("\n4.Tairunnessa Memorial Medical College & Hospital { Konia (Targach), National University, Dhaka-Mymensigh Highway, Gazpur 1704}\n");
             printf("\t\t\t\t\t ^---{ph- 01914213134}---^\n");

             printf("\n5.City Medical College & Hospital, Gazipur { Block B Dhaka - Tangail Highway, 1205}\n");
             printf("\t\t\t\t\t ^---{ph-01951402122}---^\n");

               printf("\n6.ABC Eye Hospital { Salna, Dhaka - Mymensingh Highway, Gazipur}\n");
             printf("\t\t\t\t\t ^---{ph-01757309589}---^\n");

              printf("\n7.International Medical College & Hospital { Medical College Rd, Tongi 1711}\n");
             printf("\t\t\t\t\t ^---{ph-01313498583}---^\n");
}

/// Emergency Side for Uttara area
int emu()
{
     printf("\t\t\t\t\t\t______/Here is  all emergency unit holding hospitals list in Uttara area\\______\n");

             printf("\n1.Uttara Crescent Diagnostic & Consultation Center{40 Rabindra Sarani}.\n");
             printf("\t\t\t\t\t ^---{ph- 01917704150-51}---^\n");
             printf("\n2.Appolo Hospital {Bashundhar r/a}.\n");
             printf("\t\t\t\t\t ^---{ph- (02) 8401661- 5}---^\n");

             printf("\n3.Ahsania Mission Cancer and General Hospital {Plot-03,Embankment Drive Way Sector-10 }\n");
             printf("\t\t\t\t\t ^---{ph- 01531291810}---^\n");

             printf("\n4.Shin Shin Japan Hospital {17 Gareeb-e-Nawaz Ave,Dhaka 1230}.\n");
             printf("\t\t\t\t\t ^---{ph- (02)-48962921}---^\n");

             printf("\n5.Dhaka Eye Care Hospital {32 Rabindra Sarani, Dhaka 1230}.\n");
             printf("\t\t\t\t\t^---{ph- 01716845974 , 01716845917}---^\n");

             printf("\n6.Aichi Hospital Ltd. {Plot- 35 & 37, Sector-08,Abdullahpur Main Road, Dhaka 1230}.\n");
             printf("\t\t\t\t\t ^---{ph- 01689956599}---^\n");
             printf("\n7.Japan East West Medical COllege {Aichi Nagar,JBCS Sarani,Horirampur,Turag}.\n");
             printf("\t\t\t\t\t ^---{ph- 09611222666}---^\n");
}

/// Emergency Side for Gulshan area
void emg()
{
    system("CLS");
    printf("\t\t\t\t\t\t______/Here is  all emergency unit holding hospitals list in Gulshan area\\______\n");
   printf("\n1.Z H SIKDER WOMEN’S MEDICAL COLLEGE JOURNAL{40 Felicity, 104 Rd 104, Dhaka 1212}");
   printf("\n\t\t\t\t\t\t  ^---{ph- 02-9181005-8}---^\n");
             printf("\n2.Shahabuddin Medical College {House-12 Rd No 113/A, Dhaka 1212}.\n");
               printf("\t\t\t\t\t\t  ^---{ph- 01915-055555}---^\n");
             printf("\n3.RAHETID {C/A,Zahed Plaza,3rd Floor,30 Gulshan North Ave,Dhaka 1212 }\n");
             printf("\t\t\t\t\t\t  ^--- phn(01787694510)---^");

             printf("\n4.Ever-care Hospital {Plot:81 Block: E,Dhaka 1229}.\n");
              printf("\t\t\t\t\t^---{ph- 01915-055555}---^\n");

             printf("\n5.Banani Clinic Ltd. {Rd No 13C, Dhaka 1212}\n");
              printf("\t\t\t\t\t^---{ph- 09666710678, 01611443345}---^\n");

             printf("\n6.Square Hospital {18/F, Bir Uttam Qazi Nuruzzaman Sarak West, Panthapath, Dhaka 1205}\n");
              printf("\t\t\t\t\t\t  ^---{ph- 09610010616}---^\n");

             printf("\n7.Shomorita Hospital {89/1 Panthapath, Dhaka 1215}.\n");
              printf("\t\t\t\t\t ^---{ph- 9131901}---^\n");
}

/// Appointment side

struct patient{
char Fname[15], Lname[15], disease[100], dob[15], gender[8];
} pt[30] ;

int app();
int app(){
int i, n ;
for(i=0; i<2; i++)
    {
        printf("\n\n\t\t\t\t\t\t\t\t ****** Welcome To Appointment Side ****\n");
        printf("\t\t\t\t\t\t\t\t ---------------------------------------\n");
        Sleep(600);
        system("cls");
        Sleep(500);
    }
printf("\n\n\t\t\t\t\t\t\t\t ****** Welcome To Appointment Side ****\n");
printf("\t\t\t\t\t\t\t\t ---------------------------------------\n");
printf("Enter the Number of Patients: ");
scanf("%d", &n) ;
for(i = 0; i<n;i++) {
printf("\t\t\tPatient's Details:\n");
printf("\nEnter the Patients DOB: ");
scanf("%s", &pt[i].dob);
printf("\nEnter the first Name: ");
scanf("%s", pt[i].Fname);
printf("\nEnter the Last Name: ");
scanf("%s", pt[i].Lname);
printf("\nEnter the Gender: ");
scanf("%s", pt[i].gender);
printf("\nEnter the Disease Name: ");
scanf("%s", pt[i].disease);
}
system("CLS");
printf("\nDOB              \t First Name \t Last Name \t Gender \t Disease \n\n");

for(i = 0 ; i < n ; i++){
        puts(pt[i].dob);
printf(" \t\t             %s \t    %s \t  %s \t %s \n", pt[i].Fname, pt[i].Lname, pt[i].gender, pt[i].disease);
}
printf("\n\n\n\t\t\t  ______/****Successfully Appointment Created :)****\\_______\n\n");

}

/// If User's need more Services

int k(){
    int x;
    while(1){
     printf("\n\t\t\t\t\t\t\t\t===|| Do you want to use service's again! ||===\n\t\t\t\t\t\t\t\t~~~~|Yes (Press-->1) And No for (Press-->2) :");
    scanf("%d",&x);
    system("CLS");
    if(x == 1){
        more();              //When user need more services
        }
    else if(x == 2)
        {
        printf("\n\nThanks!\n\n");
        break;
        }
    }

}

///Main function

int main()
{
    int a,c,i;
                printf("\t\t\t\t\t\t\t\t **********^^^^^^^^^^^^^^^^^^***************");
                printf("\n\t\t\t\t\t\t\t\t ===========/    Wellcome To   \\============\n\t\t\t\t\t\t\t\t **********/ Doctor Is Here App \\***********\n");
                printf("\t\t\t\t\t\t\t\t ^^^^^^^^^/----------------------\\^^^^^^^^^^\n");
                printf("\t\t\t\t\t\t\t\t\t________|^^^^^^^^^|_________ \n\t\t\t\t\t\t\t\t ||(Website view-->1 || Programme view-->2)||\n\n\n\t\t\t\t\t\t\t\t\t         Press: " );
                scanf("%d",&a);
                switch(a){

        case 1:  printf("Loading Website :\n");
                 system("explorer https://sites.google.com/diu.edu.bd/dr-is-here/home");

                  for(i=0; i<5; i++)
                 {
                  system("COLOR 81");
                printf("\n\t\t\t\t\t\t_____________/ THANK YOU FOR YOUR SURVEY.STAY HEALTHY :)\\____________________\n");
                 Sleep(650);
                system("cls");
                Sleep(450);
                }
                 return 0;
                 break;

        case 2:
             system("CLS");

              well();      // Welcome page

    printf("\n\t\t\t\t\t\t\t\t ^^^^^\\ Do you have any Account\? /^^^^^^ \n\t\t\t\t\t\t\t\t ``````\\------------------------/``````\n");
    printf("\t\t\t\t\t\t\t\t\t/If you Have then press \\ \n\t\t\t\t\t\t\t\t      (log in-->1 || sign-up-->2)\n\t\t\t\t\t\t\t\t      /     (Guest Mode -->3)    \\\n\n\t\t\t\t\t\t\t\t\t         Press: ");
    scanf("%d",&a);
    if(a==1)
    {
    l_in();             //for login
    }
    else if(a==2){
        SignUp();         // for sign up
    }
    else{
        guest();          //for guest mode
        return 0;
    }
    lh();                 //List Of our services

    k();                   // For take more services

    printf("\n");
    printf("\t\t\t\t\t\t\t\t **********^^^^^^^^^^^^^^^^^^************\n");
     printf("\t\t\t\t\t\t\t\t// Do You Want To Make any Appointment\? \\\\  \n \t\t\t\t\t\t\t\t||If Yes (Press->1) and No for (Press->2)||\n ");
    printf(" \t\t\t\t\t\t\t\t\t       Press :");
     scanf("  %d",&c);
    printf("\n");
    if(c == 1){
    app();                //Appointment Side
    printf("\n\t\t\t\t  __________________/THANKS FOR YOUR SURVEY\\__________________\n");

    }

    else{
       for(i=0; i<3; i++)
          {
            system("COLOR 08");
               printf("\n\t\t\t\t\t\t_____________/ THANK YOU FOR YOUR SURVEY.STAY HEALTHY :)\\____________________\n");
             Sleep(650);
            system("cls");
            Sleep(450);
         }
       }
    return 0;
    break;
}
}



                                                              ///[_____/ END  \______]





