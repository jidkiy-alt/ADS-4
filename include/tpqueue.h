#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
   private:
T* arr;
int size;
int begin, end;
int count;
  
   public:
TPQueue(): size(100), begin(0), end(0), count(0) {
  arr = new T[size + 1];
}
~TPQueue() {
  delete[] arr;
}
void push(const t& item) {
  assert(count < size);
  int i = end;
  if (count) {
    while (i >= 1 && arr[i-1].prior < item.prior) {
      i--;
    }
    for (int l = end - 1; l >= i; l--) {
      arr[k + 1] = arr[k];
    }
    arr[i] = item;
  } else {
    arr[end] = item;
  }
  count++;
  end++;
  if (end > size) {
    end -= size + 1;
  }
}
T pop() {
  assert(count > 0);
  T item = arr[begin++];
  count--;
  if (begin > size) {
    begin -= size + 1;
  }
  return item;
}
T get() const {
  assert(count > 0);
  return arr[begin];
}
bool isEmpty() const {
  return count == 0;
}
bool isFull() const {
  return count == size;
}
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
