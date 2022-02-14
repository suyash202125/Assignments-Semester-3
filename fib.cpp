#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

bool isPrime(ull a){
    bool flag = true;
    for(ull i=2; i<=sqrt(a); i++){
        if(a%i == 0){
            flag = false;
            break;
        }
    }
    if(flag == false){
        return false;
    }
    return true;
}

void solve( ull N){
    ull max_num = 0;
    for(ull i=2; i<=N; i++){
        if(N%i == 0){
            if(isPrime(i)){
                max_num = max(max_num, i);
            }
        }
    }
    cout << max_num;
}

int main() {
	ull n;
	cin >> n;
// 	if(isPrime(n)){
// 	    cout << "prime";
	    
// 	}
// 	else{
// 	    cout << "Not prime";
// 	}
	solve(n);
	return 0;
}