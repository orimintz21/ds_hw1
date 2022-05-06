#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "memory"
#include "Node.h"
#include "AvlTree.h"
#include "Employee.h"
#include "ostream"
#include "AvlTreeExceptions.h"


class Company;

class Employee
{
private:

public:
    int id;
    int salary;
    int grade;
    Node<Company>* company;

    Employee(int n_id);

    Employee();

    Employee(int n_id,int n_salary, int n_grade, Node<Company>* n_company);
    ~Employee()=default;
    int getSalary();
    int getGrade();

    Node<Company>* getCompany();
    void promote(int SalaryIncrease, int BumpGrade);
    void hire(Node<Company>* n_company);
    void getInfo(int *EmployerID, int *Salary, int *Grade);
    
};

#endif //EMPLOYEE_H_