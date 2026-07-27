class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        if(n == 0) return; int i=0;
        if(m == 0) {for(auto a:nums2) {nums1[i++] = a;} return;}
        int p2 = n-1;
        int curr = n+m-1;

        while(curr >= 0){
            cout<<curr<<" "<<p1<<" "<<p2<<"\n";
            if(p1 < 0) {nums1[curr--] = nums2[p2--]; continue;}
            if(p2 < 0) {nums1[curr--] = nums1[p1--]; continue;}
            if(nums1[p1] < nums2[p2]) nums1[curr--] = nums2[p2--];
            else nums1[curr--] = nums1[p1--];
            
       }
        
    }
};