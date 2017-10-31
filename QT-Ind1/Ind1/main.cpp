#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <iterator>
#include <ctime>
#include <fstream>
#include <string>

#include "dllist.h"
#include "set.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*srand((int) time(NULL));

    set<int> s;

    for(int i = 0; i < 5; ++i)
    {
        int n = rand() % 16;

        s.insert(n);

        std::cout << "Step #" << i + 1 << ". Inserting "
                  << n << ".\nSet: ";

        std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    s.insert(5);
    std::cout << "Step #6. Inserting 5.\nSet: ";
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    s.erase(5);
    std::cout << "Step #7. Deleting 5.\nSet: ";
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    set<int> k;
    k.insert(99);
    k.insert(5);
    std::cout << "Step #8. Creating another set with 99 and 5.\nSet: ";
    std::copy(k.begin(), k.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    s||k;
    std::cout << "Step #9. Union of sets.\nSet: ";
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    s&&k;
    std::cout << "Step #10. Intersection of sets.\nSet: ";
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    bool a1=s==k;
    std::cout << "Step #11. Is s=k?\nSet: ";
    std::cout << a1 << std::endl;

    bool a2=s!=k;
    std::cout << "Step #12. Is s!=k?\nSet: ";
    std::cout << a2 << std::endl;

    std::cout << k;

    set<int> m;
    std::cin >> m;
    std::cout << m;*/

    set<string> st1;
    ifstream fileIn1;
    fileIn1.open("doc1.txt");
    if(fileIn1.is_open())
    {
        string t;

        while(fileIn1 >> t)
        {
            st1.insert(t);
        }

    }
    fileIn1.close();

    set<string> st2;
    ifstream fileIn2;
    fileIn2.open("doc2.txt");
    if(fileIn2.is_open())
    {
        string t;

        while(fileIn2 >> t)
        {
            st2.insert(t);
        }

    }
    fileIn2.close();

    st1&&st2;
    cout << st1 << endl;

    return a.exec();
}
