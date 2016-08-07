#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Globales
*/
char comando[400];
char segundoComando[400];
char tempComando[400];
/*
    Se declaran metodos
*/
void iniciarSistema();
void recoleccionComandos(char *instruccion,char *lineaInstrucciones);
/*
    Metodo principal
*/

int main()
{
    int opcion;
    printf("--------------------------------------------\n");
    printf("BIENVENIDO AL SISTEMA DE DISCOS\n");
    printf("--------------------------------------------\n");
    do{
        printf("1. Commands\n");
        printf("2.Exit System\n");
        scanf( "%i", &opcion);

        if(opcion ==1){
            //llamando a metodo de iniciar sistema
            iniciarSistema();
        }else if(opcion==2){
            break;
        }else{
            printf("No existe esa opcion\n");
        }
    }while(opcion!=2);


    return 0;
}

/*
    Metodos
*/
void iniciarSistema(){
    printf("--------------------------------------------\n");
    printf("CONSOLA\n");
    printf("--------------------------------------------\n");
    printf("Porfavor Ingrese un comando\n");
    scanf(" %[^\n]s", comando);

    if(comando[0]=='#'){
        printf("ES UN COMENTARIO\n");
    }else if(comando[strlen(comando)-1]=='\\'){
        scanf(" %[^\n]s", segundoComando);
        strncpy(tempComando, comando, strlen(comando)-1);
        strcat(tempComando, segundoComando);
        strcpy(comando, tempComando);
        char *comandoInstruccion = strtok(tempComando, " ");
       /* printf("%s\n",segundoComando);
        printf("%s\n",comando);
        printf("%s\n",lineaComparable);
        printf("%s\n",Lista[1]);*/
        recoleccionComandos(comandoInstruccion, comando);
    }else{
        //copia el comando original a otro apuntador
        strcpy(tempComando, comando);
        //obtiene la primera palabra de la cadena
        char *comandoInstruccion = strtok(tempComando, " ");
        recoleccionComandos(comandoInstruccion, comando);
    }
}
void recoleccionComandos(char *instruccion,char *lineaInstrucciones){
char size[50];
char unit[10]="nada";
char path[400];
char name[100];
char type[50]="nada";
char fit[50]="nada";
char eliminar[100]="nada";
char add[50]="nada";
    //Crear disco
    if(strcasecmp(instruccion,"mkdisk")==0){
        char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-size")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(size, temp);
                //printf("size%\n",size);
            }else if(strcasecmp(temp,"+unit")==0){
                      temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(unit, temp);
               // printf("unit%s\n",unit);
            }else if(strcasecmp(temp,"-path")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(path, temp);
               // printf("path%s\n",path);
            }else if(strcasecmp(temp,"-name")==0){
                          temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(unit, temp);
              //  printf("name %s\n",name);
            }
        }
        printf("ESTOY EN CREAR DISCO\n");
    }else if(strcasecmp(instruccion,"rmdisk")==0){
        char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-path")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(path, temp);
            }
        }
    }else if(strcasecmp(instruccion,"fdisk")==0){
         char *temp=strtok(lineaInstrucciones," ");
    //    temp = strtok(NULL,"::");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-size")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(size, temp);
               // printf("size%s\n",size);
            }else if(strcasecmp(temp,"+unit")==0){
                      temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(unit, temp);
              //  printf("unit%s\n",unit);
            }else if(strcasecmp(temp,"-path")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(path, temp);
                //printf("path%s\n",path);
            }else if(strcasecmp(temp,"+type")==0){
                          temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(type, temp);
              //  printf("type %s\n",type);
            }else if(strcasecmp(temp,"+fit")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(fit, temp);
               // printf("fit %s\n",fit);
            }else if(strcasecmp(temp,"+delete")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(eliminar, temp);
              //  printf("delryr %s\n",eliminar);
            }else if(strcasecmp(temp,"-name")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(name, temp);
               // printf("name %s\n",name);
            }else if(strcasecmp(temp,"+add")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(add, temp);
               // printf("add %s\n",add);
            }
        }
    }
}
