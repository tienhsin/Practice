#include<iostream>

class mystring{
    public:
        mystring();
        ~mystring();
        mystring(const mystring&);
        mystring(const char*);

        char operator[](int);
        mystring& operator+=(char);
        mystring& operator+=(const mystring&);
        mystring& operator=(const mystring&);
        int size();

        void push_back(char);
        mystring substr(int, int);

    private:
        char *arr;
        int len, max_capacity;
        void alloc_new();
};

mystring operator + ( const mystring & a, const mystring & b  );

int mystring::size(){
    return len;
}

mystring operator + (const mystring &a, const mystring &b){
    mystring res=a;
    res+=b;
    return res;
}

mystring mystring::substr(int start, int slen){
    mystring sub;
    if(len-start<slen) return sub;
    for(int i=0;i<slen;i++){
        sub.push_back(arr[start+i]);
    }
    return sub;
}

mystring::mystring(){
    max_capacity=20;
    arr=new char[max_capacity];
    len=0;
}

mystring::mystring(const char* s){
    int slen=strlen(s);
    len=slen;
    max_capacity=slen;
    arr=new char[max_capacity];
    for(int i=0;i<len;i++){
        arr[i]=s[i];
    }
}

mystring::mystring(const mystring& s){
    max_capacity=s.max_capacity;
    len=s.len;
    arr=new char[max_capacity];
    for(int i=0;i<len;i++)
        arr[i]=s.arr[i];
}

mystring::~mystring(){
    delete[] arr;
    max_capacity=0;
    len=0;
}

char mystring::operator[](int i){
    return arr[i];
}

mystring& mystring::operator+=(char c){
    this->push_back(c);
    return *this;
}

mystring& mystring::operator+=(const mystring& s){
    for(int i=0;i<s.len;i++){
        this->push_back(s.arr[i]);
    }
    return *this;
}

mystring& mystring::operator=(const mystring& s){
    if(this!=&s){ 
        max_capacity=s.max_capacity;
        len=s.len;
        delete[] arr;
        arr=new char[max_capacity];
        for(int i=0;i<len;i++)
            arr[i]=s.arr[i];
    }
    return *this;
}

void mystring::push_back(char c){
    if(len+1>max_capacity)
        alloc_new();
    arr[len]=c;
    len++;
}

void mystring::alloc_new(){
    max_capacity*=2;
    char *tmp=new char[max_capacity];
    for(int i=0;i<len;i++){
        tmp[i]=arr[i];
    }
    delete[] arr;
    arr=tmp;
}


int main(){
    mystring s1;
    while(1){
        char tmp;
        std::cin>>tmp;
        if(tmp=='q') break;
        s1.push_back(tmp);
    }

    for(int i=0;i<s1.size();i++)
        std::cout<<s1[i]<<" ";
    std::cout<<std::endl;

    mystring s2=s1;

    s1+=s2;
    for(int i=0;i<s1.size();i++)
        std::cout<<s1[i]<<" ";
    std::cout<<std::endl;

    mystring s3("asdasdasd");
    for(int i=0;i<s3.size();i++)
        std::cout<<s3[i]<<" ";
    std::cout<<std::endl;
}
