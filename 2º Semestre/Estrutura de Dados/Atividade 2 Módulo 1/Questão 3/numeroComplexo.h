
typedef struct numero Numero;

Numero* criaNumero();

float getx(Numero* numero);
void setx(Numero* numero,float x);
float gety(Numero* numero);
void sety(Numero* numero,float y);

void destruir1(Numero* numero);
void destruir2(Numero* numero);
float soma1(Numero* numero1, Numero* numero2);
float soma2(Numero* numero1, Numero* numero2);
float subtracao1(Numero* numero1, Numero* numero2);
float subtracao2(Numero* numero1, Numero* numero2);
float multiplicacao1(Numero* numero1, Numero* numero2);
float multiplicacao2(Numero* numero1, Numero* numero2);
