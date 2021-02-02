#include<bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x)) 
#define EPS 1e-6 
#define N 5

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x) , y(y) {}
};

struct line {
    int a,b,c;
    line(int a,int b,int c) : a(a), b(b), c(c) {}
};

double dist(point p, double x,double y) {
    return sqrt(sq(x-p.x) + sq(y-p.y));
}

double calculateDist(point p[],int n, line l, double X) {
    double res =0;
    double Y = -1 * ((l.a*X + l.c)/(l.b));
    for(int i=0;i<n;i++) {
        res += dist(p[i],X,Y);
    }
    return res;
}

double findOptimumCostUtil(point p[], line l, int n) {
      
      double low = -1e6;
      double high = 1e6;

      while((high-low) > EPS) {
           
           double mid1 = low+(high-low)/3;
           double mid2 = high-(high-low)/3;

           double dist1 = calculateDist(p,n,l,mid1);
           double dist2 = calculateDist(p,n,l,mid2);

           if(dist1 > dist2) {
               low = mid1;
           }
           else {
               high = mid2;
           }
      }
      return calculateDist(p,n,l,((low+high)/2));
}

double findOptimumCost(int points[N][2], line l) {
     point p[N];
     for(int i=0;i<N;i++){
         p[i] = point(points[i][0], points[i][1]);
     }
     return findOptimumCostUtil(p,l,N);
}

int main() {
    
    line l(0, -1, -3); 
    int points[N][2] = {{-3, -2}, {-1, 0}, {-1, 2}, 
                                   {1, 2}, {3, 4}}; 
    cout << findOptimumCost(points, l) << endl;
}