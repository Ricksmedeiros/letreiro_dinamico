#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#define h GetStdHandle(STD_OUTPUT_HANDLE)
int gotoxy(int coluna, int linha)                
{
    COORD c;                                     
    c.X = coluna;                                
    c.Y = linha;                                 
    SetConsoleCursorPosition(h, c);              
    return 0;                                    
}
int textcolor(int letras, int fundo)
{
    SetConsoleTextAttribute(h,letras+(fundo << 4));
    return 0;
}
void HideCursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
int main()
{
	setlocale(LC_ALL,"portuguese");
	
    int letras[30][5] = {
        14,17,31,17,17,
        30,17,30,17,30, 
        14,17,16,17,14, 
        30,17,17,17,30, 
        31,16,30,16,31, 
        31,16,30,16,16, 
        14,16,19,17,14, 
        17,17,31,17,17,
        14, 4, 4, 4,14,
         3, 1, 1,17,14,
        18,20,24,20,18,
        16,16,16,16,30,
        17,27,21,17,17,
        17,25,21,19,17,
        14,17,17,17,14,
        30,17,30,16,16,
        14,17,21,19,14,
        30,17,30,18,17,
        15,16,14, 1,30,
        31, 4, 4, 4, 4,
        17,17,17,17,14,
        17,17,10,10, 4,
        17,17,17,21,10,
        17,10, 4,10,17,
        17,17,10, 4, 4,
        31, 2, 4, 8,31,
        0, 0, 0, 0, 4 ,
        12, 12, 12, 0,12,  
        0,0,0,12,12,         
        14,17,2,4,4,};
    int aux1, lin=0, col,color=0,eterno=1,controladordesom=0;             
    char fraseLed[5][500] = { 0 };
    HideCursor();
    int linha1 = 0, coluna1 = 5, linha2 = linha1,
        coluna2 = coluna1, j=0, i = 0, definidor=0, count=0;                 
    char str[350];
    printf(" \t Bem vindo ao nosso trabalho:\n ");
    Sleep(350);
    Beep(700,250);
    printf("\t\t Para um melhor aproveitamento segue as regras:\n ");
    Sleep(550);
    Beep(700,250);
    printf("\t\t\t Não utilizar números e  apenas utilizar  os simbolos a seguir:\n");
    Sleep(750);
    Beep(700,250);
    printf("\t\t\t\t Exclamação(!) interrogação (?) ponto final (.):\n");
    Sleep(950);
    Beep(700,250);
    printf("\t\t\t\t\tPara uma melhor experiência utilize o programa com a tela maximizada.\n");
    Sleep(1150);
    Beep(700,250);
    printf("\t\t\t\t\t\t Para finalizar o programa aperte qualquer tecla \n");
    Sleep(1350);
    Beep(700,250);
    printf("\t\t\t\t\t\t Escreva uma palavra ou uma frase:\n "); 
                         
    fgets(str,350, stdin);            
    int tamanho = strlen(str);                        
    str[tamanho - 1] = ' ';                           
    char moldura[255];                             
    for (i = 0; i < (tamanho ) * 7 - 5; i++)
        moldura[i] = (char)14;                    
    moldura[i] = 0;                                                                           
    for (aux1 = 0; aux1 < tamanho;aux1++)                     
    {
        for (j = 0; j < 5; j++)                  
        {
            gotoxy(24,j+10);
            printf("%c  ", 160);                 
            gotoxy(tamanho*7+18, j + 10);
            printf("  %c", 186);                 
            coluna1 = coluna2;                             
            if (str[aux1] == ' ') definidor = 0;
            else if (str[aux1] == '!') definidor = letras[27][j];
            else if (str[aux1] == '.') definidor = letras[28][j];
		  else if (str[aux1] == '?') definidor = letras[29][j];
            else
                 definidor = letras[(int)(toupper(
                    str[aux1]) - 65)][j];           
            for (count = 0; count < 5; count++)              {
                if ( definidor % 2 != 0)                  
                 fraseLed[linha1][coluna1] = (char)4;             
                else
                   fraseLed[linha1][coluna1] = ' ';             
                if ( definidor != 0) definidor=definidor / 2;            
                coluna1 -= 1;                         }
            fraseLed[linha1][coluna1] = ' ';
            linha1++;                               
            coluna1 = coluna2;                             
        }                                        
        coluna2 = coluna2 + 6;                             
        linha1 = linha2;                                 
    }                                            
    gotoxy(25, 8);
    printf("%s", moldura);                         
    gotoxy(25, 16);
    printf("%s", moldura);                         
    do{
    	HideCursor();
     srand(time(NULL));
    for(i=0;i<1;i++){                              
    color=rand()%15;
    if(color==0)
        color=1;
    textcolor(color,0);}
        for (lin = 0; lin < 5; lin++)           
        {gotoxy(27, lin + 10);                
             for (col = 0; col < tamanho * 8; col++)   
                 printf("%c", fraseLed[lin][col]);                 
        }
        char movimentador;
        for (i = 0; i < 5; i++)                 
        {
            movimentador = fraseLed[i][0];                        
            for (j = 0; j < tamanho * 8; j++)         
             fraseLed[i][j] = fraseLed[i][j + 1];           
            
           fraseLed[i][j] =movimentador;                        
        }                     
        Sleep(100); 
	   if(controladordesom<=10){
	   Beep(200,100);}
	   if(controladordesom>10&& controladordesom <=20){
	   Beep(300,100);}
	   if(controladordesom>20 && controladordesom<=30){
	   Beep(400,100);}
	   if(controladordesom>30 && controladordesom <=40)
	   Beep(500,100); 
	    if(controladordesom>40 && controladordesom <=50)
	   Beep(600,100); 
	    if(controladordesom>50 && controladordesom <=60)
	   Beep(700,100); 
	   controladordesom++;
	   if(controladordesom==60)
	   controladordesom=0;
	   if (kbhit())break;                            
    } while (eterno); 
    printf("\n\n\n\n");
    printf("Esse trabalho foi realizado pelos alunos \n") ;
    printf("Celso Henrique Sanches Medeiros\n");
    printf("Barbara Das Moroni\n");                                
    return 0;                                    
}
