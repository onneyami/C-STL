#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//remove, remove_if в STL (удаление элементов из текущей коллекции)

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
    
    vector<int> v = {9, 5, 1, 46, 4, 9, 4};
    
    auto result = remove(v.begin(), v.end(), 9);     //первый два параметра - стандартно начало и конец коллекции, третий параметр - удаляемый элемент
    
    //на самом деле ничего не удаляет, берет элементы, которые удовлетворяют условию записывает в конец вектора (которые нужно убрать), затем возвращает итератор указывающий на последний не исключенный элемент
    
    v.erase(result, v.end());   //для удаления - используем erase и передаем итератор полученный из remove, второй параметр - конец коллекции
    
    vector<Person> persons{
        Person("Вася", 181),
        Person("Петя", 30),
        Person("Маша", 179),
        Person("Иван", 201),
        Person("Алексей", 177)
    };
    
    /*auto result_1 = remove_if(persons.begin(), persons.end(), [](Person &p){
        return p.Score < 180;      //исключаем всех абитуриентов с баллом ниже 180
    });   //первый два параметра - начало и конец коллекции, третий - предикат
    */
    
    persons.erase(remove_if(persons.begin(), persons.end(), [](Person &p){
        return p.Score < 180;
    }), persons.end());   //можно сразу в erase передать всю конструкцию remove_if вместо отдельной переменной
    
    for(auto el : persons){
        cout << el.Name << "  " << el.Score << "  " << endl;
    }
    
    return 0;
}
//разница между remove и remove_if такая же, как и в sort, sort_if
