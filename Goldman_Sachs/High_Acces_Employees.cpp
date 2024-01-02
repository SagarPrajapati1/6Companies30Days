class Solution {
public:

  static bool cmp(pair<int,int> a,pair<int,int> b)
  {
      if(a.first!=b.first) return a.first<b.first;
      return a.second<b.second;
  }
  bool solve(pair<int,int> a,pair<int,int> b)
  {
      if(a.first==b.first) return 1;
      else if(abs(a.first-b.first)==1){
          int diff=(60-a.second) + (b.second);
          if(diff<60) return 1;
          return 0;
      }
      return 0;
  }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<pair<int,int>>> m;
        for(auto i:access_times)
        {
            m[i[0]].push_back({stoi(i[1].substr(0,2)),stoi(i[1].substr(2,4))});
            
        }

        vector<string> ans;
        for(auto it:m)
        {
            auto arr=it.second;
            if(arr.size()<3) continue;
            sort(arr.begin(),arr.end(),cmp);
            
            for(int i=0;i<arr.size()-2;i++)
            {
                if(solve(arr[i],arr[i+1]) && solve(arr[i],arr[i+2]))
                {
                    ans.push_back(it.first);
                    break;
                }
            }

        }
        return ans;
    }
};
