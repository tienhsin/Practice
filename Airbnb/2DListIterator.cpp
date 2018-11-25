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
        vector<vector<int>>::iterator v, end, start;
        int j=-1;
        bool callNext=false;
    
    public:
        Vector2D(vector<vector<int>>& vec2d) {
            start=vec2d.begin();
            v=vec2d.begin();
            end=vec2d.end();

        }

        int next() {
            callNext=true;
            return (*v)[j];
        }

        bool hasNext() {

            callNext=false;
            
            j++;
            while(v!=end && j==(*v).size()){
                j=0;
                v++;
            }
            return v!=end;
        }
        
        //before remove, the next should be called
        void remove(){
            
            if(!callNext) throw "without call next";
            callNext=false;

            //remove item at position j
            (*v).erase((*v).begin()+j, (*v).begin()+j+1);
            
            //move j to previous item
            if(j==0){
                v--;
                j=(*v).size()-1;
                while(v!=start && j==-1){
                    v--;
                    j=(*v).size()-1;
                }
            }else{
                j--;
            }
        }

};

/**
 *  * Your Vector2D object will be instantiated and called as such:
 *   * Vector2D i(vec2d);
 *    * while (i.hasNext()) cout << i.next();
 *     */

int main(){
    
    vector<vector<int>> vec2d{{1,2,3,4},{},{},{8,9}};
    Vector2D m(vec2d);

    //for(int i=0;i<5;i++) 
    //    if(m.hasNext())
    //        cout<<m.next()<<" ";
    //cout<<endl;

    m.hasNext();
    m.next();
    m.remove();
    m.remove();
    m.hasNext();
    m.next();
    m.remove();
    //m.remove();
    
    Vector2D m2(vec2d);
    while(m2.hasNext())
        cout<<m2.next()<<" ";
    cout<<endl;

}
