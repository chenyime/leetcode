/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        dfs(employees, id, res);
        return res;
    }
    
    void dfs(vector<Employee*> employees, int id, int& res) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                res += employees[i]->importance;
                for (auto emp : employees[i]->subordinates) {
                    dfs(employees, emp, res);
                }
            }
        }
    }
    
    int getImp(vector<Employee*> employees, int id) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id)
                return employees[i]->importance;
        }
        return 0;
    }
};