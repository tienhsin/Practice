/**
 * Write a method to replace all spaces in a string with '%20'.
 * Assume that the string has sufficent space at the end to hold the additional characters.
 * The true length of string is given. 
 *
 * Ex. 
 * Input "abc abc    ", 7
 * Output "abc%20abc%20"
 *
 */

#include <iostream> 
#include <string>

using namespace std;

class URLify{
public:
    void replaceSpace(string& input, int len){
        int spaceCount=0;
        
        for(int i=0;i<len;i++){
            if(input[i]==' ') spaceCount++;
        }

        int index=len+spaceCount*2;
        input[index--]='\0';
        for(int i=len-1;i>=0;i--){
            if(input[i]==' '){
                input[index]='0';
                input[--index]='2';
                input[--index]='%';
            }else{
                input[index]=input[i];
            }
            --index;
        }
    }
};

int main(int argc, char **argv){
    
    URLify test;
    string in="abc abc abc       ";
    test.replaceSpace(in, 11);
    
    cout<<in<<endl;

    return 0;
}
