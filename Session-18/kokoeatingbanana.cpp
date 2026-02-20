class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        long long n=nums.size(),k,mn=1,sum,ans;
        int mx=*max_element(nums.begin(),nums.end());
        while(mn<=mx)
        {
            k=(mx+mn)/2;
            sum=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]%k==0)
                {
                    sum=sum+(nums[i]/k);
                }
                else
                {
                    sum=sum+(nums[i]/k)+1;
                }
            }
            if(sum<=h)
            {
                ans=k;
                mx=k-1;
            }
            else if(sum>h)
            {
                mn=k+1;
            }
        }
        return ans;
    }
};