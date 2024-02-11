#include <stdio.h>
#include "my_mat.h"

#define BACKPACKSIZE 5
#define BACKPACKMAXWEIGHT 20



void fill_values(int stored_values[BACKPACKSIZE + 1][BACKPACKMAXWEIGHT + 1], int weights[], int values[])
{

	// Build table K[][] in bottom up manner
	for (int i = 0; i <= BACKPACKSIZE; i++)
	{
		for (int w = 0; w <= BACKPACKMAXWEIGHT; w++)
		{
			if (i==0 || w==0)
			{
				stored_values[i][w] = 0;
			}

			else if (weights[i-1] <= w)
			{
				stored_values[i][w] = values[i-1] + stored_values[i-1][w-weights[i-1]] > stored_values[i-1][w] ?
									  values[i-1] + stored_values[i-1][w-weights[i-1]] : stored_values[i-1][w];
			}

			else
			{
				stored_values[i][w] = stored_values[i - 1][w];
			}
		}
	}
}

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
	if (i == 0)
	{
		return;
	}

	if (stored_values[i][j] > stored_values[i-1][j])
	{
		selected_bool[i] = 1;
		get_items(i-1, j-weights[i], weights, selected_bool, stored_values);
	}
	else
	{
		get_items(i-1, j, weights, selected_bool, stored_values);
	}

}

char * create_string(char string[11], int selected_bool[], char items[], int weights[]){

	int string_index = 0;
	for (int i = 0; i < BACKPACKSIZE; ++i) {
		if (selected_bool[i])
		{
			string[string_index] = items[i];
			string[string_index + 1] = ' ';
			string_index += 2;
		}
	}
	string[string_index] = '\0'; // ending the string
	return string;
}

int knapSack(int weights[], int values[], int selected_bool[])
{
	int stored_values[BACKPACKSIZE + 1][BACKPACKMAXWEIGHT + 1];

	for (int i = 0; i <= BACKPACKSIZE; ++i) {
		for (int j = 0; j <= BACKPACKMAXWEIGHT; ++j) {
			stored_values[i][j] = -1;
		}
	}

	fill_values(stored_values, weights, values); // fill the matrix with optimal solutions

	get_items(BACKPACKSIZE, BACKPACKMAXWEIGHT, weights, selected_bool, stored_values); //update the boolean

	printf("\n");
	for (int i = 0; i <=BACKPACKSIZE; ++i) {
		for (int j = 0; j <= BACKPACKMAXWEIGHT; ++j) {
			printf("%i ", stored_values[i][j]);
		}
		printf("\n");
	}

	return stored_values[BACKPACKSIZE][BACKPACKMAXWEIGHT]; // the maximum value
}


int main()
{
	char items[BACKPACKSIZE];
	int weights[BACKPACKSIZE];
	int values[BACKPACKSIZE];
	int selected_bool[BACKPACKSIZE] = {0};


	process_inputs(items, weights, values); // processing the user input

	printf("items\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%c",items[i]);
	}
	printf("\nvalues");
	printf("\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%i ",values[i]);
	}
	printf("\nWeights");
	printf("\n");

	for (int i = 0; i <5; ++i)
	{
		printf("%i ",weights[i]);
	}

	int maximum_val = knapSack(weights, values, selected_bool); // calculating the optimal weight

	//prints
	printf("\nMaximum profit: %d", maximum_val); // the maximum value

	char string[11];
	create_string(string, selected_bool, items, weights);
	printf("\nSelected items: %s", string);


}




