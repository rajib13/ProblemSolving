class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        
        for(string email : emails){
            string emailAddress = "";
            for(char ch : email){
                if(ch == '.') continue;
                else if(ch == '+' or ch == '@')  break;
                
                emailAddress += ch;
            }
            emailAddress += email.substr(email.find('@'));
            set.insert(emailAddress);
        }
        return set.size();
    }
};

/*
    Complexity analysis:
    Time: O(m*n), where `m` and `n` are the length of the given string vector and `n` is the length of the longest email.
    Space: O(n), since we use a hashset to store all unique email addresses.
*/
