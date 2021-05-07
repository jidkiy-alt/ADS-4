// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
private:
    T* arr;
    int size;
    int begin,
        end;
    int count;
    int goBack(int index)
    {
        int res = index++;
        if (res > size) res = 0;
        return res;
    }
    int goForward(int index)
    {
        int res = index--;
        if (res < 0) res = size;
        return res;
    }
public:
    TQueue(int = 100);
    ~TQueue();

    void push(const T&);
    T pop();       
    T get() const;    
    bool isEmpty() const; 
    bool isFull() const;
};

template<typename T>
TQueue<T>::TQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0)
{
    arr = new T[size + 1];
}

template<typename T>
TQueue<T>::~TQueue()
{
    delete[] arr;
}
//извините
template<typename T>
void TQueue<T>::push(const T& item)
{
    assert(count < size);
    int pos = end;
    while (begin != end && item.prior > arr[goBack(pos)].prior)
    {
        arr[pos] = arr[goBack(pos)];
        pos = goBack(pos);
    }
    arr[pos] = item;
    end = goForward(end);
    count++;
}
T pop() {
    assert(count > 0);
    T item = arr[begin];
    count--;
    begin = goForward(begin);
    return item;
}
// функция чтения элемента на первой позиции
template<typename T>
T TQueue<T>::get() const
{
    // проверяем, есть ли в очереди элементы
    assert( count > 0 );
    return arr[begin];
}

// функция проверки очереди на пустоту
template<typename T>
bool TQueue<T>::isEmpty() const
{
  return count==0;
}

// функция проверки очереди на заполненность
template<typename T>
bool TQueue<T>::isFull() const
{
  return count==size;
}

struct SYM {
	char ch;
	int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
