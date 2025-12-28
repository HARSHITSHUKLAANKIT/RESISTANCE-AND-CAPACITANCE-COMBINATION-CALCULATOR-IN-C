#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
	#ifdef _WIN32
		system("cls");
	#else 
		system("clear");
	#endif
	char choice;
	printf("Welcome to the circuit simulator in C!!\n");

	printf("What kind of circuit do u want to simulate(Enter 'o' or 'O' for options) - ");
	scanf(" %c",&choice);

	if(choice=='r' || choice == 'R')
	{
		char combination[100];
		printf("Resistor circuit :");
		printf("Series or Parallel?? : ");
		scanf("%s",combination);

		if(strcmp(combination,"series")==0 ||strcmp(combination,"Series")==0 || strcmp(combination,"SERIES")==0)
		{
			int nr;
			int req = 0;
			printf("SCHEMATIC STRUCTURE : R - R - R -.....\n");
			printf("Enter no. of resistors: ");
			scanf("%d",&nr);
			int r[nr];
			printf("Enter value of each resitor in order like 1,2,3 for r1 = 1 ohm, r2 = 2 ohm, r3 = 3ohm : ");
			for(int i=0; i<nr; i++)
			{
				scanf("%d",&r[i]);
			}
			for(int i=0; i<nr; i++)
			{
				req+=r[i];
			}
			printf("\nEquivalent resistance = %d ohms\n",req);
		}

		else if(strcmp(combination,"parallel")==0 ||strcmp(combination,"Parallel")==0 || strcmp(combination,"PARALLEL")==0)
		{
			int nr;
			float req = 0.0;
			printf("SCHEMATIC STRUCTURE : R\n");
			printf("                      |\n");	
			printf("                      R\n");
			printf("                      |\n");
			printf("                      R\n");
			printf("Enter no. of resistors: ");
			scanf("%d",&nr);
			int r[nr];
			printf("Enter value of each resitor in order like 1,2,3 for r1 = 1 ohm, r2 = 2 ohm, r3 = 3ohm : ");
			for(int i=0; i<nr; i++)
			{
				scanf("%d",&r[i]);
			}
			for(int i=0; i<nr; i++)
			{
				req+=1.0/r[i];
			}
			req = 1.0/req;
			printf("\nEquivalent resistance = %.2f ohms\n",req);
		}
		else
		{
			printf("Wrong choice!\n");
		}
	}
	else if(choice=='c'||choice=='C')
	{
		char combination[100];
		printf("Capacitor circuit :");
		printf("Series or Parallel?? : ");
		scanf("%s",combination);

		if(strcmp(combination,"series")==0 ||strcmp(combination,"Series")==0 || strcmp(combination,"SERIES")==0)
		{
			int nc;
			float ceq = 0.0;
			printf("SCHEMATIC STRUCTURE : C - C - C -.....\n");
			printf("Enter no. of capacitors: ");
			scanf("%d",&nc);
			float c[nc];
			printf("Enter value of each resitor in order like 1,2,3 for r1 = 1F, r2 = 2 F, r3 = 3F : ");
			for(int i=0; i<nc; i++)
			{
				scanf("%f",&c[i]);
				if(c[i] == 0)
				{
    				printf("Value cannot be zero!\n");
    				return 0;
				}
			}
			
			for(int i=0; i<nc; i++)
			{
				
				ceq+=1.0/c[i];
				
			}
			ceq = 1.0/ceq;
			printf("\nEquivalent capacitance = %.2f F\n",ceq);
		}

		else if(strcmp(combination,"parallel")==0 ||strcmp(combination,"Parallel")==0 || strcmp(combination,"PARALLEL")==0)
		{
			int nc;
			float ceq = 0.0;
			printf("SCHEMATIC STRUCTURE : C\n");
			printf("                      |\n");	
			printf("                      C\n");
			printf("                      |\n");
			printf("                      C\n");
			printf("Enter no. of capacitors: ");
			scanf("%d",&nc);
			float c[nc];
			printf("Enter value of each resitor in order like 1,2,3 for c1 = 1 F, c2 = 2 F, c3 = 3 F : ");
			for(int i=0; i<nc; i++)
			{
				scanf("%f",&c[i]);
			}
			for(int i=0; i<nc; i++)
			{
				ceq+=c[i];
			}
			
			printf("\nEquivalent capacitance = %.2f F\n",ceq);
		}
		else
		{
			printf("Wrong choice!\n");
		}

	}
	else if(choice=='o'||choice=='O')
	{
		printf("R - Resistance\n");
		printf("C - Capacitance\n");
	}
}
