class Solution {
  public:
    int minTime(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,start,mid,end,count,sum;
        start=*max_element(nums.begin(),nums.end());
        end=accumulate(nums.begin(),nums.end(), 0);
        while(start<=end)
        {
            mid=start+(end-start)/2;
            sum=1;
            count=0;
            for(int i=0;i<n;i++)
            {
                if(count+nums[i]<=mid)
                {
                    count=count+nums[i];
                }
                else
                {
                    sum++;
                    count=nums[i];
                }
            }
            if(sum<=k)
            {
                ans=mid;
                end=mid-1;
            }
            else if(sum>k)
            {
                start=mid+1;
            }
        }
        return ans;
    }
};