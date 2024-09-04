//file.cpp
#include "employee.h"
#include <iostream>
#include <fstream>
using namespace std;

void LoadFromFile(Employee*& employees, int& count, const char* filename) 
{
    ifstream inFile(filename);
    if (!inFile) 
    {
        cout << "File not found !" << endl;
        return;
    }
    inFile >> count;
    employees = new Employee[count];
    for (int i = 0; i < count; i++) 
    {
        employees[i].surname = new char[50];
        employees[i].name = new char[50];
        employees[i].phone = new char[20];
        inFile >> employees[i].surname >> employees[i].name >> employees[i].phone >> employees[i].salary;
    }
    inFile.close();
}

void SaveToFile(const Employee* employees, int count, const char* filename) 
{
    ofstream outFile(filename);
    outFile << count << endl;
    for (int i = 0; i < count; i++) 
    {
        outFile << employees[i].surname << " " << employees[i].name << " " << employees[i].phone << " " << employees[i].salary << endl;
    }
    outFile.close();
}