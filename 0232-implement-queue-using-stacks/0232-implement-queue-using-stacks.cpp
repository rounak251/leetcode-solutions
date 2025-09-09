class MyQueue {
public:stack<int>input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        if(input.empty()){
            cout<<"stack is empty";exit(0);
        }int val=input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        if(input.empty()){
            cout<<"stack is empty";exit(0);
        }int val=input.top();
        return val;
    }
    
    bool empty() {
        if(input.empty())return true;
        return false;
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