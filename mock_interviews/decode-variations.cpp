
int decodeVariations(const string& s)
{
	int n = s.size();
	int first = 1;
	int second = 0;
	int curr = 0;
	for(int i = n-1; i >= 0; i--){
	    if(s[i] == '0')
		curr = 0;
	    else if(s[i] == '1')
		curr = first + second;
	    else if(s[i] == '2'){
		curr = first;
		if(i+1 < n and s[i+1] < '7')
		    curr += second;
	    }
	    else 
		curr = first;
	    
	    second = first;
	    first = curr;
	}
	return first;
}

/*
Complexity analysis:
Time: O(n), we only scan the entire string once.
Space: O(1), since we do not use any extra space.
*/
