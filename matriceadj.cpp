#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
template <class H> class MatADJ{
private:
    int n;
    int m;
    int dim;
    H *K;
    bool **mat;
public:
    MatADJ<H>(int dim){
        n=m=0;
        this->dim=dim;
        K= new H[dim];
        mat=new bool*[dim];
        for(int i=0;i<dim;i++){
            K[i]=-1;
            mat[i]=new bool[dim];
        }
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                mat[i][j]=false;
            }
        }
    }
    bool isEmpty(){
        return n==0;
    }
    bool isFull(){
        return n>=dim;
    }
    int searchVertex(H v){
        if(isEmpty()){
            return -1;
        }else{
            for(int i=0;i<n;i++){
                if(K[i]==v){
                    return i;
                }
            }
            return -1;
        }
    }
    void addvertex(H v){
        if(isFull()){
            return;
        }else{
            if(searchVertex(v)>=0){
                return;
            }else{
                K[n]=v;
                n++;
            }
        }
    }
    bool searchEdge(H v1, H v2){
        if(isEmpty()){
            return false;
        }else{
            if(searchVertex(v1)<0 || searchVertex(v2)<0){
                return false;
            }else{
                return mat[searchVertex(v1)][searchVertex(v2)] == 1;
            }
        }
    }
    void addEdge(H v1, H v2){
        if(isEmpty()){
            return;
        }else{
            if(searchVertex(v1)<0||searchVertex(v2)<0){
                return;
            }else{
                if(searchEdge(v1,v2)==false){
                    mat[searchVertex(v1)][searchVertex(v2)]=true;
                    m++;
                }else{
                    return;
                }
            }
        }
    }
    void sortVertex(){
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(K[i]>K[j]){
                    swap(K[i],K[j]);
                }
            }
        }
    }
    string printGrafo(){
        stringstream ss;
        string result;
        if(isEmpty()){
            return NULL;
        }else{
            for(int i=0;i<n;i++){
                ss<<"("<<K[i];
                for(int j=0;j<n;j++){
                    if(mat[i][j]==true){
                        ss<<" "<<K[j];
                    }
                }
                ss<<") ";
            }
            ss<<endl;
        }
        result=ss.str();
        return result;
    }

};
/*int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        int vertex=0;
        int edge=0;
        string type="";
        in>>vertex;
        in>>edge;
        in>>type;
        if(type=="int"){
            MatADJ<int> *m1= new MatADJ<int>(vertex);
            for(int j=0;j<vertex;j++){
                int data=0;
                in>>data;
                m1->addvertex(data);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string data="";
                in>>data;
                int v1=atoi(data.substr(1,2).c_str());
                in>>data;
                int v2=atoi(data.substr(0,2).c_str());
                m1->addEdge(v1,v2);
            }
            out<<m1->printGrafo();
        }else if(type=="double"){
            MatADJ<double> *m1= new MatADJ<double>(vertex);
            for(int j=0;j<vertex;j++){
                double data=0;
                in>>data;
                m1->addvertex(data);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string data="";
                in>>data;
                double v1=atof(data.substr(1,3).c_str());
                in>>data;
                double v2=atof(data.substr(0,3).c_str());
                m1->addEdge(v1,v2);
            }
            out<<m1->printGrafo();
        }else if(type=="char"){
            MatADJ<char> *m1= new MatADJ<char>(vertex);
            for(int j=0;j<vertex;j++){
                char data=' ';
                in>>data;
                m1->addvertex(data);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string data="";
                in>>data;
                char v1=data[1];
                in>>data;
                char v2=data[0];
                m1->addEdge(v1,v2);
            }
            out<<m1->printGrafo();
        }else if(type=="bool"){
            MatADJ<bool> *m1= new MatADJ<bool>(vertex);
            for(int j=0;j<vertex;j++){
                bool data=0;
                in>>data;
                m1->addvertex(data);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string data="";
                in>>data;
                int v1=atoi(data.substr(1,2).c_str());
                in>>data;
                int v2=atoi(data.substr(0,2).c_str());
                m1->addEdge(v1,v2);
            }
            out<<m1->printGrafo();
        }
    }
}*/