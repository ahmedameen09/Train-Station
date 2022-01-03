#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "unistd.h"
#include "time.h"
#include "string.h"


int choose , i = 0 ;
char pass[100] , back;


void mainscreen();
void trainR();
void clientR();



struct train {
	
	char train_no[100] ;
	char from[100] ;
	char to[100] ;
	char time[100] ;
	char cost[100] ;
}t1;

struct client {
	
	char name[100];
	char Address [100];
	char credit [100];
	char id[100] ;
}p1,p2;

int main ()
{
	ag : // passwd Function
	system("cls");
	printf("\n\t\t\t - Railway Reversation System -\n");
	printf("\n\n\n\n\t\tEnter Your Password : ");
	gets (pass);
	if ( pass[0] == '1' && pass[1] == '2' && pass[2] == '3' && pass[3] == '4' && pass[4] == '5' )
	{
		printf("\n\n\t\tAccess Granted Welcome\n");
		sleep(2);
	}		
	else {
		printf("\n\t\tPassword Wrong try again\n");
		sleep(2);
		i++;
		if ( i < 3 )
		{
			goto ag;
		}
		else {
			printf("\n\n\t\tYou Entered Password Wrong 3 times\n");
			printf("\n\t\tProgram Exit\n\n");
			exit(1);
		}
	}
	
	home : // main menu
	system ("cls");
	mainscreen();
	scanf("%d",&choose);
	switch (choose)
	{
		case 1 : 
					trainR();
					printf("\n\t\tDo you want to back menu , Y or N : ") ; // continue function 
					scanf("%s",&back) ;
					if ( back == 'Y' || back == 'y' )
					{
						goto home ;
					}
					else {
						printf("\n\t\tProgram Finished\n");
						exit(1);
					}	 
				
				break ;
				
		case 2 : 
				clientR();
					printf("\n\t\tDo you want to back menu , Y or N : ") ; // continue function 
					scanf("%s",&back) ;
					if ( back == 'Y' || back == 'y' )
					{
						goto home ;
					}
					else {
						printf("\n\t\tProgram Finished\n");
						exit(1);
					}	 
		
				break ;
				
		case 3 :
				printf("\n\t\tProgram Finished\n");
				exit(1);
				break ;
				
		default : 
				printf("\n\t\tYou entered wrong choice\n");
				sleep(2);
				goto home ;
				break ;
		
	}
}

void mainscreen()
{
	system("cls");
	printf("\n\n");
	printf("\t\t   - Railway Reversation System -     \n") ;
	printf("\n\t\t#####################################") ;
	printf("\n\t\t#                                   #") ;
	printf("\n\t\t#     (1) Add New Train Line        #") ;
	printf("\n\t\t#     (2) Add New Customer          #") ;
	printf("\n\t\t#     (3) EXIT                      #") ;
	printf("\n\t\t#                                   #") ;
	printf("\n\t\t#####################################") ;
	printf("\n\n\t\tChoose : ");
}


void trainR()
{
	FILE *fptr , *fptr2 ;
	system("cls");
	printf("\n\n");
	printf("\t\t      - Add New Train Line -       \n") ;
	printf("\n\t\t#####################################\n") ;
	printf("\n\t\t Train Number : ");
	scanf("%s",&t1.train_no);
	printf("\n\t\t Line Start : ");
	scanf("%s",&t1.from);
	printf("\n\t\t Line End : ");
	scanf("%s",&t1.to);
	printf("\n\t\t Time : ");
	scanf("%s",&t1.time);
	printf("\n\t\t Price : ");
	scanf("%s",&t1.cost);
	printf("\n\n\t\t_____________________________________\n") ;
	fptr = fopen("Trains.txt","a"); // a is Append for editing at the EOF
	fprintf (fptr, "%s\n" , t1.train_no );
	fptr2 = fopen (t1.train_no,"w");
	fprintf (fptr2, "%s " , t1.train_no );
	fprintf (fptr2, "%s " , t1.from );
	fprintf (fptr2, "%s " , t1.to );
	fprintf (fptr2, "%s " , t1.time );
	fprintf (fptr2, "%s\n" , t1.cost );
	printf("\n\t\tTrain Line Added to Database Successfully\n\n");
	fclose(fptr);
	fclose(fptr2);
}

void clientR()
{
	FILE *fptr , *fptr2 ;
	ags :
	system("cls");
	printf("\n\n");
	printf("\t\t       - Add New Customer -         \n") ;
	printf("\n\t\t#####################################\n") ;
	printf("\n\t\t Customer Name : ");
	scanf("%s",&p1.name);
	printf("\n\t\t Address : ");
	scanf("%s",&p1.Address);
	printf("\n\t\t Credit : ");
	scanf("%s",&p1.credit);
	printf("\n\t\t ID : ");
	scanf("%s",&p1.id);
	fptr = fopen ("clients.txt" , "a" );
	fprintf (fptr, "%s " , p1.id );
	fprintf (fptr, "%s " , p1.name );
	fprintf (fptr, "%s " , p1.Address );
	fprintf (fptr, "%s\n" , p1.credit );
	printf("\n\n\t\t_____________________________________\n") ;
	printf("\n\t\tCustomer Data Stored Successfully\n\n");
	fclose(fptr);
}