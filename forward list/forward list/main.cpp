#include <iostream>
#include <forward_list>

using namespace std;

//forward_list в STL

int main() {
    setlocale(LC_ALL, "RU");
    
    forward_list<int> fl = {133, 443, 853};
    
    forward_list<int>::iterator it = fl.begin();
    
    fl.insert_after(it, 9999);
    
    cout << *it << endl;
    
    for(auto el : fl){cout << el << endl;}
    
    return 0;
}

//по сути просто реализация односвязного списка
