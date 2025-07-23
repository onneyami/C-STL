#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <vector>

using namespace std;

//queue , priority queue (очередь и очередь с приоритетом, адаптеры контейнеров в STL)

int main() {
    setlocale(LC_ALL, "RU");
    
    queue<int, list<int>> q;     //чтобы выбрать оригинальный контейнер пишем также, как и в стеке (очередь может работать только с листом и деком)
    
    //q.back();   //показывает последний добавленный элемент
    
    //q.front();    //показывает первый добавленный элемент
    
    //q.swap()  //меняет значения у элементов
    
    q.push(4);
    q.push(7);
    q.push(5);
    q.push(1);
    
    auto a = q.__get_container();    //опять же с помощью a теперь можно обходить ограничения queue
    
    cout << q.back() << endl;     //получим 1
    cout << q.front() << endl;    //получим 4
    
    q.pop();    //извлечение первого элемента из очереди
    
    while(!q.empty()){    //пока элемент не пустой
        cout << q.front() << endl;   //выводим первый элемент
        q.pop();    //извлекаем первый элемент
        cout << "elements count: " << q.size() << endl;    //выводим размер очереди(колво элементов в ней)
    }
    cout << "elements count: " << q.size() << endl;
    
    priority_queue<int> pq;    //в основе очереди с приоритетом может стоять либо вектор, либо дек
    
    pq.push(56);
    
    pq.push(4);
    
    pq.push(7);
    
    pq.push(99);
    
    //в случае с очередью с приоритетом метода __get_container() нету, по умолчанию используется вектор
    
    //приоритет в очереди с приоритетом выставляется в случае с int от большего к меньшему
    
    while(!pq.empty()){   //пока не пусто
        cout << pq.top() << endl;    //выводим верхний
        pq.pop();     //извлекаем верхний
        cout << "elements count: " << pq.size() << endl;    //возвращаем кол-во элементов
    }
    cout << "elements count: " << pq.size() << endl;
    
    
    return 0;
}

//по аналогии со стеком очередь - это просто оболочка для контейнера, но в ней первый элемент который попадает первый и выходит
