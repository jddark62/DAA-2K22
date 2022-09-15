#include<iostream>
#include<vector>
#include<algorithm>

static bool cmp(std::vector<int>&a, std::vector<int>&b){
        return a[1]>b[1];
    }
int maximumUnits(std::vector<std::vector<int>>& boxtypes, int sackSize) {
        int totalSum = 0;
        std::sort(boxtypes.begin(), boxtypes.end(), cmp);
        int i=0;
        while(sackSize>0 && i<boxtypes.size()){
            // if weight is less than sackSize
            if(sackSize-boxtypes[i][0]>0){
                sackSize-=boxtypes[i][0];
                totalSum += (boxtypes[i][0]*boxtypes[i][1]);
            }
            // if weight is greater than sackSize
            else{
                totalSum += (sackSize*boxtypes[i][1]);
                sackSize = 0;
            }
            i++;
        }
        return totalSum;
}

int main(){
    std::vector<std::vector<int>> boxTypes = {{5,10},{2,5},{5,7}, {3,9}};
    int sackSize = 10;
    std::cout<<maximumUnits(boxTypes, sackSize)<<std::endl;
    return 0;
}