class Solution {
public:
    int maxArea(vector<int>& height) {

        int n=height.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            int width =j-i;
            int h=min(height[i],height[j]);
            int curr=width*h;
        if(curr>ans){
            ans=curr;
        }
            if(height[i]<=height[j]){
                i++;
            }
            else if(height[j]<height[i]){
                j--;
            }
        }
        return  ans;
        
    }
};
    