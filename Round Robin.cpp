#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cout << "Enter number of processes: ";
    cin >> n;


    vector<int> at(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> at[i];
    }


    vector<int> bt(n);
    vector<int> rt(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
    }


    int tq;
    cout<<"Enter time quantum: ";
    cin>>tq;

    vector<int> tat(n);
    vector<int> wt(n);
    vector<int>mark(n);

    queue<int>q;

    int time = 0;

    for(int i=0; i<n; i++)
    {
        if(at[i]==0)
        {
            q.push(i);
            mark[i]=1;
        }
    }

    while(q.size()!=0)
    {

        int current_Process_index=q.front();
        q.pop();

        int execution_time=min(tq,rt[current_Process_index]);
        rt[current_Process_index]=rt[current_Process_index]-execution_time;
        time=time+execution_time;

        for(int i=0; i<n; i++)
        {
            if(at[i]<=time && mark[i]==0)
            {
                q.push(i);
                mark[i]=1;
            }
        }

        if(rt[current_Process_index]>0)
        {
            q.push(current_Process_index);
        }
        else
        {
            tat[current_Process_index] = time - at[current_Process_index];
            wt[current_Process_index] = tat[current_Process_index] - bt[current_Process_index];
        }
    }

    cout << "\nPID\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    int total_tat=0,total_wt=0;
    for(int i=0; i<n; i++)
    {
        total_tat=total_tat+tat[i];
        total_wt=total_wt+wt[i];
    }

    cout << "Average Waiting Time: " << (float)total_wt / n << endl;
    cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
}
