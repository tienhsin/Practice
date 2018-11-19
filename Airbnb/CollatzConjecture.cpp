/*
 * 题目是给你公式，比如偶数的话除 2，奇数的话就变成 3*n+1，对于任何一个正数，
 * 数学猜想是最 终他会变成 1。每变一步步数加 1，给一个上限，让找出范围内最长步数。
 *
 * 比如 7，变换到 1 是如下顺序:7->22->11->34->17->52->26->13->40->20->10->5->16->8->4->2->1, 
 * 总共需要 17 步
 *
 * https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=273149
 *
 */

#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int,int> mem;

int steps(int num){
    
    if(num==1) return 1;
    if(mem.count(num)) return mem[num];

    int res;
    
    if(num%2==0){
        res=steps(num/2)+1;
    }else{
        res=steps(num*3+1)+1;
    }
        
    mem[num]=res;
    return res;
}

int main(){
    cout<<steps(7)<<endl;
    cout<<steps(199919203)<<endl;
}
