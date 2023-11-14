#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

typedef struct esfe Esfera;

 Esfera * inicializaEsfera();
 void recebeDiametro(Esfera *d,float a);
 float raio(Esfera *d);
 float area(Esfera *d);
 float volume(Esfera *d);


#endif // ESFERA_H_INCLUDED
