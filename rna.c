/*#include<stdio.h>
#include<string.h>

int is_rna(a,b){
  return(a=='A' && b=='U') || (a=='U' && b=='A') || (a=='C' && b=='G')||(a=='G' && b=='C');
}

int main(){
    char S[]= " ACCGGUAGU";
    int n = 9;
    int M[12][12] = {0};
    for(int l = 5; l < n; l++){
        for(int i = 1; i + l <= n; i++){
            int j = i + l;
            int best = M[i+1][j];
            if(M[i][j-1] > best) best = M[i][j-1];
            if(is_rna(S[i],S[j])){
                int c = M[i+1][j-1]+1;
                if(c > best) best = c; 
            }
            for(int k = i+1; k < j; k++){
                int c = M[i][k] + M[k+1][j];
                if(c > best) best = c;
            }
            M[i][j] = best;
        }
    }
    printf("Max pairs = %d\n",M[1][n]);
    return 0;
}

*/
#include <stdio.h>
#include <string.h>

#define MAXN 100
int memo[MAXN][MAXN];
int seen[MAXN][MAXN];

int is_rna(char a, char b){
    return (a=='A' && b=='U') || (a=='U' && b=='A') ||
           (a=='C' && b=='G') || (a=='G' && b=='C');
}

int nussinov(char *S, int i, int j){
    if (j - i <= 4) return 0;
    if (seen[i][j]) return memo[i][j];

    int best = nussinov(S, i+1, j);

    int opt = nussinov(S, i, j-1);
    if (opt > best) best = opt;

    if (is_rna(S[i], S[j])) {
        int c = nussinov(S, i+1, j-1) + 1;
        if (c > best) best = c;
    }

    for (int k = i+1; k < j; k++){
        int c = nussinov(S, i, k) + nussinov(S, k+1, j);
        if (c > best) best = c;
    }

    memo[i][j] = best;
    seen[i][j] = 1;
    return best;
}

int main(){
    char S[] = " ACCGGUAGU";
    int n = 9;

    memset(seen, 0, sizeof(seen));

    printf("Max pairs = %d\n", nussinov(S, 1, n));
    return 0;
}