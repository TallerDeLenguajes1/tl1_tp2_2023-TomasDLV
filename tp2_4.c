#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 5

struct compu
{
    int velocidad; // Random 1 a 3
    int anio; // Random 2015 a 2023
    char tipo_cpu[10]; // Valores de tipo arreglos
    int nucleos; // Random 1 a 8
};

void mostrarLista(struct compu *lista);
void cargarDatos(struct compu *lista);
void mostrarVieja(struct compu *lista);
void mostrarVeloz(struct compu *lista);

void main()
{
    struct compu *punt = malloc(TAMA*sizeof(struct compu));
    // Cargar datos
    cargarDatos(punt);
    mostrarLista(punt);
    mostrarVieja(punt);
    mostrarVeloz(punt);
}

void mostrarLista(struct compu *lista)
{
    printf("\n\n----- Lista de procesadores ------\n");
    for (int i = 0; i < TAMA; i++)
    {
        printf("Procesador %d:\n", i + 1);
        printf("Velocidad: %d GHz\n", lista->velocidad);
        printf("Anio: %d\n", lista->anio);
        printf("Tipo de CPU: %s\n", lista->tipo_cpu);
        printf("Numero de nucleos: %d\n\n", lista->nucleos);
        lista++;
    }
}

void cargarDatos(struct compu *lista)
{
    char tipos[6][10] = {"intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    for (int i = 0; i < 5; i++)
    {
        int random = rand() % 6;
        lista->velocidad = rand() % 3 + 1;
        lista->anio = rand() % 9 + 2015;
        lista->nucleos = rand() % 8 + 1;
        strcpy(lista->tipo_cpu, tipos[random]);
        lista++;
    }
}
void mostrarVieja(struct compu *lista){
    struct compu *aux;
    int fechaVieja = lista->anio;
    aux = lista;
    for (int i = 0; i < TAMA-1; i++)
    {
        lista++;
        if (lista->anio < fechaVieja)
        {
            fechaVieja = lista->anio;
        }
    }
    lista = aux;
    printf("\n------ El/los Procesador/es mas viejos : ------\n");
    for (int i = 0; i < TAMA; i++)
    {
        if (lista->anio == fechaVieja)
        {
            printf("Procesador %d:\n", i + 1);
            printf("Velocidad: %d GHz\n", lista->velocidad);
            printf("Anio: %d\n", lista->anio);
            printf("Tipo de CPU: %s\n", lista->tipo_cpu);
            printf("Numero de nucleos: %d\n\n", lista->nucleos);
        }
        lista++;
    }
}
void mostrarVeloz(struct compu *lista){
    struct compu *aux;
    int veloz = lista->velocidad;
    aux = lista;
    for (int i = 0; i < TAMA-1; i++)
    {
        lista++;
        if (lista->velocidad > veloz)
        {
            veloz = lista->anio;
        }
    }
    lista = aux;
    printf("\n------ El/los Procesador/es mas rapido : ------\n");
    for (int i = 0; i < TAMA; i++)
    {
        if (lista->velocidad == veloz)
        {
            printf("Procesador %d:\n", i + 1);
            printf("Velocidad: %d GHz\n", lista->velocidad);
            printf("Anio: %d\n", lista->anio);
            printf("Tipo de CPU: %s\n", lista->tipo_cpu);
            printf("Numero de nucleos: %d\n\n", lista->nucleos);
        }
        lista++;
    }
}