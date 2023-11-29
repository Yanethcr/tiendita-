#include<stdio.h>
#include<string.h>
#include<time.h>
struct new_product{
    	int id;
   	float precio;
    	int stock;
    	char depa[20];
	char nombre[20];	
};

void nuevo(struct new_product tabla[],int cont){
	
	if(cont<=20){
	printf("\n ====== NUEVO PRODUCTO ======\n");
	printf("A que departamento pertenece su producto?: ");
	scanf("%s", tabla[cont].depa);									
	printf("Cual es su nombre?: ");
	scanf("%s", tabla[cont].nombre);
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

void imprimir_lista(struct new_product tabla[],int cont){
	if(cont<=20){
		printf("\nID\t\tDepartamento\t\tNombre\t\tPrecio\t\tStock\n\n");
		for(int i =0;i<cont;i++){
			
			printf("\n%d\t\t%s\t\t%s\t\t%.2f\t\t%d",tabla[i].id,tabla[i].depa,tabla[i].nombre,tabla[i].precio,tabla[i].stock);
		}
		
	}
	
	
}

void modificar(struct new_product tabla[],int comp_prec,int comp_stock,int cont ){
	int buscar;
	printf("Ingrese la id del producto al que desea modificar: ");
	scanf("%d", &buscar);
	
		if(comp_prec== 0){					//POSIBLEMENTE AMBOS SE PUEDEN OPTIMIZAR
		
		for(int i=0;i<cont;i++){
							
			if(buscar == tabla[i].id){
				printf("\nCual es el nuevo precio de %s: ", tabla[i].nombre);
				scanf("%f",&tabla[i].precio);
				printf("\n====== El precio fue actualizado correctamente ======\n");
				break;
			}				
		}					
	}
	if(comp_stock == 0){				
		
		for(int i=0;i<cont;i++){
			
			if(buscar == tabla[i].id){
				printf("\nCual es la nueva cantidad de %s: ", tabla[i].nombre);
				scanf("%d", &tabla[i].stock);
				printf("\n====== el stock fue actualizado correctamente ======\n");
				break;
			}					
		}					
	}
}

//aqui va el de tiket 
void minimo(struct new_product tabla[],int cont){
	int aux,min;
	
	for(int i=0;i<cont;i++){
		min=i;
		for(int j=i+1;j<cont;j++){
			if(tabla[j].precio < tabla[min].precio){
				min=j;
			 }
		 }
		 aux=tabla[i].precio;
		 tabla[i].precio=tabla[min].precio;
		 tabla[min].precio=aux;
	 }
	 printf("Ordenados del menor al mayor\n");
	 for(int i=0;i<cont;i++){
	 	printf("\n%d\t\t%s\t\t%s\t\t%.2f\t\t%d",tabla[i].id,tabla[i].depa,tabla[i].nombre,tabla[i].precio,tabla[i].stock);
	 }
}
	
void maximo(struct new_product tabla[],int cont){
printf("Ordenados del mayor a menor\n");
	 for(int i=cont;i>=0;i--){
	 	printf("\n%d\t\t%s\t\t%s\t\t%.2f\t\t%d",tabla[i].id,tabla[i].depa,tabla[i].nombre,tabla[i].precio,tabla[i].stock);
	 }
}

 
int main(){
	struct new_product tabla[20];
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
		nuevo(tabla,cont);
		cont++;					
			break;			
			
		case 'b':			//MODIFICAR PRECIO O STOCK
		
		printf("Que desea modificar, precio o stock?: ");
			scanf("%s", modif);
			comp_prec = strcmp(modif, "precio");
			comp_stock = strcmp(modif, "stock");
			
			imprimir_lista(tabla,cont);
			printf("\nEstos son los productos que hay actualmente en el inventario\n");			
			modificar(tabla,comp_prec, comp_stock,  cont);		
			
		
			
			break;
			
		case 'c':     // MOSTRAR INVENTARIO
			
imprimir_lista(tabla,cont);
			
			break;
			
		case 'd':			// CALCULAR TICKET (aqui uno se marea)
		
							
			break;			
						
		case 'e':  //MINIMO VENTAS

  minimo(tabla,cont);
						
			break;
			
		case 'f':  		//MAXIMO VENTAS
						
			maximo(tabla,cont);

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
