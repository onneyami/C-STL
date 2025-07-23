#include <iostream>
#include <vector>
#include <set>

using namespace std;

//SET и MULTISET в STL (ассоциативные контейнеры)

//сет и мультисет основаны на бинарном дереве

//в сете все хранится упорядоченно и изменять в нем элементы нельзя, также все экземпляры хранятся только в одном кол-ве, то-есть повторных быть не может

int main() {
    setlocale(LC_ALL, "RU");
    
    set<int> mySet;
    
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(1);
    mySet.insert(-3);
    
    for(auto &item : mySet){
        cout << item << endl;
    }
    
    int value;
    
    cin >> value;
    
    if(mySet.find(value) != mySet.end()){
        cout << "Число присутствует." << endl;
    }else{
        cout << "Число отсутствует." << endl;
    }
    
    mySet.erase(5);
    
    multiset<int> myMultiset = {1, 1, 66, 66, 32, 7};
    
    for(auto &item : myMultiset){
        cout << item << endl;
    }
    
    auto it_1 = myMultiset.lower_bound(1);    //возвращает 1
    
    auto it_2 = myMultiset.upper_bound(1);  //возвращает 7
    
    auto a = myMultiset.equal_range(1);    //возвращает диапазон чисел от lower_bound до upper_bound, в нашем случае это 1 и 7
    
    return 0;
}

//в insert и erase ставим конкретно значение элемента, а не итератор или что-то подобное, если попытаемся удалить элемент, которого нет, то ничего не произойдет


//отличие мультисета от сета в том, что он может хранить несколько одинаковых значений
