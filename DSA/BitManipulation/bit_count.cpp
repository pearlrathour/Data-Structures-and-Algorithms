#include<bits/stdc++.h>
using namespace std;

unsigned int countBits1(unsigned int n){ 
	int count = 0; 
	while (n != 0) {
	    count++;
	    n = n/2;      
	} 
	return count; 
}


// unsigned int countBits2(unsigned int n){
//     unsigned int count=0;
//     for(int i=0 ; i<=n ; i++){
//             int j=i;
//             while(j>0){
//                 j&=(j-1);
//                 count++;
//             }
//     } 
//     return count;
// }

vector<int> countBits(int n) {
        vector<int> arr;
        for(int i=0 ; i<=n ; i++){
            int count=0;
            int j=i;
            while(j>0){
                j&=(j-1);
                count++;
            }   
            arr.push_back(count);
        }
        return arr;
    }

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<countBits1(n)<<endl;
    // cout<<countBits2(n)<<endl;
    cout<<countBits(n)<<endl;
    return 0;
}