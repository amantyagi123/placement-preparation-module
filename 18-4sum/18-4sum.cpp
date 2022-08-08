class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      int n = nums.size();
      
      for(int i=0; i<n-3; i++){
        
        if(i>0 && nums[i]==nums[i-1]){continue;} //remove all duplicates
        
        for(int j=i+1; j<n-2; j++){
          
          if(j>i+1 && nums[j] == nums[j-1]){continue;} //remove all duplicates
          
          long long left = j+1, right = n-1;
          
          long long remain = target - nums[i]; // int remain = target - (nums[i] + nums[j]);
          remain -= nums[j];
          
          while(left < right){
            
            long long twoSum = nums[left] + nums[right];
            
            if( twoSum < remain){
              // move left to a new element
              //remove all duplicates
              do{
                left++;
              }while( left < right && (nums[left] == nums[left-1]));
            }
            
            else if( twoSum > remain){
              // pull back right to new element
              //remove all duplicates
              do{
                right--;
              }
              while( right > left && (nums[right] == nums[right+1]));
            }
            
            else if( twoSum == remain ){
              //target found
              vector<int> temp = {nums[i] , nums[j] , nums[left] , nums[right]};
              ans.push_back(temp);
              
              //remove all duplicates
              do{
                left++;
              }while( left < right && (nums[left] == nums[left-1]));
              
              do{
                right--;
              }
              while( right > left && (nums[right] == nums[right+1]));
            }
          }
        }
      }
      
      return ans;
    }
};