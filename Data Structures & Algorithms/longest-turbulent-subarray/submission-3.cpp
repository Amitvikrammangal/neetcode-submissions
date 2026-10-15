class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int s=0;
        int e=1;
        int ans=1;
        while(e<arr.size())
        {
            if(arr[e]==arr[e-1])
            {
                s=e;
            }

            else if(e>=2 && (arr[e]>arr[e-1] && arr[e-1]>arr[e-2]) ||( arr[e]<arr[e-1] && arr[e-1]<arr[e-2]))
            {
                s=e-1;
            }

            ans=max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};