#include <iostream>
#include <fstream>

using namespace std;

long fibonacci(int n){
    long a=0;
    long b=1;
    long temp=0;
    if(n==0 || n==1){
        return 1;
    }else{
        for(int i=1;i<n;i++) {
            temp=a;
            a=b;
            b=temp+a;
        }
        return b;
    }
}
/*int main() {
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        int f=0;
        in>>f;
        out<<fibonacci(f)<<endl;
    }
}*/