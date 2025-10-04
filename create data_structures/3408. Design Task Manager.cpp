#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class TaskManager {
public:
    vector < vector<int>> tasks;
    unordered_map<int,int> task_pri; // task -> priority
    unordered_map<int,int> task_user; //taskid -> userId
    priority_queue<pair<int,int >> pri_task; //priority->task

    TaskManager(vector<vector<int>>& task) {
        tasks = task;
        for (auto& it : task) {
            int userid = it[0]; int taskid =it[1] ; int priority = it[2];
           task_pri[taskid]=priority;
            task_user[taskid]=userid;
            pri_task.push({priority,taskid});
        }
    }

    void add(int userId, int taskId, int priority) {
         task_pri[taskId]=priority;
            task_user[taskId]=userId;
            pri_task.push({priority,taskId});

    }

    void edit(int taskId, int newPriority) {
        task_pri[taskId]=newPriority;
        pri_task.push({newPriority,taskId});

    }

    void rmv(int taskId) {
        task_pri.erase(taskId);
            task_user.erase(taskId);

    }

    int execTop() {
        while(!pri_task.empty()){
            auto [pri , task ]= pri_task.top();
            pri_task.pop();
            if(task_pri.find(task) != task_pri.end() && task_pri[task] == pri) {
                int user = task_user[task];
                rmv(task);
                return user;
            } 

        }
        return -1;
        
    }
};
