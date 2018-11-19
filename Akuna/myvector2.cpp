#include<iostream>

using namespace std;

class myvector{
    public:
        myvector();
        myvector(int);
        myvector(const myvector&);
        ~myvector();
            
        void push_back(int);
        void pop_back();
        int operator[](int);
        myvector& operator=(const myvector&);
        myvector& operator+=(int);
        int front();
        int back();
        int size();

    private:
        int* array;
        int len, vsize;
        void alloc_new();
};

void myvector::alloc_new(){
    vsize*=2;
    int *tmp=new int[vsize];
    for(int i=0;i<len;i++){
        tmp[i]=array[i];
    }
    delete[] array;
    array=tmp;
}

myvector::myvector(){
    int vsize=20;
    array=new int[vsize];
    len=0;
}

myvector::myvector(int k){
    int vsize=k;
    array=new int[vsize];
    len=0;
}

myvector::myvector(const myvector& v){
    
    vsize=v.vsize;
    len=v.len;

    array=new int[vsize];
    for(int i=0;i<len;i++)
        array[i]=v.array[i];
}

myvector::~myvector(){
    delete[] array;
    len=0;
    vsize=0;
}

void myvector::push_back(int val){
    if(len+1>vsize){
        alloc_new();
    }
    array[len]=val;
    len++;
}

void myvector::pop_back(){
    if(len<0){
        return ;
    }
    len--;
}

int myvector::operator[](int i){
    return array[i];
}

myvector& myvector::operator=(const myvector& v){
    if(this!=&v){
        vsize=v.vsize;
        len=v.len;
        delete[] array;
        array=new int[vsize];
        for(int i=0;i<len;i++)
            array[i]=v.array[i];
    }
    return *this;
}

myvector& myvector::operator+=(int i){
    this->push_back(i);
    return *this;
}

int myvector::front(){
    return array[0];
}

int myvector::back(){
    return array[len-1];
}

int myvector::size(){
    return len;
}

int main(){

}


