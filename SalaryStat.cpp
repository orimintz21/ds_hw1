#include "Employee.h"
#include "Company.h"
#include "SalaryStat.h"
#include "AvlTree.h"

#include <exception>
#include "ex1Exceptions.h"

SalaryStat::SalaryStat() : company_tree(), employee_tree(),
                            employee_salary_tree()  {}

void SalaryStat::AddCompany(int CompanyID, int Value)
{
    if(CompanyID <= 0 || Value<=0)
        throw invalid_input();
    company_tree.insert(Company(CompanyID, Value));
}

void SalaryStat::AddEmployee(int EmployeeID, int CompanyID, int Salary, int Grade)
{
    if(Salary<=0 || CompanyID<=0 || EmployeeID<=0 || Grade<0)
        throw invalid_input();
    Employee n_employee(EmployeeID,Salary,Grade, nullptr);
    Node<Company>* company = company_tree.find(CompanyID);
    employee_tree.insert(n_employee);
    Node<Employee>* employee_in_tree = employee_tree.find(n_employee);
    employee_in_tree->data->hire(company);
    Employee* temp = employee_in_tree->data;
    company->data->addEmployeeToCompany(temp);
    try {
        n_e_company_tree.find(company->data);
    }catch(not_in_tree& e){
        n_e_company_tree.insert(company->data);
    }
    employee_salary_tree.insert(temp);
}

void SalaryStat::RemoveEmployee(int EmployeeID) {
    if(EmployeeID <= 0)
        throw invalid_input();
    Node<Employee>* employee = employee_tree.find(Employee(EmployeeID));
    Node<Company>* employees_comp = employee->data->company;
    if(employee->data->company->data->getSize() == 1)
    {
        n_e_company_tree.remove(employees_comp->data);
    }
    employees_comp->data->removeEmployeeFromCompany(employee->data);
    employee_salary_tree.remove(employee->data);
    employee_tree.remove(*employee->data);
}

void SalaryStat::RemoveCompany(int CompanyID)
{
    if(CompanyID<=0)
        throw invalid_input();
    Node<Company>* company = company_tree.find(CompanyID);
    if(!company->data->isEmpty())
        throw company_has_employees();
    company_tree.remove(CompanyID);
}

void SalaryStat::GetCompanyInfo(int CompanyID, int *Value, int *NumEmployees)
{
    if(CompanyID<=0 || Value == NULL || NumEmployees == NULL)
        throw invalid_input();

    Node<Company>* temp_comp = company_tree.find(Company(CompanyID));
    temp_comp->data->getInfo(Value,NumEmployees);
}

void SalaryStat::GetEmployeeInfo(int EmployeeID, int *EmployerID, int *Salary, int *Grade)
{
    if(Salary == NULL || EmployerID == NULL || Grade == NULL || EmployeeID<=0)
        throw invalid_input();

    Node<Employee>* temp_emp = employee_tree.find(Employee(EmployeeID));
    temp_emp->data->getInfo(EmployerID, Salary, Grade);

}

void SalaryStat::IncreaseCompanyValue(int CompanyID, int ValueIncrease)
{
    if( CompanyID<=0 || ValueIncrease <= 0)
        throw invalid_input();
    Node<Company>* temp_comp = company_tree.find(Company(CompanyID));
    temp_comp->data->increaseValue(ValueIncrease);
}

void SalaryStat::PromoteEmployee(int EmployeeID, int SalaryIncrease, int BumpGrade)
{
    if(SalaryIncrease<= 0 || EmployeeID<= 0)
        throw invalid_input();
    Node<Employee>* temp_emp = employee_tree.find(EmployeeID);
    Node<Company>* company = temp_emp->data->company;
    employee_salary_tree.remove(temp_emp->data);
    company->data->SalaryTree.remove(temp_emp->data);
    temp_emp->data->promote(SalaryIncrease,  BumpGrade);
    employee_salary_tree.insert(temp_emp->data);
    company->data->SalaryTree.insert(temp_emp->data);
//    company->data->updateEmployeeAfterChangedSalary(temp_emp->data);

}

void SalaryStat::HireEmployee(int EmployeeID, int NewCompanyID)
{
    if(NewCompanyID <= 0 || EmployeeID<= 0)
        throw invalid_input();
    Node<Employee>* temp_emp = employee_tree.find(Employee(EmployeeID));
    Node<Company>* temp_company = company_tree.find(Company(NewCompanyID));
    Node<Company>* last_company = temp_emp->data->company;
    if(last_company == nullptr)
    {
        temp_emp->data->company = temp_company;
    } else
    {
        if(last_company->data->id == temp_company->data->id)
            throw already_in_company();
        last_company->data->removeEmployeeFromCompany(temp_emp->data);
        if(last_company->data->isEmpty())
            n_e_company_tree.remove(temp_emp->data->company->data);
    }

    //the new company is now not empty
    if(temp_company->data->isEmpty())
        n_e_company_tree.insert(temp_company->data);
    temp_emp->data->hire(temp_company);
    temp_company->data->addEmployeeToCompany(temp_emp->data);

}

void SalaryStat::AcquireCompany(int AcquirerID, int TargetID, double Factor)
{
    if (AcquirerID<=0 || AcquirerID == TargetID || TargetID <= 0 || Factor<1)
    {
        throw invalid_input();
    }
    Node<Company>* acquirerComp = company_tree.find(AcquirerID);
    Node<Company>* targetComp = company_tree.find(TargetID);

    if ((targetComp->data->stock_value)*10 >  (acquirerComp->data->stock_value))
    {
        throw failure();
    }
    acquirerComp->data->mergeWith(*(targetComp->data), Factor);



    if(!targetComp->data->isEmpty())
    {
        n_e_company_tree.remove(targetComp->data);
    }

    if(!acquirerComp->data->isEmpty())
    {
        try{
            n_e_company_tree.insert(acquirerComp->data);
        }
        catch (already_in_tree&){}
    }

    updateCompany(acquirerComp->data->IdTree.root,acquirerComp);

    company_tree.remove(*targetComp->data);


}

void SalaryStat::GetHighestEarner(int CompanyID, int *EmployeeID) {
    if(EmployeeID == NULL || CompanyID == 0)
        throw invalid_input();
    if(CompanyID > 0)
    {
        GetHighestEarnerInCompany(CompanyID, EmployeeID);
    }else{
        GetHighestEarnerInTheSystem(EmployeeID);
    }
}

void SalaryStat::GetHighestEarnerInCompany(int CompanyID, int *EmployeeID ) {
    Node<Company>* company = company_tree.find(CompanyID);
    Employee* employee_ptr = company->data->getHeistEarner();
    *EmployeeID = employee_ptr->id;
}

void SalaryStat::GetHighestEarnerInTheSystem(int *EmployeeID) {
    if(employee_salary_tree.min_n == nullptr)
        throw not_in_tree();
    *EmployeeID = (*employee_salary_tree.min_n->data)->id;
}

void SalaryStat::GetAllEmployeesBySalary(int CompanyID, int **Employees, int*NumOfEmployees)
{
    if(Employees == NULL || CompanyID ==0 || NumOfEmployees== NULL)
    {
        throw invalid_input();
    }
    int* e_list = nullptr;
    if(CompanyID > 0)
    {
        Node<Company>* company = company_tree.find(CompanyID);
        e_list = company->data->getAllEmployeesBySalaryInCompany(NumOfEmployees);
    }

    else{
         e_list = GetAllEmployeesBySalaryInTheSystem(NumOfEmployees);
    }

    *Employees = e_list;
}

int* SalaryStat::GetAllEmployeesBySalaryInTheSystem(int *NumOfEmployees) {
    if(employee_salary_tree.size == 0)
    {
        throw failure();
    }
    *NumOfEmployees = employee_salary_tree.size;
    int* employee_arr = (int*)malloc(sizeof(int) * employee_tree.size);
    if(employee_arr == NULL)
    {
        throw std::bad_alloc();
    }
    Node<Employee*>* loc = employee_salary_tree.root;
    int i=0;
    GetAllEmployeesBySalaryInTheSystemAux(loc, employee_arr, i);
    return  employee_arr;
}

void SalaryStat::GetAllEmployeesBySalaryInTheSystemAux(Node<Employee *> *loc, int *employee_arr, int &i) {
    if(loc == nullptr)
    {
        return;
    }
    GetAllEmployeesBySalaryInTheSystemAux(loc->left, employee_arr, i);
    employee_arr[i] = (*loc->data)->id;
    i++;
    GetAllEmployeesBySalaryInTheSystemAux(loc->right, employee_arr, i);
}

void SalaryStat::GetHighestEarnerInEachCompany(int NumOfCompanies, int **Employees)
{
    if(Employees == NULL || NumOfCompanies < 1)
    {
        throw invalid_input();
    }

    if(NumOfCompanies > n_e_company_tree.size)
    {
        throw failure();
    }
    int* company_id_list = (int*)malloc(sizeof(int)* NumOfCompanies);
    if(company_id_list == NULL)
    {
        throw std::bad_alloc();
    }
    int i=0;
    GetHighestEarnerInEachCompanyAux(n_e_company_tree.root, company_id_list, i, NumOfCompanies);
//    Node<Company*>* last = loc;
//    while(i<NumOfCompanies)
//    {
//        company_id_list[i] = (*loc->data)->getHeistEarner()->id;
//        i++;
//        if(loc->right != nullptr)
//        {
//            last = loc;
//            loc = loc->right;
//            while(loc->left != nullptr)
//            {
//                last = loc;
//                loc = loc->left;
//            }
//        }else{
//            if(loc->parent == nullptr)
//                break;
//            while(loc->parent != nullptr)
//            {
//                last = loc;
//                loc = loc->parent;
//                if(loc->left == last)
//                {
//                    continue;
//                }
//            }
//        }
//
//    }

    *Employees = company_id_list;
}

void SalaryStat::GetHighestEarnerInEachCompanyAux(Node<Company *> *loc, int *arr, int &i, int NumOfCompanies) {
    if(i>=NumOfCompanies || loc == nullptr)
    {
        return;
    }

    GetHighestEarnerInEachCompanyAux(loc->left, arr, i , NumOfCompanies);
    if(i < NumOfCompanies)
    {
        arr[i] = (*loc->data)->getHeistEarner()->id;
        i++;
    }
    if(i <  NumOfCompanies)
    {
        GetHighestEarnerInEachCompanyAux(loc->right, arr, i , NumOfCompanies);
    }
}

void SalaryStat::GetNumEmployeesMatching(int CompanyID, int MinEmployeeID, int MaxEmployeeId, int MinSalary,
                                         int MinGrade, int *TotalNumOfEmployees, int *NumOfEmployees)
{
    if(TotalNumOfEmployees == NULL || CompanyID == 0 || NumOfEmployees == NULL 
                || MinEmployeeID < 0 || MaxEmployeeId < 0 || MinSalary < 0 
                || MinGrade < 0 || MinEmployeeID > MaxEmployeeId)
    {
        throw invalid_input();
    }

    if(CompanyID < 0 )
    {
        if(employee_tree.size == 0){
            throw failure();
        }
        GetNumEmployeesMatchingInTheSystem(MinEmployeeID, MaxEmployeeId, MinSalary,
                                                     MinGrade, TotalNumOfEmployees, NumOfEmployees);
    }
    else{
        Node<Company>* company = company_tree.find(CompanyID);
        if(company->data->isEmpty()){
            throw failure();
        }
        company->data->getNumEmployeesMatchingInCompany(MinEmployeeID, MaxEmployeeId, MinSalary,
                                                     MinGrade, TotalNumOfEmployees, NumOfEmployees);
    }
}


void SalaryStat::GetNumEmployeesMatchingInTheSystem(int MinEmployeeID, int MaxEmployeeId, int MinSalary,
                                                    int MinGrade, int* TotalNumOfEmployees, int* NumOfEmployees)
{
    *TotalNumOfEmployees = 0;
    *NumOfEmployees = 0;

    countInRange(MinEmployeeID, MaxEmployeeId, EmployeesMatchingInSystemCond(MinSalary,MinGrade), TotalNumOfEmployees
                                ,  NumOfEmployees, employee_tree.root);
}



void SalaryStat::countInRange(int min_employee, int max_employee, EmployeesMatchingInSystemCond cond,
                              int* total_num_of_employees, int* num_of_matching_employees, Node<Employee>* loc)
{
    if(loc == nullptr)
        return;

    if(loc->data->id > min_employee)
    {
        countInRange(min_employee,max_employee, cond, total_num_of_employees, num_of_matching_employees, loc->left);
    }

    if(loc->data->id <= max_employee && loc->data->id >= min_employee)
    {
        (*total_num_of_employees)++;
        if(cond(*(loc->data)))
        {
            (*num_of_matching_employees)++;
        }
    }

    if(loc->data->id < max_employee)
    {
        countInRange(min_employee,max_employee, cond, total_num_of_employees, num_of_matching_employees, loc->right);
    }
} 