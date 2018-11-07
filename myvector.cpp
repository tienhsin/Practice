#include<iostream>

using namespace std;

template<class T> 
class myVector{
    int vsize, max_capacity;
    T *array;
    void alloc_new();

    public:
    myVector();
    myVector(int);
    myVector(const myVector&); 
    ~myVector();

    void push_back(const T&);
    int size();
    T operator[](int);
    myVector& operator=(const myVector&);
    myVector& operator+=(const T&);

};

template<class T>
myVector<T>::myVector(){
    max_capacity=5;
    array=new T[max_capacity];
    vsize=0;
}

template<class T>
myVector<T>::myVector(int i){
    max_capacity=i;
    array=new T[max_capacity];
    vsize=0;
}

template<class T>
myVector<T>::myVector(const myVector& v){
    
    max_capacity=v.max_capacity;
    vsize=v.vsize;
    
    array=new T[max_capacity];
    for(int i=0;i<vsize;i++)
        array[i]=v.array[i];
}

template<class T>
myVector<T>::~myVector(){
    delete[] array;
}

template<class T>
void myVector<T>::push_back(const T& i){
    
    if(vsize+1>max_capacity){
        alloc_new();
    }
    array[vsize]=i;
    vsize++;
}

template<class T>
T myVector<T>::operator[](int i){
    return array[i];
}

template<class T>
void myVector<T>::alloc_new(){
    max_capacity=vsize*2;
    T* tmp=new T[max_capacity];
    for(int i=0;i<vsize;i++){
        tmp[i]=array[i];
    }
    delete[] array;
    array=tmp;
}

template<class T>
int myVector<T>::size(){
    return vsize;
}

template<class T>
myVector<T>& myVector<T>::operator=(const myVector& v){
    if(this!=&v){ //vec=vec
        vsize=v.vsize;
        max_capacity=v.max_capacity;
        delete[] array;
        array=new T[max_capacity];
        for(int i=0;i<vsize;i++){
            array[i]=v.array[i];
        }
    }
    return *this;
}

template<class T> 
myVector<T>& myVector<T>::operator+=(const T& v){
    this->push_back(v);
    return *this;
}

int main(){

    myVector<char> v;
    while(1){
        char tmp;
        cin>>tmp;
        if(tmp=='q') break;
        v.push_back(tmp);
    }

    for(int i=0;i<v.size();i++)
        cout<< v[i] << " ";

    cout<<endl;

    myVector<char> v2;
    v2=v;
    v2+='0';
    for(int i=0;i<v2.size();i++)
        cout<< v2[i] << " ";

    cout<<endl;
}
