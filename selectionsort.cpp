#include <iostream>
#include <fstream>

using namespace std;
int selectionsort(int *A, int n){
    int somma=0;
    int temp;
    for(int i=0;i<n-1;i++){
        temp=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[temp]){
                temp=j;
            }
        }
        somma=somma+(temp-i);
        swap(A[temp],A[i]);
    }
    return somma;
}
int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        int n;
        in>>n;
        int A[n];
        for(int j=0;j<n;j++){
            in>>A[j];
        }
        out<<selectionsort(A,n)<<endl;
    }
}