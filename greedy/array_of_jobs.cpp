/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished
before the deadline. How to maximize total profit if only one job can be scheduled at a time.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    for(int i = 0; i < n; i++){
        cout << "Enter id, deadline and profit of job " << i+1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    sort(jobs.begin(), jobs.end(), cmp);
    int max_deadline = 0;
    for(int i = 0; i < n; i++){
        if(jobs[i].deadline > max_deadline){
            max_deadline = jobs[i].deadline;
        }
    }
    vector<int> result(max_deadline, -1);
    int count = 0;
    int profit = 0;
    for(int i = 0; i < n; i++){
        for(int j = jobs[i].deadline-1; j >= 0; j--){
            if(result[j] == -1){
                result[j] = jobs[i].id;
                count++;
                profit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Maximum profit is: " << profit << endl;
    cout << "Jobs scheduled are: ";
    for(int i = 0; i < max_deadline; i++){
        if(result[i] != -1){
            cout << result[i] << " ";
        }
    }
    cout << endl;
    return 0;
}