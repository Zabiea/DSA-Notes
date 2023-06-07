//User function template in C++

//question--You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at 
//least one book. Out of all the permutations, the goal is to find 
//the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

//thought
// we have to minimize the max number of pages one can read
// if we are giving only one book to someone we should give the book with the max number of pages
// so low=maxof(arr)
// and we can allot every book to one person in that case 
//  high becomes sumof(arr)
// now search in this space where we are getting feasible allocation for givven number of partition
// if the number of partitions for choosen number of pages (mid) are > than M then we have to increse the numbe of pages (low=mid+1)
//   else high=mid-1

//return the previous mid cz in the last iteration mi crosses high 


class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool feasible (int A[],int N, int M, int mid){
        int countPartition=1;
        int sum=0;
        for(int i=0;i<N;++i){
            if(sum+A[i]>mid){
               sum=0;
               ++countPartition;
            }
            sum+=A[i];
        }
        return countPartition<=M;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M==0||M>N) return -1;
        int low=0;
        int high=0;
        for(int i=0;i<N;++i){
            high=high+A[i];
            low=max(low,A[i]);
        }
        int res=-1;
        int mid;
        while(low<=high){
          mid=low +((high-low)/2);
            if(feasible(A,N,M,mid)){
                res=mid;
                 high=mid-1;
            }
            else{
                low=mid+1;
        }
        
    }
    return res;
    }
};
