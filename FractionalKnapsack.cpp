
#include<iostream>
#include<algorithm>
using namespace std;
struct Item
{
    int value;
    int weight;

    Item(int v,int w): value(v),weight(w){}

} ;

bool comp (Item a,Item b)
{
    double x= (double)a.value/a.weight;
    double y= (double)b.value/b.weight;
    return x>y;
}

double FractionalKnapsack (Item arr[],int n,int w)
{
        sort(arr,arr+n,comp);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].value << "  " << arr[i].weight << " : "
                 << ((double)arr[i].value / arr[i].weight) << endl;
        }
        int currentweight=0;
        double finalValue=0;
        for (int i = 0; i < n; i++)
        {
            if(currentweight+arr[i].weight<=w)
            {
                currentweight+=arr[i].weight;
                finalValue+=arr[i].value;
            }
            else if(currentweight<w)
            {
                int remain = w-currentweight;
                finalValue+=arr[i].value*((double)remain/arr[i].weight);
            }
            else
                break;

        }
        return finalValue;
}

int main()
{
    int W = 50;   //    Weight of knapsack
    Item arr[] = {{100, 20},{60, 10},  {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value we can obtain = "
         << FractionalKnapsack( arr, n,W);
    return 0;
}
