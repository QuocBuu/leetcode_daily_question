class SegmentTree {
public:
    int n;
    vector<int> arr,seg;
    SegmentTree(vector<int> &nums) {
        n=nums.size();
        arr=nums;
        seg.assign(4 * max(1,n),0);
        if(n) build(1,0,n-1);
    }
    void build(int node, int l, int r) {
        if(l==r){
            seg[node]=arr[l];
            return;
        }
        int mid=(l+r) >> 1;
        build(node*2,l,mid);
        build(node*2+1,mid+1,r);
        seg[node]=max(seg[node*2],seg[node*2+1]);
    }
    int internalQuery(int node, int st, int en, int l, int r) {
        if(l<=st && en<=r) return seg[node];
        int mid=(st+en) >> 1;
        int res=0;
        if(mid>=l) res=max(res,internalQuery(node*2,st,mid,l,r));
        if(r>mid) res=max(res,internalQuery(node*2+1,mid+1,en,l,r));
        return res;
    }
    int query(int l, int r) {
        if(l>r || n==0) return 0;
        return internalQuery(1,0,n-1,l,r);
    }
};
class Solution {
public:
    int segsz=0;
    int lowerBound(vector<int> &v, int x) {
        int l=0,r=segsz;
        while(l<r) {
            int m=(l+r) >> 1;
            if(v[m]>=x) r=m;
            else l=m+1;
        }
        return l;
    }
    int upperBound(vector<int> &v, int x) {
        int l=0,r=segsz;
        while(l<r){
            int m=(l+r) >>1;
            if(v[m]<=x) l=m+1;
            else r=m;
        }
        return l;
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &q) {
        int n =s.size();
        int cnt1=0;
        for(char c: s)
            if(c=='1')
                cnt1++;
        vector<int> zeroBlocks, zeroLeft, zeroRight;
        int idx=0;
        while(idx<n){
            int r=idx;
            while(r<n && s[idx]==s[r]) r++;
            int len=r-idx;
            if(s[idx]=='0'){
                zeroBlocks.push_back(len);
                zeroLeft.push_back(idx);
                zeroRight.push_back(r-1);
            }

            idx=r;
        }
        int m=zeroBlocks.size();
        segsz=m;

        vector<int> ans;
        if(m<=1){
            for(int i=0;i<q.size();i++)
                ans.push_back(cnt1);
            return ans;
        }
        vector<int> nums(m-1);
        for(int i=0;i<m-1;i++)
            nums[i] = zeroBlocks[i]+zeroBlocks[i+1];
        SegmentTree st(nums);
        for(int i=0;i<q.size();i++){
            int l=q[i][0],r=q[i][1];
            int lidx=lowerBound(zeroRight,l);
            int ridx=upperBound(zeroLeft,r)-1;
            if(lidx>m-1 || ridx<0 || lidx>=ridx){
                ans.push_back(cnt1);
                continue;
            }
            int leftLen=zeroRight[lidx]-max(zeroLeft[lidx],l)+1;
            int rightLen=min(r,zeroRight[ridx])-zeroLeft[ridx]+1;
            if(lidx+1==ridx){
                ans.push_back(cnt1+leftLen+rightLen);
                continue;
            }
            int leftContri=leftLen+zeroBlocks[lidx+1];
            int rightContri=rightLen+zeroBlocks[ridx-1];
            int middleContri=st.query(lidx+1,ridx-2);
            ans.push_back(cnt1+max(leftContri,max(rightContri, middleContri)));
        }
        return ans;
    }
};