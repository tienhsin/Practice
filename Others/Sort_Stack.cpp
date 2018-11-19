/* Sort stack into increasing order.
 *
 * Ex.
 * Input stack {3,4,5,1,2,3}
 * Output {1,2,3,3,4,5}
 *
 */

#include<iostream>
#include<stack>
#include<vector>
#include<deque>

using namespace std;

class SortStack{
private:
    stack<int> input;
    stack<int> sorted;

public:
    SortStack(stack<int> input): input(input){
        while(!input.empty()){
            int tmp=input.top();
            input.pop();
            while(!sorted.empty() && sorted.top()<tmp){
                input.push(sorted.top());
                sorted.pop();
            }
            sorted.push(tmp);
        }    
    }

    int top(){
        return sorted.top();
    }

    void pop(){
        if(sorted.empty()){
            cout<<"Stack is empty!" <<endl;
            return;
        }
        sorted.pop();
    }

};


int main(){

    stack<int> s1;
    for(int i=0;i<=5;i++) s1.push(i);

    SortStack s2(s1);

    cout<<"s1: "<<s1.top()<<endl;
    s1.pop();

    cout<<"s2: " <<s2.top()<<endl;
    s2.pop();

    cout<<"s1: "<<s1.top()<<endl;
    s1.pop();

    cout<<"s2: "<<s2.top()<<endl;
    s2.pop();

    cout<<"s1: "<<s1.top()<<endl;
    s1.pop();

    cout<<"s2: "<<s2.top()<<endl;
    s2.pop();

}
