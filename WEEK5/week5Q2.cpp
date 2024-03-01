#include<iostream>
using namespace std;

int summm(int arr[],int n,int key)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;i++)
        {
            if(arr[i]+arr[j]==key)
            {
                cout<<arr[i]<<" "<<arr[j];
            }
        }
    }
    cout<<"No such element exist";
}
int main()
{
    int t,n,key,arr[20];
    cout<<"Enter no of test cases:";
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Enter size of array:";
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cout<<"Enter element:";
            cin>>arr[j];
        }
        cout<<"Enter key element:";
        cin>>key;
        summm(arr,n,key);
    }
}
