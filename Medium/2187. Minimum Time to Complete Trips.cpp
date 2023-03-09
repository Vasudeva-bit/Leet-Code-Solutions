#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool areTripsDone(vector<int>& time, long long maxT, int totalTrips) {
        long long total = 0;
        for(auto trip: time) {
            total += maxT/trip;
        }
        return total >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long l = 1;
        long long r = time[time.size()-1]*(1ll*totalTrips);
        long long out = INT_MAX;
        while(l <= r) {
            long long mid = l+(r-l)/2;
            if(areTripsDone(time, mid, totalTrips)) {
                out = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }

        return out;
    }
};