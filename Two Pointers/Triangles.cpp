typedef long long ll;
ll mod = 1000000007;                            //NOTE: using 10e9+7 gave wrong answer for larger test cases
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    ll ans = 0ll;
    for(ll i = (ll)A.size()-1ll ; i >= 2ll; i--){
        ll start = 0, end = i-1ll;
        while(start < end){
            ll sum = (ll)A[start] + (ll)A[end];
            if(sum > (ll)A[i]) {
                ans = (ans + (ll)((ll)end-(ll)start)%mod)%mod;
                end--;
            }
            else start++;
        }
    }
    return (int)(ans%mod);
}
/*Good Question*/
//after reset
int Solution::nTriang(vector<int> &A) {
    if(A.size() < 3) return 0;
    sort(A.begin(),A.end());
    long long int count = 0;
    
    for(long long int i = A.size()-1;i>=0;i--)
    {
        long long int j = 0;
        long long int k = i-1;
        while(j<k)
        {
            long long int sum = A[j]+A[k];
            if(sum > A[i]) {
               count =( count + (k-j)%1000000007 ) % 1000000007;
               k--;
            }
            else j++;
        }
    }
    return (int)(count%1000000007);
}

/*
    BASIC LOGIC : 
    for a sorted array
    if A[j] < A[k] < A[i]
    then triangle is possible if A[j] + A[k] > A[i], baaki conditions apne aap satisfy ho jaengi
    now if I fix index i and j = 0 and k = i-1 such that j is always less than k
    and if at a point sum = A[j] + A[k] is less than A[i] , then increase j
    if sum > A[i], then the condition will be satisfied for all j from j to k-1
    therefore count += k-j
    and then check for smaller k
*/