#include<stdio.h>
#include<conio.h>
#include<process.h>

void add();
void view();
void edit();
void delete();

void main()
{
	int choice;
	char c;
	printf("\t\t\t\t\t\t::::::::::::::::::::::::::::::::::");
	printf("\n\t\t\t\t\t\t::\t\t\t\t::");
	printf("\n\t\t\t\t\t\t::\t@@@@@@@@@@@@@@@@@\t::");
	printf("\n\t\t\t\t\t\t::\t@\t\t@\t::");
	printf("\n\t\t\t\t\t\t::\t@  WELCOME TO \t@\t::");
	printf("\n\t\t\t\t\t\t::\t@  STUDENT\t@\t::");
	printf("\n\t\t\t\t\t\t::\t@  MANAGEMENT\t@\t::");
	printf("\n\t\t\t\t\t\t::\t@  SYSTEM\t@\t::");
	printf("\n\t\t\t\t\t\t::\t@\t\t@\t::");
	printf("\n\t\t\t\t\t\t::\t@@@@@@@@@@@@@@@@@\t::");
	printf("\n\t\t\t\t\t\t::\t\t\t\t::");

	printf("\n\t\t\t\t\t\t::::::::::::::::::::::::::::::::::");
	
	printf("\n\t\t\t\t\t\tpress any key to continue");
	getch();
	
	
	system("cls");
	do
	{
		printf("\t\t\t\t\t\t:::::::::  MENU  ::::::::::");
		printf("\n\t\t\t\t\t\t1. Add Student");
		printf("\n\t\t\t\t\t\t2. View Student");
		printf("\n\t\t\t\t\t\t3. Edit Student");
		printf("\n\t\t\t\t\t\t4. Delete Student");
		printf("\n\t\t\t\t\t\t5. Exit Student");
		printf("\n\t\t\t\t\t\tEnter your choice (1-5)");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				{
					add();
					break;
				}
			case 2:
				{
					view();
					break;
				}
			case 3:
				{
					view();
					break;
				}
			case 4:
				{
					delete();
					break;
				}
			case 5:
				{
					exit(0);
				}
			default:
				{
					printf("Invalid Choice\n please select only between 1-5");
				}
		}
		printf("\n\t\t\t\t\t\tdo you want to continue(y/n)");
		fflush(stdin);
		scanf("%c",&c);
	}while(c!='n');
	
					
	
	getch();
}




void add()
{
	printf("add student");
}
void view()
{
	printf("view student");
}
void edit()
{
	printf("edit student");
}
void delete()
{
	printf("delete student");
}
