class Solution {
public:
    int n;
    vector<int>bit;
    void ft(vector<vector<int>>& queries){
        int x=min(5*10000,(3*(int)queries.size()));
        n=x;
        bit=vector<int>(n+2,0);
    }
    void add(int id,int val){
        while(id<=n){
            bit[id]=max(bit[id],val);
            id+=(id&-id);
        }
    }
    int query(int id){
        int ans=0;
        while(id>0){
            ans=max(bit[id],ans);
            id-=(id&-id);
        }
        return ans;
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool>ans;
        ft(queries);
        set<int>ob;
        //build all obstacle
        ob.insert(0);
        ob.insert(n+1);
        for(auto q:queries){
            if(q[0]==1){
                ob.insert(q[1]);
            }
        }
        for(auto it=ob.begin();it!=ob.end();it++){
            if(it==ob.begin())continue;
            auto p=prev(it);
            int x=*it;
            add(x,x-*p);
        }
        for(int i=queries.size()-1;i>=0;i--){
            if(queries[i][0]==1){
                int x=queries[i][1];
                auto it=ob.find(x);
                auto prv=prev(it);
                auto nxt=next(it);
                ob.erase(it);
                add(*nxt,*nxt-*prv);
            }else{
                int x=queries[i][1];
                int sz=queries[i][2];
                auto nxt=ob.upper_bound(x);
                auto prv=prev(nxt);
                int maxgap=max(query(*prv),x-*prv);
                ans.push_back(maxgap>=sz);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};