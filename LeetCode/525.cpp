class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        
        map<int, int> m;
        int sum = 0;
    	int ans = 0;
    	m[0] = -1;
    	for(int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    		if(m.find(sum) != m.end()){
    			ans = max(ans, i - m[sum]);
    		}
    		else{
    			m[sum] = i;
    		}
    	}
    	return ans;
    }
};