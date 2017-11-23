// C++ program to find hamming distance b/w two string
#include<bits/stdc++.h>
using namespace std;
 
int hammingDistance(char *str1, char *str2)
{
    int i = 0, count = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}
 
int main()
{
    char str1[] = "IsRajatMahajan";
    char str2[] = "KunjeshMahajan";
 
    cout << hammingDist (str1, str2);
 
    return 0;
} 
