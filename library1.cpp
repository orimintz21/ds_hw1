#include "library1.h"
#include "SalaryStat.h"
#include "AvlTreeExceptions.h"
#include "ex1Exceptions.h"

#include <exception>

void *Init()
{
    SalaryStat *DS = NULL;
    try
    {
        DS = new SalaryStat();
    }
    catch (const std::bad_alloc &e)
    {
        return NULL;
    }

    return (void *)DS;
}

StatusType AddCompany(void *DS, int CompanyID, int Value)
{
    if (DS == NULL)
        return INVALID_INPUT;
    try
    {
        ((SalaryStat *)DS)->AddCompany(CompanyID, Value);
    }
    catch (const std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    catch (const invalid_input &e)
    {
        return INVALID_INPUT;
    }
    catch (const already_in_tree &e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType AddEmployee(void *DS, int EmployeeID, int CompanyID, int Salary, int Grade)
{
    if (DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat *)DS)->AddEmployee(EmployeeID, CompanyID, Salary, Grade);
    }
    catch (const std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    catch (const invalid_input &e)
    {
        return INVALID_INPUT;
    }
    catch (const not_in_tree &e)
    {
        return FAILURE;
    }
    catch (const already_in_company &e)
    {
        return FAILURE;
    }
    catch (const already_in_tree &e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType RemoveCompany(void *DS, int CompanyID)
{
    if (DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat *)DS)->RemoveCompany(CompanyID);
    }
    catch (const std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    catch (const invalid_input &e)
    {
        return INVALID_INPUT;
    }
    catch (const not_in_tree &e)
    {
        return FAILURE;
    }
    catch (const company_has_employees &e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType RemoveEmployee(void *DS, int EmployeeID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->RemoveEmployee(EmployeeID);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetCompanyInfo(void *DS, int CompanyID, int *Value, int *NumEmployees)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->GetCompanyInfo(CompanyID, Value, NumEmployees);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetEmployeeInfo(void *DS, int EmployeeID, int *EmployerID, int *Salary, int *Grade)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->GetEmployeeInfo(EmployeeID, EmployerID, Salary, Grade);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


StatusType IncreaseCompanyValue(void *DS, int CompanyID, int ValueIncrease)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->IncreaseCompanyValue(CompanyID, ValueIncrease);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


StatusType PromoteEmployee(void *DS, int EmployeeID, int SalaryIncrease, int BumpGrade)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->PromoteEmployee(EmployeeID, SalaryIncrease, BumpGrade);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


StatusType HireEmployee(void *DS, int EmployeeID, int NewCompanyID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->HireEmployee(EmployeeID , NewCompanyID);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    catch( const already_in_company& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


StatusType AcquireCompany(void *DS, int AcquirerID, int TargetID, double Factor)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->AcquireCompany(AcquirerID , TargetID, Factor);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    catch( const already_in_company& e)
    {
        return FAILURE;
    }
    catch ( const failure& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetHighestEarner(void *DS, int CompanyID, int *EmployeeID)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->GetHighestEarner(CompanyID, EmployeeID);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const empty_company& e)
    {
        return FAILURE;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


StatusType GetAllEmployeesBySalary(void *DS, int CompanyID, int **Employees, int *NumOfEmployees)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->GetAllEmployeesBySalary(CompanyID, Employees, NumOfEmployees);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    catch( const failure& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


StatusType GetHighestEarnerInEachCompany(void *DS, int NumOfCompanies, int **Employees)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->GetHighestEarnerInEachCompany(NumOfCompanies , Employees);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    catch( const failure& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetNumEmployeesMatching(void *DS, int CompanyID, int MinEmployeeID, int MaxEmployeeId,
                                   int MinSalary, int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees)
{
    if(DS == NULL)
    {
        return INVALID_INPUT;
    }
    try
    {
        ((SalaryStat*)DS)->GetNumEmployeesMatching(CompanyID ,MinEmployeeID, MaxEmployeeId, MinSalary,
                                                     MinGrade, TotalNumOfEmployees, NumOfEmployees);
    }
    catch( const std::bad_alloc& e)
    {
        return ALLOCATION_ERROR;
    }
    catch( const invalid_input& e)
    {
        return INVALID_INPUT;
    }
    catch( const not_in_tree& e)
    {
        return FAILURE;
    }
    catch( const failure& e)
    {
        return FAILURE;
    }
    return SUCCESS;
}


void Quit(void **DS)
{
    void** temp = DS;
    SalaryStat* n_temp= static_cast<SalaryStat*>(*temp);
    delete n_temp;
    *DS = NULL;
}
