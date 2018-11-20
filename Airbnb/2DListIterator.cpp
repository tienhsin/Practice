/*
 *
 *
 *
 */

#include<iostream>
#include<vector>

using namespace std;

class Vector2D {
    private:
        vector<vector<int>>::iterator v, end;
        int j=-1;
    
    public:
        Vector2D(vector<vector<int>>& vec2d) {
            v=vec2d.begin();
            end=vec2d.end();

        }

        int next() {
            return (*v)[j];
        }

        bool hasNext() {
            j++;
            while(v!=end && j==(*v).size()){
                j=0;
                v++;
            }
            return v!=end;
        }

        void remove(){
            /*while(j==0){
                v--;
                j=(*v).size()-1;
            }*/
            (*v).erase((*v).begin()+j, (*v).begin()+j+1);
            if(j!=0) j--;
        }

};

/**
 *  * Your Vector2D object will be instantiated and called as such:
 *   * Vector2D i(vec2d);
 *    * while (i.hasNext()) cout << i.next();
 *     */

int main(){
    
    vector<vector<int>> vec2d{{1,2,3,4},{5,6,7},{},{8,9}};
    Vector2D m(vec2d);

    for(int i=0;i<6;i++) 
        if(m.hasNext())
            cout<<m.next()<<" ";
    cout<<endl;

    m.remove();
    //m.remove();
    
    Vector2D m2(vec2d);
    while(m2.hasNext())
        cout<<m2.next()<<" ";
    cout<<endl;

}
