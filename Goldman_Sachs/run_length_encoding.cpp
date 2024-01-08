
string encode(string src)
{     
  //Your code here 
    map<char, int> count;
    
    
    
    string str = "";

   
    for(int i = 0; i < src.size(); ) {
        
        char ch = src[i];
        str += ch;
 
       int cnt = 0;
        while(src[i] == ch ) {
            cnt++;
            i++;
        }
        str+= to_string(cnt);
    }
    
    return str;
}     
 
