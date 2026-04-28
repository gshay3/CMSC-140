/*
 * Class: CMSC140 CRN: 40437
 * Instructor: Ara M. Kechiantz
 * Project: Project 4
 * Integrated development environment (IDE)
 * Description: This program calculates the average number of days employees are absent 
 * based off the total number of employees and total days missed.
 * Due Date: 07/24
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Griffin Shay
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global output file stream.
ofstream outputFile;

// Function prototypes.
int getNumOfEmployees();
int getTotalDaysAbsent(int numOfEmployees);
double calculateAvgDaysAbsent(int numOfEmployees, int totalDaysAbsent);

int main()
{
	// Course info and variables.
	const string course = "CMSC140 Common Project 4", dueDate = "07/31/2023";
	string name;
	int numOfEmployees, totalDaysAbsent = 0;
	double averageDaysAbsent;

	// Open output file.
	outputFile.open("employeeAbsences.txt");

	// Display program purpose.
	cout << "Calculate the average number of days a company's employee's are absent.\n\n";

	// Call getNumOfEmployees function and store the result in numOfEmployees.
	numOfEmployees = getNumOfEmployees();

	// Call getTotalDaysAbsent function and store the result in totalDaysAbsent.
	totalDaysAbsent = getTotalDaysAbsent(numOfEmployees);
	
	// Call calculateAvgDaysAbsent function and store the result in averageDaysAbsent.
	averageDaysAbsent = calculateAvgDaysAbsent(numOfEmployees, totalDaysAbsent);

	// Write value of averageDaysAbsent to file.
	outputFile << averageDaysAbsent;

	// Close file.
	outputFile.close();

	// Prompt the user for programmer name.
	cout << "\n\nProgrammer: ";
	cin.ignore();
	getline(cin, name);

	// Display course information.
	cout << course << "\n";
	cout << dueDate << "\n";


	return 0;
}

// This function prompts the user to enter the number of employees and validates the input.
int getNumOfEmployees()
{
	int num = 0;

	cout << "Please enter the number of employees in the company: ";
	cin >> num;
	while (num < 1)
	{
		cout << "There must be at least 1 employee.\n"
			<< "Please re-enter the number of employees in the company: ";
		cin >> num;
	}
	return num;
}

// This function collects employeeIDs and number of days absent for each employee.
// It validates the input and calculates the total days absent.
int getTotalDaysAbsent(int numOfEmployees)
{
	int totalDaysAbsent = 0;
	int employeeID, daysMissed;

	for (int i = 1; i <= numOfEmployees; i++)
	{
		cout << "Please enter an employee ID: ";
		cin >> employeeID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> daysMissed;
		while (daysMissed < 0)
		{
			cout << "The number of days must not be negative.\n"
				<< "Please re-enter the number of days absent: ";
			cin >> daysMissed;
		}
		outputFile << employeeID << "\n";
		outputFile << daysMissed << "\n";
		totalDaysAbsent += daysMissed;
	}
	return totalDaysAbsent;
}

// This function calculates and returns the average number of days absent.
double calculateAvgDaysAbsent(int numOfEmployees, int totalDaysAbsent)
{
	double average = static_cast<double>(totalDaysAbsent) / numOfEmployees;
	return average;
}
