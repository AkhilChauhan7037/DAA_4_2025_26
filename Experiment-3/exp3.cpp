// maximum length of the Stable Attendance Window using unordered map T.C.=0(N) and S.C.=0(N).
#include <bits/stdc++.h>
using namespace std;
int maximumstablewindow(vector<char>& s)
{
    unordered_map<int,int> mp;
    int sum=0,ans=0,n=s.size();
    mp[0]=-1;
    for(int i =0;i<n;i++)
    {
        if(s[i]=='P')
        {
            sum++;
        }
        else if(s[i]=='A')
        {
            sum--;
        }
        if(mp.find(sum)!=mp.end())
        {
            ans=max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<char>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cout<<"the maximum length of the stable attendance window is = "<<maximumstablewindow(s);
    return 0;
}



// 2nd method brutforce approach without using map T.C.=0(N^2) and S.C.=0(1).
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maximumstablewindow(vector<char>& s)
{
    int ans=INT_MIN,count,n=s.size();
    for(int i=0;i<n;i++)
    {
        count=0;
        for(int j=i;j<n;j++)
        {
            if(s[j]=='P')
            {
                count++;
            }
            else if(s[j]=='A')
            {
                count--;
            }
            if(count==0)
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    if(ans==INT_MIN)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}
int main()
{
    int n,ans;
    cin>>n;
    vector<char>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    ans=maximumstablewindow(s);
    cout<<"the maximum length of the stable attendence window is = "<<ans;
    return 0;
}