#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>    //директива для алгоритма accumulate
#include <string>

using namespace std;

//accumulate - сумма и произведение элементов массива

int main() {
    setlocale(LC_ALL, "RU");
    
    int v[] = {2, 3, 4};
    
    auto result = accumulate(begin(v), end(v),  0);    //первые два параметра как обычно - начало и конец коллекции, третий параметр - к какому значению будут добавлятся элементы, для чистой суммы это 0
    
    cout << "Result: " << result << endl;
    
    //сделаем реализацию для умножения
    auto result_1 = accumulate(begin(v), end(v), 1, [](int a, int b){  //третий параметр - изначальное значение, к которому прибавляем (умножаем) остальные элементы, четвертый - анонимная функция, которая возвращает произведение пары чисел
        return a*b;
    });
    
    cout << "Result_1: " << result_1 << endl;
    
    //сумма четных элементов
    auto result_2 = accumulate(begin(v), end(v), 0, [](int a, int b){
        if(b%2 == 0){   //если следующее число четное, то
            return a + b;   //возвращаем сумму с предыдущим
        }else{
            return a;    //возвращаем просто предыдущее
        }
    });
    
    cout << "Result_2: " << result_2 << endl;
    
    //сделать конвертацию чисел в строки
    auto result_3 = accumulate(next(begin(v)), end(v), to_string(v[0]), [](string a, int b){  //в зависимости от типа третьего параметра алгоритм accumulate выбирает тип возвращаемого параметра, в нашем случае это первый элемент коллекции, конвертированный в строку
        return a + " " +to_string(b);
    });// в данном случае будет лишняя двойка в начале, поэтому вместо просто begin(v), указываем next(begin(v))
    
    
    return 0;
}
