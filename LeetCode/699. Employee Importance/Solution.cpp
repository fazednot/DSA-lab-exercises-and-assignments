// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
    int ans = 0;
    void dfs(vector<Employee*> employees, int node, vector<int>&vis,map<int,int>indx){
        vis[node]=1;
        ans+=employees[node]->importance;
        vector<int>adj = employees[node]->subordinates;
        for(auto it: adj){
            if(!vis[indx[it]]){
                dfs(employees,indx[it],vis,indx);
            }
        }
        return ;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        vector<int>vis(employees.size(),0);
        map<int,int>indx;
        for(int i=0;i<employees.size();i++){
            indx[employees[i]->id] = i;
        }
        dfs(employees,indx[id],vis,indx);
        return ans;
    }
};