#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> bset1(x);
        bitset<32> bset2(y);
        int count=0;
        for(int i=0;i<32;i++){
            if(bset1[i]!=bset2[i])count++;
        }
        return count;
    }
};

class Solution {
public:
    int bitCount(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        return bitCount(x^y);
    }
     
};