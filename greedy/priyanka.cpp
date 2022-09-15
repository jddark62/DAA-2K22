/*
Little Priyanka visited a kids' shop. There are N toys and their weight is represented by an array W=[w1,w2,…,wN]. Each toy costs 1 unit, and if she buys a toy with weight w', then she can get all other toys whose weight lies between [w',w'+4] (both inclusive) free of cost.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    for(int w_i = 0;w_i < n;w_i++){
       cin >> w[w_i];
    }
    sort(w.begin(), w.end());
    int i = 0;
    int count = 0;
    while(i < n){
        int j = i;
        while(j < n && w[j] <= w[i] + 4){
            j++;
        }
        count++;
        i = j;
    }
    cout << count << endl;
    return 0;
}