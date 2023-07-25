#include<stdio.h>
#include<windows.h>
#include<wincon.h>
#include<stdlib.h>
#include<unistd.h>

void gridmove(int x, int y) {  
static HANDLE han = NULL;  
if(!han){
han = GetStdHandle(STD_OUTPUT_HANDLE);  
}
COORD newpos = { x, y };  
SetConsoleCursorPosition(han,newpos);  
} 

void box(int x,int y,int l,int h){
	int n;
	
gridmove(x,y); 
printf("%c",218); 
gridmove(x+l,y); 
printf("%c",191); 
gridmove(x,y+h); 
printf("%c",192); 
gridmove(x+l,y+h); 
printf("%c",217); 
for(n=1;n<l;n++) 
{ 
gridmove(x+n,y); 
printf("%c",196); 
gridmove(x+n,y+h); 
printf("%c",196); 
} 
for(n=1;n<h;n++) 
{ 
gridmove(x,y+n); 
printf("%c",179); 
gridmove(x+l,y+n); 
printf("%c",179); 
}
}

void nicerbox(int x,int y,int l,int h){
	int n;
	
gridmove(x,y); 
printf("%c",178); 
gridmove(x+l,y); 
printf("%c",178); 
gridmove(x,y+h); 
printf("%c",178); 
gridmove(x+l,y+h); 
printf("%c",178); 
for(n=1;n<l;n++) 
{ 
gridmove(x+n,y); 
printf("%c",178); 
gridmove(x+n,y+h); 
printf("%c",178); 
} 
for(n=1;n<h;n++) 
{ 
gridmove(x,y+n); 
printf("%c",178); 
gridmove(x+l,y+n); 
printf("%c",178); 
}


}


void selectopt(int pos)
{
		system("color 1F");
		
		nicerbox(80,15,20,2);
		gridmove(85,16);
		printf(" MAIN - MENU");
		
		box(82,21,12,2);
    	gridmove(83,22);
		printf("^ CREATE ");
		
		box(82,24,12,2);
		gridmove(83,25);
		printf("^ VIEW  ");
		
		box(82,27,12,2);
		gridmove(83,28);
		printf("^ FIND  ");
		
		box(82,30,12,2);
		gridmove(83,31);
		printf("^ LOG-OFF ");
		
			
        switch(pos)
        {
        case 1:
            	gridmove(83,22);
                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED);
            	printf(" >CREATE");
                break;
                
        case 2:
            	gridmove(83,25);
            	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED);
            	printf(" >VIEW");
				break;
			
        case 3:
            	gridmove(83,28);
            	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED);
            	printf(" >FIND");
	        	break;
	        
        case 4:	
            	gridmove(83,31);
               	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY | BACKGROUND_RED);
            	printf(" >LOG-OFF");  
           		break;
            
        }
        
    
    }


void signin(){
	
	system("cls");
	nicerbox(58,15,35,19);	
	gridmove(72,17);
	printf("SIGN IN");
	
	gridmove(60,20);
	printf("Username: ");
	gridmove(60,24);
	printf("Password: ");
	
	box(71,19,15,2);
	box(71,23,15,2);
	gridmove(72,20);
	printf("k21-");
	
	box(72,30,8,2);
	gridmove(73,31);
	printf("SUBMIT");
	gridmove(76,20);
}

void loading(char x[]){
	
	int n;
	
	nicerbox(71,22,40,7);
	gridmove(83,24);
	printf("WELCOME %s TO",x);
	gridmove(83,25);
	printf("PROJECT");
	gridmove(83,26);
	putchar(175);
	printf("H.Y.D.R.A");
	putchar(174);
	box(71,32,40,2);
	gridmove(85,31);
	printf("LOADING...");
	gridmove(72,33);
	for(n=1;n<39;n++){
		printf("%c",178);
		usleep(50000);
	}
}


