#define SIZE 10 //The number of vertices of the graph

/**
 *The function receives the matrix values (the weights) from the user
 * @param matrix
 */
void inputMatrix(int matrix[][SIZE]);

/**
 * The function receives two vertices from the user and prints True if there are any path
 * between them.Otherwise, the program will print False.
 * @param matrix
 * @param src- one vertex
 * @param dest- second vertex
 */
void isValidPath(int matrix[][SIZE],int src,int dest);

/**
 * The function receives two vertices from the user and prints the shortest path
 *most among them (by weight). If the path does not exist, the program will print -1
 * @param matrix
 * @param src- one vertex
 * @param dest- second vertex
 */
void pathWeight(int matrix[][SIZE],int src,int dest);

//Helper functions//

/**
The function returns the lowest weighted value between two vertices.
Functions A,B use the shortestPath function
 */
int shortestPath(int matrix[][SIZE],int src,int dest);

/**
The shortest path function uses the minDistance function.
Return the index of the vertex with the minimum distance value
from the source vertex that has not yet been included in the
shortest path
 */
int minDistance(int distances[], int sptSet[]);