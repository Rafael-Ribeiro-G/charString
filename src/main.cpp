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

  // ! Copiando outro texto para dentro do vetor
  // ! CUIDADO: O VETOR PRECISA TER ESPAÇO SUFICIENTE

  strcpy(nomeAluno, "Guilherme");
  Serial.print(nomeAluno);

  // ! Concatenando de texo ao final
  char frase[40] = "Hello ";
  strcat(frase, "World!");
  Serial.println(frase);

  // ! Procurando um caractere no texto
  char* posicaoLetra = strchr(frase, 'W');

  if(posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada: ");
    Serial.println(posicaoLetra);
  }
  else
  {
    Serial.println("Letra não encontrada");
  }

  // ! Convertendo texto numérico para inteiro
  char idadeTexto[] = "45"; // ! 52, 53, \0
  // ! ATOI (A -> ASCII; TO -> PARA; I -> INT)
  int idade = atoi(idadeTexto);
  Serial.println(idade);

}

void textoString()
{
  // ! =============================================
  // ! USANDO String
  // ! =============================================

  // ! Quando tem atributo dentro de classe deve começar com '_'
  
  String nome = "Rafael";
  String curso = "Desenvolvimento de Sistemas";
  String mensagem = "Ola";

  // ! Concatenando String
  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  // ! Tamanho do String
  int tamanhoMensagem = mensagem.length();
  Serial.print("Tamanho da String em letras: ");
  Serial.println(tamanhoMensagem);


  // ! ===========ACESSAR UMA POSIÇÃO ESPECÍFICA===========
  // ! Acessando um caractere em posição específica
  char primeiraLetra = mensagem.charAt(0);
  Serial.print("Primeira letra: ");
  Serial.println(primeiraLetra);

  char segundaLetra = mensagem[1];
  Serial.println(segundaLetra);
  // ! ====================================================


  // ! Procurando um texto dentro da String 
  // ! indexOf -> ENDEREÇO DE
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.println(posicaoTextoProcurado);

  // ! Extraindo um texto dentro da String
  int inicioNomeCurso = posicaoTextoProcurado + 9; // ! Posição da palavra curso + 9 caracteres
  Serial.println(mensagem.substring(inicioNomeCurso, tamanhoMensagem - 1)); // ! -1 tira o ponto final

  // ! Substituindo um trxmo dentro da String
  mensagem.replace("Ola,", ("Oi, tudo bem? "));
  Serial.println(mensagem);

  // ! Convertendo para maiúsculas
  mensagem.toUpperCase();
  Serial.println(mensagem);

  // ! Convertendo para minúsculas
  mensagem.toLowerCase();
  Serial.println(mensagem);

  // ! Convertendo texto numérico para inteiro
  String textoNumero = "123";
  int numero = textoNumero.toInt();
  Serial.println(numero * 2);

  // ! Verificando se a String está vazia
  String textoVazio = "";
  if(textoVazio.length() == 0)
  Serial.println("O texto está vazio"); 

  // ! Convertendo String para const char*
  // ! Isso é útil quando alguma biblioteca espera texto estilo C
  const char* textoComChar = mensagem.c_str();
  Serial.println(textoComChar);

}