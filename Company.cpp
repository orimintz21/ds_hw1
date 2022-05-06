#include "Company.h"
#include <memory>
#include "ex1Exceptions.h"
#include "AvlTree.h"



Company::Company() : IdTree(), SalaryTree(),
                             id(-1), stock_value(0){}


Company::Company(int n_id) : IdTree(), SalaryTree(), id(n_id), stock_value(0){}



Company::Company(int n_id, int start_value) : IdTree(), SalaryTree(), id(n_id),
                            stock_value(start_value) {}

Employee* Company::getHeistEarner() {
    if(SalaryTree.min_n == nullptr)
        throw empty_company();
    return *((SalaryTree.min_n)->data);
}

bool Company::isEmpty() const {
    return (IdTree.size == 0);
}

int Company::getSize() const
{
    return IdTree.size;
}


void Company::addEmployeeToCompany(Employee* ptr_employee)
{
    try {
        IdTree.insert(ptr_employee);
    }
    catch (already_in_tree&)
    {
        throw already_in_company();
    }
    SalaryTree.insert(ptr_employee);
}


void Company::removeEmployeeFromCompany(Employee* fired)
{
    IdTree.remove(fired);
    SalaryTree.remove(fired);
}


void Company::increaseValue(int ValueIncrease)
{
    if(ValueIncrease <= 0)
        throw invalid_input();
    stock_value += ValueIncrease;
}

void Company::getInfo(int *value, int *num_of_employees_ptr) {
    *value = stock_value;
    *num_of_employees_ptr = getSize();
}


int* Company::getAllEmployeesBySalaryInCompany(int* n_size)
{
    if( getSize() == 0)
        throw failure();
   *n_size = getSize();
   
   int* employee_arr = (int*)malloc(sizeof(int) * getSize());
   if(employee_arr == NULL)
   {
       throw std::bad_alloc();
   }
   int ind = 0;
   getAllEmployeesBySalaryInCompanyAux(employee_arr, &ind, SalaryTree.root);
   return employee_arr;
}

void Company::getAllEmployeesBySalaryInCompanyAux(int* employee_arr,int* n_size, Node<Employee*>* loc) {
   if(loc == nullptr)
       return;
   getAllEmployeesBySalaryInCompanyAux(employee_arr,n_size,loc->left);
   employee_arr[*n_size] = (*(loc->data))->id;
   (*n_size)++;
   getAllEmployeesBySalaryInCompanyAux(employee_arr,n_size,loc->right);
}




void Company::getNumEmployeesMatchingInCompany(int min_employee, int max_employee,
                                      int min_salary, int min_grade,
                                      int* total_num_of_employees, int* num_of_matching_employees)
{
    *total_num_of_employees = 0;
    *num_of_matching_employees = 0;

    countInRange(min_employee, max_employee, EmployeesMatchingInCompanyCond(min_salary,min_grade),
                 total_num_of_employees,  num_of_matching_employees, IdTree.root);
}


void Company::countInRange(int min_employee, int max_employee, EmployeesMatchingInCompanyCond cond,
                           int* total_num_of_employees, int* num_of_matching_employees, Node<Employee*>* loc)
{
    if(loc == nullptr)
        return;

    if((*(loc->data))->id > min_employee)
    {
        countInRange(min_employee,max_employee, cond, total_num_of_employees, num_of_matching_employees, loc->left);
    }

    if((*(loc->data))->id <= max_employee && (*(loc->data))->id >= min_employee)
    {
        (*total_num_of_employees)++;
        if(cond(*(loc->data)))
        {
            (*num_of_matching_employees)++;
        }
    }

    if((*(loc->data))->id < max_employee)
    {
        countInRange(min_employee,max_employee, cond, total_num_of_employees, num_of_matching_employees, loc->right);
    }
}


void Company::updateEmployeeAfterChangedSalary(Employee *employee) {
    SalaryTree.remove(employee);
    SalaryTree.insert(employee);

}

void updateCompany(Node<Employee*>* emp, Node<Company>* comp)
{
    if (emp == nullptr)
        return;
    
    updateCompany(emp->left, comp);
    if((*emp->data)->company != comp)
    {
        (*emp->data)->company=comp;
    }

    updateCompany(emp->right, comp);

}

void Company::mergeWith(Company &target, double  Factor) {
    if(stock_value < 10 * target.stock_value)
        throw failure();

    stock_value = (int)((Factor)*(target.stock_value + stock_value));
    IdTree.merge(target.IdTree);
    target.IdTree.root = nullptr;
    SalaryTree.merge(target.SalaryTree);
    target.SalaryTree.root = nullptr;

}