//Q--  You are given an array of size N. Rearrange the given array in-place such that all the
// negative numbers occur before all non-nagative numbers.(Maintain the order of all -ve and non-negative numbers as given in the original array).

// Input:
// N = 4
// Arr[] = {-3, 1, 0, -2}
// Output:
// -3 -2 1 0
// Explanation:
// In the given array, negative numbers
// are -3, -2 and non-negative numbers are 1, 0.

// Expected Time Complexity: O(N. Log(N))
// Expected Auxiliary Space: O(Log(N))

//My approach

  stack<int> st;
            
            for(int i=n-1;i>=0;i--){
                if(arr[i]>=0)
                    st.push(arr[i]);
            }
            for(int i=n-1;i>=0;i--){
                if(arr[i]<0)
                    st.push(arr[i]);
            }
            int i=0;
            while(!st.empty()){
                int s=st.top();
                arr[i]=s;
                st.pop();
                i++;
            }
        }

//TC-O(N)
//SC-O(N)

//optimal-----using merge sort(modification)
