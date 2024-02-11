#include <stdio.h>
#include "my_mat.h"

#define BACKPACKSIZE 5
#define BACKPACKMAXWEIGHT 20

void fill_values(int i, int j, int stored_values[BACKPACKSIZE][BACKPACKMAXWEIGHT], int weights[], int values[])
{
	printf("\nThis call has those args:\ni: %i\nj: %i", i, j);
	if (i == 0 || j <= 0) // base case we return 0 {we are not looking at any item or the backpack size is 0
	{
		stored_values[i][j] = 0;
		return;
	}

	if (stored_values[i-1][j] == -1) // the case (i-1, j) has not been calculated
	{
		fill_values(i-1, j, stored_values, weights, values);
	}

	if (weights[i] > j) // if the item cannot fit in the bag
	{
		stored_values[i][j] = stored_values[i-1][j];
	}
	else{ // if the item CAN fit in the bag
		if (stored_values[i-1][j-weights[i]] == -1){	// the case (i-1, j-weights[i]) has not been calculated yet
			fill_values(i-1, j-weights[i], stored_values, weights, values);
		}

		// we store the maximum value
		if (stored_values[i-1][j] > stored_values[i-1][j-weights[i]] + values[i])
		{
			stored_values[i][j] = stored_values[i-1][j];
		}
		else {
			stored_values[i][j] = stored_values[i-1][j-weights[i]] + values[i];
		}
	}
}

void process_inputs(char items[], int weights[], int values[])
{
    for (int i = 0; i < BACKPACKSIZE; ++i) {
        scanf(" %c", &items[i]);
        scanf("%i", &values[i]);
        scanf("%i", &weights[i]);
    }
}


/**
 * going through the values of the precomputed matrix and if the items is taken updating the boolean array
 */
void get_items(int i, int j, int weights[], int selected_bool[], int stored_values[BACKPACKSIZE][BACKPACKMAXWEIGHT])
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
	int stored_values[BACKPACKSIZE][BACKPACKMAXWEIGHT];

	for j from 0 to W do:
	fill_values(BACKPACKSIZE - 1, BACKPACKMAXWEIGHT - 1, stored_values, weights, values); // fill the matrix with optimal solutions

	for i from 1 to n do:
			m[i, 0] := 0

	for i from 1 to n do:
	for j from 1 to W do:
	if w[i] > j then:
	m[i, j] := m[i-1, j]
	else:
	m[i, j] := max(m[i-1, j], m[i-1, j-w[i]] + v[i])

	get_items(BACKPACKSIZE-1, BACKPACKMAXWEIGHT-1, weights, selected_bool, stored_values); //update the boolean

	printf("\n");
	for (int i = 0; i <BACKPACKSIZE; ++i) {
		for (int j = 0; j < BACKPACKMAXWEIGHT; ++j) {
			printf("%i ", stored_values[i][j]);
		}
		printf("\n");
	}

	return stored_values[BACKPACKSIZE-1][BACKPACKMAXWEIGHT-1]; // the maximum value
}


int main()
{
	char items[BACKPACKSIZE];
	int weights[BACKPACKSIZE];
	int values[BACKPACKSIZE];
	int selected_bool[BACKPACKSIZE] = {0};


	process_inputs(items, weights, values); // processing the user input

	printf("items\n");
	for (int i = 0; i < 5; ++i) {
		printf("%c",items[i]);


	}
	printf("\nvalues");
	printf("\n");
	for (int i = 0; i < 5; ++i) {
		printf("%i ",values[i]);
	}
	printf("\nWeights");
	printf("\n");
	for (int i = 0; i <5; ++i) {
		printf("%i ",weights[i]);
	}

	int maximum_val = knapSack(weights, values, selected_bool); // calculating the optimal weight

	//prints
	printf("\nMaximum profit: %d", maximum_val); // the maximum value

	char string[11];
	create_string(string, selected_bool, items, weights);
	printf("\nSelected items: %s", string);


}




