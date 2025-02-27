#include <iostream>
#include <chrono>  // for C++-style time measurement
//Алгоритмы работают при условии того, что такие индексы существуют!

void linear_search(int a[1000], int sum) { //Change!!!
    int first = 0, second = 1; //Указатели
    while (a[first] + a[second] != sum) {
        if (second + 1 != 1000){
            if (a[first] + a[second + 1] <= sum) {
                second++;
            }
            else{     
                first++;
            }
        }
        else {
            first++;
        }
    }
    std::cout << first << ' ' << second << '\n';
}

void complete_search(int a[1000], int sum) {//Change!!!
    int first = 0, second = 0;
    for (int i = 0; i < 1000; i++) { //Change!!!
        bool flag = true;
        for (int j = 0; j < 1000; j++) { //Change!!!
            if (a[i] + a[j] == sum) {
                first = i;
                second = j;
                flag = false;
            }
        }
        if (flag == false) {
            break;
        }
    }
    std::cout << first << ' ' << second << '\n';
}

int main()
{


    int a[1000]; //Change!!!
    for (int i = 1; i <= 1000; i++) { //Change!!!
        a[i - 1] = i;
    }
    int sum = 1999;





    auto begin1 = std::chrono::steady_clock::now();
    linear_search(a, sum);
    auto end1 = std::chrono::steady_clock::now();

    auto begin2 = std::chrono::steady_clock::now();
    complete_search(a, sum);
    auto end2 = std::chrono::steady_clock::now();



    auto time_linear_search = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    auto time_complete_search = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

    std::cout << time_linear_search.count() << " ns" << '\n';
    std::cout << time_complete_search.count() << " ns" << '\n';
    return 0;
}