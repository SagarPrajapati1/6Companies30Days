class Solution {
public:
    int findNumberEquivalent(string &s){
        int number=0;
        for(auto &ch:s){
			//Set the (ch-'a')th bit
            number|=(1<<(ch-'a'));
        }
        return number;
    }
    
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    
        set<int>st;
        
        for(auto &s:startWords){
            int number=findNumberEquivalent(s);
            st.insert(number);
        }
        
        int ans=0;
        
        for(auto &w:targetWords){
            int targetNumber=findNumberEquivalent(w);
            for(int i=0;i<w.size();i++){
				//unset the (w[i]-'a')th bit.
                int candidate=(targetNumber - ( 1<<(w[i]-'a') ));
                if(st.find(candidate)!=st.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
