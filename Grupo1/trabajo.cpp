
#include <iostream>
using namespace std;

void regresionLineal(double *x, double *y, int n, double *m, double *b) {
  double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
  
  for(int i = 0; i < n; i++) {
    sumX += x[i];
    sumY += y[i];
    sumXY += x[i] * y[i];
    sumX2 += x[i] * x[i];
  }
  
  *m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  *b = (sumY - (*m) * sumX) / n;
}

void gradienteDescendente(double *x, double *y, int n, double *m, double *b, double alpha, int iteraciones) {
  *m = 0.0;
  *b = 0.0;
  
  for(int i = 0; i < iteraciones; i++) {
    double gradienteM = 0.0;
    double gradienteB = 0.0;
    
    for(int j = 0; j < n; j++) {
      double prediccion = (*m) * x[j] + *b;
      gradienteM += -2 *(*(x+j)*(*(y+j))-prediccion);
      gradienteB += -2 * ((*y+j) - prediccion);
    }
    
    *m -= (alpha * gradienteM) / n;
    *b -= (alpha * gradienteB) / n;
  }
}

int main() {
  const int n = 5;
  double x[] = {1, 2, 3, 4, 5};
  double y[] = {2.2, 2.8, 4.5, 3.7, 5.5};
  double m = 0, b = 0;
  double alpha = 0.01;
  int iteraciones = 1000;
  
  regresionLineal(x, y, n, &m, &b);
  cout << "Regresión lineal - La ecuación de la recta es: y = " << m << "x + " << b << endl;
  
  m = 0;
  b = 0;
  gradienteDescendente(x, y, n, &m, &b, alpha, iteraciones);
  cout << "Gradiente descendente - La ecuación de la recta es: y = " << m << "x + " << b << endl;
  
  return 0;
}
