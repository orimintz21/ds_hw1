#ifndef SALARY_STAT_H_
#define SALARY_STAT_H_

#include <exception>
#include "AvlTree2.h"
#include "library1.h"
#include "Company.h"
#include "Employee.h"

class CompanyComp
{
public:
    bool operator()(const Company& a, const Company& b) const
    {
        if(a.id > b.id)
            return true;
        return false;
    }
};

class CompanyPtrComp
{
public:
    bool operator()(const Company* a, const Company* b) const
    {
        if(a->id > b->id)
            return true;
        return false;
    }
};

class EmployeeComp
{
public:
    bool operator()(const Employee& a, const Employee& b) const
    {
        if(a.id > b.id)
            return true;
        return false;
    }
};


class EmployeesMatchingInSystemCond
{
public:
    int m_salary;
    int m_grade;
    EmployeesMatchingInSystemCond(int min_salary, int min_grade) : m_salary(min_salary), m_grade(min_grade){};
    bool operator()(const Employee& a) const
    {
        if(a.salary >= m_salary && a.grade >= m_grade)
            return true;
        return false;
    }
};

class SalaryStat
{
public:
    AvlTree<Company,CompanyComp> company_tree;
    AvlTree<Company*,CompanyPtrComp> n_e_company_tree;
    
    AvlTree<Employee,EmployeeComp> employee_tree;
    AvlTree<Employee*,SalaryComp> employee_salary_tree;

    SalaryStat();
    ~SalaryStat() = default;
    void AddCompany(int CompanyID, int Value);
    void AddEmployee(int EmployeeID, int CompanyID, int Salary, int Grade);
    void RemoveEmployee(int EmployeeID);
    void RemoveCompany(int CompanyID);
    void GetCompanyInfo(int CompanyID, int *Value, int *NumEmployees);
    void GetEmployeeInfo(int EmployeeID, int *EmployerID, int *Salary, int *Grade);
    void IncreaseCompanyValue(int CompanyID, int ValueIncrease);
    void PromoteEmployee(int EmployeeID, int SalaryIncrease, int BumpGrade);
    void HireEmployee(int EmployeeID, int NewCompanyID);
    void AcquireCompany(int AcquirerID, int TargetID, double Factor);
    void GetHighestEarner(int CompanyID, int *EmployeeID);
    void GetHighestEarnerInCompany(int CompanyID , int *EmployeeID);
    void GetHighestEarnerInTheSystem(int* EmployeeID);
    void GetAllEmployeesBySalary(int CompanyID, int **Employees, int*NumOfEmployees);
    int* GetAllEmployeesBySalaryInTheSystem(int* NumOfEmployees);
    void GetAllEmployeesBySalaryInTheSystemAux(Node<Employee*>* loc, int *employee_arr, int &i);

    //returns an array of the ids of the highest earners in relevant compan
    void GetHighestEarnerInEachCompany(int NumOfCompanies,  int **Employees);
    void GetHighestEarnerInEachCompanyAux(Node<Company*>* loc, int* arr, int& i, int NumOfCompanies);
    void GetNumEmployeesMatching(int CompanyID, int MinEmployeeID, int MaxEmployeeId, int MinSalary, 
                                                    int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees);
    
    void GetNumEmployeesMatchingInTheSystem(int MinEmployeeID, int MaxEmployeeId, int MinSalary,
                                                    int MinGrade, int* TotalNumOfEmployees, int* NumOfEmployees);

    void countInRange(int min_employee, int max_employee, EmployeesMatchingInSystemCond cond, int* total_num_of_employees, int* num_of_matching_employees, Node<Employee>* loc); 


    //Methods
};



#endif //SALARY_STAT_H_
