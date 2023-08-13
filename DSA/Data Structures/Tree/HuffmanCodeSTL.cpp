#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
	char data;
	int freq;
	MinHeapNode *left, *right;

	MinHeapNode(char d,int f){
		left = right = NULL;
		this->data = d;
		this->freq = f;
	}
};

struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(MinHeapNode* root, string str){
    if (!root)
		return;
	if (root->data != '$')
		cout << root->data << " : " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char arr[],int frq[],int size){
	MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(arr[i],frq[i]));

	while (minHeap.size() != 1){

		// Extract the two minimum freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the two extracted node as left and right children of this new node. Add this node to the min heap '$' is a special value for internal nodes, not used
		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "");
}

// Driver Code
int main(){
    char arr[] = {'a','b','c','d','e','f'};
	int frq[] = {5,9,12,13,16,45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, frq, size);
	return 0;
}