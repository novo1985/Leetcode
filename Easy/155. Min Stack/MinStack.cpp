#include <iostream>
#include <stack>
using namespace std;

/*Design a stack that supports push, pop, top, and retrieving
the minimum element in constant time.*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> element;
    stack<int> mins;

    MinStack() {

    }

    void push(int x) {
      element.push(x);
      if(mins.empty() || x <= getMin()){
        mins.push(x);
      }
    }

    void pop() {
      if(element.top() == getMin()){ mins.pop();}
      element.pop();
    }

    int top() {
      return element.top();
    }

    int getMin() {
      return mins.top();
    }
};