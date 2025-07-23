#include <iostream>
#include <vector>
#include <list>

using namespace std;

//префиксное и постфиксное написание с итераторами stl

template<typename T>
void printList(const list<T> &lst){
    for(auto i = lst.cbegin(); i != lst.cend(); ++i){
        cout << *i << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    
    list<int>::iterator it;
    
    it++;
    
    ++it;
    
    return 0;
}
