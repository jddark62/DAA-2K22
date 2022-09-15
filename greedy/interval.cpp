/*
The idea is we have a collection of jobs (tasks) to schedule on some
machine, and each job j has a given start time sj and a given finish time fj . If two jobs overlap, we
can’t schedule them both. Our goal is to schedule as many jobs as possible on our machine.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int start;
    int finish;
};

bool cmp(Job a, Job b){
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    for(int i = 0; i < n; i++){
        cout << "Enter start time and finish time of job " << i+1 << ": ";
        cin >> jobs[i].start >> jobs[i].finish;
    }
    sort(jobs.begin(), jobs.end(), cmp);
    int count = 1;
    int i = 0;
    for(int j = 1; j < n; j++){
        if(jobs[j].start >= jobs[i].finish){
            count++;
            i = j;
        }
    }
   cout << "Maximum number of jobs that can be scheduled is: " << count << endl;
   
    return 0;
}

