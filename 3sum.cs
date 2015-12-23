public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        var closest = nums[0] + nums[1] + nums[2];
        Array.Sort(nums);
  
      for(var i = 0; i < nums.Length; i++) {
          
          var left = i + 1;
          var right = nums.Length - 1;
          
          while(left < right) {
              
              var sum = nums[i] + nums[left] + nums[right];
              
              if(Math.Abs(target - sum) < Math.Abs(target - closest)) {
                  closest = sum;
              }
              
              if(sum > target) {
                  right--;
              } else if(sum < target) {
                  left++;
              } else return target;
          }
      }
      
      return closest;
    }
}