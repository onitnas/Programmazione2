#include <iostream>
#include <fstream>

using namespace std;

void merge(int *A, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //Create temp Arrays
    int M1[n1], M2[n2];

    //Insert A[] to temp ARRAYS
    for (i = 0; i < n1; i++) {
        M1[i] = A[l + i];
    }
    for (j = 0; j < n2; j++) {
        M2[j] = A[m + 1 + j];
    }
    i = j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (M1[i] <= M2[j]) {
            A[k] = M1[i];
            i++;
        } else {
            A[k] = M2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = M1[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = M2[j];
        j++;
        k++;
    }
}
void mergeSort(int *A,int l,int r, int &contatore){
    if(l<r){
        int m=l+(r-l)/2;
        contatore+=A[l];
        mergeSort(A,l,m,contatore);
        mergeSort(A,m+1,r,contatore);
        merge(A,l,m,r);
    }
}

int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        int n;
        in>>n;
        int *A= new int[n];
        for(int j=0;j<n;j++){
            int dato;
            in>>dato;
            A[j]=dato;
        }
        int cont=0;
        mergeSort(A,0,n-1,cont);
        out<<cont<<endl;
    }
}
