// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

template<typename T>
class queue {
    int top;
    size_t memSize;
    T* pMem;
public:
    //stack(T val):top(-1),memSize((sizeof T)*val),pMem(new T[memSize]){};
    queue(size_t _memSize) :top(-1), memSize(_memSize), pMem(new T[memSize]) {};
    ~queue() { delete[] pMem; pMem = nullptr; }
    size_t size()               const { return top + 1; }
    bool IsEmpty()              const { return top == -1; }
    bool IsFull()               const { return top == memSize - 1; }
    T Pop() { 
        T temp=pMem[0];
        top--;
        for (T i = 0; i < top+1;i++) {
            pMem[i]=pMem[i+1];
        }
        return temp;
    }
    void Push(const T& val) {
        if (top == memSize - 1) {
            T* tmpMem = new T[memSize * 2];
            std::copy(pMem, pMem + memSize, tmpMem);
            delete[] pMem;
            pMem = tmpMem;
            memSize *= 2;
        }

        pMem[++top] = val;
    }
    void Print() {
        for (int i = 0; i <= top; i++) {
            std::cout << pMem[i] << ' ';
        }
    }
};

int main()
{
    //std::cout << "Enter 10 numbers\n";
    queue<int> q(10);
    for (int i = 0; i < 10; i++) {
        q.Push(i);
    }
    q.Print();
    std::cout << std::endl << "size " << q.size();
    std::cout << std::endl << "Is Full? " << q.IsFull();
    std::cout << std::endl << "Is Empty? " << q.IsEmpty();
    std::cout << std::endl << "Pop " << q.Pop();
    std::cout<<std::endl;
    q.Print();
    std::cout << std::endl << "size " << q.size();
    std::cout << std::endl << "Is Full? " << q.IsFull();
    std::cout << std::endl << "Is Empty? " << q.IsEmpty();
}