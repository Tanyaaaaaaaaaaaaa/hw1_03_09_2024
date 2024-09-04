//employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee 
{
    char* surname;
    char* name;
    char* phone;
    double salary;
};

void AddEmployee(Employee*& employees, int& count);
void DeleteEmployee(Employee*& employees, int& count, int index);
void ShowEmployees(const Employee* employees, int count);
void SearchBySurname(const Employee* employees, int count, const char* surname);
void SearchBySalaryRange(const Employee* employees, int count, double minSalary, double maxSalary);
void SortBySurname(Employee* employees, int count);
bool IsValidPhoneNumber(const char* phone);

#endif // EMPLOYEE_H