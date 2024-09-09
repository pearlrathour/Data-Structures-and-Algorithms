#include <bits/stdc++.h> 
using namespace std; 

bool isPrime(int n) { 
	if (n<=1) return 0; 
	if (n<=3) return 1; 

	if (n%2==0 || n%3==0) return 0; 

	for (int i=5; i*i<=n; i=i+6){
        // primes occur with gap of 2 and 6
		if (n%i==0 || n%(i+2)==0) 
			return 0; 
    }

	return 1; 
} 

bool isPrime2(int n){
    if (n <= 1) return 0;

    for (int i=2; i<=sqrt(n); i++){
        if (n % i == 0)
            return false;
    }

    return true;
}


int main() { 
	int n = 7; 
	cout<<(isPrime(n)? "YES" : "NO"); 
    return 0;
} 
