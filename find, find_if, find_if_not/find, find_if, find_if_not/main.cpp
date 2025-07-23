#include <iostream>
#include <algorithm>

using namespace std;

//алгоритмы поиска STL (find, find_if, find_if_not)

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
    
    vector<int> v = {6, 4, 4, 12, 1, 2, 7};
    
    auto result = find(v.begin(), v.end(), 12);   //первые два параметра - начало и конец коллекции, третий - то, что ищем, возвращает итератор, который указывает на найденный элемент
    
    //если ничего не находит, то возвращает указатель на последнюю переменную коллекции
    
    if(result == v.end()){
        cout << "-" << endl;
    }else{
        cout << "+" << endl;
    }
    
    auto result_1 = find_if(v.begin(), v.end(), [](int a){   //для find_if третий параметр не элемент, а предикат
        return a % 2 == 0;    //сделали предикат, проверяющий на четность
    });
    
    vector<Person> persons = {
        Person("Вася", 181),
        Person("Петя", 30),
        Person("Маша", 179),
        Person("Даша", 200),
        Person("Катя", 198),
        Person("Андрей", 181),
        Person("Сергей", 50),
        Person("Иван", 150),
    };
    
    auto result_2 = find_if(persons.begin(), persons.end(), [](const Person &p){
        return p.Name == "Маша" && p.Score == 50;    //можно искать по нескольким полям, использовать && || и так далее
    });
    
    return 0;
}
//find_if_not это просто инвертированный find_if

//недостаток: если в коллекции несколько элементов удовлетворяющих условию
