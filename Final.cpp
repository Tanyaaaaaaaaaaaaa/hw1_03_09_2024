#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee 
{
    char* surname;
    char* name;
    char* phone;
    double salary;
};

bool IsValidPhoneNumber(const char* phone) 
{
    if (strlen(phone) != 19) return false;
    if (phone[0] != '(' || phone[4] != ')' || phone[5] != ' ' || phone[8] != ' ' || phone[12] != ' ' || phone[15] != ' ') 
    {
        return false;
    }
    return true;
}

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
    } while (!IsValidPhoneNumber(newEmployee.phone));

    cout << "Enter salary : ";
    cin >> newEmployee.salary;

    Employee* temp = new Employee[count + 1];
    for (int i = 0; i < count; ++i) 
    {
        temp[i] = employees[i];
    }
    temp[count] = newEmployee;
    delete[] employees;
    employees = temp;
    ++count;
}

void DeleteEmployee(Employee*& employees, int& count, int index) 
{
    if (index < 0 || index >= count) 
    {
        cout << "Invalid index !" << endl;
        return;
    }
    cout << "Are you sure you want to delete this employee ? : ";
    char confirm;
    cin >> confirm;
    if (tolower(confirm) != 'y') 
    {
        return;
    }
    for (int i = index; i < count - 1; ++i) 
    {
        employees[i] = employees[i + 1];
    }
    --count;
}

void ShowEmployees(const Employee* employees, int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << "Employee " << i + 1 << ": " << employees[i].surname << " " << employees[i].name
            << ", Phone : " << employees[i].phone << ", Salary : " << employees[i].salary << endl;
    }
}

void SearchBySurname(const Employee* employees, int count, const char* surname) 
{
    for (int i = 0; i < count; ++i) 
    {
        if (strcmp(employees[i].surname, surname) == 0) 
        {
            cout << "Found : " << employees[i].surname << " " << employees[i].name
                << ", Phone : " << employees[i].phone << ", Salary : " << employees[i].salary << endl;
        }
    }
}

void SearchBySalaryRange(const Employee* employees, int count, double minSalary, double maxSalary) 
{
    for (int i = 0; i < count; ++i) 
    {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) 
        {
            cout << "Employee " << employees[i].surname << " " << employees[i].name
                << ", Phone : " << employees[i].phone << ", Salary : " << employees[i].salary << endl;
        }
    }
}

void SortBySurname(Employee* employees, int count) 
{
    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = 0; j < count - i - 1; ++j) 
        {
            if (strcmp(employees[j].surname, employees[j + 1].surname) > 0) 
            {
                swap(employees[j], employees[j + 1]);
            }
        }
    }
}

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
    for (int i = 0; i < count; ++i) 
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
    for (int i = 0; i < count; ++i) 
    {
        outFile << employees[i].surname << " " << employees[i].name << " " << employees[i].phone << " " << employees[i].salary << endl;
    }
    outFile.close();
}

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