#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    vector<int>at(n);
    for(int i=0; i<n; i++)
    {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>at[i];
    }

    vector<int>bt(n);
    vector<int>rt(n);
    for(int i=0; i<n; i++)
    {
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>bt[i];
        rt[i]=bt[i];
    }

    vector<int>tat(n);
    vector<int>wt(n);

    int time=0,completed_Processes=0;
    int total_tat=0,total_wt=0;

    for(time=0; completed_Processes!=n; time++)
    {

        int selected_Process_index=-1;

        for(int i=0; i<n; i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(selected_Process_index==-1 || rt[i]<rt[selected_Process_index] )
                {
                    selected_Process_index=i;
                }

            }
        }


        if(selected_Process_index==-1)
        {
            time++;
            continue;
        }


        rt[selected_Process_index]--;


        if(rt[selected_Process_index]==0)
        {
            completed_Processes++;
            int ct=time+1;

            tat[selected_Process_index]=ct-at[selected_Process_index];
            wt[selected_Process_index]=tat[selected_Process_index]-bt[selected_Process_index];

            total_tat=total_tat+tat[selected_Process_index];
            total_wt=total_wt+wt[selected_Process_index];

        }
    }

    cout << "\nPID\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "Average Waiting Time: " <<(float)total_wt/n << endl;
    cout << "Average Turnaround Time: " <<(float)total_tat/n<<endl;

}
