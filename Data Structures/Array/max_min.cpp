#include<iostream>
using namespace std;

struct Pair{
	int min;
	int max;
};

//Linear Search
//O(n) & O(1)
//Comparisons- 1+n-2 to 1+2(n-2)
Pair getMinMax1(int arr[], int n){
	Pair minmax;
	if (n == 1){
		minmax.max = arr[0];
		minmax.min = arr[0];	
		return minmax;
	}
	
	if (arr[0] > arr[1]){
		minmax.max = arr[0];
		minmax.min = arr[1];
	}
	else{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}
	
	for(int i = 2; i < n; i++){
		if (arr[i] > minmax.max)	
			minmax.max = arr[i];
			
		else if (arr[i] < minmax.min)	
			minmax.min = arr[i];
	}
	return minmax;
}

//Divide and Conquer
//O(n) & O(logn)
//3n/2 -2 
Pair getMinMax2(int arr[], int low, int high){
    Pair minmax, mml, mmr;
    int mid;
 
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
 
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
    
    mid = (low + high) / 2;
    mml = getMinMax2(arr, low, mid);
    mmr = getMinMax2(arr, mid + 1, high);
    
    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;
 
    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;
 
    return minmax;
}


//Comparing in pairs
//O(n) & O(1)
//odd- 3(n-1)/2 && even 1+3(n-2)/2=3n/2 -2

Pair getMinMax3(int arr[], int n){
    struct Pair minmax;    
    int i;
    //even size
    if (n % 2 == 0){
        if (arr[0] > arr[1]){
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else{
            minmax.min = arr[0];
            minmax.max = arr[1];
        }  
        // Set the starting index for loop
        i = 2;
    }
    
    //odd size
    else{
        minmax.min = arr[0];
        minmax.max = arr[0]; 
        // Set the starting index for loop
        i = 1;
    }
     
    for(i ; i<n-2 ; i+=2){        
        if (arr[i] > arr[i + 1]){
            if(arr[i] > minmax.max)    
                minmax.max = arr[i];    
            if(arr[i + 1] < minmax.min)        
                minmax.min = arr[i + 1];    
        }
        else{
            if (arr[i + 1] > minmax.max)    
                minmax.max = arr[i + 1];
             if (arr[i] < minmax.min)        
                minmax.min = arr[i];    
        }      
    }        
    return minmax;
}


int main(){
	int arr[] = {1000, 11, 445,1, 330, 3000 };
	int size =sizeof(arr) / sizeof(arr[0]);
	
	struct Pair minmax1 = getMinMax1(arr, size);
	cout << "Minimum element is "<< minmax1.min << endl;
	cout << "Maximum element is "<< minmax1.max << endl;

    struct Pair minmax2 = getMinMax2(arr,0, size);
	cout << "Minimum element is "<< minmax2.min << endl;
	cout << "Maximum element is "<< minmax2.max << endl;

struct Pair minmax3 = getMinMax3(arr, size);
	cout << "Minimum element is "<< minmax3.min << endl;
	cout << "Maximum element is "<< minmax3.max << endl;
	return 0;
}