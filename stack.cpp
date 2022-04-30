//Questions 7.13, and 7.16.
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

const size_t CAPACITY = 100;

template <class T>
class stack { //element added (push) and removed (pop) from TOP/last end only.
private:
  size_t used;
  T data[CAPACITY];
public:
  std::size_t size_type;
  T value123;
  //const size_t CAPACITY = 100;
  void push(const T& item);
  void pop();
  void flip();

  size_t getUsed(){
    return used;
  }
  T getData(int i) {
    return data[i];
  }
  stack(){
    used=0;
  }
  bool empty() const {
    return (used==0);
  }
  size_t size() const {
    return used;
  }
  T top() const;
};  //if you are doing a stack with an array, just reverse the array123

template <class T>
std::ostream& operator<<(std::ostream& os, const stack<T>& item) { //overload

    os << item.getUsed()<<item.getData();

    return os;
}

template <class T>
void stack<T>::push(const T& item){
  assert(size()<CAPACITY);
  data[used]=item;
  ++used;
}

template <class T>
void stack<T>::pop(){
  assert(!empty());
  --used;
}

template<class T>
T stack<T>::top() const{
  assert(!empty());
  return data[used-1];
}

template<class T>
void stack<T>::flip(){  //question 7.16
  while(!empty()){
    int top123 = top(); //make a new variable for the top item in the stack
    pop();  //pop the top item.
    push(top123);  //pish the top item into an empty stack. how to put into code.
  }
}

template <class T>
bool isIdentical (stack<T> a, stack<T> b){ //question 7.13
  if(a.size()==b.size()){
    while(!a.empty()){
      if(a.top()==b.top()){
        a.pop();
        b.pop();   //use recursion?
      }
    }
    return true;
  }
  else{
    return false;
  }
}


int main(){
  stack<int> firststack;  //stack<int> firststack;
  stack<int> secondstack;  //stacl<int> secondstack;
  firststack.push(3);
  firststack.push(4);
  firststack.push(5);
  firststack.push(6);
  secondstack.push(3);
  secondstack.push(4);
  secondstack.push(5);
  secondstack.push(6);
  cout<<"0 means false (not identical), and 1 means true (they are identical)"<<endl;
  cout<<"The first and second stacks are: "<<isIdentical(firststack, secondstack)<<endl;
  //cout<<"First stack reversed is:"<<firststack.flip()<<endl;  //need output operator for stack
  //cout<<"Second stack reversed is:"<<secondstack.flip()<<endl;
}
