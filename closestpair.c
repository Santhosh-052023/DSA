#include<stdio.h>
#include<math.h>
#include<float.h>
#include<Stdlib.h>


typedef struct{
    double x;
    double y;
} Point;

double distance(Point a, Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double brute(Point p[], int n){
    double min = DBL_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double d = distance(p[i],p[j]);
            if (d < min){
                min = d;
            }
        }
    }
    return min;
}

int compareY(const void *a, const void *b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if(p1 -> y < p2 -> y){
        return -1;
    }
    if(p1-> y > p2 -> y){
        return 1;
    }
    return 0;
}
int compareX(const void *a, const void *b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if(p1 -> x < p2 -> x){
        return -1;
    }
    if(p1-> x > p2 -> x){
        return 1;
    }
    return 0;
}
double closestPair(Point p[], int n){
    if (n <= 3){
        return brute(p,n);
    }
    int mid = n / 2;
    double midx = p[mid].x;
    double left = closestPair(p,mid);
    double right = closestPair(p + mid, n - mid);
    double delta;
    if(left < right){
        delta = left;
    }
    else{
        delta = right;
    }
    Point S[100];
    int k = 0;
    for(int i = 0; i < n; i++){
        if(fabs(p[i].x - midx) < delta){
            S[k] = p[i];
            k++;
        }
    }
    qsort(S , k, sizeof(Point), compareY);
     for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k && j <= i + 15; j++){
            double d = distance(S[i],S[j]);
            if(d < delta){
                delta = d;
            }
        }
     }
     return delta;
}

int main()
{
    Point p[] = {
        
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };

    int n = sizeof(p) / sizeof(p[0]);

    qsort(p, n, sizeof(Point), compareX);

    double answer = closestPair(p, n);

    printf("Closest distance = %.2f\n", answer);

    return 0;
}