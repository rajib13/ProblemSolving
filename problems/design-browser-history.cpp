class BrowserHistory {
public:
    vector<string> st;
    int pos = 0;
    BrowserHistory(string home) {
        st.push_back(home);
        pos = st.size();
    }
    
    void visit(string url) {
        if(st.size()  > pos) 
        {
            while(st.size() != pos) st.pop_back();
        }
        st.push_back(url);
        pos = st.size();
    }
    
    string back(int steps) {
        
        if(pos - steps <= 0) {pos = 1; return st[0];}
        pos -= steps;
        return st[pos-1];
    }
    
    string forward(int steps) {
        if(pos + steps >= st.size()) {pos = st.size(); return st[st.size()-1];}
        pos += steps;
        return st[pos-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
