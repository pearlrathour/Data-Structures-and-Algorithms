#include <iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int src, int dest){
	adj[src].push_back(dest);
}

void displayGraph(vector<int> adj[], int v){
	for (int i = 0; i < v; i++) {
		cout << i << "--> ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
}

void transposeGraph(vector<int> adj[],vector<int> transpose[], int v){
	for (int i = 0; i < v; i++){
		for (int j = 0; j < adj[i].size(); j++)
			addEdge(transpose, adj[i][j], i);
    }
}

int main(){
	int v;
    cout<<"Enter no of vertices : ";
    cin>>v;
	vector<int> adj[v];
    int cont=1;
    while(cont){
        int src,dest;
        cout<<"Enter Source : ";
        cin>>src;
        cout<<"Enter destination : ";
        cin>>dest;
        if(src > v-1 || src<0 || dest > v-1|| dest<0)
            return -1;
        addEdge(adj,src,dest);
        cout<<"Continue? (for yes-1,for no-0) : ";
        cin>>cont;
    }
	
    cout<<"Original Graph : "<<endl;
    displayGraph(adj, v);
    cout<<endl;

	vector<int> transpose[v];
	transposeGraph(adj, transpose, v);
    cout<<"Transpose Graph : "<<endl;
	displayGraph(transpose, v);
	return 0;
}
