/*
	CSCI 270 Spring 2019
	Programming Assignment
	Name    : Jerson Gutierrez
	USC ID  : 2833544170
	Username: jersongu
	Email   : jersongu@usc.edu
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//	Feel free to include any other C++ standard library if necessary.

using namespace std;
//	You can add any custom classes / helper functions here.

/*
	This function receives two parameters n, m, as described in problem description, and
	it should return the minimum number of times Sora has to try in the worst case,
	without risking failing too many times.
*/

// function to calculate the maximum of an array
int maximum_solver(int row, int end, int** sora_array){
	int maximum = 0;
	for(int i = 0; i < end; i++ ){
		if(sora_array[row][i] > maximum) maximum = sora_array[row][i];
	}

	return maximum;
}

// function to calculate the minimum of an int array 
int minimum_solver(int max, int* array){
	int minimum = 100000000;
	for(int i = 0; i < max; i++ ){
		if(array[i] < minimum) minimum = array[i];
	}
	return minimum;
}

// helper funcion for the solve function and to fill in the 2-d array
int solve_helper(int n , int m, int** sora_array){
	int* num_holder = new int[n];
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(m == 1) return n;
	for(int i = 1; i <= n; i++){
		num_holder[i -1] = max(1 + sora_array[m -1][n - i-1], 1 + sora_array[m-2][i-2]);
	}
	int minimum = minimum_solver(n, num_holder);
	delete num_holder;
	return minimum;
}

/*
	This function receives two parameters n, m, as described in problem description, and
	it should return the minimum number of times Sora has to try in the worst case,
	without risking failing too many times.
*/

int solve(int n, int m) {
	int ** sora_array = new int*[m];
	for(int i = 0; i < m; i++){
		sora_array[i] = new int[n];
	}

	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j++){
			sora_array[i][j] = solve_helper(j+1, i+1, sora_array);
		}
	}

	int maximum = maximum_solver(m-1,n, sora_array);
	for(int i = 0; i < m; i++){
		delete [] sora_array[i];
	}

	delete sora_array;

	return maximum;
}

//	The main function reads the input and outputs your answer.
//	DO NOT EDIT
int main() {
	int n, m;
	cin >> n >> m;
	cout << solve(n, m) << endl;
	return 0;
}