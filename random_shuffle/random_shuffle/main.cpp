#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

//STL random_shuffle, отсортировать массив в случайном порядке

//работает со всеми контейнерами STL

class IAction
{
public:
    
    virtual void Action() = 0;
};

class CatAction : public IAction{
public:
    virtual void Action(){
        cout << "Гладим кота" << endl;
    }
};

class DogAction : public IAction{
public:
    virtual void Action(){
        cout << "Гуляем с собакой" << endl;
    }
};

class TeaAction : public IAction{
public:
    virtual void Action(){
        cout << "Пьем чай" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    srand(time(NULL));
    
    IAction* arr[] = {
        new CatAction(),
        new DogAction(),
        new TeaAction(),
    };
    
    //random_shuffle(begin(arr), end(arr));  //не работает в XCode, будет каждый раз при запуске программы запускать Action у наследников класса IAction в рандомном порядке
    
    for(auto &el : arr){
        el -> Action();
    }
    cout << endl;
    
    return 0;
}


