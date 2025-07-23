#include <iostream>
#include <algorithm>   //директива для подключения stl алгоритмов
#include <vector>
#include <string>

using namespace std;

//Алгоритмы сортировки STL, бинарный предикат, лямбда функции

bool GreaterThanZero(int a){return a > 0;}

/*bool MyPredicat(int a, int b){     //сравнивает два входящих параметра, бинарный предикат, так как принимает два параметра
    return a > b;
}*/

bool LessThanZero(int a){return a < 0;}

class Person
{
public:
    Person(string name, double score){
        this->Name = name;
        this->Score = score;
    }
    bool operator()(const Person &p){
        return p.Score > 180;
    }
    
public:
    string Name;
    double Score;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<int> v = {9, 4, 94, 6, 1, 3, 7};

    //sort(v.begin(), v.end());     //указываем начало и конец коллекции, изначально sort() расставит числа от меньшего к большему, но можно сортировать другим образом
    //sort(v.begin(), v.end(), MyPredicat);
    
    sort(v.begin(), v.end(), [](int a, int b){return a > b;});  //используем анонимную функцию, так как она больше нигде использоваться не будет, в этом случае сортировка от большего к меньшему
    for(auto el : v){
        cout << el << endl;
    }
    
    const int size = 7;
    int arr[size] = {9, 4, 94, 6, 1, 3, 7};
    sort(arr, arr+size, [](int a, int b){return a > b;});   //если обычный массив, то передаем первым параметром имя массива, так как оно является указателем на начало, а конец с помощью арифметики указателей имя массива + его размер
    
    for(auto el : arr){
        cout << el << endl;
    }
    
    vector<Person> people
    {
        Person("Вася", 181),
        Person("Петя", 30),
        Person("Маша", 179),
        Person("Иван", 201),
        Person("Алексей", 177)
    };
   
    sort(people.begin(), people.end(), [](const Person &p1, const Person &p2){   //используем анонимную функцию
        //так как у класса string уже есть перегрузка оператора > мы можем писать так просто
        return p1.Name < p2.Name;   //сортируем от А до Я, можно и наоборот если поменять знак
    });   //точно также можно отсортировать и по баллам, а не по именам, просто заменим p1.Name и p2.Name на p1.Score и p2.Score соответственно
    
    for(auto el : people){
        cout << "Имя:\t " << el.Name << "\tбаллы:\t " << el.Score << endl;
    }
    
    return 0;
}


