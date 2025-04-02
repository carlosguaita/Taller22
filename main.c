#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char id[5][10];
    char nombres[5][30];
    int stock[5];
    float precio[5];
    float total_ganancias = 0, venta = 0;
    int opc1, cont=0, cantidad, len;

    do{
        printf("Selecciones una opcion:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Detalle producto\n");
        printf("5. Total ganancias\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d",&opc1);

        switch (opc1)
        {
        case 1:
            if (cont < 5)
            {
                printf("Ingrese el ID del producto %d: ", cont);
                scanf("%s", &id[cont]);
                printf("Ingrese el nombre del producto %d: ", cont);
                fflush(stdin);
                fgets(nombres[cont], 30, stdin);

                len = strlen(nombres[cont]) - 1;
                nombres[cont][len]='\0';

                printf("Ingrese el stock del producto %d: ", cont);
                scanf("%d", &stock[cont]);
                printf("Ingrese el precio del producto %d: ", cont);
                scanf("%f", &precio[cont]);
                cont++;
            }
            break;
        case 2:
            char naux[10];
         
            printf("Seleccione el producto que desea vender\n");
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%s\t\t%s\t\t%d\t\t%f\n",id[i],nombres[i],stock[i],precio[i]);
            }
            printf(">> ");
            scanf("%s",&naux);
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(id[i], naux) == 0)
                {
                    printf("Ingrese la cantidad de producto a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad <= stock[i])
                    {
                        venta = cantidad * precio[i];
                        printf("El valor de la venta es: %f\n", venta);
                        if (cantidad > 20)
                        {
                            printf("Se aplica un descuento por cantidad superior a 20 unidades\n");
                            venta*=0.9;
                            printf("El valor de la venta con descuento es: %f\n",venta);
                        }
                        total_ganancias += venta;
                        stock[i]-=cantidad;
                    }
                    else
                    {
                        printf("No existe stock suficiente para esta venta\n");
                    }
                }
            }
            break;
        
        default:
            break;
        }


    }while(opc1 != 6);





    return 0;
}