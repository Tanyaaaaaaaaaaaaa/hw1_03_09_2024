//employee.cpp
#include "employee.h"
#include <iostream>
#include <cstring>
using namespace std;

void AddEmployee(Employee*& employees, int& count) 
{
    Employee newEmployee;
    newEmployee.surname = new char[50];
    newEmployee.name = new char[50];
    newEmployee.phone = new char[20];

    cout << "Enter surname : ";
    cin >> newEmployee.surname;
    cout << "Enter name : ";
    cin >> newEmployee.name;
    do
    {
        cout << "Enter phone (format : (380) XX XXX XX XX) : ";
        cin >> newEmployee.phone;
    } 
    while (!IsValidPhoneNumber(newEmployee.phone));

    cout << "Enter salary : ";
    cin >> newEmployee.salary;

    Employee* temp = new Employee[count + 1];
    for (int i = 0; i < count; i++) 
    {
        temp[i] = employees[i];
    }
    temp[count] = newEmployee;
    delete[] employees;
    employees = temp;
    count++;
}

void DeleteEmployee(Employee*& employees, int& count, int index) 
{
    if (index < 0 || index >= count) 
    {
        cout << "Invalid index !" << endl;
        return;
    }
    cout << "Are you sure you want to delete this employee? (y/n) : ";
    char confirm;
    cin >> confirm;
    if (tolower(confirm) != 'y') 
    {
        return;
    }
    for (int i = index; i < count - 1; i++) 
    {
        employees[i] = employees[i + 1];
    }
    count--;
}

void ShowEmployees(const Employee* employees, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        cout << "Employee " << i + 1 << ": " << employees[i].surname << " " << employees[i].name << ", Phone : " << employees[i].phone << ", Salary : " << employees[i].salary << endl;
    }
}

void SearchBySurname(const Employee* employees, int count, const char* surname) 
{
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(employees[i].surname, surname) == 0) 
        {
            cout << "Found : " << employees[i].surname << " " << employees[i].name << ", Phone : " << employees[i].phone << ", Salary : " << employees[i].salary << endl;
        }
    }
}

void SearchBySalaryRange(const Employee* employees, int count, double minSalary, double maxSalary) 
{
    for (int i = 0; i < count; i++) 
    {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) 
        {
            cout << "Employee " << employees[i].surname << " " << employees[i].name << ", Phone : " << employees[i].phone << ", Salary : " << employees[i].salary << endl;
        }
    }
}

void SortBySurname(Employee* employees, int count) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = 0; j < count - i - 1; j++) 
        {
            if (strcmp(employees[j].surname, employees[j + 1].surname) > 0) 
            {
                swap(employees[j], employees[j + 1]);
            }
        }
    }
}

bool IsValidPhoneNumber(const char* phone) 
{
    if (strlen(phone) != 19) return false;
    if (phone[0] != '(' || phone[4] != ')' || phone[5] != ' ' || phone[8] != ' ' || phone[12] != ' ' || phone[15] != ' ') 
    {
        return false;
    }
    return true;
}