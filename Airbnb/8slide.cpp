#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<cstdlib>
using namespace std;


class Solution {
    public:
        int slidingPuzzle(vector<vector<int>>& board) {
            string goal="123456780";
            int Rows=3, Cols=3;

            string start;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    start.push_back(board[i][j]+'0');
                }
            }

            if(start==goal) 
                return 0;

            unordered_set<string> visited{start};
            queue<string> q;
            q.push(start);
            int steps=0;

            vector<pair<int,int>> dirt{{1,0},{-1,0},{0,1},{0,-1}};

            while(!q.empty()){
                steps++;
                int n=q.size();
                for(int i=0;i<n;i++){
                    string cur=q.front();
                    q.pop();
                    int p=cur.find('0');
                    int y=p/Cols;
                    int x=p%Cols;
                    for(int j=0;j<dirt.size();j++){
                        int dy=y+dirt[j].first;
                        int dx=x+dirt[j].second;
                        if(dy<0 || dx<0 || dy>=board.size() || dx>=board[0].size())
                            continue;
                        int pp=dy*Cols+dx;
                        string t=cur;
                        swap(t[p], t[pp]);
                        if(visited.count(t))
                            continue;
                        if(t==goal)
                            return steps;
                        visited.insert(t);
                        q.push(t);

                    }

                }

            }
            return -1;

        }
};

void shuffle(vector<vector<int>> &board){

    int Cols=board[0].size();
    int Rows=board.size();

    for(int i=0;i<9;i++){
        int r=rand()%9; //0-8
        int col=i%Cols;
        int row=i/Cols;
        int col2=r%Cols;
        int row2=r/Cols;
        swap(board[row][col], board[row2][col2]);
    }
}

int main(){
    Solution A;
    vector<vector<int>> board{{1,2,3},{4,5,6},{7,8,0}};
    shuffle(board);

    cout<<"original: "<<endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<A.slidingPuzzle(board)<<endl;
}
