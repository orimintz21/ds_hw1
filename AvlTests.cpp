//
// Created by lenovo on 24/04/2022.
//

#include <iostream>
#include "Node.h"
#include "AvlTree2.h"
#include "Company.h"
#include "Employee.h"
#include "ostream"
#include "AvlTreeExceptions.h"
#include "string"
class intComp
{
public:
    bool operator()(int a, int b)
    {
        return  a>b;
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

// int main()
// {
//     AvlTree<int,intComp> treea;
//     AvlTree<int, intComp> treeb;

//     treea.insert(3);
//     treea.insert(5);
//     treea.insert(13);
//     treea.insert(1);
//     treea.insert(6);
//     treea.insert(10);
//     treea.insert(32);

//     treeb.insert(4);
//     treeb.insert(66);
//     treeb.insert(2);
//     treeb.insert(100);
//     treeb.insert(33);
//     treeb.insert(11);
//     treeb.insert(14);

//     AvlTree<int, intComp> n_tree;
//     margeTrees(treea,treeb, n_tree);
//     n_tree.remove(11);

    

//     AvlTree<Employee, EmployeeComp> emptree;
//     AvlTree<Employee, EmployeeComp> emptree2;

//     Employee e1(1);
//     Employee e3(3);

//     emptree.insert(e1);
//     emptree.insert(Employee(2));
//     emptree.insert(Employee(3));
//     emptree.insert(Employee(5));
//     emptree.insert(Employee(11));


//     emptree2.insert(Employee(4));
//     emptree2.insert(114);
//     emptree2.insert(135);
//     AvlTree<Employee, EmployeeComp> n_e_tree;
//     margeTrees(emptree, emptree2, n_e_tree);
//     n_e_tree.remove(e3);


//     return 0;
// }