#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

// алгоритм поиска наибольшего элемента STL

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<int> v = {10, 1, -55, 11, 13, 58};
    
    list<int> lst = {4, 7, 77, -3, 44, 74};
    
    auto result = max_element(v.begin(), v.end());     //два параметра по стандарту - начало и конец коллекции
    
    cout << *result << endl;  //при выводе разыменовываем, так как изначально result - это итератор
    
    auto result_1 = max_element(lst.begin(), lst.end());
    
    cout << *result_1 << endl;
    
    const int size = 6;
    int arr[size] = {10, 1, -55, 11, 13, 58};
    
    auto result_2 = max_element(arr, arr + size);   //используем арифметику указателей в случае с обычным массивом
    
    cout << *result_2 << endl;
    
    return 0;
}
