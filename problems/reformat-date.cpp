class Solution {
public:
    string reformatDate(string str) {
        
        unordered_map<string, string> m;
        m["Jan"] = "01";
        m["Feb"] = "02";
        m["Mar"] = "03";
        m["Apr"] = "04";
        m["May"] = "05";
        m["Jun"] = "06";
        m["Jul"] = "07";
        m["Aug"] = "08";
        m["Sep"] = "09";
        m["Oct"] = "10";
        m["Nov"] = "11";
        m["Dec"] = "12";
            
        stringstream ss(str); 
        string word;
        string year = "";
        string month = "";
        int d;
        int i = 0;
        string date = "";
        while(ss >> word){
            if(i == 0){
                stringstream ss(word);
                ss >> d;
                
                date = to_string(d);

                if(date.size() == 1) date.insert(date.begin(), '0');
                
            }
            else if(i == 1){
                month = m[word];
            }
            else{
                year = word;
            }
            i++;
        }
        return year + "-" + month + '-' + date;
    }
};

