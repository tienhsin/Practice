/*
 *
 * Design a Queue with arrayList, 但是有限制条件, arraylist 的长度最多为 10, queue 不限制长度。
 * Implement pop and push methods
 * 
 * https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=279191&extra=&page=2
 *
 */

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int start;
    int end;
    vector<int> arr;
    Node *next;
    Node():start(0), end(0), next(nullptr){}
};

class myQueue{
    private:
        int arr_size;
        Node *head, *tail;

    public:
        myQueue(int n):arr_size(n){
            head=new Node();
            tail=head;
        }

        void push(int val){
            if(tail->end==arr_size){  //new node and update tail
                tail->next = new Node();
                tail=tail->next;
            }
            tail->arr.push_back(val);
            tail->end++;
        }

        int pop(){

            if(!head) return -1;

            if(head->start==head->end){
                Node* tmp=head;
                head=head->next;
                delete(tmp);
            }
    
            return head==nullptr?-1:head->arr[head->start++];
        }
};

int main(){

    myQueue q(3);
    q.push(1);
    q.push(2);   
    q.push(8);
    q.push(4);
    q.push(5);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

}

