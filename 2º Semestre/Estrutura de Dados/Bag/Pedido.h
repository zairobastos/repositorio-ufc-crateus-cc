 typedef struct {
 	int codigo;
 	double valor;
 } Pedido;
 
 Pedido* createPedido(int c, double v);
 
 void printPedido(Pedido* p);
