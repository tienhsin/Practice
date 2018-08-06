#include<iostream>
#include<vector>

using namespace std;

class Stacks{
public:
    Stacks(int numStacks, int capacity): numStacks(numStacks){
        
        stackTop.resize(numStacks, -1);
        stackData.resize(capacity, 0);
        for(int i=0;i<numStacks-1;i++) nextIndex.push_back(i+1);
        nextIndex.push_back(-1);

        nextAvailable=0;

    }

    int top(int stack_id){

        if(!isValidID(stack_id)) return -1;
        
        if(stackTop[stack_id]>=0){ 
            return stackData[stackTop[stack_id]]; 
        }else{
            return -1;
        }
    }
    
    void push(int stack_id, int num){
        
        if(!isValidID(stack_id)) return;
        
        if(nextAvailable>=0){

            int prev=stackTop[stack_id];
            int cur=nextAvailable;

            stackData[cur]=num;
            stackTop[stack_id]=cur;
            nextAvailable=nextIndex[cur];
            nextIndex[cur]=prev;

        }else{
            cout<<"Stack is full"<<endl;
        }
    }

    void pop(int stack_id){
        
        if(!isValidID(stack_id)) return;

        if(stackTop[stack_id]>=0){
            
            int cur=stackTop[stack_id];
            stackTop[stack_id]=nextIndex[cur];
            nextIndex[cur]=nextAvailable;
            nextAvailable=cur;
            
        }else{
            cout<< "Stack is empty!!"<<endl;
        }
    }


private:

    bool isValidID(int id){
        return id>=0 && id<numStacks;
    }

    vector<int> stackTop;
    vector<int> stackData;
    vector<int> nextIndex;
    
    int numStacks;
    int nextAvailable;    
};

int main(int argc, char **agrv){
    Stacks my_stk(3, 10);
    my_stk.push(1,1);
    my_stk.push(1,2);
    my_stk.push(2,5);
    cout << my_stk.top(1) << endl;
    my_stk.pop(1);
    cout << my_stk.top(2) << endl;
    my_stk.pop(2);
    cout << my_stk.top(2) << endl;
}
