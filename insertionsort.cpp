#include <iostream>
#include <fstream>

using namespace std;
int insertionsort(int *A, int n){
    int i=1;
    int cont=0;
    while(i<n){
        int j=i;
        while(j>0){
            if(A[j-1]>A[j]) {
                cont++;
                swap(A[j], A[j - 1]);
            }
            j--;
        }
        i++;
    }
    return cont;
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
        out<<insertionsort(A,n)<<endl;
    }

}