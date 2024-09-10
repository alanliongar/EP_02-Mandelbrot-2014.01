/*Nome: Alan Lucindo Gomes, N° Usp: 7572130  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMx 1024 /*Aqui eh a quantidade de linhas, pode ser decidida pelo programador.*/
#define LIMy 768 /*Aqui eh a quantidade de colunas. Também pode ser decidida pelo programador.*/
/*Ambos os LIM definem a resolução da imagem.*/
double Y[LIMy][LIMx],X[LIMy][LIMx],M[LIMy][LIMx];
int R[LIMy][LIMx],G[LIMy][LIMx],B[LIMy][LIMx];/*Declarei as matrizes fora da função int porque quando declaradas dentro da int, o programa dá erro e eu não sei pq isso acontece :/*/
int main()
{
int ite, i, j, c, d, f, e, z,rec,grc,blc,ref,grf,blf,r1,g1,b1,v;
double X1, X2, Y1, Y2, x, a, dx, dy, b ,A, D, C, g, y,p,q,con;
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
arq = fopen("mandelbrot.ppm", "w");
fprintf(arq, "P3\n%d %d\n255\n", LIMx, LIMy);
a=Y2-Y1; /*calculando delta Y*/
b=X2-X1; /*calculando delta X*/
dx=b/LIMx;/*Dividindo a 'amplitude' pela quantidade de pixels em cada eixo*/
dy=a/LIMy;
for(j=0;j<LIMy;j++){/*Um laço para atribuir valores às matrizes.*/
    for(i=0;i<LIMx;i++){
        Y[j][i] = Y1+j*dy;/*Atribuindo valores no eixo Y*/
        X[j][i] = X1+i*dx;/*Atribuindo valores no eixo X*/
        M[j][i] = 0; /*Atribuindo valores à matriz módulo, para que todos os elementos dela comecem com 0.*/
    }
}
x=y=e=d=f=g=z=0;

rec=0;
grc=0;     /*cor inicial C1, segundo o enunciado, ou simplesmente a cor de fora*/
blc=0;


ref=0;
grf=0;    /*cor final / C2, segundo o enunciado, ou simplesmente a cor proxima ao conjunto*/
blf=255;


r1=0;
g1=0;  /*Cor do conunto*/
b1=0;
/*
Coordenadas do enunciado.
X1=-1.5;
Y1=-1.0;
X2=0.5;
Y2=1.0;

X1=0.278587;
Y1=-0.012560;
X2=0.285413;
Y2=-0.007440;
*/




for(j=0;j<LIMy;j++){
    for(i=0;i<LIMx;i++){
            x=X[j][i];
            y=Y[j][i];
        for(c=0;(c<ite)&&((M[j][i])<=4);c++){
        A=(X[j][i]*X[j][i]);
        D=(Y[j][i]*Y[j][i]);
        C=(X[j][i])*(Y[j][i]);
        X[j][i] = (A)-(D)+(x);
        Y[j][i] = 2*(C)+y;
        M[j][i] = (A)+(D);
        if((M[j][i]>=4)){
                p=((log10((c)+1))/(log10((ite+1))));
                q=1-p;
                R[j][i]=(p*(ref)+q*(rec));//C1 e C2 em média ponderada.
                G[j][i]=(p*(grf)+q*(grc));
                B[j][i]=(p*(blf)+q*(blc));
           }
        else if(M[j][i]<4){
                R[j][i]=r1;//C2
                G[j][i]=g1;
                B[j][i]=b1;}

           }}}
    for(j=0;j<LIMy;j++){
    for(i=0;i<LIMx;i++){
        fprintf(arq, "%d %d %d ", R[j][i], G[j][i], B[j][i]);
                            }
    fprintf(arq, "\n");
    }
    fclose(arq);
return 0;
}
