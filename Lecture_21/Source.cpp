// Lecture 21 supplementary program
// 1D Arrays continued
// sorting functions courtesy of Dr Anwar

#include<iostream>
#include<string>
#include<fstream>

using namespace std;
// Functions' prototype
double getAverage(double[], int);
void displayElements(double[], int);
void changeElements(double[], int, int);
void fileArrRead(string fileName, double outArr[], int &count);
int getMax(double input[], int size);
int getMin(double input[], int size);

int main() {
	

	// variable declaration
	const int SIZE = 500;
	int data[5] = { 1,2,3,4,5 };
	double marks[SIZE];
	int counter = 0;
	double temp;

	string fileName;
	fileName = "C:\\Users\\100711084\\source\\repos\\Lecture_21\\ENGR1200Marks.txt";
	double engMarks[SIZE];
	int count = 0;
	fileArrRead(fileName, engMarks, count);
	cout << "The max is: " << getMax(engMarks, count) << endl;
	cout << "The max is: " << getMin(engMarks, count) << endl;










/*

	//read 5 inputs from the user 
	do {
		cout << "Insert value " << counter + 1 << ": ";
		cin >> temp;
		//save the current value in the ith position in the array
		marks[counter] = temp;

		//increament the counter
		counter++;
	} while (counter < SIZE);
	//call getAvrage to calc. the average 
	double average = getAverage(marks, SIZE);
	cout << "The average = " << average << endl;

	//display the current elements 
	cout << "The elements are: " << endl;
	displayElements(marks, SIZE);


	//read the value of factor 
	int factor;
	cout << "Insert a factor: ";
	cin >> factor;

	//change the array's elements by calling the following function
	changeElements(marks, SIZE, factor);

	cout << "After applying a factor of " << factor << " The elements are: " << endl;

	//display the current elements after modify the elements
	displayElements(marks, SIZE);

	//recalculate the average based on the new vlues
	cout << "The average after applying factor of " << factor << " = " << getAverage(marks, SIZE) << endl;
	*/
	system("pause");
	return 0;
}


//to get the avergae of array's elements
double getAverage(double input[], int size) {

	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += input[i];

	return sum / size;
}

//disply an array's elements on the screen 
void displayElements(double input[], int size) {

	for (int i = 0; i < size; i++)
		cout << input[i] << " ";

	cout << endl;

}



//change all the elements of an array by adding a factor
void changeElements(double input[], int size, int factor) {

	for (int i = 0; i < size; i++)
		input[i] += factor; // input[i] = input[i]+factor;
}

void fileArrRead(string fileName, double outArr[],int &count) { // filename is inserted as a string, array passed by reference, count passed by reference so we can track the number of elements.
	ifstream myFile;
	myFile.open(fileName);

	
	if (myFile.fail()) {
		cout << "Error opening the file." << endl;
		return;
	}
	count = 0;
	while (!myFile.eof()) {
		
		myFile >> outArr[count];
		count++;
	}
	
	cout << "File is read with " << count << " elements."  << endl;
	myFile.close();
}

int getMax(double input[], int size) { // finds the maximum value in an array by searching if the current number is larger than the the next number.
	double max = input[0];

	for (int i = 1; i < size; i++) {
		if (input[i] > max) {
			max = input[i];
		}
	}
	return max;
}

int getMin(double input[], int size) { // finds the maximum value in an array by searching if the current number is larger than the the next number.
	double min = input[0];

	for (int i = 1; i < size; i++) {
		if (input[i] < min) {
			min = input[i];
		}
	}
	return min;
}