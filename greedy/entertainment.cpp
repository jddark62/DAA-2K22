/*
Consider a long road with many entertainment zones as theatres, parks etc., The distances
where each is located is specified with a distance in kms. For eg. If position is 20km, then it is
situated at the 20th km from one end of the road. You are considering constructing packed food
delivery kiosks in that stretch (assume the road is constructed new, and no kiosk is
available). Each packed food delivery kiosks has a radius ‘r’ which covers the distance and
the places within the radius. For eg. If the theatre is at distance d, then the packed food delivery
kiosks c can be placed if abs(d-c)<=r which can serve the theatre. Consider it as an
optimization problem that minimizes the number of distribution centers along the road and
covers all the entertainment places around.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        cin >> pos[i];
    }
    int r;
    cin >> r;
    sort(pos.begin(), pos.end());
    int i = 0;
    int count = 0;
    while(i < n){
        int j = i;
        while(j < n && pos[j] <= pos[i] + 2*r){
            j++;
        }
        count++;
        i = j;
        while(i < n && pos[i] <= pos[j-1] + r){
            i++;
        }
    }
    cout << count << endl;
    return 0;
}