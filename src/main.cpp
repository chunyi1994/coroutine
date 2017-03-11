#include <iostream>
#include "coroutine.h"
using namespace std;
using namespace coroutine;
void func(Coroutine* s) {
    for (int i = 0; i <5; ++i) {
        cout<<"正在运行的id"<<s->id()<<":"<<i<<endl;
        s->yield();
    }
}

void func2(Coroutine* s) {
    for (int i = 0; i <15; ++i) {
        cout<<"正在运行的id"<<s->id()<<":"<<i<<endl;
        s->yield();
    }
}
int main()
{
    Schedule s;
    s.new_coroutine(func);
    s.new_coroutine(func2);

    while (!s.empty()) {
        s.resume_all();
    }

    cout << "Hello World!" << endl;
    return 0;
}

