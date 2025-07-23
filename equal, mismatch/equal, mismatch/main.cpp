#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

//equal, mismatch сравнение последовательностей (контейнеров)

int main() {
    setlocale(LC_ALL, "RU");
    
    int arr[] = {10, 3, 4, 5, 7, 11};
    
    int arr_2[] = {10, 3, 4, 5, 7, 11};
    
    auto result = equal(begin(arr), end(arr), begin(arr_2), end(arr_2));  //первые два параметра - начало и конец первой коллекции, третий параметр - начало и конец второй коллекции, equal() возвращает булевую переменную (true/false)
    
    cout << result << endl;
    
    vector<int> v = {10, 3, 4, 5, 7, 11};
    
    auto result_1 = equal(begin(arr), end(arr), begin(v), end(v));   //можно использовать equal для сравнения разных типов коллекций, как в нашем примере: вектор со статическим массивом
    
    //если у двух коллекций одни и те же элементы, но в разном порядке, то для equal эти коллекции будут разными, поэтому для сравнения на идентичность вне зависимости от порядка, используем сортировку перед сравнением
    
    auto result_2 = mismatch(begin(arr), end(arr), begin(v), end(v));  //mismatch в отличии от equal еще возвращает и пару итераторов на элементы, которые не совпадают
    
    
    //если все совпадает, то возвращает пару итераторов, которые будут указывать на конец коллекции
    if(result_2.first == end(arr) && result_2.second == end(v)){
        cout << "+" << endl;
    }else{
        cout << "-" << endl;
    }
    
    
    
    return 0;
}
