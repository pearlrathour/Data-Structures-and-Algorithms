#include <iostream>
using namespace std;

void subset(string ip,string op){
    if(ip.length()==0){
        cout<<'"'<<op<<'"'<<", ";
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    subset(ip,op1);
    subset(ip,op2);
    return;
}
int main(){
    string ip;
    cin>>ip;
    string op="";
    subset(ip,op);
    return 0;
}