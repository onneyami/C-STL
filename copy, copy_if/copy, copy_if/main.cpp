#include <iostream>
#include <algorithm>

using namespace std;

//выборка данных по условию, STL copy, copy_if

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
    
    vector<Person> result;
    
    copy(persons.begin(), persons.end(), back_inserter(result));  //первый и второй параметры - как обычно начало и конец копируемой коллекции, а третий - обязательно при помощи back_inserter(название коллекции в которую копируем)
    
    vector<Person> result_1;
    copy_if(persons.begin(), persons.end(), back_inserter(result_1), [](Person &p){return p.Score > 180;});
    
    for(auto el : result_1){
        cout << el.Name << "  " << el.Score << endl;
    }
    
    return 0;
}

//copy_if в отличии от простого copy может использовать предикат - то-есть копировать с условиями
