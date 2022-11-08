#include<iostream>
using namespace std;
 
struct Node{
	int data;
	struct Node *next;

    Node(int val){
	data=val;
	next = NULL;
    }
};
 
struct vertexlist{
	struct node *vlisthead;
};
 
struct Graph{
	int v;
	struct vertexlist *vl; 
};
 
Graph* CreateGraph(int n){
	int i;
	Graph *vlist = new Graph;
	vlist->v = n;
 
	vlist->vl = new vertexlist[n+1];

	for(i = 0; i < n+1; i++)
		vlist->vl[i].vlisthead = NULL;
	return vlist;
}
 
void InsertNode(Graph *G, int v1, int v2){
	Node *temp1 = new Node(v1);
	Node *temp2 = new Node(v2);
	Node *temp = new Node;
	// Since it is undirected graph, count each edge as two connection.
	// Connection 1, v2 to v1.
	if(G->vl[v2].vlisthead == NULL){
		// If the head is null insert the node to the head.
		G->vl[v2].vlisthead = temp1;
	}
	else{
		// Otherwise, add the node at the beginning.
		new temp1->next = G->vl[v2].vlisthead;
		G->vl[v2].vlisthead = temp1;
	}
	// Connection 2, v1 to v2.
	if(G->vl[v1].vlisthead == NULL){
		// If the head is null insert the node to the head.
		G->vl[v1].vlisthead = temp2;
	}
	else
	{
		// Otherwise, add the node at the beginning.
		temp2->next = G->vl[v1].vlisthead;
		G->vl[v1].vlisthead = temp2;
	}
}
 
int main(){
	int i, v, e;
	cout<<"Enter the number of verteces of the graph: ";
	cin>>v;
	Graph *G = CreateGraph(v);
	cout<<"\nEnter the number of edges of the graph: ";
	cin>>e;
	int edge[e][2];
 
	// Take the input of the adjacent vertex pairs of the given graph.
	for(i = 0; i < e; i++){
		cout<<"\nEnter the vertex pair for edge "<<i+1;
		cout<<"\nV(1): ";
		cin>>edge[i][0];
		cout<<"V(2): ";
		cin>>edge[i][1];
 
		InsertNode(G, edge[i][0], edge[i][1]);
	}

	cout<<"\n\nThe incidence list representation for the given graph: ";
	for(i = 0; i < v; i++)
	{
		cout<<"\n\tV("<<i+1<<") -> {  ";
		while(G->vl[i+1].vlisthead != NULL)
		{
			cout<<G->vl[i+1].vlisthead->data<<"  ";
			G->vl[i+1].vlisthead = G->vl[i+1].vlisthead->next;
		}
		cout<<"}";
	}
}