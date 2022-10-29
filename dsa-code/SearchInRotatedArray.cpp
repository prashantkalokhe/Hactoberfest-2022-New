class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[s]<=arr[mid])  //left part sorted
        {
            if(key>=arr[s] && key<arr[mid])
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }

        }
        else //right part sorted
        {
            if(key>arr[mid] && key<=arr[e])
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }

        }
    }
    return -1;
}
        
};