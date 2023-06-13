/*========================================================================
 * 
 *          Milivoltímetro para a disciplina de instrumentação
 *          Autor: Rafael Dantas
 *          Data: Outubro de 2019
 * 
 *======================================================================*/

//================= Constantes ======================
#define D7    2
#define D6    3
#define D5    4
#define D4    5
#define Enbl  6
#define RS    7

//================= Bibliotecas =====================
#include <LiquidCrystal.h>

//================ Objetos =========================

LiquidCrystal lcd(RS, Enbl, D4, D5, D6, D7);    //Faz o objeto da biblioteca LiquidCrystal
                                                //(<pino RS>, <pino Enable>, <pino D4>, <pino D5>, <pino D6>, <pino D7>)

//================ Variáveis ========================
float valorMedido;

void setup() 
{
   lcd.begin(16, 2);                            //Define o número de colunas e linhas, respectvamente

}

void loop() 
{

   valor();

}

void valor()
{

   valorMedido = analogRead(A0);
   valorMedido = valorMedido*(2.00/1023.00);                     //Faz a converção para mostrar o valor lido 

   lcd.setCursor(5, 0);                                          //Seta o cursor na coluna e na linha
   lcd.print(valorMedido);                                       //Imprime o valor
   lcd.setCursor(10, 0);                    
   lcd.print("mV");                        
   
   delay(100);                                                   //Delay de 100 milisegundos

}
