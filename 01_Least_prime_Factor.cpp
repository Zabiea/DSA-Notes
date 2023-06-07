//gfg---  https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1

//Question

/*Given a number N, find the least prime factors for all numbers from 1 to N.  The least prime factor of an integer X is the smallest prime number that divides it.
Note :

    1 needs to be printed for 1.
    You need to return an array/vector/list of size N+1 and need to use 1-based indexing to store the answer for each number.*/

//thoughts

// making an array of bool arr[10^5+1]={1} values 
// the array will denote arr[i] is prime or not
// 1.setting every element to true;
// 2.then set 0 and 1 to false 
// 3. from i=2 if arr[i]  is true then set every multiple of arr[i] to false







//Code

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        // vector<int> isPrime(0,100001);   // same code not working on vector  
        // vector<int> ans(n+1);
        
        // for(int i=0;i<=n;++i)
        //     isPrime[i]=i;
        
        // for(int i=2;i<=n;++i){
        //     if(isPrime[i]==i){
        //         for(int j=i*i;j<=n;j+=i){
        //             if(isPrime[j]==j)
        //                 isPrime[j]=i;
        //         }
        //     }
        // }
        
        
        
        // for(int i=0;i<=n;++i){
        //   ans[i]=isPrime[i];
        // }
        
        // return ans;
               int arr[100001]={0};
        for(int i=0;i<=n;i++)
        {
            arr[i]=i;
        }
        for(int i=2;i<=n;i++)
        {
            if(arr[i]==i)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    if(arr[j]==j)
                    {
                        arr[j]=i;
                    }
                }
            }
        }
        vector<int>ans;
        
        for(int i=0;i<=n;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends

