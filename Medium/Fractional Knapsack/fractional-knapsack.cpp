//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a,Item b){
        return a.value/(a.weight*1.0)>b.value/(b.weight*1.0);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        
        double finalvalue =0.0;
        int currw = 0;
        for(int i=0;i<n;i++){
            if(currw + arr[i].weight <= W){
                   currw +=arr[i].weight;
                finalvalue +=arr[i].value;
             
            }
            else{
                int remain = W-currw;
                finalvalue += arr[i].value * ((double) remain / arr[i].weight  );
                break;
            }
        }
        return finalvalue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends