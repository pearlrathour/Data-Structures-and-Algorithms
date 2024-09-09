#include<bits/stdc++.h>
using namespace std;

void Tower(int n,char Src, char Dst,char Hlp,int & count){
    if(n==1){
        cout<<"Move Disk "<<n<<" from "<<Src<<" to "<< Dst<<endl;
        return;
    }
    Tower(n-1,Src,Hlp,Dst,count);
    cout<<"Move Disk "<< n<<" from "<< Src<<" to "<<Dst<<endl;
    count++;
    Tower(n-1,Hlp,Dst,Src,count);
    count++;
}

int main(){
    int n;
    cin>>n;
    int count=0;
    Tower(n,'S','D','H',count);
    cout<<"No. of steps "<<count<<endl;
    return 0;
}