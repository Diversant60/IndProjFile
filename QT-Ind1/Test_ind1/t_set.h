#ifndef T_SET_H
#define T_SET_H

#include "/home/student/Ind1/set.h"

class t_set
{
public:

    t_set(){}

    set<int> get_test_set();

    bool test_erase(bool);

    bool test_insert(bool, int);

    bool test_empty(bool);

    bool test_find(bool);

    bool test_operator_combine(bool);

    bool test_operator_intersection(bool);

    bool test_operator_add(int);

    bool test_operator_exclude(int);

    bool test_operator_eq(bool);

    bool test_operator_neq(bool);

    bool test_operator_assign(bool);

};

#endif // T_SET_H
