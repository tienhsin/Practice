#include<iostream>
#include<vector>

using namespace std;

void findCombo(vector<vector<int>> &combo, vector<double> &price, vector<int>& tmp, double money, int pos){
    
    if(money<0.0){
        return ;
    }

    if(money-0.0<=0.1){
        combo.push_back(tmp);
        return ;
    }

    if(pos==price.size()){
        return ;
    }
    
    tmp.push_back(pos);
    findCombo(combo, price, tmp, money-price[pos], pos+1);
    tmp.pop_back();
    findCombo(combo, price, tmp, money, pos+1);
    
}


int main(){
    
    vector<double> price{1.23, 2.33, 4.0, 0.99, 0.41};
    double money=5;
    vector<vector<int>> combo;
    vector<int> tmp;
    findCombo(combo, price, tmp, money, 0);

    for(int i=0;i<combo.size();i++){
        for(int j=0;j<combo[i].size();j++){
            cout<<combo[i][j]<<" ";
        }
        cout<<endl;
    }
}
