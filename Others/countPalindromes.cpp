#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int extend(string &s, int start, int end ){
    
    int count=0;
        
    while(start>=0 && end<s.size()){
        if(s[start--]!=s[end++]){
            break;
        } 
        count++;
    }

    return count;

}


int countPalindromes(string s){
    
    int sum=0;

    for(int i=0;i<s.size();i++){
        sum+=extend(s, i-1, i);
        sum+=extend(s, i, i);
    }

    return sum;
}

int main(){
    
    cout << countPalindromes("hellolle") << endl;
    cout << countPalindromes("wowpurerocks") << endl;

}
