//Fonte do arquivo aluno.h:
/* TAD: Aluno*/
/* Tipo exportado*/
typedef struct aluno Aluno;
/* A composi��o da estrutura Aluno (struct aluno) n�o � exportada pelo
 m�dulo. Dessa forma, os demais m�dulos que usarem esse TAD n�o poder�o
acessar
 diretamente os campos dessa estrutura. Os arquivos que usarem esse TAD s�
ter�o acesso �s
 informa��es que possam ser obtidas atrav�s das fun��es exportadas pelo
arquivo
 aluno.h. */
/** Dessa forma se faz necess�rio termos uma fun��o para criar o nosso
TAD */
/* Fun��o construtora de Aluno na mem�ria do computador*/
Aluno* criaAluno();
/** E tamb�m, fun��es para acessar os atr�butos do nosso TAD e passar
valores pare estes atr�butos */
char* getNome(Aluno* aluno);
void setNome(Aluno* aluno, char *nome);
int getMatricula(Aluno* aluno);
void setMatricula(Aluno* aluno, int matricula);
float getNota1(Aluno* aluno);
void setNota1(Aluno* aluno, float nota1);
float getNota2(Aluno* aluno);
void setNota2(Aluno* aluno, float nota2);
float getNotaFinal(Aluno* aluno) ;
void setNotaFinal(Aluno* aluno, float notaFinal);
int getQuantidadeFaltas(Aluno* aluno);
void setQuantidadeFaltas(Aluno* aluno, int quantidadeFaltas);
/*Demais funcionalidades exportadas*/
float calcularMedia(Aluno* aluno);
