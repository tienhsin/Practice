#include<iostream>

using namespace std;

class ReadNWrite{
private:
    int l=0, r=0, n;
    char *buff;
    
public:
    ReadNWrite(int n):n(n){
        buff = new char[n];
    }

    int read(char buf[], int n){
        int cnt=0;
        while(cnt<n && l!=r){
            l=(l+1)%n;
            buf[cnt]=buff[l];
        }
        return cnt;
    }

    int write(string s){
        int cnt=0;
        while(cnt<s.size() && (r+1)%n!=l ){
            r=(r+1)%n;
            buff[r]=s[cnt++];
        }
        return cnt;
    }
};
