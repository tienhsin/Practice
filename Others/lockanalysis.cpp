#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
#include<string>

using namespace std;

class SaftLocks{
    public:
        int checkLocks(vector<string>& events){
            
            stack<string> stk;
            unordered_set<string> locking;

            for(int i=0;i<events.size();i++){
                
                string id=events[i].substr(8);
                //cout << id << endl;

                if(events[i][0]=='A'){
                    stk.push(id);
                    if(locking.count(id))
                        return i+1;
                    locking.insert(id);
                    
                }else if(events[i][0]=='R'){
                    if(stk.empty() || stk.top()!=id)
                        return i+1;
                    stk.pop();
                    locking.erase(id);

                }
            }

            return stk.empty()?0:events.size()+1;

        }
};

int main(){
    SaftLocks item;
    vector<string> in1{"ACQUIRE 123", "ACQUIRE 12", "ACQUIRE 123", "RELEASE 1", "ACQUIRE 7"};
    cout << item.checkLocks(in1) << endl;
}
