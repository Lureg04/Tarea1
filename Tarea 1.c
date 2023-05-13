#include<stdio.h>
#include<stdlib.h>

int main(){
	/// Constantes
	//Datos de empresa:
	const char razonSocial[] = "Megaretail y Cia S.A.";
	const char rut[] = "99.999.999-9";
	const char giro[] = "Grandes tiendas";
	const char direccion[] = "Avenida Fake 1202, Concepcion";
	const char telefono[] = "41 22 3333";
	const char email[] = "contacto@megaretailycia.cl";

    ///Variables y arreglos
	int zapatos[4][2], modaMujer[6][2], modaHombre[6][2], blancaElectronica[5][2], computacion[4][2], contBoleta = 1;
    char op, confirmacion;

    ///Definicion de productos
    //Zapatos y Zapatillas
    zapatos[0][0] = 25000; zapatos[0][1] = 6;
    zapatos[1][0] = 60000; zapatos[1][1] = 2;
    zapatos[2][0] = 33000; zapatos[2][1] = 4;
    zapatos[3][0] = 72000; zapatos[3][1] = 2;

    //Moda Mujer
    modaMujer[0][0] = 12000; modaMujer[0][1] = 10;
    modaMujer[1][0] = 15000; modaMujer[1][1] = 10;
    modaMujer[2][0] = 7000; modaMujer[2][1] = 8;
    modaMujer[3][0] = 12000; modaMujer[3][1] = 10;
    modaMujer[4][0] = 20000; modaMujer[4][1] = 5;
    modaMujer[5][0] = 21000; modaMujer[5][1] = 6;

    //Moda Hombre
    modaHombre[0][0] = 15000; modaHombre[0][1] = 5;
    modaHombre[1][0] = 20000; modaHombre[1][1] = 5;
    modaHombre[2][0] = 10000; modaHombre[2][1] = 10;
    modaHombre[3][0] = 12000; modaHombre[3][1] = 10;
    modaHombre[4][0] = 18000; modaHombre[4][1] = 6;
    modaHombre[5][0] = 20000; modaHombre[5][1] = 6;

    //Linea Blanca y Electronica
    blancaElectronica[0][0] = 50000; blancaElectronica[0][1] = 2;
    blancaElectronica[1][0] = 55000; blancaElectronica[1][1] = 3;
    blancaElectronica[2][0] = 200000; blancaElectronica[2][1] = 1;
    blancaElectronica[3][0] = 350000; blancaElectronica[3][1] = 1;
    blancaElectronica[4][0] = 250000; blancaElectronica[4][1] = 1;

    //Computacion
    computacion[0][0] = 500000; computacion[0][1] = 1;
    computacion[1][0] = 800000; computacion[1][1] = 2;
    computacion[2][0] = 220000; computacion[2][1] = 1;
    computacion[3][0] = 999990; computacion[3][1] = 2;

	do{
        system("cls");
		printf("     %s\n"
		   "--------Menu Principal--------\n"
		   "1) Procesar Venta\n"
		   "2) Mostrar existencias de productos\n"
		   "3) Mostrar total de ventas\n"
		   "0) Salir del programa\n"
		   "OP: ", razonSocial); scanf("%s", &op);
		   
		   while(!(op == '0' || op == '1' || op == '2' || op == "3")){ printf("Operacion invalida, ingresela nuevamente: "); scanf("%s", &op); }

           system("cls");
		   switch(op){
               case '1': { ///Procesar Venta
                   int cat, valorUnitario, existencias, valorNeto, iva, valorTotal, cant = 1, prod = 0;
                   do{
                       system("cls");
                       printf("     %s\n"
                              "----------Categorias----------\n"
                              "1) Zapatos y Zapatillas\n"
                              "2) Moda Mujer\n"
                              "3) Moda Hombre\n"
                              "4) Linea blanca y Electronica\n"
                              "5) Computacion\n"
                              "0) Menu Principal\n"
                              "OP: ", razonSocial); scanf("%d", &cat);

                       while(cat < 0 || cat > 5){ printf("Categoria invalida, ingresela nuevamente: "); scanf("%d", &cat); }
                       if(cat == 0) { break; }

                       switch(cat) {
                           case 1: { //Zapatos y Zapatillas
                               do {
                                   do {
                                       system("cls");
                                       printf("           %s\n"
                                              "----------Seleccione el Producto----------\n"
                                              "   Producto        Valor        Existencias\n"
                                              "1) Zapato A:       %d             %d\n"
                                              "2) Zapato B:       %d             %d\n"
                                              "3) Zapatilla A:    %d             %d\n"
                                              "4) Zapatilla B:    %d             %d\n"
                                              "0) Volver atras\n"
                                              "Producto: ",
                                              razonSocial,
                                              zapatos[0][0], zapatos[0][1],
                                              zapatos[1][0], zapatos[1][1],
                                              zapatos[2][0], zapatos[2][1],
                                              zapatos[3][0], zapatos[3][1]);
                                       scanf("%d", &prod); if(prod == 0){ break;}

                                       do{
                                           while (prod < 0 || prod > 4) { printf("El producto (u opcion) seleccionado es invalido, ingreselo nuevamente: "); scanf("%d", &prod);}

                                           valorUnitario = zapatos[prod - 1][0];
                                           existencias = zapatos[prod - 1][1];

                                           if(existencias == 0 && prod != 0){
                                               printf("Ya no quedan existencias de este producto, ingrese otro producto o vuelva al menu de categorias: ");
                                               scanf("%d", &prod);
                                           }
                                       } while(existencias == 0);

                                       if(prod == 0){ break;}
                                       if(prod == 1 && existencias != 0) { printf("\nCuantas unidades de 'Zapato A' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 2 && existencias != 0) { printf("\nCuantas unidades de 'Zapato B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 3 && existencias != 0) { printf("\nCuantas unidades de 'Zapatilla A' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 4 && existencias != 0) { printf("\nCuantas unidades de 'Zapatilla B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       scanf("%d", &cant); if(cant == 0){ break; }

                                       while (cant > existencias || cant < 0) {
                                           if (cant > existencias) {
                                               printf("No puede procesar mas unidades que las existencias disponibles, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           } else {
                                               printf("No puede procesar un numero negativo de unidades, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           }
                                       }
                                   } while (prod == 0); if(prod == 0){ break; }
                                   system("cls");
                                   if(prod == 1){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Zapato A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 2){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Zapato B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 3){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Zapatilla A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 4){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Zapatilla B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                               } while (cant == 0);
                               break;
                           } //Zapatos y Zapatillas
                           case 2: { //Moda Mujer
                               do{
                                   do{
                                       system("cls");
                                       printf("           %s\n"
                                              "----------Seleccione el Producto----------\n"
                                              "   Producto        Valor        Existencias\n"
                                              "1) Pantalon A:       %d             %d\n"
                                              "2) Pantalon B:       %d             %d\n"
                                              "3) Polera A:         %d              %d\n"
                                              "4) Polera B:         %d             %d\n"
                                              "5) Poleron A:        %d             %d\n"
                                              "6) Poleron B:        %d             %d\n"
                                              "0) Volver atras\n"
                                              "Producto: ", razonSocial,
                                              modaMujer[0][0], modaMujer[0][1],
                                              modaMujer[1][0], modaMujer[1][1],
                                              modaMujer[2][0], modaMujer[2][1],
                                              modaMujer[3][0], modaMujer[3][1],
                                              modaMujer[4][0], modaMujer[4][1],
                                              modaMujer[5][0], modaMujer[5][1]);
                                       scanf("%d", &prod);
                                       if(prod == 0){ break;}

                                       do{
                                           while (prod < 0 || prod > 6) { printf("El producto (u opcion) seleccionado es invalido, ingreselo nuevamente: "); scanf("%d", &prod);}

                                           valorUnitario = modaMujer[prod - 1][0];
                                           existencias = modaMujer[prod - 1][1];

                                           if(existencias == 0 && prod != 0){
                                               printf("Ya no quedan existencias de este producto, ingrese otro producto o vuelva al menu de categorias: ");
                                               scanf("%d", &prod);
                                           }
                                       } while(existencias == 0);

                                       if(prod == 0){ break;}
                                       if(prod == 1 && existencias != 0) { printf("\nCuantas unidades de 'Pantalon A' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 2 && existencias != 0) { printf("\nCuantas unidades de 'Pantalon B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 3 && existencias != 0) { printf("\nCuantas unidades de 'Polera A' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 4 && existencias != 0) { printf("\nCuantas unidades de 'Polera B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 5 && existencias != 0) { printf("\nCuantas unidades de 'Poleron B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 6 && existencias != 0) { printf("\nCuantas unidades de 'Poleron B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       scanf("%d", &cant); if(cant == 0){ break; }

                                       while (cant > existencias || cant < 0) {
                                           if (cant > existencias) {
                                               printf("No puede procesar mas unidades que las existencias disponibles, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           } else {
                                               printf("No puede procesar un numero negativo de unidades, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           }
                                       }
                                   } while (prod == 0); if(prod == 0){ break; }
                                   system("cls");
                                   if(prod == 1){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Pantalon A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 2){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Pantalon B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 3){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Polera A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 4){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Polera B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 5){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Poleron A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 6){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Poleron B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                               } while (cant == 0);
                               break;
                           } //Moda Mujer
                           case 3: { //Moda Hombre
                               do{
                                   do{
                                       system("cls");
                                       printf("           %s\n"
                                              "----------Seleccione el Producto----------\n"
                                              "   Producto        Valor        Existencias\n"
                                              "1) Pantalon A:       %d             %d\n"
                                              "2) Pantalon B:       %d             %d\n"
                                              "3) Polera A:         %d             %d\n"
                                              "4) Polera B:         %d             %d\n"
                                              "5) Poleron A:        %d             %d\n"
                                              "6) Poleron B:        %d             %d\n"
                                              "0) Volver atras\n"
                                              "Producto: ", razonSocial,
                                              modaHombre[0][0], modaHombre[0][1],
                                              modaHombre[1][0], modaHombre[1][1],
                                              modaHombre[2][0], modaHombre[2][1],
                                              modaHombre[3][0], modaHombre[3][1],
                                              modaHombre[4][0], modaHombre[4][1],
                                              modaHombre[5][0], modaHombre[5][1]);
                                       scanf("%d", &prod);
                                       if(prod == 0){ break;}

                                       do{
                                           while (prod < 0 || prod > 6) { printf("El producto (u opcion) seleccionado es invalido, ingreselo nuevamente: "); scanf("%d", &prod);}
                                           valorUnitario = modaHombre[prod - 1][0];
                                           existencias = modaHombre[prod - 1][1];

                                           if(existencias == 0 && prod != 0){
                                               printf("Ya no quedan existencias de este producto, ingrese otro producto o vuelva al menu de categorias: ");
                                               scanf("%d", &prod);
                                           }
                                       } while(existencias == 0);

                                       if(prod == 0){ break;}
                                       if(prod == 1 && existencias != 0) { printf("\nCuantas unidades de 'Pantalon A' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 2 && existencias != 0) { printf("\nCuantas unidades de 'Pantalon B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 3 && existencias != 0) { printf("\nCuantas unidades de 'Polera A' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 4 && existencias != 0) { printf("\nCuantas unidades de 'Polera B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 5 && existencias != 0) { printf("\nCuantas unidades de 'Poleron B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 6 && existencias != 0) { printf("\nCuantas unidades de 'Poleron B' desea procesar? (Ingrese 0 para volver atras): "); }
                                       scanf("%d", &cant); if(cant == 0){ break; }

                                       while (cant > existencias || cant < 0) {
                                           if (cant > existencias) {
                                               printf("No puede procesar mas unidades que las existencias disponibles, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           } else {
                                               printf("No puede procesar un numero negativo de unidades, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           }
                                       }
                                   } while (prod == 0); if(prod == 0){ break; }
                                   system("cls");
                                   if(prod == 1){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Pantalon A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 2){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Pantalon B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 3){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Polera A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 4){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Polera B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 5){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Poleron A'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 6){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Poleron B'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                               } while (cant == 0);
                               break;
                           } //Moda Hombre
                           case 4: { //Linea blanca y Electronica
                               do{
                                   do{
                                       system("cls");
                                       printf("           %s\n"
                                              "----------Seleccione el Producto----------\n"
                                              "   Producto        Valor        Existencias\n"
                                              "1) Aspiradora:       %d             %d\n"
                                              "2) Microondas:       %d             %d\n"
                                              "3) Cocina:           %d            %d\n"
                                              "4) Lavadora:         %d            %d\n"
                                              "5) Refrigerador:     %d            %d\n"
                                              "0) Volver atras\n"
                                              "Producto: ", razonSocial,
                                              blancaElectronica[0][0], blancaElectronica[0][1],
                                              blancaElectronica[1][0], blancaElectronica[1][1],
                                              blancaElectronica[2][0], blancaElectronica[2][1],
                                              blancaElectronica[3][0], blancaElectronica[3][1],
                                              blancaElectronica[4][0], blancaElectronica[4][1]);
                                       scanf("%d", &prod);
                                       if(prod == 0){ break;}

                                       do{
                                           while (prod < 0 || prod > 5) { printf("El producto (u opcion) seleccionado es invalido, ingreselo nuevamente: "); scanf("%d", &prod);}

                                           valorUnitario = blancaElectronica[prod - 1][0];
                                           existencias = blancaElectronica[prod - 1][1];

                                           if(existencias == 0 && prod != 0){
                                               printf("Ya no quedan existencias de este producto, ingrese otro producto o vuelva al menu de categorias: ");
                                               scanf("%d", &prod);
                                           }
                                       } while(existencias == 0);

                                       if(prod == 0){ break;}
                                       if(prod == 1 && existencias != 0) { printf("\nCuantas unidades de 'Aspiradora' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 2 && existencias != 0) { printf("\nCuantas unidades de 'Microondas' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 3 && existencias != 0) { printf("\nCuantas unidades de 'Cocina' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 4 && existencias != 0) { printf("\nCuantas unidades de 'Lavadora' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 5 && existencias != 0) { printf("\nCuantas unidades de 'Refrigerador' desea procesar? (Ingrese 0 para volver atras): "); }
                                       scanf("%d", &cant); if(cant == 0){ break; }

                                       while (cant > existencias || cant < 0) {
                                           if (cant > existencias) {
                                               printf("No puede procesar mas unidades que las existencias disponibles, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           } else {
                                               printf("No puede procesar un numero negativo de unidades, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           }
                                       }
                                   } while (prod == 0); if(prod == 0){ break; }
                                   system("cls");
                                   if(prod == 1){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Aspiradora'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 2){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Microondas'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 3){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Cocina'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 4){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Lavadora'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 5){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Refrigerador'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                               } while (cant == 0);
                               break;
                           } //Linea blanca y Electronica
                           case 5: { //Computacion
                               do{
                                   do{
                                       system("cls");
                                       printf("           %s\n"
                                              "----------Seleccione el Producto----------\n"
                                              "   Producto        Valor        Existencias\n"
                                              "1) PC de Escritorio: %d            %d\n"
                                              "2) PC Gamer:         %d            %d\n"
                                              "3) Notebook:         %d            %d\n"
                                              "4) Notebook Gamer:   %d            %d\n"
                                              "0) Volver atras\n"
                                              "Producto: ", razonSocial,
                                              computacion[0][0], computacion[0][1],
                                              computacion[1][0], computacion[1][1],
                                              computacion[2][0], computacion[2][1],
                                              computacion[3][0], computacion[3][1]);
                                       scanf("%d", &prod);
                                       if(prod == 0){ break;}

                                       do{
                                           while (prod < 0 || prod > 4) { printf("El producto (u opcion) seleccionado es invalido, ingreselo nuevamente: "); scanf("%d", &prod);}

                                           valorUnitario = computacion[prod - 1][0];
                                           existencias = computacion[prod - 1][1];

                                           if(existencias == 0 && prod != 0){
                                               printf("Ya no quedan existencias de este producto, ingrese otro producto o vuelva al menu de categorias: ");
                                               scanf("%d", &prod);
                                           }
                                       } while(existencias == 0);

                                       if(prod == 0){ break;}
                                       if(prod == 1 && existencias != 0) { printf("\nCuantas unidades de 'PC de Escritorio' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 2 && existencias != 0) { printf("\nCuantas unidades de 'PC Gamer' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 3 && existencias != 0) { printf("\nCuantas unidades de 'Notebook' desea procesar? (Ingrese 0 para volver atras): "); }
                                       if(prod == 4 && existencias != 0) { printf("\nCuantas unidades de 'Notebook Gamer' desea procesar? (Ingrese 0 para volver atras): "); }
                                       scanf("%d", &cant); if(cant == 0){ break; }

                                       while (cant > existencias || cant < 0) {
                                           if (cant > existencias) {
                                               printf("No puede procesar mas unidades que las existencias disponibles, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           } else {
                                               printf("No puede procesar un numero negativo de unidades, ingrese una cantidad nuevamente: "); scanf("%d", &cant);
                                           }
                                       }
                                   } while (prod == 0); if(prod == 0){ break; }
                                   system("cls");
                                   if(prod == 1){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'PC de Escritorio'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 2){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'PC Gamer'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 3){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Notebook'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                                   if(prod == 4){ printf("     %s\nATENCION: Esta apunto de emitir una venta de %d unidades de 'Notebook Gamer'\nDesea Confirmar la venta? (s/n): ", razonSocial, cant);}
                               } while (cant == 0);
                               break;
                           } //Computacion
                       }

                       if(cant != 0 && prod != 0){
                           do{
                               scanf("%s", &confirmacion);
                               if(!(confirmacion == 's' || confirmacion == 'n')){ printf("La opcion ingresada no es valida, porfavor ingresela nuevamente (s/n): "); }
                           } while(!(confirmacion == 's' || confirmacion == 'n'));

                           if(confirmacion == 's') {
                               system("cls");
                               valorNeto = valorUnitario * cant;
                               iva = (valorNeto * 19) / 100;
                               valorTotal = valorNeto + iva;

                               if(cat == 1){ zapatos[prod-1][1] -= cant; }
                               if(cat == 2){ modaMujer[prod-1][1] -= cant; }
                               if(cat == 3){ modaHombre[prod-1][1] -= cant; }
                               if(cat == 4){ blancaElectronica[prod-1][1] -= cant; }
                               if(cat == 5){ computacion[prod-1][1] -= cant; }

                               printf("----------- Boleta Electronica N.%04d -----------\n"
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

                               contBoleta++;
                               system("pause");
                           }
                       }
                   } while(prod == 0);
               }
		   }
	} while(op != '0');
}