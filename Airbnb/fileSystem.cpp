/*
 * compelete the create, get and set methods
 *
 * create("/a",1)
 * get("/a") => 1
 * create("/a/b",2)
 * get("/a/b") => 2
 * create("/c/d",1) => Error 因为它的上一级“/c”并不存在 get("/c") //Error,因为“/c”
 * set("/a/b", 10)
 * get("/a/b") => 10
 *
 * https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=215056&extra=&page=1
 */

#include<iostream>
#include<unordered_map>

using namespace std;

class fileSystem{
private:
    unordered_map<string, int> pathMap;

public:
    fileSystem(){
        pathMap[""]=0;
    }

    bool create(string path, int val){
        //path already be created
        if(pathMap.count(path))
            return false;
        
        //get name of previous path
        string prev;
        for(int i=path.size()-1;i>=0;i--){
            if(path[i]=='/'){
                prev=path.substr(0, i);
                break;
            }
        }
        
        //cannot find previous path
        if(pathMap.count(prev)==0)
            return false;

        pathMap[path] = val;
        return true;
    }

    int get(string path){
        if(!pathMap.count(path))
            return -1;
        return pathMap[path];
    }

    bool set(string path, int val){
        if(!pathMap.count(path))
            return false;
        pathMap[path] = val;
        return true;
    }

};


int main(){
    fileSystem F;
    cout<< F.create("/a", 1) <<endl;
    cout<< F.create("/a/b", 2) <<endl;
    cout<< F.create("/c/d", 3) <<endl;
    cout<< F.get("/a") <<endl;;
    cout<< F.get("/a/b") << endl;
}
