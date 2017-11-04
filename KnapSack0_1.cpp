
#include<iostream>
using namespace std;
/*struct Item
{
    long int value;
    long int weight;
    Item(int v,int w): value(v),weight(w){}

};
*/

int knapSack0_1(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}


int KnapSack0_1(int MaxW,int W[],int val[],int n)
{
    int i,j;
    int k[n+1][MaxW+1];
    for(i=0;i<=n;i++)
    {
        for( j=0;j<=MaxW;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            else if(W[i-1]<=j)
                k[i][j]=max(val[i-1]+k[i-1][j-W[i-1]],k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
            //cout<<k[i][j]<<" "<<MaxW<<" "<<n<<" "<<i<<" "<<j<<endl;

        }
        //cout<<endl;
    }/**/
    for( i=0;i<=n;i++)
    {
        for(j=0;j<=MaxW;j++)
        {
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }/**/
    return k[n][MaxW];
}/**/

int Knapsack0_1(int MaxW,int W[],int val[],int n)
{
    if(n==0||MaxW==0)
        return 0;

    if(W[n-1]>MaxW)
        return Knapsack0_1(MaxW,W,val,n-1);

    return max(val[n-1]+Knapsack0_1(MaxW-W[n-1],W,val,n-1),Knapsack0_1(MaxW,W,val,n-1));
}/**/
int main()
{
     int val[] = { 100,60, 120};
    int wt[] = {10, 20, 30};
    int  W = 10;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack0_1(W, wt, val, n)<<endl;
    cout<<Knapsack0_1(W, wt, val, n)<<endl;
    cout<<KnapSack0_1(W, wt, val, n)<<endl;
    return 0;

    return 0;
}
