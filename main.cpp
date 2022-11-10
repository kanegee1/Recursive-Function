#include "parameters.h"
#include <fstream>
#include <iostream>
using namespace std;

// fibonacci recursive function
int fibonacci(int F);

// sum of integers function
int sum(int S);

// largest value function
int largest(const int array[], int L);

// passing in 2d array, my x and y denoted as rows (r) colums (c)
int FindEagle(int[][50], int rows, int cols, int r, int c);
// print for my findEagle function,  input is file stream, and 2D array
void printEagle(ifstream &, int[][50], int &x, int &y);

int main() {

  // Fibonacci sequence funciton
  cout << "\n";
  cout << "Fibonacci(" << FibVal << ") = ";
  cout << fibonacci(FibVal) << "\n\n";

  // Sum function
  cout << "\n";
  cout << "Sum(" << SumVal << ") = ";
  cout << sum(SumVal) << "\n\n";

  // Largest function
  cout << "\n";
  cout << "Largest Value of the array { ";
  for (int i = 0; i < 13; i++)     // loop to display contents of the array
    cout << LongestVal[i] << ", "; // displaying array
  cout << "} is: ";
  int L = sizeof(LongestVal) / sizeof(LongestVal[0]); // assigning the L value
  cout << largest(LongestVal, L);
  cout << endl;

  // find eagle function
  // declaring my array and dimensions
  cout << "\n\n\n";
  int array[50][50], x, y;
  // declaring file as ifstream
  ifstream file;
  // opening my file
  file.open("eagle.dat");
  // do contents in while loop while the file is not ended
  while (!file.eof()) {
    int count = 0;
    // reading from the file
    printEagle(file, array, x, y);
    cout << "\n";
    // double for loop to fill 2d array
    for (int i = 0; i < x; i++)
      for (int j = 0; j < y; j++) {
        // assigning k to decide if this intance is greater than 0
        int k = FindEagle(array, x, y, i, j);
        if (k > 0) {
          // increment count if greater
          count++;
          cout << "An eagle size " << k << " is found.\n";
        }
      }
    cout << " \n";
    cout << count << " eagle(s) found in the picture.\n";
    cout << endl << endl;
  }
  // closing file
  file.close();
}
int fibonacci(int F) {
  if (F <= 1) // if FibVal is <= 1, then it is its #
    return F;
  else
    return fibonacci(F - 1) +
           fibonacci(F - 2); // this is the fibonacci sequence
}

int sum(int S) {
  if (S <= 1) // if SumVal <= 1, then ruturn its value
    return S;
  return S + sum(S - 1); // else return its value, plus the value -1
}

int largest(const int array[], int L) {
  if (L == 1) // if 1 then return index 0 of array
    return array[0];
  return max(array[L - 1],
             largest(array, L - 1)); // finding largest value in array
}

// FindEagle function
int FindEagle(int a[][50], int rows, int cols, int r, int c) {
  // base cases
  if (r < 0 || r >= rows || c < 0 || c >= cols)
    return 0;
  if (a[r][c] == 0)
    return 0;
  int size = 1;
  a[r][c] = 0;
  // adding size of eagle
  size += FindEagle(a, rows, cols, r - 1, c);
  size += FindEagle(a, rows, cols, r + 1, c);
  size += FindEagle(a, rows, cols, r, c - 1);
  size += FindEagle(a, rows, cols, r, c + 1);
  // returns the size
  return size;
}

// printEagle function
void printEagle(ifstream &file, int a[][50], int &x, int &y) {
  cout << endl;
  // reading file into x and y
  file >> x >> y;
  // double for loop to insert file into our array
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
      // reading content into array
      file >> a[i][j];
  // double for loop to display contents inside 2D array
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
}
