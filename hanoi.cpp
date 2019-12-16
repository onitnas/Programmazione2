#include <iostream>
#include <fstream>
using namespace std;
int cont=0;
void hanoi(int iniziale, int centrale, int finale, int n, int m, fstream &out){
    if(n==1){
        cont++;
        if(cont==m) {
            out << iniziale << " " << finale << endl;
        }
    }else{
        hanoi(iniziale,finale,centrale,n-1,m,out);
        cont++;
        if(cont==m) {
            out << iniziale << " " << finale << endl;
        }
        hanoi(centrale,iniziale,finale,n-1,m,out);
    }
}
int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        int n;
        int m;
        in>>n;
        in>>m;
        cont=0;
        hanoi(1,2,3,n,m,out);
    }
}