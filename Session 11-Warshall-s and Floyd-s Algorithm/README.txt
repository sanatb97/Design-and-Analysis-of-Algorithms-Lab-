Session 12 - Warshall's and Floyd's Algorithms

Dynamic Programming: Implementation of Warshall's and Floyd's algorithms.

Problem Definition: 
Find the transitive closure of a graph using Warshall’s algorithm, and find all-pairs-shortest-paths of a graph.
Input: The input for the Warshall’s algorithm begins with the number n of the order of the adjacency matrix of the undirected graph (n <= 100) followed by the adjacency matrix. An adjacency matrix is represented in n lines having n integers (0s or 1s) separated by a space in each line. The input for the Floyd’s algorithm begins with the number n of the order of the weight matrix of the undirected graph (n <= 100) followed by the weight matrix. A weight matrix is represented in n lines having n integers separated by a space in each line. Weight of an edge is an integer lesser than 1000000 if there is an edge with a finite cost, 1000000 if there is no edge. Number 1000000 is practically infinite for us and you can sure that no other edge and even the shortest distances between any pair of edges is greater than or equal to 1000000.

Output: Print the transitive closure and all-pairs-shortest-distances matrices with an empty line in between. Print the total time taken in milliseconds for each algorithm in the end.

Sample Input:
4
0 0 0 1
1 0 0 0
0 0 0 1
0 1 0 0

4
0 1000000 3 1000000
2 0 1000000 1000000
1000000 7 0 1
6 1000000 1000000 0

Sample Output:
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1

0 10 3 4
2 0 5 6
7 7 0 1
6 16 9 0
0.000000 sec.
0.000000 sec.

Algorithms:



