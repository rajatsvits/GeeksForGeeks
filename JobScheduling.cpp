//Job executing for a unit of time
#include<iostream>
//#include<cstdlib>
#include<algorithm>

using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;

};

bool compare(Job a,Job b)
{
    return a.profit>b.profit;
}
void JobScheduling(Job JobArray[],int n)
{
    //int n=sizeof(JobArray)/sizeof(JobArray[0]);
    //cout<<n;
    sort(JobArray,JobArray+n,compare);
    bool slot[n]={false};
    int result[n];
//for(int i=0;i<n;i++)
  //  cout<<slot[i];
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,JobArray[i].deadline)-1;j>=0;j--)
        {
            //cout<<j<<" "<<JobArray[i].deadline<<" ";
            if(slot[j]==false)
            {
                //cout<<JobArray[i].id<<" ";
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
        //cout<<endl;
    }
//for(int i=0;i<n;i++)
  //  cout<<slot[i];
    for(int i=0;i<n;i++)
        if(slot[i])
            cout<<JobArray[result[i]].id<<" ";
}
int main()
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    JobScheduling(arr,n);
    return 0;
}
