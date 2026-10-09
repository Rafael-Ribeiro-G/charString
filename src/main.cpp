#include <Arduino.h>
#include <string.h> // ! strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> // ! atoi

void textoChar();
void textoString();

void setup() 
{
  Serial.begin(9600);
  // ! Tirar o ruído ESP
  Serial.println(" ");
  textoChar();
  textoString();
}

void loop() {}

void textoChar()
{
  // ! Texto literal
  // ! char com "*" está trabalhando com memória e não com um endere;co fixo
  // ! Use o char* quando o texto não será alterado
  // ! 'cidade' é um ponteiro
  const char cidade[] = "Santos";
  Serial.println(cidade);

  // ! strlen ---> string length (CONTA QUANTOS CARACTERES ANTES DO '\0')
  // ! '\0' ---> null
  // ! Descobre o tamanho do texto

  // ! O último caracter é sempre um '\0'
  int tamanhoTextoCidade = strlen(cidade);
  Serial.print("Comprimento do texto: ");
  Serial.println(tamanhoTextoCidade);

  // ! Descobre o espaço utilizado para o texto
  int tamanhoVariavelCidade = sizeof(cidade);
  Serial.print("Espaço utilizado: ");
  Serial.println(tamanhoVariavelCidade);

  // ! Quando for trabalhar com letras únicas usar aspas simples '', para palavras aspas duplas ""
  // ! Quando tem "" o computador entendi automaticamente o fim da palavra e adiciona o \0
  char vetorTexto[7] = {'R', 'a', 'f', 'a', 'e', 'l', '\0'};
  Serial.println(vetorTexto);

  // ! Comparar texto
  // ! com o * indica onde tem que alocar na memória
  // ! O ponteiro vai ser impresso até achar o '\0'
  const char* cidade1 = "Sao Caetano";
  const char* cidade2 = "Sao Caetano";

  if(strcmp(cidade, cidade2) == 0)
  {
    Serial.println("Os textos são iguais");
  }
  else
  {
    Serial.println("Os textos são diferentes");
  } 

  // ! strcmp analiza a ordem léxica das palavras, se a primeira palavra vem antes
  // ! que a segunda palavra o valor retornado será menor que zero, se a primeira
  // ! palavra vem após a segunda o retorno será maior que zero

  // ! =========================
  // ! TEXTO EDITAVEL COM char[]
  // ! =========================
  
  char nomeAluno[20] = "Rafaek";
  Serial.println(nomeAluno);

  // ! Alterando caracteres individualmente
  nomeAluno[5] = 'l';
  Serial.println(nomeAluno);
}

void textoString()
{

}