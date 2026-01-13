#include <bits/stdc++.h>
using namespace std;
void  complexRec(int n,int& count) {
   if (n <= 2) {
       return;
   }
   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           count++;
       }
       p >>= 1;
   }
   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }
   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }
   complexRec(n / 2,count);
   complexRec(n / 2,count);
   complexRec(n / 2,count);
}
int main()
{
    int n,count=0;
    auto start=high_resolution_clock::now();
    cout<<"enter the value of n:";
    cin>>n;
    complexRec(n,count);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<millisecond>(end-start);
    cout<<"the number of operation is perform by the given code is = "<<count<<endl;
    return 0;
}
// recurence relation T(n)=3*T(n/2)+nlogn+3n/2
// Time Complexity = 0(n^log2(3))
// depth of code = logn