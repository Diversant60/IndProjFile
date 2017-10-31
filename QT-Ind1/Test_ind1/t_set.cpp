#include "t_set.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

set<int> t_set::get_test_set(){

    set<int> new_set;

    new_set.insert(1);
    new_set.insert(2);
    new_set.insert(4);
    new_set.insert(5);

    return new_set;
}


bool t_set::test_erase(bool f)
{
    set<int> p;

    if(f)
        p.insert(1);

    return p.erase(1);

}

bool t_set::test_insert(bool f, int a)
{
    set<int>  p;

    if(f){
    p=get_test_set();
    p.insert(a);
    if(find(p.begin(),p.end(),a)!=NULL)
        return true;
    return false;
    }
    else{
        p.insert(a);
        if(find(p.begin(),p.end(),a)!=NULL)
            return true;
        return false;
    }
}

bool t_set::test_empty(bool f)
{
    set<int> p;

    if(f)
        p.insert(1);

    return p.empty();
}

bool t_set::test_operator_combine(bool f)
{
    set<int> one, two;
    two=get_test_set();
    if(f)
        one.insert(6);
   one = one||two;

    if(f) {
        int array[5]={1, 2, 4, 5, 6};
        vector<int> result(array,array+5);
        return equal(one.begin(),one.end(), result.begin());
    }
   else{
        int array[4]={1, 2, 4, 5};
        vector<int> result(array,array+4);
        return equal(one.begin(),one.end(), result.begin());
    }
}

bool t_set::test_operator_intersection(bool f)
{
    set<int> one, two;
    two=get_test_set();
    if(f)
        one.insert(1);
    else
        one.insert(6);;
   one = one&&two;

    if(f) {
        int array[1]={1};
        vector<int> result(array,array+1);
        return equal(one.begin(),one.end(), result.begin());
    }
   else
        return !one.empty();
}

bool t_set::test_operator_add(int a)
{
     set<int> p;
     p=get_test_set();
     p|=a;

     int array[5]={1, 2, 4, 5, a};
     vector<int> result(array,array+5);
     return equal(p.begin(),p.end(), result.begin());
}

bool t_set::test_operator_eq(bool f)
{
    set<int> one, two;

    one=two=get_test_set();
    if(f)
        one|=7;

    return one==two;
}

bool t_set::test_operator_neq(bool f)
{
    set<int> one, two;

    one=two=get_test_set();
    if(f)
        one|=7;

    return one!=two;
}

bool t_set::test_operator_assign(bool f)
{
    set<int> one,two;
    if(f)
        two=get_test_set();
    one=two;
    return one==two;
}


bool t_set::test_operator_exclude(int a)
{

    set<int> one;

    one=get_test_set();

      one/=a;

      if(one.find(a)==NULL)
          return true;
      return false;

}



bool t_set::test_find(bool f)
{
    set<int> p;

    if(f)
       p.insert(1);

    if(p.find(1)!=NULL)
        return true;
    return false;

}
