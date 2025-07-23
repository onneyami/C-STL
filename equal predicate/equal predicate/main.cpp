#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

//equal predicate

class Point{
public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    int x, y;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<Point> arr {
        Point(1, 1),
        Point (4, 5),
        Point(5, 7)
    };
    
    vector<Point> arr_2 {
        Point(1, 1),
        Point (4, 5),
        Point(5, 7)
    };
    
    //сравниваем по анонимной функции, в которой перегружаем сравнение элементов класса Point
    bool result = equal(begin(arr), end(arr), begin(arr_2), end(arr_2), [](const Point &p1, const Point &p2){
        bool result = p1.x == p2.x && p1.y == p2.y; //поля x и y должны быть равны
        return result;
    });
    
    return 0;
}

