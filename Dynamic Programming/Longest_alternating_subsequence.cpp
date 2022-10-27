int AlternatingaMaxLength(vector<int>&nums){
     int ma=1;
     int mi=1;
     int n=nums.size();
     
     for(int i=1;i<n;i++)
     {
         if(nums[i]>nums[i-1]){
         ma=mi+1;
     }
    else if(nums[i]<nums[i-1])
     {
         mi=ma+1;
     }
     else
     continue;
     
 }
 return max(ma,mi);
