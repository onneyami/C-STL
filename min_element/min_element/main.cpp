#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

// алгоритм поиска наименьшего элемента STL

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<int> v = {10, 1, -55, 11, 13, 58};
    
    list<int> lst = {4, 7, 77, -3, 44, 74};
    
    auto result = min_element(v.begin(), v.end());     //два параметра по стандарту - начало и конец коллекции
    
    cout << *result << endl;  //при выводе разыменовываем, так как изначально result - это итератор
    
    auto result_1 = min_element(lst.begin(), lst.end());
    
    cout << *result_1 << endl;
    
    const int size = 6;
    int arr[size] = {10, 1, -55, 11, 13, 58};
    
    auto result_2 = min_element(arr, arr + size);   //используем арифметику указателей в случае с обычным массивом
    
    cout << *result_2 << endl;
    
    //гибридный метод, который ищет сразу мин и макс:
    vector<int> v_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    auto result_3 = minmax_element(v_1.begin(), v_1.end());   //возвращает пару значений
    
    cout << *result_3.first << "  " << *result_3.second << endl;   //при выводе обращаемся через first и second, так как опять же у нас пара значений в итераторе
    
    
    return 0;
}

