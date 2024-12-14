#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char movieName[21];
	float duration;
	char category[3];
	int ticketCost;
}Movie;

Movie getMovieDetails()
{
	Movie m;
	printf("Enter the Movie Name:");
	scanf_s("%20s", m.movieName, (unsigned)sizeof(m.movieName));
	printf("Enter the Duration of Movie:");
	scanf_s("%f", &m.duration);
	printf("Enter the category like 2 for 2D and 3 for 3D:");
	scanf_s("%2s", m.category, (unsigned)sizeof(m.category));
	m.ticketCost = 0;
	return m;
}


char* getCircleDetails() 
{
	static char circle[10]; 
	printf("Enter the Circle like gold or silver for Gold and Silver respectively: "); 
	scanf_s("%9s", circle, (unsigned)sizeof(circle)); 
	return circle;
}

int calculateTicketCost(Movie* m, char circle[])
{

	if (strcmp(m->category,"2D") != 0 && strcmp(m->category, "3D"))
	{
		return -1;
	}
	else if (strcmp(circle,"gold") != 0 && strcmp(circle, "silver") != 0)
	{
		return -2;
	}
	else if (strcmp(m->category, "2D") != 0 && strcmp(m->category, "3D") && strcmp(circle, "gold") != 0 && strcmp(circle, "silver") != 0)
	{
		return -3;
	}
	else if (strcmp(circle, "gold") == 0)
	{
		m->ticketCost = (strcmp(m->category, "2D")==0) ? 300 : 500;
		return 0;
	}
	else if (strcmp(circle, "silver") == 0)
	{
		m->ticketCost = (strcmp(m->category, "2D") == 0) ? 250 : 450;
		return 0;
	}
	
}

int main()
{
	Movie m = getMovieDetails();
	char *circle = getCircleDetails();
	int tp = calculateTicketCost(&m, circle);

	if (tp == -1)
	{
		printf("Invalid movie category\n");
	}
	else if (tp == -2) {
		printf("Invalid circle type\n");
	}
	else if (tp == -3)
	{
		printf(" Both category and circle are Invalid type\n");
	}
	else if (tp == 0)
	{
		int num;
		printf("How many tickets you want to buy:");
		scanf_s("%d", &num);
		printf("Ticket price for %d is %d Rs\n", num, num * m.ticketCost);

	}

}
