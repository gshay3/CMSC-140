/*
 * Class: CMSC140 CRN: 40437
 * Instructor: Ara M. Kechiantz
 * Project<number> Project 1
 * Description: This program simulates a simple interactive robot that
 * communicates with a user. It performs the following tasks:
 * 
 * 1. Greets the user and asks for their name.
 * 2. Prompts the user to enter an age and converts that age
 *    into different time units (months, days, hours, minutes,
 *    seconds).
 * 3. Converts the given age into equivalent "human years"
 *    for dogs and goldfish.
 * 4. Asks the user for two integers and demonstrates basic
 *    arithmetic operations (addition and division).
 * 5. Shows the difference between integer division and
 *    floating-point division.
 * 6. Displays programmer and assignment information.
 * Due Date: 06/19
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Griffin Shay
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// Variables for user input.
	string visitorName;
	int age, num1, num2, val;

	// Time conversion constants.
	const int months = 12, days = 30, hours = 24, minutes = 60, seconds = 60;

	// Animal age conversion factors.
	const int goldfish = 5, dog = 7;
	
	// Program metadata.
	const string robotName = "Nao", programmerName = "Griffin Shay", assignmentNum = "Project 1", dueDate = "06/19";

	// Greeting and name input.
	cout << "**************** Robot Prototype Scripting ********************\n"
		<< "\n"
		<< "Hello, welcome to Montgomery College! My name is " << robotName << ". May I have your name?\n";
	getline(cin, visitorName);

	// Personalized greeting and prompt for number.
	cout << "Nice to have you with us today, " << visitorName << "!\n"
		<< "Let me impress you with a small game.\n"
		<< "Give me the age of an important person or a pet to you.\n"
		<< "Please give me only a number:\n";

	// Age input.
	cin >> age;

	// Age conversions.
	cout << "\n"
		<< "You have entered " << age << ".\n"
		<< "If this is for a person, the age can be expressed as:\n"
		<< age << " years\n"
		<< "or " << age * months << " months\n"
		<< "or about " << age * months * days << " days\n"
		<< "or about " << age * months * days * hours << " hours\n"
		<< "or about " << age * months * days * hours * minutes << " minutes\n"
		<< "or about " << age * months * days * hours * minutes * seconds << " seconds \n";

	// Animal age equivalent.
	cout << "If this is for a dog, it is " << age * dog << " years old in human age.\n"
		<< "If this is for a gold fish, it is " << age * goldfish << " years old in human age.\n"
		<< "\n";

	// Second game: Arithematic operations.
	cout << "Let's play another game, " << visitorName << ". Give me a whole number.\n";
	cin >> num1;
	cout << "Very well. Give me another whole number.\n";
	cin >> num2;

	// Integer arithematic.
	cout << "Using the operator '+' in C++, the result of " << num1 << " + " << num2 << " is " << num1 + num2 << ".\n"
		<< "Using the operator '/', the result of " << num1 << " / " << num2 << " is " << num1 / num2 << "\n";

	// Floating-point division with formatting.
	cout << "however, the result of " << setprecision(1) << fixed << static_cast<double>(num1) 
		<< " / " << setprecision(1) << fixed << static_cast<double>(num2) << " is about " 
		<< setprecision(1) << fixed << (float)num1 / num2 << ".\n"
		<< "\n";

	// Program closing and credits.
	cout << "Thank you for testing my program!!\n"
		<< "PROGRAMMER: " << programmerName << "\n"
		<< "CMSC140 " << assignmentNum << "\n"
		<< "Due Date : " << dueDate << "\n";


	return 0;
}