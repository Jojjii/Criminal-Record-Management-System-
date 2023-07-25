#include<stdio.h>		//Standard I/O Library
#include<stdlib.h>		//For system functions
#include<windows.h>		//For cursor movements
#include<unistd.h>		//For sleep functions
#include<time.h>		//For time function
#include<string.h>		//For string functions
#include<conio.h>		//For console functions

#include "hydra.h"      //our own personal library for graphics

#define PPL 100			//Population of people in the area for which the program is for. Sets a value for determining the maximum number of records there can be

struct data			//Defining structure. It will hold the ddta from the file till the program has been executed. Makes handling and manipulating the data from the file much easier.
{
	char fname[20];
	char lname[20];
	char gen[2];
	char dob[9];
	int arson;
	int theft;
	int traffic;
	int assault;
	int vandalism;
	int id;
};

int evaluation(int *pts, int *crms, int i, int sum);	//function prototype for evaluation
int validcheck(char txt[]);
void capitalize(char *x);

int main()
{
	system("color 1F");		//Changing background to 'Blue', text to 'Bright White'
	
	char chi=224, d_ob[10],dob[10], user[15], d[2], m[3], y[2], password[7], name[10], fn[20], ln[20], g[5], db[10], c1[5], c2[5], c3[5], c4[5], c5[5], ci[5], lines[70], crime[6][10], search[20];		//Declaration of arrays, variables, file & structure array
	int usr, pos, inc=0, a, b, i=0, j=0,d_int, y_int, opt, ic1, ic2, ic3, ic4, ic5, ici, line_number=0, A=1, B=1, temp=0, ids, occ, num[6], len, create=0, record_num=0, flag=0, *points, *crimes, sum, e, c, check, x;
	points=(int*)malloc(5*sizeof(int));
	crimes=(int*)malloc(5*sizeof(int));
	points=(int[5]){7,6,3,5,2};
	FILE *fp;
	struct data criminal[PPL];
	
	fp = fopen("Records.txt", "rt");		//Reads the entire data from the file and stores it in the struct for easier handling
	while(fgets(lines, 70, fp)!=NULL)
	{
		if(line_number==0)
		{
			sscanf(lines, "%s %s %s %s %s %s %s %s %s %s", fn, ln, g, db, c1, c2, c3, c4, c5, ci);		//Inputs strings from the line
		
			strcpy(criminal[j].fname, fn);		//Copying data to struct that is to be remained in string format
			strcpy(criminal[j].lname, ln);
			strcpy(criminal[j].gen, g);
			strcpy(criminal[j].dob, db);
			
			ic1 = atoi(c1);		//Converting strings to integer which are actually integer
			ic2 = atoi(c2);
			ic3 = atoi(c3);
			ic4 = atoi(c4);
			ic5 = atoi(c5);
			ici = atoi(ci);
				
			criminal[j].arson = ic1;		//Now adding them to struct
			criminal[j].theft = ic2;
			criminal[j].traffic = ic3;
			criminal[j].assault = ic4;
			criminal[j].vandalism = ic5;
			criminal[j].id = ici;
			j++;
			record_num++;
		}
	}
	
		//break;
	//}
	//cur_line++;
	fclose(fp);
	
	
	LogOff:
	system("cls");
	COORD newPosition = { 78, 20 };		//Declares the x & y values of the cursor. NOTE: It can be only be declared ONCE in the main function. To again declare the x & y values, as done further in the program, it is either done in IF or LOOPS
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );		//Moves the cursor to the declared x & y values
	printf("  Sign in >>");			//Sign in screen, followed by username and password input
	getch();
	
	username:						
					
	system("cls");		//Clearing screen
	signin();
	scanf("%d",&usr);
	gridmove(72,24);
	i=0;
	while(1==1)				//Makes * appear instead of characters of password
	{
		password[i]=getch();
		if(password[i]=='\r'){
			break;
		}
		else{
			printf("*");
		}
		i++;
	}
	i=0;
	
	if(usr==/*any acceptable id of your choice here*/)		//All acceptable IDs
	{
		//Do something here
	}
	else
	{
		gridmove(60,27);
		printf("Incorrect Username or Password!");
		gridmove(60,28);
		printf(" Press Enter to try again...");
		inc++;
		if(inc>=3)			//Check for 3 username attempts
		{
			system("cls");
			gridmove(75,20);
			system("color 0F");
			printf("POTENTIAL BREACH!\n\t\t\t\t\t\t\t\t    AUTHORITIES HAVE BEEN CONTACTED.\a");
			exit(1);		//Exits program if 3 unsuccessful attempts have been made
		}
		getch();
		goto username;
	}
	if(password[0]=='h' && password[1]=='y' && password[2]=='d' && password[3]=='r' && password[4]=='a' && password[5]=='8' && password[6]=='8'){
		system("cls");
		loading(user);
		goto homepage;
	}
	else
	{
		gridmove(60,27);
		printf("Incorrect Username or Password!");
		gridmove(60,28);
		printf(" Press Enter to try again...");
		inc++;
		if(inc>=3)			//Check for 3 username attempts
		{
			system("cls");
			gridmove(75,20);
			system("color 0F");
			printf("POTENTIAL BREACH!\n\t\t\t\t\t\t\t\t    AUTHORITIES HAVE BEEN CONTACTED.\a");
			exit(1);		//Exits program if 3 unsuccessful attempts have been made
		}
		getch();
		goto username;
	}
	
	inc=0;
	


	homepage:
	system("cls");
	time_t t;   
    time(&t);	
	gridmove(0,0);	//Inputs time
	printf("\n %s \t\t\t\t\t\t\t\t\t  H.Y.D.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));		//Outputs the name of user using the program, program name & time 
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	
	pos=1;
	selectopt(pos);

	while(1){
	
	chi = getch();	
	if(chi=='\r'){
		 system("color 1F");
		break;
	}
	else{
	
		switch(chi){
			case 72:
				
				(pos==1) ? pos = 5 : 0; 
				pos--;
				break;
			
			case 80:
			
				(pos==4) ? pos = 0 : 0;
				pos++;
				break;
			
		}
		selectopt(pos);
		}
	}

	
	switch(pos)			//Switch case for directing to page as per user's choice
	{	
		system("color 1F");
		
		case 1:
			goto Create;
			break;
		case 2:
			goto View;
			break;
		case 3:
			goto Find;
			break;
		case 4:
			system("cls");
			COORD newPosition = { 78+i, 20 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("Logging Off");
			for(i=1;i<=3;i++)
			{
				usleep(500000);
				printf(".");
			}
			sleep(1);
			goto LogOff;
			break;
	}
	
	View:			//View page DISPLAYS ONLY THE RECORDS IN THE FILE
	system("cls");
	system("color 1F");
	printf("\n %s \t\t\t\t\t\t\t\t\t  H.Y.D.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t    View");
	A=1;
	for(i=0;i<record_num;i++)		//Inputs data from struct to display all records to the user in table form
	{
		if(A==1)
		{
			COORD newPosition = { 15, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("CRIMINAL ID\n");
			A=2;
		}
		COORD newPosition = { 18, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", criminal[i].id);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 39, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("NAME\n");
			A=2;
		}
		COORD newPosition = { 33, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%s %s", criminal[i].fname, criminal[i].lname);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 57, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("GENDER\n");
			A=2;
		}
		COORD newPosition = { 60, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%s", criminal[i].gen);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 73, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("DOB\n");
			A=2;
		}
		COORD newPosition = { 70, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%s", criminal[i].dob);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 85, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("ARSON\n");
			A=2;
		}
		COORD newPosition = { 88, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", criminal[i].arson);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 95, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("THEFT\n");
			A=2;
		}
		COORD newPosition = { 98, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", criminal[i].theft);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 105, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("TRAFFIC\n");
			A=2;
		}
		COORD newPosition = { 108, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", criminal[i].traffic);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 115, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("ASSAULT\n");
			A=2;
		}
		COORD newPosition = { 118, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", criminal[i].assault);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 125, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("VANDALISM\n");
			A=2;
		}
		COORD newPosition = { 129, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", criminal[i].vandalism);
	}
	A=1;
	for(i=0;i<record_num;i++)
	{
		if(A==1)
		{
			COORD newPosition = { 140, 12 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("TOTAL CRIMES\n");
			A=2;
		}
		COORD newPosition = { 145, 14+(i*2) };
		SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
		printf("%d", (criminal[i].arson+criminal[i].theft+criminal[i].traffic+criminal[i].assault+criminal[i].vandalism));
	} 
	
	printf("\n\n\n\t\t1. View Specific Record\n\t\t2. Go Back\n\t\tOption: ");		//View page menu
	scanf("%d", &opt);
	switch(opt)
	{
		case 1:
			Input1:
			printf("\n\t\tEnter Criminal ID: ");		//Asks user a specific record to view and checks which ID has been input from struct data
			scanf("%d", &ids);
			for(i=0;i<record_num;i++)
			{
				if(ids==criminal[i].id)
				{
					temp = i;
					flag = 1;
				}
			}
			if(flag==0)
			{
				printf("\t\tInvalid ID entered! Try again...");
				sleep(2);
				goto Input1;
			}
			break;
		case 2:
			goto homepage;
			break;
		default:
			printf("Invalid option number! Try again...");
			sleep(2);
			goto View;
	}
	

		SV:		//SV stands for Specific View
		usleep(100000);		
		system("cls");
		printf("\n %s \t\t\t\t\t\t\t\t\t  H.Y.D.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));
		printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n\n\t\t\t\t\t\t\t\t\t    Viewing - Record %d", criminal[temp].id);
		for(i=temp;i<temp+1;i++)		//Inputs data from struct to display specific records to the user in table form
		{
			if(A)
			{
				COORD newPosition = { 15, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("CRIMINAL ID\n");
				A=2;
			}
			COORD newPosition = { 18, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", criminal[i].id);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 39, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("NAME\n");
			A=2;
			}
			COORD newPosition = { 35, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%s %s", criminal[i].fname, criminal[i].lname);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 57, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("GENDER\n");
			A=2;
			}
			COORD newPosition = { 60, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%s", criminal[i].gen);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 73, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("DOB\n");
				A=2;
			}
			COORD newPosition = { 70, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%s", criminal[i].dob);
		}	
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 85, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("ARSON\n");
				A=2;
			}
			COORD newPosition = { 88, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", criminal[i].arson);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 95, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("THEFT\n");
				A=2;
			}
			COORD newPosition = { 98, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", criminal[i].theft);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 105, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("TRAFFIC\n");
				A=2;
			}
			COORD newPosition = { 108, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", criminal[i].traffic);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 115, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("ASSAULT\n");
				A=2;
			}
			COORD newPosition = { 118, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", criminal[i].assault);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 125, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("VANDALISM\n");
				A=2;
			}
			COORD newPosition = { 129, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", criminal[i].vandalism);
		}
		for(i=temp;i<temp+1;i++)
		{
			if(A)
			{
				COORD newPosition = { 140, 12 };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("TOTAL CRIMES\n");
				A=2;
			}
			COORD newPosition = { 145, 14 };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("%d", (criminal[i].arson+criminal[i].theft+criminal[i].traffic+criminal[i].assault+criminal[i].vandalism));
		}
	
		strcpy(crime[0], "Arson");		//Name of each of 5 crime categories
		strcpy(crime[1], "Theft");
		strcpy(crime[2], "Traffic");
		strcpy(crime[3], "Assault");
		strcpy(crime[4], "Vandalism");
		num[0] = criminal[temp].arson;		//Number of each crime committed is input from the struct to a number array to plot a bar graph 
		num[1] = criminal[temp].theft;
		num[2] = criminal[temp].traffic;
		num[3] = criminal[temp].assault;
		num[4] = criminal[temp].vandalism;
		
		*(crimes)=criminal[temp].arson;		//Input values for each crime for evaluation
		*(crimes+1)=criminal[temp].theft;
		*(crimes+2)=criminal[temp].traffic;
		*(crimes+3)=criminal[temp].assault;
		*(crimes+4)=criminal[temp].vandalism;
	
		for(i=0;i<5;i++)		//Plotting of graph
		{
			if(B)
			{
				COORD newPosition = { 15, 20+(i*2) };
				SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
				printf("%s", crime[i]);
			}
			COORD newPosition = { 25, 20+(i*2) };
			SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
			printf("| ");
			for(j=1;j<=num[i]*2;j++)
			{	
				usleep(80000);
				printf("%c", 219);
			}
			printf(" %d", num[i]);
		}
	
		printf("\n\n\n\n\n\n\t\t1. Evaluate\n\t\t2. Edit Record\n\t\t3. Delete Record\n\t\t4. Go Back\n\t\t5. Homepage\n\t\tOption Number: ");		//Options for user in the 'Specific View' page
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
				goto Evaluate;
				break;
			case 2:
				goto Edit;
				break;
			case 3:
				goto Delete;
				break;
			case 4:
				goto View;
				break;
			case 5:
				goto homepage;
				break;
			default:
				printf("\n\tInvalid option number!\n\tTry again...");
				usleep(1500000);
				goto SV;
		}
	
	
			Evaluate:		//Evaluates the criminal based on the crimes committed whether its a threat to society
			printf("\n\t\t\t\t\t\t\tEvaluating - Record %d", criminal[temp].id);
			c=0;
			sum=0;
			e=evaluation(points, crimes, c, sum);
			printf("\n\n\t\tCriminal Score: %d",e);
			if(e>33){
				printf("\n\t\tPerson may be a possible threat to society.");
			}
			printf("\n\n\t\tSuggested Punishments:");		//Program suggests punishments based on crimes of the person
			if(*crimes>1){
				printf("\n\t\t\t%.1f years of imprisonment for Arson.",(*crimes-1)*1.5);
			}
			if(*(crimes+1)>2){
				if(*(crimes+1)>7){
					printf("\n\t\t\t3 years of imprisonment for Theft.");
				}
				else if(*(crimes+1)>4){
					printf("\n\t\t\t2 years of imprisonment for Theft.");
				}
				else{
					printf("\n\t\t\t1 years of imprisonment for Theft.");
				}
			}
			if(*(crimes+2)>0){
				printf("\n\t\t\tFine of Rs.%d for Traffic crimes.", (*(crimes+2))*400);
			}
			if(*(crimes+3)>2){
				printf("\n\t\t\t%d months of imprisonment for Assault.", *(crimes+3)+3);
			}
			if(*(crimes+4)>2){
				printf("\n\t\t\tFine of Rs.%d for Vandalism.", (*(crimes+4)*500)+1000);
			}
			if(*crimes<=1&&*(crimes+1)<=2&&*(crimes+2)<=0&&*(crimes+3)<=2&&*(crimes+4)<=2){
				printf("None.");
			}
			printf("\n\n");
			printf("\t\tPress Enter to go back to options");
			getch();
			free(points);		//free memory used by dynamic arrays
			free(crimes);
			goto SV;
			
			
		
	
			Edit:		//Allows the user to edit the information of the criminal
		{	
		FILE *fpr = fopen("D://project//Records1.txt","w");
		for(i=0;i<record_num;i++)
		{
		strcpy(fn, criminal[i].fname);
		strcpy(ln, criminal[i].lname);
		strcpy(g, criminal[i].gen);
		strcpy(db, criminal[i].dob);
		ic1 = criminal[i].arson;
		ic2 = criminal[i].theft;
		ic3 = criminal[i].traffic;
		ic4 = criminal[i].assault;
		ic5 = criminal[i].vandalism;
		ici = criminal[i].id;
		
		fprintf(fpr, "%s ", fn);
		fprintf(fpr, "%s ", ln);
		fprintf(fpr, "%s ", g);
		fprintf(fpr, "%s ", db);
		fprintf(fpr, "%d ", ic1);
		fprintf(fpr, "%d ", ic2);
		fprintf(fpr, "%d ", ic3);
		fprintf(fpr, "%d ", ic4);
		fprintf(fpr, "%d ", ic5);
		fprintf(fpr,"%d\n", ici);
		}
	
	fclose(fpr);
	
	remove("D://project//Records.txt");
	rename("D://project//Records1.txt","D://project//Records.txt");
	
			system("cls");
			printf("\n %s \t\t\t\t\t\t\t\t\t  H.Y.D.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));
			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n\n\t\t\t\t\t\t\t\t\t    Editing - Record %d", criminal[temp].id);
			printf("\n\n\n\t\tEdit:\n\n\n\t\t1. First Name\n\t\t2. Last Name\n\t\t3. Gender\n\n\t\tCrimes\n\t\t4. Arson\n\t\t5. Theft\n\t\t6. Traffic\n\t\t7. Assault\n\t\t8. Vandalism\n\t\t9. Go Back\n\n\t\tOption Number: ");
			scanf("%d", &opt);
			
			fn[20] = 0;
			ln[20] = 0;
			  g[2] = 0;
			db[10] = 0;
			ic1 = 0;
			ic2 = 0;
			ic3 = 0;
			ic4 = 0;
			ic5 = 0;
			
			Input:
			switch(opt)
			{
				case 1:
					printf("\n\n\n\t\tEnter new First Name: ");
					scanf("%s", &fn);
					len = strlen(fn);
					if(len<=20)
					{
						check = validcheck(fn);
						if(check==1)
						{
							capitalize(&fn[0]);
							strcpy(criminal[temp].fname, fn);	
						}
						else
						{
							printf("INVALID CHARACHTERS ! PLEASE ONLY ENTER VALID CHARACHTERS");
							goto LN;
						}
						printf("\n\n\t\tRecord has been successfully updated!");
						sleep(2);
						goto Edit;
					}
					else
					{
						printf("Too many characters! MAX 20");
						sleep(2);
						goto Input;
					}
					break;
				case 2:
					printf("\n\n\n\t\tEnter new Last Name: ");
					scanf("%s", &ln);
					len = strlen(ln);
					if(len<=20)
					{
						check = validcheck(ln);
						if(check==1)
						{
							capitalize(&ln[0]);
							strcpy(criminal[temp].lname, ln);	
						}
						else
						{
							printf("INVALID CHARACHTERS ! PLEASE ONLY ENTER VALID CHARACHTERS");
							goto LN;
						}
						printf("\n\t\tRecord has been successfully updated!");
						sleep(2);
						goto Edit;
					}
					else
					{
						printf("Too many characters! MAX 20");
						sleep(2);
						goto Input;
					}
					break;
				case 3:
					printf("\n\n\n\t\tEnter new Gender: ");
					scanf("%s", &g);
					len = strlen(g);
					if(len==1)
					{
						if((strcmp(g, "M")==0) || (strcmp(g, "m")==0))
						{
							strcpy(criminal[temp].gen, "M");
							printf("\n\t\tRecord has been successfully updated!");
							sleep(2);
							goto Edit;	
						}
						else if((strcmp(g, "F")==0) || (strcmp(g, "f")==0))
						{
							strcpy(criminal[temp].gen, "F");	
							printf("\n\t\tRecord has been successfully updated!");
							sleep(2);
							goto Edit;
						}
						else 
						{
							printf("\n\t\tInvalid character entered! Enter M or F");
							sleep(2);
							goto Input;
						}
						
					}
					break;
				case 4:
					printf("\t\tEnter number of Arson committed: ");
					scanf("%d", &ic1);
					if(ic1<0)
					{
						printf("\t\tInvalid number entered! Try again...");
						sleep(2);
						goto Input;
					}
					criminal[temp].arson = ic1;
					goto Edit;
					break;
				case 5:
					printf("\t\tEnter number of Theft committed: ");
					scanf("%d", &ic2);
					if(ic2<0)
					{
						printf("\t\tInvalid number entered! Try again...");
						sleep(2);
						goto Input;
					}
					criminal[temp].theft = ic2;
					goto Edit;
					break;
				case 6:
					printf("\t\tEnter number of Traffic crimes committed: ");
					scanf("%d", &ic3);
					if(ic3<0)
					{
						printf("\t\tInvalid number entered! Try again...");
						sleep(2);
						goto Input;
					}
					criminal[temp].traffic = ic3;
					goto Edit;
					break;
				case 7:
					printf("\t\tEnter number of Assault committed: ");
					scanf("%d", &ic4);
					if(ic4<0)
					{
						printf("\t\tInvalid number entered! Try again...");
						sleep(2);
						goto Input;
					}
					criminal[temp].assault = ic4;
					goto Edit;
					break;
				case 8:
					printf("\t\tEnter number of Vandalism committed: ");
					scanf("%d", &ic5);
					if(ic5<0)
					{
						printf("\t\tInvalid number entered! Try again...");
						sleep(2);
						goto Input;
					}
					criminal[temp].vandalism = ic5;
					goto Edit;
					break;
				case 9:
					goto SV;
					break;
				default:
					printf("\t\tInvalid Option number entered! Try again...");
					goto Edit;
			}		
		
		
	}
	
		
			Delete:		//Allows the user to delete the record of the criminal upron password confirmation
			system("cls");
			printf("\n %s \t\t\t\t\t\t\t\t\t  H.Y.D.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));
			printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n\n\t\t\t\t\t\t\t\t\t    Deleting - Record %d", criminal[temp].id);
			printf("\n\n\n\n\t\tEnter password for confirmation: ");
			scanf("%s", &password);
			if(password[0]=='h' && password[1]=='y' && password[2]=='d' && password[3]=='r' && password[4]=='a' && password[5]=='8' && password[6]=='8')		//Password for sign in
			{
				printf("\n\n\t\tDeleting");
				for(i=0;i<3;i++)
				{
					usleep(150000);
					printf(".");	
				}
				sleep(1);
				system("cls");
				printf("\n %s \t\t\t\t\t\t\t\t\t  H.D.Y.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));
				printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
				printf("\n\n\t\t\t\t\t\t\t\t\t\t Deleting - Record %d", criminal[temp].id);
				printf("\n\n\n\n\t\tRecord deleted successfully!");
		
					criminal[temp].id = 0;
					strcpy(criminal[temp].fname, "   -   ");
					strcpy(criminal[temp].lname, "   -   ");
					strcpy(criminal[temp].gen, "-");
					strcpy(criminal[temp].dob, "    -    ");
					criminal[temp].arson = 0;
					criminal[temp].theft = 0;
					criminal[temp].traffic = 0;
					criminal[temp].assault = 0;
					criminal[temp].vandalism = 0;
					
					FILE *fpr = fopen("D://project//Records1.txt","w");
		for(i=0;i<record_num;i++)
	{	
		if(criminal[i].id != 0){
		
		strcpy(fn, criminal[i].fname);
		strcpy(ln, criminal[i].lname);
		strcpy(g, criminal[i].gen);
		strcpy(db, criminal[i].dob);
		ic1 = criminal[i].arson;
		ic2 = criminal[i].theft;
		ic3 = criminal[i].traffic;
		ic4 = criminal[i].assault;
		ic5 = criminal[i].vandalism;
		ici = criminal[i].id;
		
		fprintf(fpr, "%s ", fn);
		fprintf(fpr, "%s ", ln);
		fprintf(fpr, "%s ", g);
		fprintf(fpr, "%s ", db);
		fprintf(fpr, "%d ", ic1);
		fprintf(fpr, "%d ", ic2);
		fprintf(fpr, "%d ", ic3);
		fprintf(fpr, "%d ", ic4);
		fprintf(fpr, "%d ", ic5);
		fprintf(fpr,"%d\n", ici);
		}
	}
	fclose(fpr);
	
	remove("D://project//Records.txt");
	rename("D://project//Records1.txt","D://project//Records.txt");
					
					sleep(2);
					goto SV;		
				}
			else
			{
				printf("Incorrect password! Try again...");
				inc++;
				if(inc>=3)		//Check for 3 password attempts
				{
					system("cls");
					COORD newPosition = { 75, 20 };
					SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
					system("color 0F");
					printf("POTENTIAL BREACH!\n\t\t\t\t\t\t\t\t    AUTHORITIES HAVE BEEN CONTACTED.\a");
					exit(1);		//Exits program if 3 unsuccessful attempts have been made
				}
				goto Delete;
			}
	
		
	Create:		//Allows user to create a new record. Option in hompage menu 
	system("cls");
	printf("\n %s \t\t\t\t\t\t\t\t\t  H.Y.D.R.A.\t\t\t\t\t\t\t %s", user, ctime(&t));
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t    Create");
			//Increments the variable 'record_num' on every successful new record being created
	
	fn[20] = 0;
	ln[20] = 0;
	  g[2] = 0;
	db[10] = 0;
	ic1 = 0;
	ic2 = 0;
	ic3 = 0;
	ic4 = 0;
	ic5 = 0;
	
	FN:	
	printf("\n\n\n\n\t\tFirst Name: ");
	scanf("%s", &fn);
	len = strlen(fn);
	if(len<=20)
	{
		check = validcheck(fn);
		if(check==1)
		{
			capitalize(&fn[0]);
			strcpy(criminal[record_num].fname, fn);	
			for(i=0;i<record_num;i++)
			{
				a = strcmp(criminal[i].fname, fn);
				if(a==0)
				{
					printf("There exists a record before wtih the same name! Do you want to continue?\nPress (1) for Yes\nPress (2) for No\nENTER CHOICE: ");
					scanf("%d", &opt);
					switch(opt)
					{
						case 1:
							break;
						case 2:
							goto homepage;
					}

				}
			}
		}
		else
		{
			printf("\nINVALID CHARACHTERS ! PLEASE ENTER VALID LETTERS ONLY\n");
			goto FN;
		}
	}
	else
	{
		printf("Too many characters! MAX 20");
		sleep(2);
		goto FN;
	}
	
	LN:
	printf("\n\t\tLast Name: ");
	fflush(stdin);
	scanf("%s", &ln);
	len = strlen(ln);
	if(len<=20)
	{
		check = validcheck(ln);
		if(check==1)
		{
			capitalize(&ln[0]);
			strcpy(criminal[record_num].lname, ln);	
		}
		else
		{
			printf("Invalid input! ONLY ENTER VALID CHARACTHERS PLEASE");
			goto LN;
		}
	}
	else
	{
		printf("Too many characters! MAX 20");
		sleep(2);
		goto LN;
	}
	
	GEN:
	printf("\n\t\tGender: ");
	fflush(stdin);
	scanf("%s", &g);
	len = strlen(g);
	if(len==1)
	{
		if((strcmp(g, "M")==0) || (strcmp(g, "m")==0))
		{
			strcpy(criminal[record_num].gen, "M");
		}
		else if((strcmp(g, "F")==0) || (strcmp(g, "f")==0))
		{
			strcpy(criminal[record_num].gen, "F");	
		}
		else 
		{
			printf("\n\t\tInvalid character entered! Enter M or F");
			sleep(2);
			goto GEN;
		}
	}
	else
	{
		printf("\n\t\tToo many characters! Enter M or F");
		sleep(2);
		goto GEN;
	}
	
	DOB:

	printf("DOB: \n");
	printf("\n\t\tEnter day(e.g 09): ");
	scanf("%s", &d);
	d_int = atoi(d);
	if(d_int<1 || d_int>31)
	{
		printf("\nInvalid day entered! Try again...");
		sleep(2);
		goto DOB;
	}
	
	printf("\n\t\tEnter month(e.g Feb or feb): ");
	scanf("%s", &m);
	capitalize(&m[0]);
	if(d_int==31)
	{
		if(m=="Feb" || m=="Apr" || m=="Jun" || m=="Sep" || m=="Nov")
		{
			printf("\nInvalid month in correspondence to day! Try again...");
			sleep(2);
			goto DOB;
		}
	}
	if(m=="Feb" && d_int>29)
	{
		printf("\nInvalid month in correspondence to day! Try again...");
		sleep(2);
		goto DOB;
	}
	
	printf("\n\t\tYear(e.g 98): ");
	scanf("%s", &y);
	y_int = strlen(y);
	if(y_int>2)
	{
		printf("\nInvalid Year! Try again...");
		sleep(2);
		goto DOB;
	}
	strcat(d,"-");
	strcat(m,"-");
	strcat(dob, d);
	strcat(dob, m);
	strcat(dob, y);
	strcpy(criminal[record_num].dob,dob);


	printf("\n\n\t\tEnter number of crimes committed for each category: ");
	
	C1:
	printf("\n\t\tArson: ");
	scanf("%d", &ic1);
	
	if(ic1<0)
	{
		printf("\t\tInvalid number entered! Try again...");
		sleep(2);
		goto C1;
	}
	criminal[record_num].arson = ic1;
		
	C2:
	printf("\n\t\tTheft: ");
	scanf("%d", &ic2);
	if(ic2<0)
	{
		printf("\t\tInvalid number entered! Try again...");
		sleep(2);
		goto C2;
	}
	criminal[record_num].theft = ic2;

	C3:
	printf("\n\t\tTraffic: ");
	scanf("%d", &ic3);
	if(ic3<0)
	{
		printf("\t\tInvalid number entered! Try again...");
		sleep(2);
		goto C3;
	}
	criminal[record_num].traffic = ic3;

	C4:
	printf("\n\t\tAssault: ");
	scanf("%d", &ic4);
	if(ic4<0)
	{
		printf("\t\tInvalid number entered! Try again...");
		sleep(2);
		goto C4;
	}
	criminal[record_num].assault = ic4;
	
	C5:
	printf("\n\t\tVandilism: ");
	scanf("%d", &ic5);
	if(ic5<0)
	{
		printf("\t\tInvalid number entered! Try again...");
		sleep(2);
		goto C5;
	}
	criminal[record_num].vandalism = ic5;
	
	criminal[record_num].id = 42001 + (record_num);
	
	create = create + 1;		//Increments the variable 'create' on every successful new record being created   
	printf("\n\n\t\tA new record created successfully!");
	record_num++;
	FILE *fpr = fopen("D://project//Records1.txt","w");
	for(i=0;i<record_num;i++)
	{
		strcpy(fn, criminal[i].fname);
		strcpy(ln, criminal[i].lname);
		strcpy(g, criminal[i].gen);
		strcpy(db, criminal[i].dob);
		ic1 = criminal[i].arson;
		ic2 = criminal[i].theft;
		ic3 = criminal[i].traffic;
		ic4 = criminal[i].assault;
		ic5 = criminal[i].vandalism;
		ici = criminal[i].id;
		
		fprintf(fpr, "%s ", fn);
		fprintf(fpr, "%s ", ln);
		fprintf(fpr, "%s ", g);
		fprintf(fpr, "%s ", db);
		fprintf(fpr, "%d ", ic1);
		fprintf(fpr, "%d ", ic2);
		fprintf(fpr, "%d ", ic3);
		fprintf(fpr, "%d ", ic4);
		fprintf(fpr, "%d ", ic5);
		fprintf(fpr,"%d\n", ici);
	}
	
	fclose(fpr);
	
	remove("D://project//Records.txt");
	rename("D://project//Records1.txt","D://project//Records.txt");
	
	Input2:
	printf("\n\n\t\t1. Create new record\n\t\t2. Homepage\n\t\tOption: ");
	scanf("%d", &opt);
	
	switch(opt)
	{
		case 1:
			goto Create;
			break;
		case 2:
			goto homepage;
			break;
		defaultf:
			printf("\t\tInvalid option number! Try again...");
			sleep(2);
			goto Input2;
	}
	

	Find:
	system("cls");
		nicerbox(25,1,50,2);
		gridmove(26,2);
		printf("ENTER LETTERS: ");
		strcpy(search,"");
		chi=getch();
		search[0]=chi;
		i=1;
		printf("%c",chi);
		while(chi!='\r'){
			x=5;
			gridmove(10, x);
			printf("CRIMINAL ID");
			gridmove(25, x);
			printf("NAME");
			gridmove(40, x);
			printf("GENDER");
			gridmove(50, x);
			printf("DOB");
			gridmove(65, x);
			printf("ARSON");
			gridmove(75, x);
			printf("THEFT");
			gridmove(85, x);
			printf("TRAFFIC");
			gridmove(95, x);
			printf("ASSAULT");
			gridmove(105, x);
			printf("VANDALISM");
			for(j=0;j<record_num;j++)
			{
				
				if((i>1 && strstr(criminal[j].fname,search)!=NULL) || (i==1 && strchr(criminal[j].fname,search[0])!=NULL))
				{	
					gridmove(10,x+2);
					printf("%d",criminal[j].id);
					
					gridmove(20,x+2);
					printf("%s",criminal[j].fname);
					gridmove(30,x+2);
					printf("%s",criminal[j].lname);
					
					gridmove(40,x+2);
					printf("%s",criminal[j].gen);
					
					gridmove(50,x+2);
					printf("%s",criminal[j].dob);
					
					gridmove(65,x+2);
					printf("%d",criminal[j].arson);
					
					gridmove(75,x+2);
					printf("%d",criminal[j].theft);
					
					gridmove(85,x+2);
					printf("%d",criminal[j].traffic);
					
					gridmove(95,x+2);
					printf("%d",criminal[j].assault);
					
					gridmove(105,x+2);
					printf("%d",criminal[j].vandalism);
					x+=2;
					gridmove(26+15+i,2);
				}
			}
		
		chi=0;
		chi = getch();
		search[i]=chi;	
		system("cls");
		if(i==1){
			search[i+1]=0;
		}
		nicerbox(25,1,50,2);
		gridmove(26,2);
		printf("ENTER LETTERS: %s",search);
		i++;
	}
	Input3:
	system("cls");
	printf("\n\n\n\t\t1. Search again\n\t\t2. Homepage\n\t\tOption: ");
	scanf("%d", &opt);
	switch(opt)
	{
		case 1:
			goto Find;
			break;
		case 2:
			goto homepage;
			break;
		default:
			printf("Invalid option number! Try again...");
			sleep(2);
			goto Input3;
	}
	
}

int evaluation(int *pts,int *crms, int i, int sum)
{
	if(i>=5){
		return sum;		//base case
	}
	else{
		sum+=(*(pts+i)*(*(crms+i)));
		i++;
		evaluation(pts,crms,i,sum);		//recursion of function until all crimes have been added to the score
	}
}

void capitalize(char *x)
{
	if(*x>=97 && *x<=122){
		*x = *x-97 + 65;
	}
}

int validcheck(char txt[])
{
	int i;
	for(i=0;i<strlen(txt);i++){
		if(txt[i]<65 || (txt[i]>90 && txt[i]<97) || txt[i]>122){
			return 0;
		}
	}
	return 1;	
}
