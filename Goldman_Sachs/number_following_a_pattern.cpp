class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans  = "";
        
        for(int i = 1; i <= S.length()+1; i++) ans += '0' + i;
         
        while(true) {
            int j = 1; int k = 0;
            
            bool flag = true;
            
            while(j < ans.size()) { 
                if(S[k] == 'D' && ans[j] > ans[j-1]) {
                    swap(ans[j], ans[j-1]);
                    flag = false;
                }
            
            
                if(S[k] == 'I' && ans[j] < ans[j-1]) {
                    swap(ans[j], ans[j-1]);
                    flag = false;
         
                }       j++; k++;
            }
            if(flag == true) break;
            
                
        }
        
        return ans;
        
        
    }
};
