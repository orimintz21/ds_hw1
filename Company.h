#ifndef WORKPLACE_H_
#define WORKPLACE_H_

#include <memory>
#include "AvlTree.h"
#include "Employee.h"


class IdComp
{
public:
    bool operator()(const Employee* a, const Employee* b) const
    {
        if(a->id > b->id)
        {
            return true;
        }
        return false;
    }
};

class SalaryComp
{
public:
    bool operator()( const Employee* a, const Employee* b) const
    {
        if(a->salary < b->salary)
        {
            return true;
        }
        if(a->salary == b->salary)
        {
            if(a->id > b->id)
            {
                return true;
            }
        }
        return false;
    }
};

class EmployeesMatchingInCompanyCond
{
public:
    int m_salary;
    int m_grade;
    EmployeesMatchingInCompanyCond(int min_salary, int min_grade) : m_salary(min_salary), m_grade(min_grade){};
    bool operator()(const Employee* a) const
    {
        if(a->salary >= m_salary && a->grade >= m_grade)
            return true;
        return false;
    }
};


class Company
{
public:
    AvlTree<Employee*, IdComp> IdTree;
    AvlTree<Employee*, SalaryComp> SalaryTree;
    int id;
    int stock_value;

    Company();
    Company(int n_id);
    Company(int n_id, int start_value);

    ~Company() = default;

    Employee* getHeistEarner();
    
    bool isEmpty() const;
    int getSize() const;

    void addEmployeeToCompany(Employee* ptr_employee);

    void removeEmployeeFromCompany(Employee* fired);

    void increaseValue(int ValueIncrease);

    int* getAllEmployeesBySalaryInCompany(int* n_size);

    void getNumEmployeesMatchingInCompany(int min_employee, int max_employee,
                        int min_salary, int min_grade, int* total_num_of_employees, int* num_of_matching_employees);


    void getInfo(int *value, int* num_of_employees_ptr);

    void getAllEmployeesBySalaryInCompanyAux(int employee_arr[],int* n_size, Node<Employee*>* loc);

    void countInRange(int min_employee, int max_employee, EmployeesMatchingInCompanyCond cond, int* total_num_of_employees, int* num_of_matching_employees, Node<Employee*>* loc); 


    void updateEmployeeAfterChangedSalary(Employee* employee);

    void mergeWith(Company& target, double Factor);
};

void updateCompany(Node<Employee*>* emp, Node<Company>* comp);

#endif //WORKPLACE_H_