class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> res;
        for (int i=0; i< nums.size(); i++){
            int temp = target - nums[i];
            if (mp.find(temp) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                res.push_back(i);
                res.push_back(mp[temp]);
            }
        }
        return res;
    }
};