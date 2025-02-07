#include <iostream>
using namespace std;

void regresionLineal(double *x,double *y,int *n,double* m, double *b){
  double sumX=0.0,sumY=0.0,sumXY=0.0,sumX2=0.0;
  
  for(int i=0;i<n;i++){
  sumX+= *(x+i);
    
  sumY+= *(y+i);
    
  sumXY+=(*(x+i))*(*(y+i));
    
  sumX2+=(*(x+i))*(*(x+i));
    
  }
  *m=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
  *b=(sumY-(*m)*sumX)/n;




}

int main() {  
const int n=5;
double x[]={1,2,3,4,5};
double y[]={2.2,2.8,4.5,3.7,5.5};
double m=0,b=0;
regresionLineal(x,y,n,&m,&b);
cout<<"la ecuacion de la recta es: y="<<m<<"x+"<<b<<endl;

}

