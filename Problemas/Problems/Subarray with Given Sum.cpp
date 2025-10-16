//https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = (int) arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for(int i = 1;i<n;i++)
            pref[i] = pref[i-1]+arr[i];
        
        unordered_map<int,int> pos;
        pos[0] = -1;
        for(int i = 0;i<n;i++){
            int req = pref[i]-target;
            if(pos.find(req)!=pos.end())
                return {pos[req]+2,i+1};
            if(pos.find(pref[i])==pos.end())
                pos[pref[i]] = i;
        }
        return {-1};
    }
};
