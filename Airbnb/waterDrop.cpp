/* 
 * in[4, 1, 2, 1, 1, 3]
 * water=4
 * pourAt=4
 *
 * x       
 * x w       x
 * x w x w w x
 * x x x x x x
 * 0 1 2 3 4 5
 * 
 *
 *
 */

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>,vector<int>);

void waterPour(vector<int> &in, int water, int pourAt){
    
    int n=in.size();
    vector<int> w(n,0);
    
    while(water){
        
        //find left
        int left=pourAt-1;
        while( left>-1 && (in[left]+w[left] <= in[left+1]+w[left+1]) ){
            left--;
        }
        /*
        if(left<pourAt-1){
            w[left+1]++;
            water--;
            continue;
        }
        */

        //find right
        int right=pourAt+1;
        while( right<in.size() && (in[right]+w[right] <= in[right-1]+w[right-1]) ){
            right++;
        }
        /*
        if(right>pourAt+1){
            w[right-1]++;
            water--;
            continue;
        }
        */
        
        int wall=min(in[0], in[n-1]);
        int leftH=in[left+1]+w[left+1];
        int rightH=in[right-1]+w[right-1];

        if(leftH<=rightH && leftH<wall){
            w[left+1]++;
        }else if(rightH<wall){
            w[right-1]++;
        }

        //w[pourAt]++;
        water--;

    }

    print(in, w);

}


void print(vector<int> in, vector<int> w){
    
    int maxHigh=0;
    for(int i=0;i<in.size();i++) 
        maxHigh=max(maxHigh, w[i]+in[i]); 
    
    while(maxHigh){
        for(int i=0;i<in.size();i++){
            int high=in[i]+w[i];
            if(maxHigh==high){
                if(w[i]>0){
                    cout<<"w ";
                    w[i]--;
                }else{
                    cout<<"x ";
                    in[i]--;
                }
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
        maxHigh--;
    }
}

int main(){
    vector<int> in{4,1,1,0,0,3};
    int water=30;
    int pourAt=3;

    waterPour(in, water, pourAt);

}
