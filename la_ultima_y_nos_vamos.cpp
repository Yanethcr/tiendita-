#include<stdio.h>
#include<string.h>
struct new_product{
    int id;
    float precio;
    int stock;
    char depa[20];
	char nombre[20];	
};
void nuevo(int id,float precio,int stock,char depa[],char nombre[], int cont){
	struct new_product tabla[20];
	if(cont<=20){
	printf("\n ====== NUEVO PRODUCTO ======\n");
	printf("A que departamento pertenece su producto?: ");
	scanf("%s", tabla[cont].nombre);									
	printf("Cual es su nombre?: ");
	scanf("%s", tabla[cont].depa);
	printf("Cual es su precio?: ");
	scanf("%f", &tabla[cont].precio);
	printf("Cuantos hay en la venta?: ");
	scanf("%d", &tabla[cont].stock);
		
	for(int i=0;i<20;i++){
		if(tabla[cont].id== 0) {		
			tabla[cont].id = i + 1;		
			break;
		}			
	}	
	printf("\n======== Su articulo fue añadido correctamente, su ID es %d ========\n", tabla[cont].id);	
	} else {
		printf("Se alcanzo el maximo de articulos por registrar");
	}
}

void modificar(int comp_prec, int comp_stock,  int cont){
	nuevo();
	int buscar;
	printf("Ingrese la id del producto al que desea modificar: ");
	scanf("%d", &buscar);
	
		if(comp_prec== 0){					//POSIBLEMENTE AMBOS SE PUEDEN OPTIMIZAR
		
		for(int i=0;i<cont;i++){
							
			if(buscar == tabla[i].id){
				printf("\nCual es el nuevo precio de %s: ", tabla[i].precio);
				scanf("%f", &tabla[i].precio);
				printf("\n====== El precio fue actualizado correctamente ======\n");
				break;
			}				
		}					
	}
	if(comp_stock == 0){				
		
		for(int i=0;i<cont;i++){
			
			if(buscar == tabla[i].id){
				printf("\nCual es la nueva cantidad de %s: ", tabla[i].stock);
				scanf("%d", &tabla[i].stock);
				printf("\n====== el stock fue actualizado correctamente ======\n");
				break;
			}					
		}					
	}
}
	
int main(){
	struct new_product p;
	char modif[2];
	int cont=0;
	char opc;
	int comp_prec ,comp_stock;
	
	
		printf("\t\t---------------------------------------------------\n");	
	printf("\t\t||\t\tPRODUCTOS DE LA TIENDA \t\t||\t\t\n");
	printf("\t\t---------------------------------------------------\n");
	do{	
	printf("\n ======== MENU ========\n");
	printf("\na)Ingresar un nuevo producto\n");
	printf("\nb)Modificar el precio o stock de un producto\n");
	printf("\nc)Desplegar lista de productos registrados\n");
	printf("\nd)Calcular ticket\n");
	printf("\ne)Calcular minimo monto de venta\n");
	printf("\nf)Calcular el maximo monto de venta\n");
	printf("\ng)Desplegar el historial de ventas\n");
	printf("\nh)Guardar resumen de ventas\n");
	printf("\nCualquier otra letra para salir\n");
	printf("\nELIJA SU OPCION: ");
	scanf(" %c", &opc);
	getchar();
	
	switch(opc){
		
		default: 
			break;			
		case 'a':	//AÑADIR PRODUCTO
		nuevo(p.id,p.precio,p.stock,p.depa,p.nombre,cont);
		cont++;					
			break;			
			
		case 'b':			//MODIFICAR PRECIO O STOCK
		
		printf("Que desea modificar, precio o stock?: ");
			scanf("%s", modif);
			comp_prec = strcmp(modif, "precio");
			comp_stock = strcmp(modif, "stock");
			
			//imprimir_lista(datos.id, datos.depart, datos.nombre, datos.precio, datos.stock, cont);
			printf("\nEstos son los productos que hay actualmente en el inventario\n");			
			modificar(comp_prec, comp_stock,  cont);		
			break;
		
					
			break;
			
		case 'c':     // MOSTRAR INVENTARIO
						
			break;
			
		case 'd':			// CALCULAR TICKET (aqui uno se marea)
		
							
			break;			
						
		case 'e':  //MINIMO VENTAS
						
			break;
			
		case 'f':  		//MAXIMO VENTAS
						
			break;
			
		case 'g':			//HISTORIAL
						
			break;
			
		case 'h':		//GUARDAR RESUMEN DE VENTAS
			
			
			break;
		
	}
	}while(opc>='a' && opc<='h');		
	printf("\nPROGRAMA FINALIZADO");
	return 0;	
	
	
}
