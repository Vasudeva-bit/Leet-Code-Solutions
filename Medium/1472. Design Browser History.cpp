#include <bits/stdc++.h>
using namespace std;
// tags: Design, Doubly Linked List, struct
struct ListN {
    string url;
    ListN *forward;
    ListN *backward;
    ListN(string link, ListN *l, ListN *r): url(link), forward(r), backward(l) {}
};
class BrowserHistory {
public:
    ListN *cur = NULL;
    BrowserHistory(string homepage) {
        cur = new ListN(homepage, NULL, NULL);
    }
    
    void visit(string url) {
        cur->forward = new ListN(url, cur, NULL);
        cur = cur->forward;
    }
    
    string back(int steps) {
        while(cur->backward != NULL and steps--) {
            cur = cur->backward;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while(cur->forward != NULL and steps--) {
            cur = cur->forward;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */