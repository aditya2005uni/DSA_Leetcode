class Solution {
    public:
    bool ispalin(string s){
        if(s.size()==0 || s.size()==1){
            return true;
        }
        string str=s;
        int i=0;
        int j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        if(str==s){
            return true;
        }
        return false;
    }
    void fun(vector<vector<string>>&ans,vector<string>&out,string s){
        if(s.size()==0){
            ans.push_back(out);
        }
        for(int i=0;i<s.size();i++){
            string str=s.substr(0,i+1);
            if(ispalin(str)){
                out.push_back(str);
                fun(ans,out,s.substr(i+1));
                out.pop_back();
            }

        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>out;
        fun(ans,out,s);
        return ans;
    }
};