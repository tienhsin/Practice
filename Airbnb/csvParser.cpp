#include <iostream>
#include <sstream>

using namespace std;


class myClass{ 
private:
    
    enum State{
        START,
        QUOTE_LESS,
        QUOTE_START,
        QUOTE_IN_QUOTE
    };

public:  
/*    void csvParser(string in){
        
        stringstream ss(in);
        string token;
        stringstream out;

        while(getline(ss, token, ',')){
            out<<token<<"|";
        }

        cout<< out.str()<<endl;
    }
*/

    void csvParser(string in){
        
        State state=START;
        string out;

        for(int i=0;i<in.size();i++){
            char ch=in[i];

            if(state==START){
                if(ch=='\"'){
                    state=QUOTE_START;
                    continue;
                }else{
                    state=QUOTE_LESS;
                }
            }else if(state==QUOTE_LESS){
                if(ch=='\n'){
                    state=START;
                }else if(ch==','){
                    state=START;
                    ch='|';
                }else if(ch=='\"'){
                    error(ch);
                }
            }else if(state==QUOTE_START){
                if(ch=='\"'){
                    state=QUOTE_IN_QUOTE;
                    continue;
                }

            }else if(state==QUOTE_IN_QUOTE){
                if(ch=='\"'){
                    state=QUOTE_START;
                }else if(ch==','){
                    state=START;
                    ch='|';
                }else{
                    error(ch);
                    break;
                }
            }

            out.push_back(ch);
        }

        cout<<out<<endl;
    }

    void error(char ch){
        cout<<"error at: "<<ch<<endl;
    }

};

int main(){

    myClass A;
    //A.csvParser("John,Smith,john.smith@gmail.com,Los Angeles,1");
    //A.csvParser("Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0\n\"\"\"Alex\"\"\",100\n\"Alexandra \"\"Alex\"\"\"");
    
    string in;
    int count=3;
    while(count-->0){
        getline(cin, in);
        A.csvParser(in);
    }
}
