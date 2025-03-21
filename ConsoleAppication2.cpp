#include <iostream>
#include "MyDateTime.h"
#include "Person.h"
#include "MyArray.h"

#define ARR_SIZE 10
#define DATE_ARR_SZIE 3

using namespace std;
MyDateTime MIN(MyDateTime* a, int n) {
    if (!n)
        return MyDateTime();
    MyDateTime m = MyDateTime(31, 12, 1<<31, 23, 59, 59);
    for (int i = 0; i < n; i++) {
        if (a[i] < m)
            m = a[i];
    }
    return m;
}

MyDateTime MAX(MyDateTime* a, int n) {
    if (!n)
        return MyDateTime();
    MyDateTime m = MyDateTime(0, 0, 0, 0, 0, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > m)
            m = a[i];
    }
    return m;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    MyDateTime today = MyDateTime(12, 02, 2026, 11, 30, 0);
    today.print();

    MyDateTime newTime;
    newTime.printInfo();

    MyDateTime anotherTime = MyDateTime(12, 02, 2025, 9, 29, 00);
    anotherTime.printInfo();

    MyDateTime anotherTime1 = MyDateTime(13, 02, 2025, 9, 29, 00);
    anotherTime.printInfo();

    anotherTime.compareTo(anotherTime1);

    //1 задание
    
    MyDateTime day;
    day.print();
    
    //2 задание
    
    MyDateTime newDay = day;
    newDay = day;

    cout << (today >= day) << endl;
    cout << (day >= today) << endl;
    cout << (day == day) << endl;
    cout << (day != day) << endl;
    cout << (day < today) << endl;
    
    //3 задание
    
    today++;
    today.print();

    MyDateTime today1 = MyDateTime(29, 12, 2025, 11, 30, 0);
    today1++.print();
    today1.print();

    //4 задание 
   
    MyDateTime newday = MyDateTime(12, 02, 2025, 11, 30, 0);
    MyDateTime newestday = MyDateTime(13, 02, 2024, 11, 30, 0);
    newday.print();
    newestday.print();

    newday = newday + newestday;
    newday.print();


    MyDateTime* a = new MyDateTime[5];
    a[0] = MyDateTime(10, 02, 2025, 8, 59, 0);
    a[1] = MyDateTime(11, 02, 2025, 9, 59, 0);
    a[2] = MyDateTime(12, 02, 2025, 10, 59, 0);
    a[3] = MyDateTime(13, 02, 2025, 11, 59, 0);
    a[4] = MyDateTime(14, 02, 2025, 12, 59, 0);

    MyDateTime c = MIN(a, 5);
    printf("1 задание: ");
    c.print();
    c = MAX(a, 5);
    c.print();

    MyDateTime DATA(10, 02, 2025, 8, 59, 0);
    cout << DATA;

    std::ofstream file("text.txt");
    if (!file.is_open())
    {
        return -1;
    }
    file << DATA.getday() << " " << DATA.getmonth() << " " << DATA.getyear() << " " << DATA.gethour() << " " << DATA.getmin() << " " << DATA.getsec() << endl;
    file.close();

    MyDateTime* dateArr = new MyDateTime[DATE_ARR_SZIE];
    dateArr[0] = MyDateTime(1, 1, 2025, 10, 00, 00);
    dateArr[1] = MyDateTime(1, 5, 2025, 10, 30, 00);
    dateArr[2] = MyDateTime(1, 1, 2025, 7, 30, 00);

    MyArray<MyDateTime> dateArrObj = MyArray<MyDateTime>(DATE_ARR_SZIE);
    dateArrObj[0] = MyDateTime(1, 1, 2025, 10, 00, 00);
    dateArrObj[1] = MyDateTime(1, 5, 2025, 10, 30, 00);
    dateArrObj[2] = MyDateTime(1, 1, 2025, 7, 30, 00);

    MyArray<int> myArr = MyArray<int>(6);
    myArr[0] = 1;
    myArr[1] = 5;
    myArr[2] = 7;
    myArr[3] = 4;
    myArr[4] = 2;
    myArr[5] = 6;

    cout << dateArrObj << endl;
    cout << myArr << endl;

    cout << myArr.max() << endl;
    cout << dateArrObj.max() << endl;

    cout << myArr.min() << endl;
    cout << dateArrObj.min() << endl;
    cout << endl << endl;
    myArr.reverse();
    cout << myArr;
}
