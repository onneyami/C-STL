#include <iostream>
#include <algorithm>

using namespace std;

//алгоритм for_each, отличие от цикла for_each

//разница в синтаксисе и в особенностях использования

void Foo(int a){
    cout << a << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    int arr[] = {1, 2, 10, 55};
    
    for_each(begin(arr), end(arr), Foo);    //два параметра - начало и конец коллекции, третий параметр - функция или анонимная функция, которая и будет выполняться для каждого элемента коллекции
    
    //тоже самое, но через цикл for each
    for(auto a : arr){
        Foo(a);
    }
    
    //алгоритм for_each может работать с анонимными функциями
    for_each(begin(arr), end(arr), [](int a){
        cout << a << endl;
    });
    
    for(auto a : arr){
        cout << a << endl;
    }
    
    //главное отличие от цикла for each в том, что алгоритм при работе с анонимной функцией может принимать параметры как по значению, так и по ссылке (это функционал анонимной функции)
    
    return 0;
}
