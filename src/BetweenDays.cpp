/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL || date2head==NULL)
	return -1;
	int l1=0;
	int date=0, date1=0, mnth=0, mnth1=0, year=0, year1=0,i;
	struct node *ptr, tmp;
	ptr = date1head;
	while (ptr != NULL)
	{
		
		ptr = ptr->next;
		l1++;
	}
	if (l1 != 8)
		return -1;
	ptr = date2head;
	l1= 0;
	while (ptr != NULL)
	{

		ptr = ptr->next;
		l1++;
	}
	if (l1 != 8)
		return -1;
	ptr = date1head;
	for (i = 0; i < 2; i++)
	{
		date = date*10+ptr->data;
		ptr = ptr->next;
	}
	for (i = 0; i < 2; i++)
	{
		mnth = mnth * 10 + ptr->data;
		ptr = ptr->next;
	}
	for (i = 0; i < 4; i++)
	{
			year = year * 10 + ptr->data;
		ptr = ptr->next;
	}
	
	ptr = date2head;
	for (i = 0; i < 2; i++)
	{
		date1 = date1 * 10 + ptr->data;
		ptr = ptr->next;
	}
	for (i = 0; i < 2; i++)
	{
		mnth1 = mnth1 * 10 + ptr->data;
		ptr = ptr->next;
	}
	for (i = 0; i < 4; i++)
	{
		year1= year1 * 10 + ptr->data;
		ptr = ptr->next;
	}
	int leap,n1,n2;
	if (date>2)
		leap=year / 4 - year / 100 + year / 400;
	else
		leap=(year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
	n1 = year * 365 + mnth +date  + leap;
	if (date1>2)
		leap = year1 / 4 - year1 / 100 + year1 / 400;
	else
		leap = (year1 - 1) / 4 - (year1 - 1) / 100 + (year1- 1) / 400;
	n2= year1* 365 + mnth1 + date1 + leap;
	int result = abs(n1 - n2);
	return result;

	
}