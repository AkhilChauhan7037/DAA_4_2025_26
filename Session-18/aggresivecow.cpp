class Solution {
  public:
    int aggressiveCows(vector<int> &nums, int k) {
        int n=nums.size(),start,end,mid,ans,temp;
        long long sum;
        sort(nums.begin(),nums.end());
        start=1;
        end=nums[n-1]-nums[0];
        while(start<=end)
        {
            sum=0;
            mid=start+(end-start)/2;
            temp=nums[0];
            for(int i=1;i<n;i++)
            {
                if(nums[i]-temp>=mid)
                {
                    sum++;
                    temp=nums[i];
                }
            }
            if(sum>=k-1)
            {
                ans=mid;
                start=mid+1;
            }
            else if(sum<k-1)
            {
                end=mid-1;
            }
        }
        return ans;
    }
};