#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mkdisk(int size, char unit, char *path, char *name);
/*
    Estructuras para la creacion del disco y partciones
*/
//Estructura para la particion
typedef struct Particion{
    char partStatus[10];
    char partType[1];
    char partFit[2];
    int partStart;
    int partSize;
    char partName[16];
}Particion;
//Estructura Master boot record
typedef struct Mbr{
    int mbrTamanio;
    int mbrFechaCreacion;
    int mbrDiskSignature;
    particion particion1;
    particion particion2;
    particion particion3;
    particion particion4;
}Mbr;
//Estructura Extended boot record
typedef struct Ebr{
    char ebrStatus[10];
    char ebrFit[2];
    int ebrStart;
    int ebrSize;
    int ebrNext;
    char ebrName[16];
}Ebr;

int crearDisco(int size, char unit, char *path, char *name){


    char ruta [200];
    strcat(ruta,path);
    strcat(ruta,name);

    if(unit=='k' ||unit=='K')
    {
        size = size*1024;
    }else if(unit=='M'||unit=='m' || unit=="nada")
    {
        size = size*1048576;
    }

}

