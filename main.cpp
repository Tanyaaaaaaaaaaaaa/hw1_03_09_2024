//main.cpp
#include "employee.h"
#include <iostream>
#include "file.cpp"
using namespace std;

int main() 
{
    Employee* employees = nullptr;
    int count = 0;
    int choice;

    do 
    {
        cout << "1. Add employee\n2. Delete employee\n3. Show all employees\n4. Search by surname\n" << "5. Search by salary range\n6. Sort by surname\n7. Load from file\n8. Save to file\n9. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            AddEmployee(employees, count);
            break;
        case 2:
            int index;
            cout << "Enter index to delete : ";
            cin >> index;
            DeleteEmployee(employees, count, index - 1);
            break;
        case 3:
            ShowEmployees(employees, count);
            break;
        case 4:
            char surname[50];
            cout << "Enter surname : ";
            cin >> surname;
            SearchBySurname(employees, count, surname);
            break;
        case 5:
            double minSalary, maxSalary;
            cout << "Enter min salary : ";
            cin >> minSalary;
            cout << "Enter max salary : ";
            cin >> maxSalary;
            SearchBySalaryRange(employees, count, minSalary, maxSalary);
            break;
        case 6:
            SortBySurname(employees, count);
            break;
        case 7:
            LoadFromFile(employees, count, "employees.txt");
            break;
        case 8:
            SaveToFile(employees, count, "employees.txt");
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice !" << endl;
        }
    } while (choice != 9);
    delete[] employees;
    return 0;
}