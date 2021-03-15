#include <stdio.h>


void escreveValor(int nLin, int nCol, int a[][nCol]){
    int lin, col;
    
    printf("Linha e Coluna: ");
    scanf("%d %d", &lin, &col);
    
    if(lin<0 || lin>=nLin || col<0 || col >= nCol)
        return;
    
    printf("Valor em (%d, %d): %d\n", lin, col, a[lin][col]);
}

int main(){
    
    int m1[2][2] = {{1,2},
                    {3,4}};
                    
    int m2[2][3] = {{1,2,3},
                    {4,5,6}};
    
    int m3[3][4] = {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12}};
     
    printf("%d %d %d\n", m3[0][2], *(m3[1]-1), *(m3[2]+2));
    
/*
    escreveValor(2, 2, m1);    
    escreveValor(2, 3, m2);   
    escreveValor(3, 4, m3);   
*/
    return 0;
}


