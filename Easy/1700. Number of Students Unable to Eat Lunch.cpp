class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> p;
        queue<int> q;
        int n = students.size();
        int m = sandwiches.size();
        for(int i=0;i<n;i++){
            p.push(students[i]);
        }
        for(int i=0;i<m;i++){
            q.push(sandwiches[i]);
        }
        int k = 0;
        while(n > 0 && m > 0){
            if(p.front() == q.front()){
                p.pop();
                q.pop();
                k = 0;
                n--;
                m--;
            }
            else{
                int a = p.front();
                p.pop();
                p.push(a);
                k++;
                if(k > p.size()){
                    break;
                }
            }
        }
        return p.size();
    }
};