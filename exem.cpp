/*
ALGORITHM:
given an array arr of size n.
i(depth): 1-->log2(n) 


the time taken by this algorithm:

*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void EquateArray(int* &A,int* &B,int n){
    for (int i = 0; i < n; i++)
    {
        A[i]=B[i];
    }  
}

void printArray(int* arr,int n){
    cout<<"[";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]";
}


int* KoggStone(int* arr,int n){
    int arr2[n];
    int* arr3=arr2;
    arr2[0]=arr[0];
    for (int i = 0; i <log2(n) ; i++)
    {
       for (int j = 0; j < n; j++)
       {
        if((j-exp2(i))>=0){
            arr2[j]=arr[j]+arr[(int)(j-exp2(i))];
        }
       }
        EquateArray(arr,arr3,n);
    }
    return arr;
    }

int main() {
int n;
cout<<"enter the number of elements of the array"<<endl;
cin>>n;
int arr[n];
cout<<"enter the elements :"<<endl;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
printArray(KoggStone(arr,n),n);
return 0;
}

