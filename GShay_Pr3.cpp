/*
 * Class: CMSC140 CRN: 40437
 * Instructor: Ara M. Kechiantz
 * Project: Project 3
 * Integrated development environment (IDE)
 * Description: A program that determines the location, number of floors, and number of rooms per floor of a hotel. 
 * It then determines the number of occupied rooms and the hotel's income and occupancy rate.
 * Due Date: 07/17
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
	// Constants for validation and room pricing.
	const int FLOOR_MIN = 1, FLOOR_MAX = 5, ROOMS_MIN = 1, ROOMS_MAX = 30;
	const double SINGLE = 60.00, TWO_BED = 75.00, KING = 100.00, SUITE = 150.00, PERCENT = 100;

	// Variable declarations.
	int equals, floors, floorCount, rooms[FLOOR_MAX], roomSingle, roomTwoBed, roomKing, roomSuite,
		singleTotal, twoBedTotal, kingTotal, suiteTotal, roomsTotal, unoccupied, floorWithMin = -1, lowestRooms = ROOMS_MAX + 1;
	double income, roomRates, occupied, occupancyRate;
	string location;

	// Print header line.
	for (equals = 1; equals <= 60; equals++)
	{
		cout << "=";
	}
	cout << "\n\t\tBlueMont Hotel\n";
	for (equals = 1; equals <= 60; equals++)
	{
		cout << "=";
	}

	// Get hotel location from user.
	cout << "\nEnter the location of this hotel chain: ";
	getline(cin, location);

	// Get number of floors and validate input.
	cout << "Enter total number of floors of the hotel: ";
	cin >> floors;
	while (floors < FLOOR_MIN || floors > FLOOR_MAX)
	{
		cout << "number of floors should be between 1 and 5 !! please try again.\n\n";
		cout << "Enter total number of floors of the hotel: ";
		cin >> floors;
	}


	// Loop through each floor to gather data.
	for (floorCount = 0, singleTotal = 0, twoBedTotal = 0, kingTotal = 0, suiteTotal = 0, roomsTotal = 0; floorCount < floors; floorCount++)
	{
		// Get number of rooms on current floor and validate input.
		cout << "\nEnter the total number of rooms on Floor " << (floorCount + 1) << " : ";
		cin >> rooms[floorCount];
		while (rooms[floorCount] < ROOMS_MIN || rooms[floorCount] > ROOMS_MAX)
		{
			cout << "Number of rooms should be between 1 and 30 !! Please try again.\n\n";
			cout << "Enter the total number of rooms on Floor " << (floorCount + 1) << " : ";
			cin >> rooms[floorCount];
		}

		// Get number of occupied rooms by type and validate input.
		cout << "How many SINGLE rooms are occupied on floor " << (floorCount + 1) << " : ";
		cin >> roomSingle;
		while (roomSingle < 0)
		{
			cout << "Please enter a number 0 or greater: ";
			cin >> roomSingle;
		}
		cout << "How many DOUBLE rooms are occupied on floor " << (floorCount + 1) << " : ";
		cin >> roomTwoBed;
		while (roomTwoBed < 0)
		{
			cout << "Please enter a number 0 or greater: ";
			cin >> roomTwoBed;
		}
		cout << "How many KING rooms are occupied on floor " << (floorCount + 1) << " : ";
		cin >> roomKing;
		while (roomKing < 0)
		{
			cout << "Please enter a number 0 or greater: ";
			cin >> roomKing;
		}
		cout << "How many SUITE rooms are occupied on floor " << (floorCount + 1) << " : ";
		cin >> roomSuite;
		while (roomSuite < 0)
		{
			cout << "Please enter a number 0 or greater: ";
			cin >> roomSuite;
		}

		// Ensure total occupied rooms does not exceed total rooms on the floor.
		while (roomSingle + roomTwoBed + roomKing + roomSuite > rooms[floorCount])
		{
			cout << "Total number of occupied rooms exceeds the total number of rooms on this floor. Please try again!!\n";

			// Re-enter total rooms.
			cout << "\nEnter the total number of rooms on Floor " << (floorCount + 1) << " : ";
			cin >> rooms[floorCount];

			// Validate again.
			while (rooms[floorCount] < ROOMS_MIN || rooms[floorCount] > ROOMS_MAX)
			{
				cout << "number of rooms should be between 1 and 30 !! Please try again.\n\n";
				cout << "Enter the total number of rooms on Floor " << (floorCount + 1) << " : ";
				cin >> rooms[floorCount];
			}

			// Re-enter occupied rooms with validation.
			cout << "How many SINGLE rooms are occupied on floor " << (floorCount + 1) << " : ";
			cin >> roomSingle;
			while (roomSingle < 0)
			{
				cout << "Please enter a number 0 or greater: ";
				cin >> roomSingle;
			}
			cout << "How many DOUBLE rooms are occupied on floor " << (floorCount + 1) << " : ";
			cin >> roomTwoBed;
			while (roomTwoBed < 0)
			{
				cout << "Please enter a number 0 or greater: ";
				cin >> roomTwoBed;
			}
			cout << "How many KING rooms are occupied on floor " << (floorCount + 1) << " : ";
			cin >> roomKing;
			while (roomKing < 0)
			{
				cout << "Please enter a number 0 or greater: ";
				cin >> roomKing;
			}
			cout << "How many SUITE rooms are occupied on floor " << (floorCount +1) << " : ";
			cin >> roomSuite;
			while (roomSuite < 0)
			{
				cout << "Please enter a number 0 or greater: ";
				cin >> roomSuite;
			}
		}

		// Track floor with the least number of rooms.
		if (rooms[floorCount] < lowestRooms)
		{
			lowestRooms = rooms[floorCount];
			floorWithMin = floorCount + 1;
		}

		// Accumulate totals.
		singleTotal += roomSingle;
		twoBedTotal += roomTwoBed;
		kingTotal += roomKing;
		suiteTotal += roomSuite;
		roomsTotal += rooms[floorCount];
	}

	// Print report header.
	cout << "\n\n\n";

	for (equals = 1; equals <= 80; equals++)
	{
		cout << "=";
	}
	cout << "\n\t\tBlueMont Hotel located in " << location << "\n";
	cout << "\t\t\tTODAY'S ROOM RATES(US$/night)\n";
	cout << "\tSingle Room\tDouble Room\tKing Room\tSuite Room\n";
	cout << "\t\t" << SINGLE << "\t\t" << TWO_BED << "\t\t" << KING << "\t\t" << SUITE << "\n";
	for (equals = 1; equals <= 80; equals++)
	{
		cout << "=";
	}
	
	// Calculate totals and occupancy rate.
	income = (singleTotal * SINGLE) + (twoBedTotal * TWO_BED) + (kingTotal * KING) + (suiteTotal * SUITE);
	occupied = singleTotal + twoBedTotal + kingTotal + suiteTotal;
	unoccupied = roomsTotal - occupied;
	occupancyRate = (occupied / roomsTotal) * PERCENT;

	// Display results.
	cout << "\n" << roomsTotal;
	cout << setw(30) << right << "\n\t\tHotel Income:" << setw(24) << right << "$" << fixed << setprecision(2) << showpoint << income << "\n";
	cout << setw(29) << right << "Total # of rooms:" << setw(30) << right << roomsTotal << "\n";
	cout << setw(29) << right << "Total # of Occupied Rooms:" << setw(30) << right << static_cast<int>(occupied) << "\n";
	cout << setw(29) << right << "Total # of Unoccupied Rooms:" << setw(30) << right << unoccupied << "\n";
	cout << setw(29) << right << "Occupancy rate:" << setw(29) << right << fixed << setprecision(2) << showpoint << occupancyRate << "%\n\n";

	// Suggest improvement if occupancy is low.
	cout << "Floor #" << floorWithMin << " with " << lowestRooms << " rooms is the floor with the least amount of rooms!\n";
	if (occupancyRate < 60)
	{
		cout << "Need to improve Hotel occupancy rate!!\n";
	}

	// Closing message.
	cout << "\n\nThank you for testing my program!!\n"
		<< "PROGRAMMER: Griffin Shay\n"
		<< "CMSC140 Common Project 3\n"
		<< "Due Date: 07/17\n";

	return 0;
}