// https://leetcode.cn/problems/two-sum/
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int> map;
        vector<int> returnValues;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(map.count(target-nums[i])>0 && map[target-nums[i]]!=i)
            {
                returnValues.push_back(i);
                returnValues.push_back(map[target-nums[i]]);
                break;
            }
        }
        return returnValues;
    }
};


// 以下是官方解答，使用unordered_map
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hashtable = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            if (hashtable.containsKey(target - nums[i])) {
                return new int[]{hashtable.get(target - nums[i]), i};
            }

            //它并没有最开始就把所有的就加进来，而是一个个加，避免了重复的问题，感觉很好
            hashtable.put(nums[i], i);
        }
        return new int[0];
    }
}

// 作者：力扣官方题解
// 链接:https://leetcode.cn/problems/two-sum/
// 来源:力扣(LeetCode)
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。