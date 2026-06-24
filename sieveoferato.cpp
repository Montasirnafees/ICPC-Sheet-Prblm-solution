#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number : ";
    cin >> n;
    bool prime[1000];
    for(int i=0;i<=n;i++)
    {
        prime[i] = true;
    }
    prime[0] = false,prime[1] = false;

    for(int i=2;i*i<=n;i++)
    {
        if(prime[i] == true)
        {
            for(int j=i*i;j<=n;j += i)
            {
                prime[j] = false;
            }
        }
    }
    cout<<"The prime num are : ";
    for(int i=2;i<=n;i++)
    {
        if(prime[i] == true)
        {
            cout << i << " ";
        }
    }

    return 0;
}
