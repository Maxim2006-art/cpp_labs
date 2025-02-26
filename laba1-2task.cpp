#include <iostream>
#include <random>
#include <chrono> 
/*Комментарии :-)
int binary_search_cycle() - функция поиска элемента упорядоченного массива бинарным поиском, алгоритм реализован итеративно. Возращает индекс вхождения элемента или -1 в случае отсутствия элемента в массиве (значение хранится в переменной binary_search_cycle_index).
int binary_search_reduction() - функция поиска элемента упорядоченного массива бинарным поиском, алгоритм реализован рекурсивно. Возращает индекс вхождения элемента или -1 в случае отсутствия элемента в массиве (значение хранится в переменной binary_search_reduction_index).
int left, right - переменные, играющие роль указателей в бинарном поиске.
int ordinary_search() - функция поиска элемента упорядоченного массива обычным поиском, алгоритм реализован рекурсивно. Возращает индекс вхождения элемента или -1 в случае отсутствия элемента в массиве (значение храниться в переменной ordinary_search_index).
int random_values[50] - массив целых чисел, в котором хранятся 50 случайных величин (в пределах между min и max)
Комментарий //Change!!! стоит на тех строчках, в которых нужно менять данные, при смене размера массива.
time_span_АЛГОРИТМ_worst.count() - возвращает худшее время (если осуществляется поиск элемента вне массива) работы АЛГОРИТМА(binary_search_cycle, binary_search_reduction, или ordinary_search).
time_span_АЛГОРИТМ_average.count() - возвращает среднее время (среднее) работы АЛГОРИТМА.
*/
int binary_search_cycle(int a[1000], int n){ //Change!!!
    int left = -1, right = 999; //Change!!!
    while (left != right - 1){
        int i = (right - left)/2;
        if (a[left + i] < n){
            left = i + left;
        }
        else{
            right = i + left;
        }
    }
    if (a[right] == n){
        return right;
    }
    else{
        return -1;
    }
}

int binary_search_reduction(int a[1000], int n, int left, int right){ //Change!!!
    if (left == right - 1){
        if (a[right] == n){
            return right;
        }
        else{
            return -1;
        }
    }
    
    int i = (right - left)/2;
    
    if (a[left + i] < n){
        left = i + left;
    }
    else{
        right = i + left;
    }
    return binary_search_reduction(a, n, left, right);
}

int ordinary_search(int a[1000], int n){ //Change!!!
    for (int i = 0; i<1000; i++){ //Change!!!
        if (a[i] == n){
            return i;
        }
    }
    return -1;
}




int main() {
    
    //Создаём массив случайных величин.
    const int seed = 10101;
    std::default_random_engine engine(seed);
    
    const int min = 1, max = 1000;//Change!!!
    std::uniform_int_distribution<int> distribution(min, max);
    
    int random_values[50];
    for (unsigned i = 0; i < 50; ++i) {
        random_values[i] = distribution(engine);
    }
    
    
    //Создаём искомый массив.
    int a[1000]; //Change!!!
    for (int i = 1; i <= 1000; i++){ //Change!!!
        a[i-1] = i;
    }
    
    int n; //Число, вхождение которого в массив нас интересует
    int b, c, d; //переменные пустышки, нужны так как функция возвращает число, не хранят полезной информации.
    std::cin >> n;
    
    // Запишем результаты работы алгоритмов.
    int binary_search_cycle_index =0, binary_search_reduction_index = 0, ordinary_search_index = 0;
    binary_search_cycle_index = binary_search_cycle(a, n);
    binary_search_reduction_index = binary_search_reduction(a, n, -1, 999); //Change!!!
    ordinary_search_index = ordinary_search(a, n);
    
    
    
    // Найдём худшее время работы алгоритмов
    auto begin1 = std::chrono::steady_clock::now();
    d = binary_search_cycle(a, -1);
    auto end1 = std::chrono::steady_clock::now();
    auto time_span_binary_search_cycle_worst = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    
    auto begin2 = std::chrono::steady_clock::now();
    b = binary_search_reduction(a, -1, -1, 999); //Change!!!
    auto end2 = std::chrono::steady_clock::now();
    auto time_span_binary_search_reduction_worst = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    
    auto begin3 = std::chrono::steady_clock::now();
    c = ordinary_search(a, -1);
    auto end3 = std::chrono::steady_clock::now();
    auto time_span_ordinary_search_worst = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
    
    
    
    
    
    int time_span_ordinary_search_average = 0, time_span_binary_search_reduction_average = 0, time_span_binary_search_cycle_average = 0;
    //Найдём среднее время работы алгоритмов.
    for (int i = 0; i < 50; i++){
        auto begin_1 = std::chrono::steady_clock::now();
        d = binary_search_cycle(a, random_values[i]);
        auto end_1 = std::chrono::steady_clock::now();
        auto time_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_1 - begin_1);
    
        time_span_binary_search_cycle_average += time_1.count() / 50;
        
        auto begin_2 = std::chrono::steady_clock::now();
        b = binary_search_reduction(a, random_values[i], -1, 999); //Change!!!
        auto end_2 = std::chrono::steady_clock::now();
        auto time_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_2 - begin_2);
    
        time_span_binary_search_reduction_average += time_2.count() / 50;
    
        auto begin_3 = std::chrono::steady_clock::now();
        c = ordinary_search(a, random_values[i]);
        auto end_3 = std::chrono::steady_clock::now();
        auto time_3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_3 - begin_3);
        
        time_span_ordinary_search_average += time_3.count() / 50;
        
    }
    
    // Вывод результатов.
    std::cout << "Cycle_result: " << binary_search_cycle_index << "    "<<"Time_span_binary_search_cycle_worst: " 
    << time_span_binary_search_cycle_worst.count() << " ns" << "    "
    <<"Time_span_binary_search_cycle_average: " << time_span_binary_search_cycle_average << " ns" << '\n';
    
    std::cout << "Reduction_result: " << binary_search_reduction_index << "    " <<"Time_span_binary_search_reduction_worst: " 
    << time_span_binary_search_reduction_worst.count() << " ns" << "    "
    << "Time_span_binary_search_reduction_average: "<< time_span_binary_search_reduction_average << " ns" << '\n';
    
    std::cout << "Ordinary_result: " << ordinary_search_index << "    "<< "Time_span_ordinary_search_worst: " 
    << time_span_ordinary_search_worst.count() << " ns" << "    "
    << "Time_span_ordinary_search_average: " << time_span_ordinary_search_average <<" ns" << '\n';
    
    
}