# EP_02-Mandelbrot
<html>
<head>
  <h1>Data da entrega: <b>18/04/2014</b></h1>
</head>
<body>
<center>
  <h2>MAC110 - Introdução à Computação
    <br>
    Prof. Dr. Paulo Miranda
    <br>
    Instituto de Matemática e Estatística (IME)
    <br>
    Universidade de São Paulo (USP)
    <br>
  </h2>
</center>

Um fractal é um objeto geométrico que pode ser dividido em partes, cada uma das quais semelhante ao
objeto original. Fractais são muito usados em arte gerada por computador. O objetivo deste EP é fazer
programas em linguagem C, para gerar imagens (nos <b><a href="http://www.vision.ime.usp.br/~pmiranda/mac110_1s14/EPs/ep02/pgm_ppm.pdf">formatos PGM e PPM</a></b>) com desenhos derivados do
conjunto de Mandelbrot.<br><br>
Conjunto de Mandelbrot:<br>
Em matemática, conjunto de Mandelbrot é um fractal definido como o conjunto de pontos c no plano
complexo para o qual a sequência definida pela seguinte fórmula de recorrência:<br>
<img src="https://github.com/user-attachments/assets/cfba1f58-4033-4746-9280-bc6fd1bf3281" width="200"/>
<br>
não tende ao infinito.<br>

O conjunto de Mandelbrot, em sua representação gráfica no espaço contínuo, pode ser dividido em um
conjunto infinito de figuras pretas, sendo a maior delas um cardióide localizado ao centro do plano
complexo. Existe uma infinidade de quase-círculos que tangenciam o cardióide e variam de tamanho com
raio tendendo assintoticamente a zero. Cada um desses círculos tem seu próprio conjunto infinito de
pequenos círculos cujos raios também tendem assintoticamente a zero. Esse processo se repete
infinitamente, gerando uma figura fractal.<br><br>

A) Desenhando o conjunto:<br>
No espaço discreto de uma imagem digital, a repetição da figura fractal é interrompida a partir de uma certa
altura devido a limitada resolução da imagem, sendo que apenas um conjunto finito de pontos amostrados
são visualizados (Figuras 1 e 2). No entanto, a quantidade de cálculos necessária para se gerarem tais
imagens está além da capacidade de um ser humano executar a mão. O Professor Benoît Mandelbrot foi a
primeira pessoa a utilizar um computador para plotar o conjunto.

<img src="https://github.com/user-attachments/assets/6b5c7e45-514b-4cab-ab65-937ab591e0ae" width="700"/><br><br>


A sequência de pontos no plano complexo obtida pela fórmula de recorrência é chamada órbita de z0 sob a transformação 
<img src="https://github.com/user-attachments/assets/c15dad37-c23a-41bf-aa04-ac1356c54a05" width="100"/>
É possível provar que uma vez que um ponto atinge uma distância da origem maior que 2 (valor absoluto de zn maior que 2), 
a órbita explode para o infinito e, portanto, c não pertence ao conjunto de Mandelbrot. Este valor, conhecido como valor de fuga, permite o término dos cálculos para
pontos que não pertencem ao conjunto de Mandelbrot. Para aqueles que pertencem ao conjunto, ou seja,
valores de c para os quais zn não tende ao infinito, o cálculo nunca irá terminar. Portanto, o cálculo deve ser
terminado após um certo número de iterações determinado pelo programa. Isso resulta em uma imagem
que é apenas uma representação aproximada do conjunto verdadeiro.


B) Adicionando cor:<br>
Teoricamente, as imagens dos conjuntos de Mandelbrot são binárias (os pontos pertencem ou não ao
conjunto), no entanto, as imagens de arte gerada por computador são desenhadas em cores.
No método de renderização mais comum, para os pontos que divergem para o infinito e que, portanto, não
fazem parte do conjunto, as cores refletem o número de iterações necessárias para atingirem o valor de
fuga. Isso cria formas concêntricas, cada uma sendo uma melhor aproximação para o conjunto de
Mandelbrot em relação à camada exterior (Figuras 3 e 4). <br>
<img src="https://github.com/user-attachments/assets/a346d8f8-214f-4c3e-87d8-86738f38f164" width="700"/><br>
Para um conjunto finito A de pontos amostrados para visualização, seja AF  A o subconjunto de pontos que
não pertencem ao conjunto de Mandelbrot (subconjunto dos pontos de fuga). Para um dado ponto 
<img src="https://github.com/user-attachments/assets/243f7f62-75c0-4463-8956-92143d80facb" width="50"/>,
seja k(c) o seu número de iterações de fuga, e kmin e kmax o menor e maior número de iterações de fuga
encontrados no conjunto AF, respectivamente:<br> <img src="https://github.com/user-attachments/assets/6a4c1d12-b2a2-4da4-b4c7-24efb120d8c5" width="150"/><br>
Dadas duas cores C1 e C2, um esquema possível é pintar de C1 os pontos <img src="https://github.com/user-attachments/assets/8bd8c520-a389-41b0-acbb-d47b90e87f4b" width="60"/> que divergem rapidamente (isto é, k(c) = kmin), e de C2 os que divergem mais vagarosamente  (isto é, k(c) = kmax). As cores para pontos com números intermediários de iterações (isto é, kmin < k(c) < kmax) são então obtidas através da média ponderada de C1 e C2, gerando um gradiente de cores (cores interpoladas).<br><br>
Visto que o número de iterações de fuga para pontos próximos ao conjunto de Mandelbrot pode ser
extremamente elevado, em comparação com os demais pontos, uma estratégia de realce para melhorar a
visualização consiste em aplicar a função logarítmica no cálculo dos pesos, usando a seguinte fórmula:<br>
<img src="https://github.com/user-attachments/assets/97adb6bb-d366-4e6f-ac58-2c4c18ee93d1" width="250"/><br>
onde p é o peso da cor C2, e q = (1.0 - p) é o peso da cor C1 na média ponderada.<br><br>

C) Buddhabrot:<br>
O Buddhabrot é uma representação gráfica especial do conjunto de Mandelbrot (Figura 5) que, quando
girada em 90 graus no sentido horário, se assemelha a algumas representações do Buda (em inglês
Buddha). Para gerar a representação de Buddhabrot usamos um vetor bidimensional de contadores, um
para cada pixel da tela. Então um conjunto A de pontos de amostragem é iterado na função de Mandelbrot.
Para os pontos C pertence a A que escapam em um dado número de iterações (ou seja, pontos do subconjunto 
<img src="https://github.com/user-attachments/assets/420b9175-2533-4298-9ce0-047aa9a59b7f" width="50"/>,
, que não fazem parte do conjunto de Mandelbrot), a órbita da transformação correspondente, obtida pela
fórmula de recorrência, é desenhada sobre o mapa de contadores. Mais precisamente, os contadores
correspondentes as posições dos pontos zn, de cada iteração da sequência no plano complexo, são
incrementados para cada vez que zn for igual a posição do contador.<br>
<img src="https://github.com/user-attachments/assets/406d220f-0412-4793-9961-974f36c09c6d" width="500"/>,<br><br>

Após a iteração sobre um número grande de pontos c pertencentes a A, as cores dos pixels são escolhidas com base
nos valores de cada contador. Um esquema possível é pintar da cor C1 os pixels com contagem mínima
Cmin, e da cor C2 os que possuem contagem máxima Cmax. As cores para pixels com valores intermediários
de contagem (isto é, Cmin < count < Cmax) são então obtidas através da média ponderada de C1 e C2,
gerando um gradiente de cores (cores interpoladas). O cálculo dos pesos é dado pela seguinte equação:

<img src="https://github.com/user-attachments/assets/75fc921b-2831-4a1a-9fbb-d04ecafc1337" width="100"/><br>
onde p é o peso da cor C2, e q = (1.0 - p) é o peso da cor C1 na média ponderada.<br>
Uma estratégia de realce para melhorar a visualização consiste em aplicar a seguinte correção no peso p:<br>
<img src="https://github.com/user-attachments/assets/3f2298fc-0d67-44a7-8f17-afd4ac78471a" width="300"/><br><br>


Atividade:<br>
Faça programas em linguagem C que geram imagens dos desenhos dos três tipos de representações
gráficas do conjunto de Mandelbrot, apresentadas anteriormente, até um valor máximo de iterações
fornecido pelo usuário. O primeiro programa (ep02_a.c) deve gerar a imagem binária (valor 0 ou 255) do
conjunto de Mandelbrot no formato PGM (arquivo mandelbrot.pgm). O segundo programa (ep02_b.c) deve
gerar a renderização em cores do conjunto de Mandelbrot no formato PPM (arquivo mandelbrot.ppm), para
quaisquer cores da sua preferência. O terceiro programa (ep02_c.c) deve gerar a imagem da representação
de Buddhabrot (sem rotação) no formato PPM (arquivo buddhabrot.ppm), para quaisquer cores da sua
preferência.<br><br>
Os parâmetros dos programas são:<br>
  • Número máximo de iterações da fórmula de recorrência (ex: 10000, 20000),<br>
  • Coordenadas do canto inferior esquerdo (ponto P1) e do canto superior direito (ponto P2) da região visualizada do plano de Argand-Gauss.<br><br>

Para o terceiro programa temos também o seguinte parâmetro adicional:
  • Fator multiplicativo da quantidade de amostras por linha e coluna (ex: 2, 5, 10)<br><br>

No caso dos problemas 1 e 2, temos que as amostras c pertencentes a A correspondem aos centros dos pixels, tal que o centro do pixel na coordenada linha e coluna (m-1,0) corresponde ao ponto do plano complexo P1 e o centro do pixel em (0,n-1) corresponde ao ponto do plano complexo P2.<br>
<img src="https://github.com/user-attachments/assets/b445d751-59fa-4444-adad-10fb28d8f57f" width="300"/>
<br><br>
No caso do terceiro programa, precisamos de um número maior de amostras em A, a fim de obter uma
maior relevância estatística no acesso aos contadores, o que resulta em uma imagem final de Buddhabrot
com maior qualidade. As amostras são selecionadas em intervalos igualmente espaçados, sendo o número
total de amostras igual ao número total de pixels vezes o fator multiplicativo ao quadrado. O exemplo abaixo
mostra um caso onde o fator multiplicativo é 2, ou seja temos o dobro de amostras em cada linha e coluna
(5x2=10 amostras por linha e 3x2=6 amostras por coluna).
<br>
<img src="https://github.com/user-attachments/assets/65c116b4-c85c-4d4e-accd-4676b7f5273b" width="300"/>
<br><br>
Observações:<br>
No problema 2, para usar a função logarítmica (double log(double x);) você deve incluir a biblioteca math.h
(#include <math.h>), e no comando de compilação do gcc acrescentar a opção -lm:
<br><br>
gcc ep02_b.c -o ep02_b -lm
<br><br>
Sem o -lm você vai obter a seguinte mensagem de erro<br><br>
/tmp/cc1akiRG.o: In function `main`:<br>
ep02_b.c:(.text+0x42f): undefined reference to `log`<br>
ep02_b.c:(.text+0x45c): undefined reference to `log`<br>
collect2: error: ld returned 1 exit status <br><br>

Com relação ao tamanho das imagens, você pode usar valores como 640x480, 800x600, 1024x768, ou
qualquer outro tamanho. No entanto, para valores grandes você deve declarar os vetores usando a classe
de armazenamento static (estática):<br><br>

#define MAX_W 1024<br>
#define MAX_H 768<br><br>
int main(){<br>
 static int C[MAX_H][MAX_W];<br>
 ...<br>
 return 0;<br>
}<br><br>
As variáveis declaradas dentro da função main, sem o modificador static, são da classe de armazenamento
auto (automática). As variáveis automáticas são alocadas na pilha. O tamanho máximo de pilha para um
programa em C é dependente do sistema. Variáveis da classe estática são armazenadas na área de
armazenamento estática, sendo mais recomendáveis para armazenar grandes quantidades de dados.
