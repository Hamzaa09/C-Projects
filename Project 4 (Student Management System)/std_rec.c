#include <stdio.h>
#include <conio.h>
#include <windows.h>

//system functions
void gotoxy(int x,int y);
int system();

//menu functions
void menu ();
void view();
void new_rec();
void update();
void search();
void delete();

//structure for students

typedef struct students {

    char name[100];
    int rollno;
    char class[50];
    char mobile[50];
    char batch[50];

}students;


int main (){
    
    printf("\n\nStudens Record File\n");
    gotoxy(0,10);
    printf("Press Any Key To continue...");
    getch();
    
   menu ();
   
    return 0;
} 


void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void menu (){
    system("cls");

    int input;

    printf("\n\n   <-- MENU -->  ");
    printf("\n\n  1. View Record\n");
    printf("  2. Create New Record\n");
    printf("  3. Update Record\n");
    printf("  4. Search Record\n");
    printf("  5. Delete Record\n");
    printf("  6. Close Menu\n");

    printf("\n\nEnter Number for respective tasks...\t");
    scanf("%d",&input);


    switch (input)
    {
    case 1:
        view();
        break;
    case 2:
        new_rec();
        break;
    case 3:
        update();
        break;
    case 4:
        search();
        break;
    case 5:
        delete();
        break;
    case 6:
        break;
    
    default:
        printf("\nInvalid Input :(");
        break;
    }
}


void new_rec(){

    system("cls");    

    students *stu;
    int n;

    printf("\n\n   <-- ADDING RECORDS -->  \n\n");


    printf("How Many Student Records You Want to Enter?? ");
    scanf("%d",&n);

    stu = (students*)calloc(n , sizeof(students) );
        
    FILE *ptr;
    ptr = fopen("record.txt" , "w");
    if(ptr == NULL){
        printf("Error opening file.");
        exit(1);
    }

    for (int i=0; i<n; i++){
            
        system("cls");

    printf("\n\nEnter %d Student's Data : ",i+1);

    printf("\n\nEnter Roll No. : ");
    scanf("%d" ,&stu[i].rollno);
    printf("\nEnter Name : ");
    fflush(stdin);
    gets(stu[i].name);
    printf("\nEnter Mobile No. : ");
    fflush(stdin);
    scanf("%s" , &stu[i].mobile);
    printf("\nEnter Class : ");
    fflush(stdin);
    scanf("%s" , &stu[i].class);
    printf("\nEnter Batch : ");
    fflush(stdin);
    scanf("%s", &stu[i].batch);

    fwrite(&stu[i],sizeof(students),1,ptr);
    }

    fclose(ptr);

    printf("Press Any Key to Return to main menu...");
    getch();
    menu();
}

void view(){

        system("cls");

    printf("\n\n   <-- VIEWING RECORDS -->  \n\n");
    printf("\n Roll No.       Name                           Mobile no.   Class  Batch\n");
    printf("-----------------------------------------------------------------------------\n"); 

    students stu;
    FILE *ptr;
    ptr = fopen("record.txt" , "r");
    if(ptr == NULL){
        printf("Error opening file.");
        exit(1);
    }

    while (fread(&stu,sizeof(students),1,ptr) != 0)
    {
        printf("\n  %-15d" , stu.rollno);
        printf("%-30s" , stu.name);
        printf("%-15s" , stu.mobile);
        printf("%-5s" ,  stu.class);
        printf("%-5s" ,  stu.batch);
    }
    fclose(ptr);
    
    printf("\n\n\nPress any key to Return to main menu... ");
    getch();


    menu();
}

void update(){

    system("cls");    

    students *stu;
    int n;

    printf("\n\n   <-- UPDATING EXISTING RECORDS -->  \n\n");


    printf("How Many Student Records You Want to Enter?? ");
    scanf("%d",&n);

    stu = (students*)calloc( n,sizeof(students) );
        
    FILE *ptr;
    ptr = fopen("record.txt" , "a");


    for (int i=0; i<n; i++){
            
        system("cls");

    printf("\n\nEnter %d Student's Data : ",i);

    printf("\n\nEnter Roll No. : ");
    scanf("%d" ,&stu[i].rollno);
    printf("\nEnter Name : ");
    fflush(stdin);
    gets(stu[i].name);
    printf("\nEnter Mobile No. : ");
    fflush(stdin);
    scanf("%s" , &stu[i].mobile);
    printf("\nEnter Class : ");
    fflush(stdin);
    scanf("%s" , &stu[i].class);
    printf("\nEnter Batch : ");
    fflush(stdin);
    scanf("%s", &stu[i].batch);


    fwrite(&stu[i],sizeof(students),1,ptr);
    }

    fclose(ptr);

    printf("Press Any Key to Return to main menu...");
    getch();
    menu();

}

void search(){
       
    system("cls");    

    students stu;
    int rollno;

    printf("\n\n   <-- SEARCHING EXISTING RECORD -->  \n\n");
        
    FILE *ptr;

    ptr = fopen("record.txt" , "r");

    printf("\n\nEnter Student's rollno to search : ");
    scanf("%d", &rollno);

    fread(&stu, sizeof(students),1,ptr);

    if (rollno == stu.rollno){
        printf("\n Roll No.       Name                           Mobile no.   Class  Batch\n");
        printf("-----------------------------------------------------------------------------\n"); 
        printf("\n  %-15d" , stu.rollno);
        printf("%-30s" , stu.name);
        printf("%-15s" , stu.mobile);
        printf("%-5s" ,  stu.class);
        printf("%-5s" ,  stu.batch);
    } else {
        printf("\nRecord Not Found\n\n");
    } 

    fclose(ptr);

    printf("\n\nPress Any Key to Return to main menu...");
    getch();
    menu();

}

void delete(){
    
    system("cls");    

    students stu;
    int rollno;

    printf("\n\n   <-- DELETING EXISTING RECORD -->  \n\n");
        
    FILE *ptr;
    FILE *ptr1;

    ptr = fopen("record.txt" , "r");
    ptr1 = fopen("record1.txt" , "w");

    printf("\n\nEnter Student's rollno to delete : ");
    scanf("%d", &rollno);

    while(fread(&stu, sizeof(students),1,ptr) != 0){
        if (rollno != stu.rollno){
            fwrite(&stu, sizeof(students),1,ptr1);
        }
    } 

    fclose(ptr);
    fclose(ptr1);

    remove("record.txt");
    rename("record1.txt", "record.txt");

    printf("Press Any Key to Return to main menu...");
    getch();
    menu();

}