#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii              pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define repb(i,a,b) 	for(int i=a;i>=b;i--)
#define endl			"\n"
#define m(a)		    memset(a,0,sizeof(a))
#define all(x)                          begin(x), end(x)

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	#endif
}

int bs(int a[] , int s , int e, int x){
	if(s<=e){
		int m = (s+e)/2;
		if(a[m]==x)
			return m;
		else if(a[m] > x)
			return bs(a,s,m-1,x);
		else return bs(a,m+1,e,x);
	}
	return -1;
}

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

const int N = 1e5+5;
int a[N];
int st[4*N];
int f[N];

int combine(int x , int y){
	return __gcd(x,y);
}

void build(int si , int ss , int se){
    if(ss==se){
        st[si] = a[ss]%mod;
        return;
    }
    int mid = (ss+se)/2;
    build(2*si+1 , ss , mid);
    build(2*si + 2 , mid+1 , se);
    st[si] = combine(st[2*si+1] , st[2*si+2])%mod;
}

int query(int si , int ss , int se , int qs , int qe){
    if(qs > se || qe < ss)      //completely outside
        return 0;
    if(ss >= qs && se <= qe)    //completely inside
        return st[si];
    int mid = (ss+se)/2;
    int l = query(2*si+1, ss , mid , qs , qe)%mod;
    int r = query(2*si+2 , mid+1 , se , qs , qe)%mod;
    return combine(l,r)%mod;
}

void Print(int n){ 
    for(int i=0 ; i<=2*n ; i++)
        cout << st[i] << " ";
}

int32_t main(){	
	__;
	file();
	f[0]=0; f[1]=1 ; f[2]=1;
	rep(i , 3 , N){
		f[i] = f[i-1]+f[i-2];
	}
	int n,q; sd2(n,q);
	rep(i ,0 ,n)sd(a[i]);
	rep(i , 0 , n){
		a[i]=f[a[i]];
	//	tr(a[i]);
	}
	build(0 , 0 ,n-1);
	while(q--){
		int x,y; sd2(x,y);
		cout << query(0 , 0 ,n-1,--x , --y)%mod << endl;
	}
	return 0;
}




