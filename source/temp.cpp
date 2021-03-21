class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int start=0;
        int flag=0;
            
        if(nums.size()==1) return nums[0];
        if(nums[0]==0&&nums.size()==2)
            return max(nums[0],nums[1]);
        else if(nums[0]==0&&nums.size()>2)
                start=1;
             else
                start=0;
        
        int globalMax=nums[start],localMax=nums[start],middleMax=nums[start];        
        for(int i=start+1;i<nums.size();++i)
        {
            if(flag>0)
            {
                middleMax*=nums[i];
                localMax*=nums[i];
            }
            else
                localMax*=nums[i];
            globalMax=max(max(localMax,globalMax),middleMax);
            if(nums[i]==0)
            {
                flag=0;
                localMax=1;
            }
            if(nums[i]*nums[i-1]<0) 
            {
                if(flag==0)
                    middleMax=1;
                ++flag;
            }  
        }
        if(flag>=3)
            globalMax=max(globalMax,middleMax*nums[nums.size()-1]);
        return max(globalMax,0);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}