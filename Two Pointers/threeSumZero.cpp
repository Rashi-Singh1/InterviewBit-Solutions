typedef long long ll;

//way 1 to remove duplicates, use set of vector<int>
//here unordered set of vectors wont work, bcs 
//1) need sorted result, 
/*****2) unordered_set of vector doesn't exist?******/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    if(A.size() < 3) return ans;
    set<vector<int> > s;
    for(int i = 0 ; i < A.size()-2; i++){
        int start = i+1, end = A.size()-1;
        while(start < end){
            ll sum = (ll)((ll)A[i] + (ll)A[start]) + (ll)A[end];
            if(sum == 0) {
                vector<int> temp = {A[i], A[start], A[end]};
                s.insert(temp);
                start++;
                end--;
            }
            else if(sum > 0) end--;
            else start++;
        }
    }
    for(auto x : s) ans.push_back(x);
    return ans;
}

//change start and end (here j and k), till diff value achieved, similarly with i
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int> > ans;
    if(A.size() < 3) return ans;
    sort(A.begin(),A.end());
    for(int i = 0;i<A.size()-2;i++)
    {
        if (i > 0 && A[i] == A[i-1]) continue;
        int j = i+1;
        int k = A.size()-1;
        while(j < k){
            long long int sum = A[j] + A[k] + A[i];
            if(sum == 0)
            {
                vector<int> temp = {A[i],A[j],A[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && A[j] == A[j-1]) j++;
                while(j<k && A[k] == A[k+1]) k--;
            }
            else if(sum > 0) k--;
            else j++;
        }
    }
    return ans;
}
