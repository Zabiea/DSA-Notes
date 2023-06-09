//Q--Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    vector<string> ans;
		    
		    do{
		        ans.push_back(S);
		    }while(next_permutation(S.begin(),S.end()));
		    return ans;
		}
