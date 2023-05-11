#include<stdio.h>

int main(){
	/* CONSTANTES */
	//Datos de empresa:
	const char razonSocial[] = "Megaretail y Cia S.A.";
	const char rut[] = "99.999.999-9";
	const char giro[] = "Grandes tiendas";
	const char direccion[] = "Avenida Fake 1202, Concepcion";
	const char telefono[] = "41 22 3333";
	const char email[] = "contacto@megaretailycia.cl";
	
	int op;
	do{
		printf("     Megaretail y Cia S.A\n"
		   "--------Menu Principal--------\n"
		   "1) Procesar Venta\n"
		   "2) Mostrar existencias de productos\n"
		   "3) Mostrar total de ventas\n"
		   "0) Salir del programa\n"
		   "OP: "); scanf("%d", &op);
		   
		   while(op < 0 || op > 3){
				printf("Operacion invalida, ingresela nuevamente: "); scanf("%d", &op);
		   }
		   
		   switch(op){
		   	 //inserte opciones del menu
		   }
	} while(op != 0);
}