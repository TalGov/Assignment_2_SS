#include <stdio.h>
#include "my_mat.h"

#define BACKPACKSIZE 5 // The maximum number of items
#define BACKPACKMAXWEIGHT 20


/**
 * fill the lookup table for the knapsack problem
 * @param stored_values the lookup table
 * @param weights the inputted weights accordingly
 * @param values  the values of each item accordingly
 */
void fill_values(int stored_values[BACKPACKSIZE + 1][BACKPACKMAXWEIGHT + 1], int weights[], int values[])
{

	// Filling the lookup table
	for (int i = 0; i <= BACKPACKSIZE; i++)
	{
		for (int w = 0; w <= BACKPACKMAXWEIGHT; w++)
		{
			if (i==0 || w==0) // the base case no items left or no weights left
			{
				stored_values[i][w] = 0; // zero is assigned
			}


			else if (weights[i-1] <= w) // if there is enough space
			{
				// the maximum value is assigned
				stored_values[i][w] = values[i-1] + stored_values[i-1][w-weights[i-1]] > stored_values[i-1][w] ?
									  values[i-1] + stored_values[i-1][w-weights[i-1]] : stored_values[i-1][w];
			}
			else // if there is not enough place
			{
				stored_values[i][w] = stored_values[i - 1][w]; // we continue with one less item
			}
		}
	}
}

/**
 * This function fill the items, weights, and values acoording to the user input
 */
void process_inputs(char items[], int weights[], int values[])
{
    for (int i = 0; i < BACKPACKSIZE; ++i)
	{
        scanf(" %c", &items[i]);
        scanf("%i", &values[i]);
        scanf("%i", &weights[i]);
    }
}


/**
 * going through the values of the precomputed matrix and if the items is taken updating the boolean array
 */
void get_items(int i, int j, int weights[], int selected_bool[], int stored_values[BACKPACKSIZE + 1][BACKPACKMAXWEIGHT + 1])
{
	if (i == 0) // if we went through all the items
	{
		return;
	}

	if (stored_values[i][j] > stored_values[i-1][j]) // if the value WITH the items is greater than the value without
	{
		selected_bool[i-1] = 1; // we have take the item
		get_items(i-1, j - weights[i-1], weights, selected_bool, stored_values); // recursive call with the weight reduced by the taken items
	}
	else // if the value is same without the object
	{
		get_items(i-1, j, weights, selected_bool, stored_values); // recursive call without the object
	}
}

/**
 * given a boolean array build the string for the output
 * @return the built string
 */
char * create_string(char string[11], int selected_bool[], char items[]){

	int string_index = 0;
	for (int i = 0; i < BACKPACKSIZE; ++i)
	{
		if (selected_bool[i]) // if the boolean is 1 at this index
		{
			string[string_index] = items[i]; // add the item
			string[string_index + 1] = ' '; // add a space
			string_index += 2; // increment the index by two to not override
		}
	}
	string[string_index] = '\0'; // ending the string
	return string;
}

/**
 * The main function which solve the knapsack problem using an iterative solution
 *	@return the maximum value of the bag computed
 */
int knapSack(int weights[], int values[], int selected_bool[])
{
	int stored_values[BACKPACKSIZE + 1][BACKPACKMAXWEIGHT + 1];

	// starting the lookup table with -1
	for (int i = 0; i <= BACKPACKSIZE; ++i)
	{
		for (int j = 0; j <= BACKPACKMAXWEIGHT; ++j)
		{
			stored_values[i][j] = -1;
		}
	}

	fill_values(stored_values, weights, values); // fill the matrix with optimal solutions
	get_items(BACKPACKSIZE, BACKPACKMAXWEIGHT, weights, selected_bool, stored_values); //update the boolean

	return stored_values[BACKPACKSIZE][BACKPACKMAXWEIGHT]; // the maximum value
}

/**
 * The main function of the program, take the input of the user and precess the optimal solution for the knapsack problem
 * then print the results
 */
int main()
{
	// array initialisation
	char items[BACKPACKSIZE];
	int weights[BACKPACKSIZE];
	int values[BACKPACKSIZE];
	int selected_bool[BACKPACKSIZE] = {0};

	process_inputs(items, weights, values); // processing the user input

	int maximum_val = knapSack(weights, values, selected_bool); // calculating the optimal weight

	//prints
	printf("Maximum profit: %d", maximum_val); // the maximum value

	char string[BACKPACKSIZE * 2 + 1];
	create_string(string, selected_bool, items);
	printf("\nSelected items: %s", string); // the picked items
}




