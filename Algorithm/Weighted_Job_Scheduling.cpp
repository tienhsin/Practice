/*
 *
 * https://www.geeksforgeeks.org/weighted-job-scheduling/ 
 *
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct Job{
    int start;
    int end;
    int val;
    Job(int s, int e, int v):start(s), end(e), val(v){}
};

int findNext(vector<Job> &jobs, int cur){
    
    for(int i=cur-1;i>=0;i--){
        if(jobs[i].end <= jobs[cur].start)
            return i;
    }

    return -1;
}

//Time: O(n*2^n)
int findMaxProfitRec(vector<Job> &jobs, int cur){
    
    if(cur==0)
        return jobs[0].val;

    int next = findNext(jobs, cur);
    int incVal = jobs[cur].val;
    if(next!=-1) 
        incVal += findMaxProfitRec(jobs, next);

    int  exclVal = findMaxProfitRec(jobs, cur-1);
    
    return max(exclVal, incVal);

}


unordered_map<int, int> mem;

//Time: ? 
int findMaxProfitMem(vector<Job> &jobs, int cur){
    
    if(cur==0)
        return jobs[0].val;

    if(mem.count(cur))
        return mem[cur];

    int next = findNext(jobs, cur);
    int incVal = jobs[cur].val;
    if(next!=-1) 
        incVal += findMaxProfitRec(jobs, next);

    int  exclVal = findMaxProfitRec(jobs, cur-1);
    
    mem[cur] = max(exclVal, incVal);
    return mem[cur];

}

int findMaxProfit(vector<Job> jobs){
    
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.end < b.end;
    });

    int n=jobs.size()-1;

    return findMaxProfitMem(jobs, n);
}

int findMaxProfitDP(vector<Job> jobs){
    
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b){
        return a.end < b.end;
    });
    
    int n=jobs.size();
    vector<int> table(n,0);
    table[0]=jobs[0].val;

    for(int i=1;i<n;i++){

        int incVal = jobs[i].val;
        int next = findNext(jobs,i-1);
        if(next!=-1)
            incVal+=table[next];

        int exclVal = table[i-1];
        table[i] = max(exclVal, incVal);
    }
    
    int res = table[n-1];
    return res;
}

int main() 
{ 
    Job j1(3, 10, 20), j2(1, 2, 5), j3(6, 19, 100), j4(2, 100, 200);
    vector<Job> jobs{j1,j2,j3,j4};
    
    cout << "The optimal profit is " << findMaxProfitDP(jobs) << endl;
}
