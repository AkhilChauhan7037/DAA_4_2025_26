#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getCutOff(priority_queue<int, vector<int>, greater<int>>& heap, int score, int K) {
    if (heap.size() < K) 
    {
        heap.push(score);
    } 
    else if (score > heap.top()) 
    {
        heap.pop();
        heap.push(score);
    }
    if (heap.size() < K)
    {
        return -1;
    }
    else
    {
        return heap.top();
    }
}

int main() {
    int K, N;
    cin >> K >> N;

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < N; i++) 
    {
        int score;
        cin >> score;
        cout << getCutOff(heap, score, K) << endl;
    }
    return 0;
}