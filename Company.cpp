#include "Company.h"
#include <memory>
#include "ex1Exceptions.h"
#include "AvlTree2.h"



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
   employee_arr[*n_size] = (*((*loc).data))->id;
   (*n_size)++;
   getAllEmployeesBySalaryInCompanyAux(employee_arr,n_size,loc->right);
}




void Company::getNumEmployeesMatchingInCompany(int min_employee, int max_employee,
                                      int min_salary, int min_grade,
                                      int* total_num_of_employees, int* num_of_matching_employees)
{
    *total_num_of_employees = 0;
    *num_of_matching_employees = 0;

    countInRange(min_employee, max_employee, EmployeesMatchingInCompanyCond(min_salary,min_grade), total_num_of_employees
                                ,  num_of_matching_employees, IdTree.root);
}


void Company::countInRange(int min_employee, int max_employee, EmployeesMatchingInCompanyCond cond, int* total_num_of_employees, int* num_of_matching_employees, Node<Employee*>* loc)
{
    if(loc == nullptr)
        return;

    if((*(loc->data))->id > min_employee)
    {
        countInRange(min_employee,max_employee, cond, total_num_of_employees, num_of_matching_employees, loc->right);
    }

    if((*(loc->data))->id < max_employee)
    {
        countInRange(min_employee,max_employee, cond, total_num_of_employees, num_of_matching_employees, loc->left);
    }

    if((*(loc->data))->id < max_employee && (*(loc->data))->id > min_employee)
    {
        (*total_num_of_employees)++;
        if(cond(*(loc->data)))
        {
            (*num_of_matching_employees)++;
        }
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

void mergeCompanies(Company& acquirerComp, Company& targetComp, Company& mergedComp, double Factor)
{
    
    mergedComp.id = acquirerComp.id;
    mergedComp.stock_value = (int)((Factor)*(acquirerComp.stock_value + targetComp.stock_value));




}


template<class T, class Pred>
void storeInOrder( Node<T>* root, T arr[], int *ind)
{
    if( root == nullptr)
        return;

    storeInOrder<T,Pred>(root->left, arr, ind);

    arr[*ind] = *(root->data);
    (*ind)++;

    storeInOrder<T,Pred>(root->right, arr, ind);
}

template<class T, class Pred>
Node<T>* sortedArrayToRoot(T arr[], int start , int end)
{
    if(start > end)
        return nullptr;
    int mid = (int)((start+end)/2);
    Node<T> *root = newNode(arr[mid]);

    root->left = sortedArrayToRoot<T,Pred>(arr, start, mid-1);
    root->right = sortedArrayToRoot<T,Pred>(arr, mid+1 , end);

    calcNodeHeight(root);

    return  root;
}


template<class T, class Pred>
T* merge(T arr1[], T arr2[], int size1, int size2, T mergedArr[] ,Pred cond)
{
    int it1 = 0;
    int it2 = 0;
    int it3 = 0;
    while (it1 < size1 && it2 < size2)
    {
        if(cond(arr2[it2] , arr1[it1]))
        {
            mergedArr[it3] = arr1[it1];
            it1++;
        }
        else
        {
            mergedArr[it3] = arr2[it2];
            it2++;
        }
        it3++;
    }

    while ( it1 < size1)
    {
        mergedArr[it3] = arr1[it1];
        it1++;
        it3++;
    }

    while ( it2 < size2 )
    {
        mergedArr[it3] = arr2[it2];
        it2++;
        it3++;
    }

    return  mergedArr;
}

template<class T, class Pred>
Node<T>* margeNodes(Node<T>* root1, Node<T>* root2, int size1, int size2 , Pred cond)
{
    T *arr1 = new T[size1];
    int iter1 = 0;
    storeInOrder<T, Pred>(root1, arr1, &iter1);

    T *arr2 = new T[size2];
    int iter2 = 0;
    storeInOrder<T, Pred>(root2, arr2, &iter2);

    T *merged = new T[size1 +size2];
    merge(arr1, arr2, size1, size2, merged ,cond);
    delete[] arr1;
    delete[] arr2;
    Node<T>* n_root = sortedArrayToRoot<T,Pred> (merged, 0, size1 + size2 - 1);
    delete[] merged;
    return n_root;
}

template<class T, class Pred>
void margeTrees(AvlTree<T,Pred>& a, AvlTree<T,Pred>& b, AvlTree<T,Pred>& ab)
{
    ab.root = margeNodes(a.root, b.root, a.size, b.size, a.a_bigger_b);
    ab.setMin();
    ab.setMax();
    ab.size = b.size + a.size;
}





