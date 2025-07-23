#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//STL unique удалить повторяющиеся элементы

int main() {
    setlocale(LC_ALL, "RU");
    
    int arr[] = {1, 2, 2, 2, 5, 4, 4};
    
    auto result = unique(begin(arr), end(arr));   //после обработки алгоритмом unique кол-во элементов не изменилось, а те, которые повторялись сдвинулись назад, возвращает итератор на первый ненужный элемент
    
    for_each(begin(arr), result, [](int a){cout << a << endl;});   //как конец коллекции ставим результат алгоритма unique, то-есть выводиться будут все элементы до ненужных
    
    //работает со всеми контейнерами STL
    
    vector<int> v = {1, 2, 2, 2, 5, 4, 4};
    
    auto result_1 = unique(begin(v), end(v));
    
    vector<int> v2;
    
    unique_copy(begin(v), end(v), back_inserter(v2));   //unique copy позволяет скопировать уникальные элементы в новую коллекцию
    
    v.erase(result_1, end(v));   //можно из вектора удалить все ненужные, сгруженные в конец алгоритмом unique, (от куда, до куда)
    
    return 0;
}


