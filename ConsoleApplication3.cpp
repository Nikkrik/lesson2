#include <iostream>
#include"MyList.h"
using namespace std;

int main()
{
    int k = 1;
    int n = 2;
    MyList<int>list1 = MyList<int>(k);
    MyList<int>list2 = MyList<int>(n);
    list1.add(0);
    list1.add(1);
    list1.add(2);
    list1.add(3);
    cout << list1 << endl;
    
    list2.add(1);
    list2.add(2);
    list2.add(3);
    list1.addListBack(list2);
    cout << list1;
}


