//
// Created by lenovo on 22/04/2022.
//

#ifndef EX1_EX1EXCEPTIONS_H
#define EX1_EX1EXCEPTIONS_H
#include "exception"
class Ex1Exceptions : std::exception{};

class invalid_input : Ex1Exceptions{};

class bad_malloc: Ex1Exceptions{};

class already_in_company: Ex1Exceptions{};

class empty_company: Ex1Exceptions{};

class failure: Ex1Exceptions{};

class company_has_employees :Ex1Exceptions{};

#endif //EX1_EX1EXCEPTIONS_H
