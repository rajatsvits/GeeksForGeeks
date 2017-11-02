#include<iostream>
#include<cstring>
using namespace std;
//lps longest prefix sum which is equal to suffix to

void calculateLPS(int *a,char *pat)
{
    int m=strlen(pat);
    //cout<<m;
    int len=0;
    int i=1;
    a[0]=0;
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            a[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = a[len-1];
            }
            else
            {
                a[i]=0;
                i++;
            }
        }
    }
}

void KMP(char *pat,char *txt)
{
    int p=strlen(pat);
    int t=strlen(txt);
    //cout<<p<<t;
    int lps[p];
    calculateLPS(lps,pat);
    for(int i=0;i<p;i++)
        cout<<lps[i]<<" ";
    int i=0;
    int j=0;
    while(i<t)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==p)
        {
            cout<<"Found Pattern at: "<<i-j<<" till "<<i<<endl;
            j=lps[j-1];
        }

        else if(i<t&&pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
                i++;
        }
        //i++;
    }
}
int main()
{


    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMP(pat, txt);
    return 0;
}
