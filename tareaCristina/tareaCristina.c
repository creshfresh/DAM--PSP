#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



#define MAX_LINE_LENGHT 50
#define TAMANIO_ARREGLO 3


struct AlumnoN 
{

};


struct Alumno
{   char nombre [MAX_LINE_LENGHT +1];
    char apellido [MAX_LINE_LENGHT +1];
    int edad;
}; 


struct Alumno arregloAlumnos [TAMANIO_ARREGLO];


//Declaración de funciones
void calculadora();
void printArregloEnteros(int arreglo []);
void ordenarArreglo(int arreglo[]);
void potencias();
int factorialRecursivo(int num);
void contarPalabras();

void ordenarEstructuras(struct Alumno arregloAlumnos []);
void imprimirArregloEstructuras(struct Alumno arregloAlumnos []);
void llenarArregloEstructura (struct Alumno arregloAlumnos []);
void ordenarEstructuras (struct Alumno arregloAlumnos []);


int procesoFork();


int main() {
    int opcion;

    do {
        // Mostrar el menú
        printf("Menu:\n");
        printf("1. Calculadora simple\n");
        printf("2. Ordenamiento de arreglos de numeros enteros\n");
        printf("3. Calculo de potencia\n");
        printf("4. Calculo factorial con funcion recursiva\n");
        printf("5. Contar numero de palabras\n");
        printf("6. Ordenar estructuras\n");
        printf("7. Creacion de proceso con fork() \n");
        printf("8. Creacion de pipes \n");
        printf("9. Proceso System\n");
        printf("10. Proceso excel\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        // Procesar la selección del usuario
        switch (opcion) {
            case 1:
                calculadora();
                break;
            case 2: 
                int arreglo[9]= {15,2,45,4,2,9,80,70,19};
                printf("Este es el arreglo desordenado:\n");
                printArregloEnteros(arreglo);
                printf("Este es el arreglo ordenado:\n");
                ordenarArreglo(arreglo);
                break;
            case 3:
                potencias();
                break;
            case 4:
                int num;
                printf("Deme un numero para hacer su factorial:\n");
                scanf("%d", &num);
                int resultado =  factorialRecursivo(num);
                printf("El factorial de %d es: %d\n", num, resultado);
               
                break;
            case 5:

                contarPalabras();
                break;
           
            case 6:
                llenarArregloEstructura(arregloAlumnos);
                imprimirArregloEstructuras(arregloAlumnos);
                ordenarEstructuras(arregloAlumnos);
                break;
            case 7:
            case 8:
            case 9:
            case 10:
                printf("Funcionalidad aún no implementada.\n");
                break;
            case 0:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Por favor, selecciona una opcion valida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

//---------------------Calculadora simple-----------------

int suma(int num1, int num2) {
    return num1 + num2;
}
int resta(int num1, int num2) {
    return num1 - num2;
}
int multiplicacion(int num1,int num2){
    return num1*num2;
}
float division (float num1, float num2){
    return num1/num2;
}
void calculadora() {

    int opcion, num1, num2;

    printf("¿Qué operación quieres realizar?\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");

    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Dame el primer número para sumar:\n");
            scanf("%d", &num1);
            printf("Dame el segundo número:\n");
            scanf("%d", &num2);
        
            int resultadoSuma = suma(num1, num2);

            printf("El resultado de la suma es: %d\n", resultadoSuma);
            break;

        case 2:
            printf("Dame el primer número para restar:\n");
            scanf("%d", &num1);
            printf("Dame el segundo número:\n");
            scanf("%d", &num2);
            
         
            int resultadoResta = resta(num1, num2);

            printf("El resultado de la resta es: %d\n", resultadoResta);
            break;

        case 3:
            printf("Dame el primer número para multiplicar:\n");
            scanf("%d", &num1);
            printf("Dame el segundo número:\n");
            scanf("%d", &num2);

            int resultadoMultiplicar = multiplicacion(num1, num2);

            printf("El resultado de la multiplicación es: %d\n", resultadoMultiplicar);
            break;

        case 4:
            printf("Dame el primer número para dividir:\n");
            scanf("%d", &num1);

            printf("Dame el segundo número:\n");
            scanf("%d", &num2);

            float resultadoDividir = division (num1, num2);

            printf("El resultado de la división es: %f\n", resultadoDividir);
            break;

        default:
            printf("Opción incorrecta. Por favor, introduce un número válido.\n");
            break;
    }
}

//----------------Ordenación de arreglos------------------//
//Función que ordena el arreglo

void ordenarArreglo( int arreglo[] ){

    int numAux;
    for (size_t i = 0; i < 9; i++){
        for (size_t j = 0; j < 9; j++)
        {
           if (arreglo[j] > arreglo[i])
           {    
            //Se guarda el valor mayor en aux
                numAux = arreglo[j];
            // A la posición del valor más alto se le asigna el valor menor
                arreglo[j] = arreglo[i];
            //A la posición del valor menor, se le asigna el valor más alto guardado en aux
                arreglo[i] = numAux;
           }
        }
    }
    printArregloEnteros( arreglo);
}

//Función que imprime un arreglo de enteros desordenado
void printArregloEnteros(int arreglo[]){
    
    for (size_t i = 0; i < 9; i++){
        printf("%d ",arreglo[i]);
    }
    printf("\n");
}
//---------Calculo de potencia con bucle for------------//

void potencias() {

    int valor, potencia, resultado = 1;

    printf("Dime qué número quieres calcular su potencia:\n");
    scanf("%d", &valor);

    printf("Dame en qué base quieres la potencia:\n");
    scanf("%d", &potencia);

    for (size_t i = 0; i < potencia; i++) {
        resultado = valor * resultado;
    }
    printf("La potencia de %d elevado a %d es: %d \n", valor, potencia, resultado);
}

//--------------Factorial con recursividad-------------//

int factorialRecursivo(int num){
    int resultado;
    //Se comprueba que el numero es mayor 
    if (!(num <= 1)){   
        resultado = num * factorialRecursivo(num -1);
        return resultado;
    }else {
        return 1;
    }
}
//---------Contar palabras de una cadena------------//
void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void contarPalabras(){
    char cadena[100]; 
    int contador = 0;
  
    limpiarBuffer();//No dejaba introducir datos, habia que limpiar la entrada

    printf("Escribe una frase\n");

    // fgets coge el arreglo (cadena) y lo llenará con el num de caracteres de cadena (sizeof(cadena))
    // stidin es la entrada stándar de teclado
    fgets(cadena, sizeof(cadena), stdin);

    for (size_t i = 0; i < strlen(cadena); i++)
    {  
        if (cadena[i] == ' ' && i > 0 && cadena[i - 1] != ' ')
            contador++;
    }
    //No contaba la última palabra si no era con espacio al final
    if (cadena[strlen(cadena) - 1] != ' ') {
        contador++;
    }
    printf("La frase es: %s\n", cadena);
    printf("Esta frase tiene %d palabras\n", contador);
    
 }






//-------------Ordenación de estructuras--------------//

void llenarArregloEstructura(struct Alumno arreglo[]) {
 

    strcpy(arregloAlumnos[0].nombre, "Javier");
    strcpy(arregloAlumnos[0].apellido, "Reyes");
    arregloAlumnos[0].edad = 29;

    strcpy(arregloAlumnos[1].nombre, "Santiago");
    strcpy(arregloAlumnos[1].apellido, "Saenz de Santa Maria");
    arregloAlumnos[1].edad = 27;

    strcpy(arregloAlumnos[2].nombre, "Cristina");
    strcpy(arregloAlumnos[2].apellido, "Ramos");
    arregloAlumnos[2].edad = 29;

}

void imprimirArregloEstructuras(struct Alumno arreglo[]){
   
    for (size_t i = 0; i < TAMANIO_ARREGLO; i++){

        printf("Nombre: %s\n", arreglo[i].nombre);
        printf("Apellido: %s\n", arreglo[i].apellido);
        printf("Edad: %d\n", arreglo[i].edad);
        printf("\n");
    } 
}

void ordenarEstructuras (struct Alumno arreglo[]) {

    int opcion;
    printf("¿Que operacion quieres realizar?\n");
    printf("1. Ordenar por Edad\n");
    printf("2. Ordenar por Nombre\n");
    printf("3. Ordenar por apellido\n");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:

        void ordenarPorEdad(struct Alumno arreglo []){

            struct Alumno nuevaListaOrdenada [TAMANIO_ARREGLO];
            int aux;
            
            for (size_t i = 0; i < TAMANIO_ARREGLO; i++)
            {
                for (size_t j = 0; j < TAMANIO_ARREGLO; j++)
                {
                    if (arreglo[i].edad < arreglo[j].edad)
                    {
                        nuevaListaOrdenada[i] = arreglo[j];
                    }                     
                }
            
            }
            imprimirArregloEstructuras(nuevaListaOrdenada);
        }
        
        ordenarPorEdad(arreglo);
        
        break;
    case 2:
        // void ordenarPorNombre(arreglo);
    
    case 3:
        // void ordenarPorApellido(arreglo);
        
    default:
        printf("Opcion no valida");
        break;
    }

  
    
    


}

//-------------------Procesos en C-------------------//

// int procesoFork(void){
//     pid_t pid;
//     pid = fork();

//     if(pid == -1){
//         printf("Error al crear el proceso hijo\n");
//     return 0;
//     }
//     else if (pid){
//         printf("Soy el padre con PID: %d\n", getpid());
//     }
//     else {
//         printf("Soy el hijo con PID: %d\n", getpid());
//     }

//     printf("Final de ejecución de %d \n", getpid());
//  return 0; 
// //  exit(0);
// }


     

// Intercambio de valores

void intercambioValores(int numero1, int numero2) {
    printf("El valor original de a es: %d\n", numero1);
    printf("El valor original de b es: %d\n", numero2);
}

