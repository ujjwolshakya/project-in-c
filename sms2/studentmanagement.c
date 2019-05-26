#include<stdio.h>
#include<conio.h>
#include<process.h>

void add();
void view();
void search();
void update();
void delete();
struct student{
	char name[20];
	int roll;
	char address[20];
	char contact[20];
};
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
		printf("\n\t\t\t\t\t\t3. Search Student");
		printf("\n\t\t\t\t\t\t4. Update Student");
		printf("\n\t\t\t\t\t\t5. Delete Student");
		printf("\n\t\t\t\t\t\t6. Exit Student");
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
					search();
					break;
				}
			case 4:
				{
					update();
					break;
				}
			case 5:
				{
					delete();
					break;
				}
			case 6:
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
	struct student s1;
	FILE *fp;
	int result;
	fp=fopen("student.dat","a+");
	if(fp==NULL)
	{
		printf("\ncouldn't create file'");
	}
	printf("enter name of student");
	fflush(stdin);
	scanf("%[^\n]",&s1.name);
	
	printf("enter roll number of student");
	scanf("%d",&s1.roll);
	
	printf("enter address of student");
	fflush(stdin);
	scanf("%[^\n]",&s1.address);	
	
	printf("enter contact of student");
	fflush(stdin);
	scanf("%[^\n]",&s1.contact);
	
	
	result=fwrite(&s1,sizeof(s1),1,fp);
	if(result!=0)
	{
		printf("one record added successfully");
	}
	else
	{
		printf("failed to add record");
	}
	fclose(fp);
//	printf("add student");
}
void view()
{
	FILE *fp;
	struct student s1;
	int result,counter=0;
	fp=fopen("student.dat","r");
	if(fp==NULL)
	{
		printf("\ncouldn't create file'");
	}
	while(fread(&s1,sizeof(s1),1,fp)==1)
	{
		counter=1;
		printf("\n name = %s",s1.name);
		printf("\n roll number = %d",s1.roll);
		printf("\n address = %s",s1.address);
		printf("\n contact = %s",s1.contact);
		printf("\n**************************");
	}
	if(counter==0)
	{
		printf("no record found");
	}
	fclose(fp);
	//printf("view student");
}
void search()
{
	FILE *fp;
	struct student s1;
	int result,choice,roll,counter=0;
	char name[20],address[20],contact[20];
	fp=fopen("student.dat","r");
	if(fp==NULL)
	{
		printf("\ncouldn't create file'");
	}
	
	printf("\nsearch by:");
	printf("\n1. By name");
	printf("\n2. By Roll Number");
	printf("\n3. By Address");
	printf("\n4. By Contact");
	printf("\n enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				printf("enter name you want to search");
				fflush(stdin);
				scanf("%[^\n]",&name);
				while(fread(&s1,sizeof(s1),1,fp)==1)
				{
					if(strcmp(s1.name,name)==0)
					{
						counter=1;
						printf("\n name = %s",s1.name);
						printf("\n roll number = %d",s1.roll);
						printf("\n address = %s",s1.address);
						printf("\n contact = %s",s1.contact);
						printf("\n**************************");
						//fread(&s1,sizeof(s1),1,fp);
					}
				
			}
			if(counter==0)
			{
				printf("couldn't find record");
			}
		break;
		}
		case 2:
			{
				counter=0;
				printf("enter roll number you want to search");
				//fflush(stdin);
				scanf("%d",&roll);
				while(fread(&s1,sizeof(s1),1,fp)==1)
				{
				
					if(s1.roll==roll)
					{
						counter=1;
						printf("\n name = %s",s1.name);
						printf("\n roll number = %d",s1.roll);
						printf("\n address = %s",s1.address);
						printf("\n contact = %s",s1.contact);
						printf("\n**************************");
						//fread(&s1,sizeof(s1),1,fp);
					}
					
			}
			if(counter==0)
			{
				printf("couldn't find record");
			}
		break;
		}
		case 3:
			{
				counter=0;
				printf("enter address you want to search");
				fflush(stdin);
				scanf("%[^\n]",&address);
				while(fread(&s1,sizeof(s1),1,fp)==1)
				{
					if(strcmp(s1.address,address)==0)
					{
						counter=1;
						printf("\n name = %s",s1.name);
						printf("\n roll number = %d",s1.roll);
						printf("\n address = %s",s1.address);
						printf("\n contact = %s",s1.contact);
						printf("\n**************************");
						//fread(&s1,sizeof(s1),1,fp);
					}
				
			}
				if(counter==0)
					{		
						printf("\nno record found");
					}
		break;
		}
		case 4:
			{
				counter=0;
				printf("enter contact you want to search");
				fflush(stdin);
				scanf("%[^\n]",&contact);
				while(fread(&s1,sizeof(s1),1,fp)==1)
				{
					if(strcmp(s1.contact,contact)==0)
					{
						counter=1;
						printf("\n name = %s",s1.name);
						printf("\n roll number = %d",s1.roll);
						printf("\n address = %s",s1.address);
						printf("\n contact = %s",s1.contact);
						printf("\n**************************");
						//fread(&s1,sizeof(s1),1,fp);
					}
					
			}
			if(counter==0)
			{		
				printf("\nno record found");
			}
		break;
		}
		default:
			printf("invalid selection \"please enter values between 1-4\"");
	}

}
void update()
{
	FILE *fp;
	struct student s1;
	int result,roll;
	fp=fopen("student.dat","r+");
	if(fp==NULL)
	{
		printf("\ncouldn't create file'");
	}
	printf("\nenter roll number of student you want to update");
	scanf("%d",&roll);
	while(fread(&s1,sizeof(s1),1,fp)==1)
	{
		if(s1.roll==roll)
		{
			printf("\n enter new name");
			fflush(stdin);
			scanf("%[^\n]",s1.name);
			
			printf("\n enter new address");
			fflush(stdin);
			scanf("%[^\n]",s1.address);
			
			printf("\n enter new contact");
			fflush(stdin);
			scanf("%[^\n]",s1.contact);
	
			result=fwrite(&s1,sizeof(s1),1,fp);
			if(result>0)
			{
				printf("record updated successfully");
			}else
			{
				printf("failed to update");
			}
		}
		
	}
	fclose(fp);
//	printf("edit student");
}
void delete()
{
	FILE *fp,*fp1;
	fp=fopen("student.dat","r");
	fp1=fopen("temp.dat","w");
 	struct student s1;
	int roll, s,counter=0;
 	printf("Enter the Roll no you want to delete :");
 	scanf("%d",&roll);
 	while(!feof(fp))
 	{
 		fread(&s1,sizeof(s1),1,fp);
 		//printf("\nroll is %d",s1.roll);
 		if(s1.roll==roll)
 		{
 			//printf("\nroll no found");
 			counter=1;
			 break;
		 }
	}
	if(counter==0)
	{
	//	printf("%d value of counter",counter);
		printf("roll no %d doesn't exist",roll);
	}
	else
	{
		while (fread(&s1, sizeof(s1), 1, fp))
  		{	
   			if (s1.roll!= roll)
    			fwrite(&s1, sizeof(s1), 1, fp1);
  		}
	}
	fclose(fp);
	fclose(fp1);
	fp=fopen("student.dat","w");
	fp1=fopen("temp.dat","r");
	while (fread(&s1, sizeof(s1), 1, fp1))
	{
		fwrite(&s1, sizeof(s1), 1, fp);
	} 
   	printf("\nRECORD DELETED\n");
   	fclose(fp);
   	fclose(fp1);
   	fp1=fopen("temp.dat","w");
   	fclose(fp1);
}
