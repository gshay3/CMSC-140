/*
 * Class: CMSC140 CRN: 40437
 * Instructor: Ara M. Kechiantz
 * Project: Project 5
 * Integrated development environment (IDE)
 * Description: A program that has the user input numbers in a square grid. The numbers and then checked and the program determines whether it's a Lo Shu Magic Square.
 * Due Date: 08/07
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Griffin Shay
*/

#include<iostream>
using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

const int PROJECT = 5;
const string NAME = "Griffin Shay";
const string DUE_DATE = "08/07";

// Function prototypes
bool isMagicSquare(int r1[], int r2[], int r3[], int size);
bool checkRange(int r1[], int r2[], int r3[], int size, int min, int max);
bool checkUnique(int r1[], int r2[], int r3[], int size);
bool checkRowColDiag(int r1[], int r2[], int r3[], int size);
void fillArray(int r1[], int r2[], int r3[], int size);
void showArray(int r1[], int r2[], int r3[], int size);

int main()
{
    char choice;

    do
    {
        /* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
        // 3 parallel arrays represent the 3 rows of the 3x3 grid.
        int row1[COLS], row2[COLS], row3[COLS];

        // Call fillArray to get user input for the magic square.
        fillArray(row1, row2, row3, COLS);

        // Call showArray to display the magic square.
        showArray(row1, row2, row3, COLS);

        // Validate whether it is a Lo Shu magic square.
        if (isMagicSquare(row1, row2, row3, COLS))
        {
            cout << "This is a Lo Shu magic square." << endl;
        }
        else
        {
            cout << "This is not a Lo Shu magic square." << endl;
        }


        // Ask user if they want to try again.
        cout << "\n\n\nDo you want to try again? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y')
        {
            break;
        }

    } while (true);

    // Display project information.
    cout << "\n\n\nName: " << NAME << "\n";
    cout << "Project #: " << PROJECT << "\n";
    cout << "Due Date: " << DUE_DATE << "\n";

    return 0;
}

// Function definitions

// Reads user input into 3 seperate row arrays.
void fillArray(int r1[], int r2[], int r3[], int size)
{
    cout << "Enter the values of the magic square:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 1 column " << i << ": ";
        cin >> r1[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 2 column " << i << ": ";
        cin >> r2[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number for row 3 column " << i << ": ";
        cin >> r3[i];
    }
}

// Displays the 3x3 grid in row format.
void showArray(int r1[], int r2[], int r3[], int size)
{
    cout << "\nMagic Square:\n";

    for (int i = 0; i < size; i++)
    {
        cout << r1[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        cout << r2[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < size; i++)
    {
        cout << r3[i] << " ";
    }
    cout << "\n";
}

// Runs all validation checks for a Lo Shu magic square.
bool isMagicSquare(int r1[], int r2[], int r3[], int size)
{
    return checkRange(r1, r2, r3, size, MIN, MAX)
        && checkUnique(r1, r2, r3, size)
        && checkRowColDiag(r1, r2, r3, size);
}

// Ensures all values are within the allowed range.
bool checkRange(int r1[], int r2[], int r3[], int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        if (r1[i] < min || r1[i] > max)
        {
            return false;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (r2[i] < min || r2[i] > max)
        {
            return false;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (r3[i] < min || r3[i] > max)
        {
            return false;
        }
    }
    return true;
}

// Ensures all 9 numbers are unique.
bool checkUnique(int r1[], int r2[], int r3[], int size)
{
    int values[9];
    int k = 0;

    for (int i = 0; i < size; i++)
    {
        values[k++] = r1[i];
    }
    for (int i = 0; i < size; i++)
    {
        values[k++] = r2[i];
    }
    for (int i = 0; i < size; i++)
    {
        values[k++] = r3[i];
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (values[i] == values[j])
            {
                return false;
            }
        }
    }
    return true;
}

// Verifies all rows, columns, and diagonals sum equally.
bool checkRowColDiag(int r1[], int r2[], int r3[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += r1[i];
    }

    if (sum != r2[0] + r2[1] + r2[2])
    {
        return false;
    }
    if (sum != r3[0] + r3[1] + r3[2])
    {
        return false;
    }

    if (sum != r1[0] + r2[0] + r3[0])
    {
        return false;
    }
    if (sum != r1[1] + r2[1] + r3[1])
    {
        return false;
    }
    if (sum != r1[2] + r2[2] + r3[2])
    {
        return false;
    }

    if (sum != r1[0] + r2[1] + r3[2])
    {
        return false;
    }
    if (sum != r1[2] + r2[1] + r3[0])
    {
        return false;
    }


    return true;
}