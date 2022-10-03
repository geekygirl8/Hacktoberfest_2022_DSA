// Mudit - https://github.com/MuditJain5
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution 
{
    public:
    
    bool static comp(Job &j1, Job &j2){
        
        return j1.profit > j2.profit;

    }

    vector<int> JobScheduling(Job arr[], int n) 
    { 

        sort(arr, arr+n, comp);
        
        int cnt = 0, p = 0;
        vector<int> d(101, 0);
        
        for(int i = 0; i < n; i++){
            
            for(int j = arr[i].dead; j > 0; j--){
                if(d[j] == 0){
                    d[j] = 1;
                    cnt++;
                    p += arr[i].profit;
                    break;
                }
            }
            
        }
        
        return {cnt, p};
        
    } 
};
