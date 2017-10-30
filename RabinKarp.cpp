#include<iostream>
#include<cstring>
using namespace std;
void search(char txt[],char pat[],int q)
{
    int n=strlen(txt);
    int m=strlen(pat);
    //cout<<n<<" "<<m;
    int h=1;
    int d=256;
    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }
   // cout<<h<<" "<<m;
    int p=0,t=0;
    for(int i=0;i<m;i++)
    {
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
         //cout<<pat[i]<<" "<<txt[i]<<endl;
    }
    //cout<<p<<" "<<t<<endl;
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(txt[i+j]!=pat[j])
                    break;
            }
        }
        //cout<<p<<" "<<t<<endl;
        if(j==m)
            cout<<"Match found from "<<i<<" to "<<i+m<<endl;

        if(i<n-m)
        {
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0)
                t+=q;
        }
    }
}
int main()
{
    char txt[]="Rajat Mahajjajja Kunjesh Mahajjajja";
    char pat[] = "ajja";
    int q=101;
    search(txt,pat,q);
    return 0;
}
