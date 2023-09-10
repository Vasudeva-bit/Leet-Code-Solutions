#include "bits/stdc++.h"
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> h;
    MyQueue() {}
    
    void push(int x) {
        while(!st.empty()) {
            h.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!h.empty()) {
            st.push(h.top());
            h.pop();
        }
    }
    
    int pop() {
        int out = st.top();
        st.pop();
        return out;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */