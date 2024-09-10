/*Nome: Alan Lucindo Gomes, N° Usp: 7572130  */


/*Infelizmente não consegui fazer a tarefa 3 a tempo.... Nem o Lucas Mariano.:/ */
#include <stdio.h>
#include <stdlib.h>
#define LIMx 1024 /*Aqui eh a quantidade de linhas, pode ser decidida pelo programador.*/
#define LIMy 768 /*Aqui eh a quantidade de colunas. Também pode ser decidida pelo programador.*/
/*Ambos os LIM definem a resolução da imagem.*/
double X1, X2, Y1, Y2,x,y, a, dx, dy, b ,Y[LIMy][LIMx],X[LIMy][LIMx],M[LIMy][LIMx], A, B, C;
int main()
{
int ite, i, j, c;

printf("Digite o numero de iteracoes maximas: ");
scanf("%d", &ite);
printf("Digite a coordenada do x inferior esquerdo: ");
scanf("%lf", &X1);
printf("Digite a coordenada do y inferior esquerdo: ");
scanf("%lf", &Y1);
printf("Digite a coordenada do x superior direito: ");
scanf("%lf", &X2);
printf("Digite a coordenada do y superior direito: ");
scanf("%lf", &Y2);
FILE *arq;
arq = fopen("mandelbrot.pgm", "w");
fprintf(arq, "P2\n%d %d\n255\n", LIMx, LIMy);
a = Y2-Y1; /*calculando delta Y*/
b = X2-X1; /*calculando delta X*/
dx=b/LIMx;/*Dividindo a 'amplitude' pela quantidade de pixels em cada eixo*/
dy=a/LIMy;
for(j=0;j<LIMy;j++){/*Um laço para atribuir valores às matrizes.*/
    for(i=0;i<LIMx;i++){
        Y[j][i] = Y1+j*dy;/*Atribuindo valores no eixo Y*/
        X[j][i] = X1+i*dx;/*Atribuindo valores no eixo X*/
        M[j][i] = 0; /*Atribuindo valores à matriz módulo, para que todos os elementos dela comecem com 0.*/
    }
}
x=y=0;
for(j=0;j<LIMy;j++){
    for(i=0;i<LIMx;i++){
            x=X[j][i];
            y=Y[j][i];
        for(c=0;(c<ite)&&((M[j][i])<=4);c++){
        A=(X[j][i]*X[j][i]);
        B=(Y[j][i]*Y[j][i]);
        C=(X[j][i])*(Y[j][i]);
        X[j][i] = (A)-(B)+(x);
        Y[j][i] = 2*(C)+y;
        M[j][i] = (A)+(B);
        }}}

    for(j=0;j<LIMy;j++){
    for(i=0;i<LIMx;i++){
            if(M[j][i] > 4){
            fprintf(arq, "255 ");
            }
            else if(M[j][i] <= 4){
            fprintf(arq, "0 ");
            }
    }
    fprintf(arq, "\n");
    }
    fclose(arq);
return 0;
}
