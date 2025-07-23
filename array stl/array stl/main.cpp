#include <iostream>
#include <array>

using namespace std;

//array STL

int main() {
    setlocale(LC_ALL, "RU");
    
    array<int, 4> arr = {1, 94, 77, 8};
    
    arr.at(0);
    
    return 0;
}
//по сути все преимущества этого контейнера над обычным статическим массивом - это наличие полезных методов, таких же как и у vector или list к примеру, также возможность использования for each, удобное использование try catch
