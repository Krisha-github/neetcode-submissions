class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded="";
        for(const string & s: strs){
            int len = s.size();
            encoded+= to_string(len) + "#"+ s;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        int n=s.size();
        vector<string> decoded;
        int i=0;
        while(i<n){
            int k=i;
            while(s[k]!='#'){
                k++;
            }
            int len=stoi(s.substr(i,k));
            string word = s.substr(k+1,len);
            decoded.push_back(word);
            i= k+1+len;
        }
        return decoded;
    }
};
