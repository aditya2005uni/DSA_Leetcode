class Solution {
    public:
    bool isvalid(string str){
        if(str.size()%2!=0){
            return false;
        }
        int cnt=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                cnt=cnt+1;
            }
            else{
                cnt=cnt-1;
                if(cnt<0){
                    return false;
                }
            }
        }
        return cnt==0;
    }
    void fun(vector<string>&ans,string &res,int n){
        if(res.size()==n*2){
            if(isvalid(res)){
                ans.push_back(res);
            }
            return;
        }
        res.push_back('(');
        fun(ans,res,n);

        res.pop_back();

        res.push_back(')');
        fun(ans,res,n);

        res.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res="";
        fun(ans,res,n);
        return ans;
    }
};