#include<stdio.h>
#include<stdlib.h>

int main(){
	/// CONSTANTES
	//Datos de empresa:
	const char razonSocial[] = "Megaretail y Cia S.A.";
	const char rut[] = "99.999.999-9";
	const char giro[] = "Grandes tiendas";
	const char direccion[] = "Avenida Fake 1202, Concepcion";
	const char telefono[] = "41 22 3333";
	const char email[] = "contacto@megaretailycia.cl";

    ///Variables y arreglos
	int op, zapatos[4][2], modaMujer[6][2], modaHombre[6][2], blancaElectronica[5][2], computacion[4][2], contBoleta = 0;
    char confirmacion;

    ///Definicion de productos
    //Zapatos y Zapatillas
    zapatos[0][0] = 25000; zapatos[0][1] = 6;
    zapatos[1][0] = 60000; zapatos[1][1] = 2;
    zapatos[2][0] = 33000; zapatos[2][1] = 4;
    zapatos[3][0] = 72000; zapatos[3][1] = 2;

	do{
        system("cls");
		printf("     %s\n"
		   "--------Menu Principal--------\n"
		   "1) Procesar Venta\n"
		   "2) Mostrar existencias de productos\n"
		   "3) Mostrar total de ventas\n"
		   "0) Salir del programa\n"
		   "OP: ", razonSocial); scanf("%d", &op);
		   
		   while(op < 0 || op > 3){
				printf("Operacion invalida, ingresela nuevamente: "); scanf("%d", &op);
		   }

           system("cls");
		   switch(op){
               case 1: { ///Procesar Venta
                   int cat, valorUnitario, existencias, valorNeto, iva, valorTotal, cant = 1;
                   printf("     %s\n"
                           "----------Categorias----------\n"
                          "1) Zapatos y Zapatillas\n"
                          "2) Moda Mujer\n"
                          "3) Moda Hombre\n"
                          "4) Linea Blanca\n"
                          "5) Computacion\n"
                          "0) Menu Principal\n"
                          "OP: ", razonSocial); scanf("%d", &cat);

                   while(cat < 0 || cat > 5){
                       printf("Categoria invalida, ingresela nuevamente: "); scanf("%d", &cat);
                   }

                   switch(cat) {
                       case 0: { //Menu Principal
                           break;
                       }
                       case 1: { //Zapatos y Zapatillas
                           int prod = 0;

                           do {
                               do {
                                   system("cls");
                                   printf("     %s\n"
                                          "----Seleccione el Producto----\n"
                                          "   Producto        Valor        Existencias\n"
                                          "1) Zapato A:       %d             %d\n"
                                          "2) Zapato B:       %d             %d\n"
                                          "3) Zapatilla A:    %d             %d\n"
                                          "4) Zapatilla B:    %d             %d\n\n"
                                          "0) Volver atras\n"
                                          "Producto: ", razonSocial,
                                          zapatos[0][0], zapatos[0][1],
                                          zapatos[1][0], zapatos[1][1],
                                          zapatos[2][0], zapatos[2][1],
                                          zapatos[3][0], zapatos[3][1]);
                                   scanf("%d", &prod);

                                   while (prod < 0 || prod > 4) {
                                       printf("El producto (u opcion) seleccionado es invalido, ingreselo nuevamente: ");
                                       scanf("%d", &prod);
                                   }

                                   valorUnitario = zapatos[prod - 1][0];
                                   existencias = zapatos[prod - 1][1];

                                   if(prod == 1) { printf("\nCuantas unidades de 'Zapato A' desea procesar? (Ingrese 0 para volver atras): "); }
                                   if(prod == 2) { printf("\nCuantas unidades de 'Zapato B' desea procesar? (Ingrese 0 para volver atras): "); }
                                   if(prod == 3) { printf("\nCuantas unidades de 'Zapatilla A' desea procesar? (Ingrese 0 para volver atras): "); }
                                   if(prod == 4) { printf("\nCuantas unidades de 'Zapatilla B' desea procesar? (Ingrese 0 para volver atras): "); }
                                   if(prod != 0) { scanf("%d", &cant); } else { break; }

                                   while (cant > existencias || cant < 0) {
                                       if (cant > existencias) {
                                           printf("No puede procesar mas productos que las existencias disponibles, ingrese una cantidad nuevamente: ");
                                           scanf("%d", &cant);
                                       } else {
                                           printf("No puede procesar un numero negativo de existencias, ingrese una cantidad nuevamente: ");
                                           scanf("%d", &cant);
                                       }
                                   }
                               } while (prod == 0);
                               if(prod == 0){ break; }
                               system("cls");
                               if(prod == 1){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Zapato A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                           } while (cant == 0);
                           break;
                       }
                       case 2: { //Moda Mujer
                           break;
                       }
                   }

                   //TODO: Confirmacion de emision de boleta. (Work in progress)
                   if(cant != 0){
                       scanf("%s", &confirmacion);
                       if(confirmacion == 'y' || confirmacion == 's') {
                           system("cls");
                           valorNeto = valorUnitario * cant;
                           iva = (valorNeto * 19) / 100;
                           valorTotal = valorNeto + iva;

                           printf("------------Boleta Electronica %d------------\n"
                                  "    Razon Social: %s\n"
                                  "    RUT: %s\n"
                                  "    Giro: %s\n"
                                  "    Direccion: %s\n"
                                  "    Telefono: %s\n"
                                  "    Email: %s\n\n"
                                  "    Valor Neto: %d\n"
                                  "    IVA: %d\n"
                                  "    Valor Total: %d\n"
                                  "--------------------------------------------\n\n",
                                  contBoleta, razonSocial, rut, giro, direccion, telefono, email, valorNeto, iva, valorTotal);
                           system("pause");
                       }
                   }
               }
		   }
	} while(op != 0);
}