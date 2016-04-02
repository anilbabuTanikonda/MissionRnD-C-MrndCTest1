/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int p(int r, int n)
{
	int result = 1;
	while (n>0)
	{
		result = result*r;
		n--;
	}
	return result;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]

	if (len == 0 || len < 0)
		return NULL;
	int count, a, i, d, n, n1, strt_ind, end_ind, strt_ind1, end_ind1, strt_ind2, end_ind2, r, result[6];

	for (i = 0; i<len; i++)
	{
		a= arr[i];
		d = arr[i + 1] - arr[i];
		count = 2;
		n1 = i + 2;
		n = 3;
		while ((a + ((n - 1)*d)) == arr[n1])
		{
			count++;
			n++;
			n1++;
		}
		if (count >= 3)
		{
			strt_ind = i;
			end_ind = n1 - 1;
			break;
		}
	}
	result[0] = strt_ind;
	result[1] = end_ind;
	i = 0;
	for (i = end_ind; i<len; i++)
	{
		a = arr[i];
		d = arr[i + 1] - arr[i];
		count = 2;
		n1 = i + 2;
		n = 3;
		while ((a + ((n - 1)*d)) == arr[n1])
		{
			count++;
			n++;
			n1++;
		}
		if (count >= 3)
		{
			strt_ind1 = i;
			end_ind1 = n1 - 1;
			break;
		}
	}
	result[2] = strt_ind1;
	result[3] = end_ind1;
	for (i = 0; i<len; i++)
	{
		a = arr[i];
		r = arr[i + 1] / arr[i];
		n1 = i + 2;
		n = 3;
		count = 2;
		while ((a*p(r, n - 1)) == arr[n1])
		{
			count++;
			n++;
			n1++;
		}
		if (count >= 3)
		{
			strt_ind2 = i;
			end_ind2 = n1 - 1;
			break;
		}
	}
	result[4] = strt_ind2;
	result[5] = end_ind2;
	return result;
}