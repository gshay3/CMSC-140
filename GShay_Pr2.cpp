/*
 * Class: CMSC140 CRN: 40437
 * Instructor: Ara M. Kechiantz
 * Project: Project 2
 * Integrated development environment (IDE)
 * Description: This program provides a simple menu-driven toolkit that allows the user to perform basic unit conversions.
 * Due Date: 07/03
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Griffin Shay
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	// Constants representing menu choices.
	const int choice1 = 1, choice2 = 2, choice3 = 3, choice4 = 4;

	// Conversion constants.
	const double temp1div = 9, temp2div = 5, temp3add = 32, miles = 0.6, pounds = 2.2;

	// Variable declarations.
	int choice, celsius;
	double fahrenheit, kilometers, distance, kilograms, weight;
	string country;

	// Prompt user for a country name and display menu.
	cout << "Enter a country name: ";
	getline(cin, country);
	cout << "\n\n"
		<< "Converter Toolkit\n"
		<< "--------------------\n"
		<< "1. Temperature Converter\n"
		<< "2. Distance Converter\n"
		<< "3. Weight Converter\n"
		<< "4. Quit\n\n";

	
	// Get user menu choice and validate input.
	cout << "Enter your choice (1-4): ";
	cin >> choice;
	while (choice < 1 ||  choice > 4)
	{
		cout << "Please enter a number between 1 and 4.";
		cin >> choice;
	}

	// Prompt user for unit value and perform unit conversion based on user's choice.
	switch (choice)
	{
		case choice1:
			cout << "Please enter temperature in Celsius (such as 24 ): ";
			cin >> celsius;
			fahrenheit = temp1div / temp2div * celsius + temp3add;
			cout << "It is " << static_cast<int>(fahrenheit) << " in Fahrenheit.\n\n";
			break;
		case choice2:
			cout << "Please enter the distance in Kilometer (such as 18.54 ): ";
			cin >> kilometers;
			if (kilometers > 0)
			{
				distance = kilometers * miles;
				cout << fixed << setprecision(2) << showpoint << "It is " << distance << " in miles.\n\n";
			}
			else
			{
				cout << "!!! Program does not convert negative distance !!!\n\n";
			}
			break;
		case choice3:
			cout << "Please enter weight in Kilogram (such as 7 ): ";
			cin >> kilograms;
			if (kilograms >= 1)
			{
				weight = kilograms * pounds;
				cout << fixed << setprecision(2) << showpoint << "It is " << weight << " in pounds.\n\n";
			}
			else
			{
				cout << "!!! Program does not convert negative weight !!!\n\n";
			}
			break;
		case choice4:
			cout << "\n\n";
			break;
		default :
			cout << "Invalid input, please enter a number 1 through 4.\n\n";
	}

	// Closing message.
	cout << country << " sounds fun!\n\n\n"
		<< "Thank you for testing my program!!\n"
		<< "Programmer: Griffin Shay\n"
		<< "CSMSC140 Common Project 2\n"
		<< "Due Date: 07/03/2023\n";

	return 0;
}