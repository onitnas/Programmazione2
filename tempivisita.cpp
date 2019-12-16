#include <iostream>
#include <fstream>
#include <sstream>
#define  W 0
#define  G 1
#define  B 2
#define Inf -1

using namespace std;
template <class H> class MADJ{
private:
    int n;
    int m;
    int dim;
    H *K;
    bool ** Madj;
    int tempovisita;
    int currentroot;
    int * tempoPartenza;
    int * colorati;
    int * distanze;
    int * completamento;
    int * radici;
    int * precedenti;

public:
    MADJ<H>(int d){
        dim=d;
        n=m=0;
        K= new H[dim];
        Madj= new bool *[dim];
        tempovisita=0;
        tempoPartenza= new int[dim];
        colorati=new int[dim];
        distanze= new int[dim];
        completamento= new int[dim];
        radici= new int[dim];
        precedenti= new int[dim];
        for(int i=0;i<dim;i++){
            K[i]=-1;
            Madj[i]=new bool[dim];
            tempoPartenza[i]=-1;
            colorati[i]=W;
            distanze[i]=-1;
            completamento[i]=-1;
            radici[i]=-1;
            precedenti[i]=-1;
        }
        for(int i=0;i<dim;i++){
            for(int j=0;j<dim;j++){
                Madj[i][j]=false;
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
    void addVertex(H v){
        if(isFull()){
            return;
        }else{
            if(searchVertex(v)<0){
                K[n]=v;
                n++;
            }else{
                return;
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
    bool searchEdge(H v1, H v2){
        if(isEmpty()){
            return false;
        }else{
            if(searchVertex(v1)<0 || searchVertex(v2)<0){
                return false;
            }else{
                return Madj[searchVertex(v1)][searchVertex(v2)];
            }
        }
    }
    void addEdge(H v1, H v2){
        if(isEmpty()){
            return;
        }else{
            if(searchVertex(v1)<0 || searchVertex(v2)<0){
                return;
            }else{
                if(!searchEdge(v1,v2)){
                    Madj[searchVertex(v1)][searchVertex(v2)]=true;
                    m++;
                }
            }
        }
    }
    string printGrafo(){
        stringstream ss;
        if(isEmpty()){
            return "grafo vuoto";
        }else{
            for(int i=0;i<n;i++){
                ss<<"("<<K[i];
                for(int j=0;j<n;j++){
                    if(Madj[i][j]){
                        ss<<" "<<K[j];
                    }
                }
                ss<<") ";
            }
            ss<<endl;
        }
        return ss.str();
    }
    void DFSVisit(int index){
        colorati[index]=G;
        radici[index]=currentroot;
        tempoPartenza[index]=tempovisita++;
        for(int i=0;i<n;i++){
            if(Madj[index][i]){
                if(colorati[i]==W) {
                    precedenti[i] = index;
                    DFSVisit(i);
                }
            }
        }
        colorati[index]=B;
        completamento[index]=tempovisita++;
    }
    string DFS(){
        stringstream ss;
        for(int i=0;i<n;i++){
            if(colorati[i]==W){
                currentroot=i;
                DFSVisit(i);
            }
            ss<<"("<<K[i]<<" "<<tempoPartenza[i]<<" "<<completamento[i]<<") ";
        }
        ss<<endl;
        return ss.str();
    }
};
int main(){
    fstream in;
    fstream out;
    in.open("input.txt");
    out.open("output.txt");
    for(int i=0;i<100;i++){
        string type;
        int node;
        int edge;
        in>>node;
        in>>edge;
        in>>type;
        if(type=="int"){
            MADJ<int> * m1= new MADJ<int>(node);
            for(int j=0;j<node;j++){
                int dato;
                in>>dato;
                m1->addVertex(dato);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string dato;
                in>>dato;
                int d1=atoi(dato.substr(1).c_str());
                in>>dato;
                int d2=atoi(dato.substr(0,2).c_str());
                m1->addEdge(d1,d2);
            }
            out<< m1->DFS();
        }else if(type=="double"){
            MADJ<double> * m1= new MADJ<double>(node);
            for(int j=0;j<node;j++){
                double dato;
                in>>dato;
                m1->addVertex(dato);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string dato;
                in>>dato;
                double d1=atof(dato.substr(1).c_str());
                in>>dato;
                double d2=atof(dato.substr(0,3).c_str());
                m1->addEdge(d1,d2);
            }
            out<< m1->DFS();
        }else if(type=="char"){
            MADJ<char> * m1= new MADJ<char>(node);
            for(int j=0;j<node;j++){
                char dato;
                in>>dato;
                m1->addVertex(dato);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string dato;
                in>>dato;
                int d1=dato[1];
                in>>dato;
                int d2=dato[0];
                m1->addEdge(d1,d2);
            }
            out<< m1->DFS();
        }else if(type=="bool"){
            MADJ<bool> * m1= new MADJ<bool>(node);
            for(int j=0;j<node;j++){
                bool dato;
                in>>dato;
                m1->addVertex(dato);
            }
            m1->sortVertex();
            for(int j=0;j<edge;j++){
                string dato;
                in>>dato;
                bool d1=atoi(dato.substr(1).c_str());
                in>>dato;
                bool d2=atoi(dato.substr(0,2).c_str());
                m1->addEdge(d1,d2);
            }
            out<< m1->DFS();
        }
    }
}