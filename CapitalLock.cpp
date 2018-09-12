#include<iostream>
#include<string>

using namespace std;

class CaptialLock{
public:
    string change(string in){
        string out;
        bool changable=false;

        for(char c:in){
            if(c=='a' || c=='A'){
                changable=~changable;
                continue;
            }
            if(changable) c=reverseCaptial(c);
            out.push_back(c);
        }

        return out;
    }

    char reverseCaptial(char c){
        if(c-'a'>=0 && c-'a'<26) 
            return toupper(c);
        else
            return tolower(c);
    }

};

int main(){
    CaptialLock str;
    cout<<str.change("RRRaYYIIAA") << endl;
}
