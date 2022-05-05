//
// Created by lenovo on 19/04/2022.
//

#ifndef EX1_AVLTREEEXCEPTIONS_H
#define EX1_AVLTREEEXCEPTIONS_H
#include "exception"
class AvlTreeExceptions : std::exception{};
class not_in_tree : AvlTreeExceptions {};
class already_in_tree : AvlTreeExceptions{};
#endif //EX1_AVLTREEEXCEPTIONS_H
