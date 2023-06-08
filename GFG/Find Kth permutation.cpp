//QUESTION
// Given two integers N (1<=N<=9) and K. Find the kth permutation sequence of first N natural numbers. Return the answer in string format.

// Example 1:

// Input: N = 4, K = 3
// Output: 1324
// Explanation: 
// Permutations of first 4 natural numbers:
// 1234,1243,1324,1342,1423,1432.....
// So the 3rd permutation is 1324. 


// 1.brute force 

//   a.find all permutations and find the kth one
//   b.find upto kth premutation
  
//   both of them will have TC=O(nXn!) in worst case
  
// 2.better
  
//   using the built-in function next_premutation()
  
//   --code
  
  class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        string ans="";
        vector<int> num(n);
        for(int i=0;i<n;++i) num[i]=i+1;
        k--;
        while(k--){
            next_permutation(num.begin(),num.end());
        }
        for(int i=0;i<n;i++){
            ans+=(num[i]+'0');
        }
        
        return ans;
    }
};

3.optimal
  
//   suppose N=4 we will have 4!=24 permutations and 1 _ _ _ we will have 1 at first position in  (4-1)!=6 permutations(similar for 2,3,4)
//   if k=14 then (6+6+2) we will get 3 _ _ _ the 2nd permutation where 3 is at first position
//   3 1 2 4
//   3 1 4 2
//   3 2 1 4
//   3 2 4 1
//   3 4 1 2
//   3 4 2 1
    
//   now we can say that we will have 3 1 _ _ in our number
//   similarly, we will find 3 1 4 2 in our number
  
//   filtering (4-1)! -> (3-1)! ->(2-1)! -> final answer
  
   vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++)fact[i]=i*fact[i-1];
        vector<bool> vis(n+1,false);
        string ans="";
        int i=n;
        while(ans.length()!=n){
            int row = k/fact[i-1];
            if(k%fact[i-1])row++;
            for(int j=1;j<=n;j++){
                if(vis[j]==false){
                    row--;
                }
                if(row==0){
                    vis[j]=true;
                    ans+=(j+'0');
                    break;
                }
            }
            k = k%fact[i-1];
            if(k==0)k=fact[i-1];
            i--;
        }
        return ans;
    }
