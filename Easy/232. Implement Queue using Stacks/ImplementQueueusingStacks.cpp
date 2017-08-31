#include <iostream>
#include <stack>
using namespace std;

/* Implement the following operations of a queue using stacks.
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.    ***********/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
      //stack1 only store the most earliest pushed element, of which size is <=1
      s1.push(x);
      while(s1.size()>1){
        s2.push(s1.top());
        s1.pop();
      }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int res = peek();
      s1.pop();
      return res;
    }

    /** Get the front element. */
    int peek() {
      if(s1.empty()){
        // we need push the front element of s2 into s1, which require rotate s2
        stack<int> rev_s2 = reversestack(s2);
        s1.push(rev_s2.top());
        rev_s2.pop();
        s2 = reversestack(rev_s2);
      }
      return s1.top();
    }

    stack<int> reversestack(stack<int> s){
      int n = s.size();
      if(n<=1) {return s;}
      stack<int> res;
      for(int i = 0; i < n; i++){
        res.push(s.top());
        s.pop();
      }
      return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return s1.empty() && s2.empty();
    }
private:
  stack<int> s1, s2;
};


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    // using two stacks: one for push, one for pop (reverse_relationship)
    void push(int x) {
      s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int res = peek();
      s2.pop();
      return res;
    }

    /** Get the front element. */
    int peek() {
      if(!s2.empty()) { return s2.top();}
      else{
        while(!s1.empty()){ // reverse s1 to s2
          s2.push(s1.top());
          s1.pop();
        }
      }
      return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return s1.empty() && s2.empty();
    }

private:
  stack<int> s1, s2;
};












