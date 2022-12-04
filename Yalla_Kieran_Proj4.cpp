/*

 * Class: CMSC140 CRN

 * Instructor: Prof. Koo

 * Project<4>

 * Description: Write a program that calculates the average number of days a company's employees are absent during the year and outputs a report on a file named "employeeAbsences.txt".  

 * Due Date: 11/09/21

 * I pledge that I have completed the programming assignment independently.

   I have not copied the code from a student or any source.

   I have not given my code to any student.

   Print your Name here: Kieran Yalla
   
   */


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// global variable of type ofstream for the output file
ofstream outputFile;

// declares the 3 functions that were asked for
int NumOfEmployees();
int TotDaysAbsent(int);
double AverageAbsent(int, int);

int main() {
    // open the output file
    outputFile.open("employeeAbsences.txt");
    
    outputFile<<"ABSENCE REPORT"<<endl;
    
    int numOfEmployees = NumOfEmployees();
    outputFile << endl << "ID" << "\t" << "Total Days missed" <<endl;
    int absentdays = TotDaysAbsent(numOfEmployees);
    
    outputFile << endl << "The " << numOfEmployees << " employees were absent a total of " << absentdays << endl;
    
    outputFile << fixed << setprecision(2);
    outputFile << endl << "The average number of days absent is " << AverageAbsent(numOfEmployees, absentdays) << " days" << endl;
    outputFile << endl << "Programmer: Kieran Yalla" << endl;
    outputFile.close(); 
    return 0;
}

 
// returns the number of employees in the company
int NumOfEmployees()
{
    int numEmployees;
    do {
        cout << "Enter number of employees in the company : ";
        cin >> numEmployees;
        if(numEmployees < 1){
            cout<<"Number of employees should not be less than 1"<<endl;
        }
    } while(numEmployees < 1);
    return numEmployees;

}

int TotDaysAbsent(int numOfEmployees)
{
    int employeeID;
    int daysmissed = 0;
    int absentdays = 0;
    for(int index = 0;index < numOfEmployees;index++)
    {
        cout << "Enter an employee ID: ";
        cin >> employeeID;
        do {
            cout << "Enter the number of days missed/absent: ";
            cin >> daysmissed;
            if(daysmissed < 0)
            {
                cout<<"The number of days should not be negative"<<endl;
                cout << "Please re-enter the number of days absent: ";
                cin >> daysmissed;
            }
        }
        while(daysmissed < 0);
        absentdays += daysmissed;
        outputFile << employeeID <<  "\t\t" << daysmissed << endl;
    }
    return absentdays;
}

double AverageAbsent(int numOfEmployees, int absentdays)
{
    double avg = (double)absentdays/numOfEmployees;
    return avg;
}