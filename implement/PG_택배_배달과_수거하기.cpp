#include <string>
#include <vector>

using namespace std;

// 00:22
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int prevans;
    int del = n-1, pick = n-1;
    int amount = cap;

    while(del >= 0 || pick >= 0) {
        if(deliveries[del] == 0) {
            del--; continue;
        }
        if(pickups[pick] == 0) {
            pick--; continue;
        }
        
        if(pick < del) answer += (del+1)*2;
        else answer += (pick+1)*2;
        amount = cap;
        
        // delivery
        while(amount != 0 && del >= 0) {
            if(deliveries[del] < amount) {
                amount -= deliveries[del];
                del--;
            }
            else {
                deliveries[del] -= amount;
                break;
            }
        }
        
        // pickup
        amount = cap;
        while(amount != 0 && pick >= 0) {
            if(pickups[pick] < amount) {
                amount -= pickups[pick];
                pick--;
            }
            else {
                pickups[pick] -= amount;
                break;
            }
        }
    }
    
    return answer;
}