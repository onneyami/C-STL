#include <iostream>
#include <vector> //обязательно для использования вектора
using namespace std;

//Вектор

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<int> myVector;
    myVector.push_back(3);
    myVector.push_back(5);
    myVector.push_back(44);
    
    myVector.reserve(10);        //reserve() выдает вектору количество capacity по сути
    
    myVector.shrink_to_fit();    //автоматически очищает все пустые ячейки, то-есть capacity = size
    
    cout << myVector.empty() << endl;   //empty() проверяет на пустоту вектора

    myVector[0] = 1000;
    
    cout << myVector.at(0) << endl;      //at в векторе - это по сути как [] в массиве, но, в отличии от [] метод at() проверяет перед тем, как получить доступ к элементу вектора границы этого вектора
    
    //но почему не стоит использовать метод at() вместо [] всегда? всё из-за того, что он в разы медленнее и нагружает систему
    
    cout << "Количество элементов в векторе: " << myVector.size() << endl;
    
    cout << "Capacity вектора: " << myVector.capacity() << endl;
    
    //capacity отличается от size тем, что size показывает по сути, сколько занятых ячеек в векторе, а capacity абсолютно все
    
    myVector.pop_back();
    
    cout << "Количество элементов в векторе: " << myVector.size() << endl;
    
    for(int i = 0; i < myVector.size(); i++){
        cout << myVector[i] << endl;
    }
    
    myVector.clear();      //метод для очищения вектора от всех элементов
    
    return 0;
}
