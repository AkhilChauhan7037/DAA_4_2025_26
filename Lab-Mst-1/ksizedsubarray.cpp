class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>ans;
        multiset<int,greater<int>>mp;
        int n=arr.size(),j=0;
       for(int i=0;i<k;i++)
       {
        mp.insert(arr[i]);
       }
       for(int i=k;i<n;i++)
       {
           auto it=mp.begin();
           ans.push_back(*it);
           auto a=mp.find(arr[j]);
           mp.erase(a);
           mp.insert(arr[i]);
           j++;
       }
       auto it=mp.begin();
       ans.push_back(*it);
       return ans;
    }
};