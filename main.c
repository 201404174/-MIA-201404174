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
char id[100];
char k[50];
char m[50];
char h[50];
char i[50];
char hC[50];
char n[50];
char fs[50];
char ruta[100];
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
            }else if(strcasecmp(temp,"+unit")==0){
                      temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(unit, temp);
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
            }else if(strcasecmp(temp,"+fit")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(fit, temp);
            }else if(strcasecmp(temp,"+delete")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(eliminar, temp);
            }else if(strcasecmp(temp,"-name")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(name, temp);
            }else if(strcasecmp(temp,"+add")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(add, temp);

            }
        }
    }else if(strcasecmp(instruccion,"mount")==0){
         char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-path")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(path, temp);
            }else if(strcasecmp(temp,"-name")==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(name, temp);
            }
        }
    }else if(strcasecmp(instruccion,"umount")==0){
        char idTemp[]="-idx";
        int conta=1;
        char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            idTemp[3] = conta + '0';
            if(strcasecmp(temp,idTemp)==0){
                temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(id, temp);
            }
            conta++;
        }
    }else if(strcasecmp(instruccion,"Df")==0){
            char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"+k")==0){
                strcpy(k, "k");
            }else if(strcasecmp(temp,"+m")==0){
                strcpy(m, "m");
            }else if(strcasecmp(temp,"+h")==0){
                strcpy(hC, "h");
            }else if(strcasecmp(temp,"+i")==0){
                strcpy(i, "i");
            }
        }
    }else if(strcasecmp(instruccion,"Du")==0){
        char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-h")==0){
                strcpy(h, "h");
            }else if(strcasecmp(temp,"+n")==0){
                  temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(n, temp);
            }else if(strcasecmp(temp,"+path")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(path, temp);
            }
        }
    }else if(strcasecmp(instruccion,"mkfs")==0){
        char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-id")==0){
                    temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(id, temp);
            }else if(strcasecmp(temp,"+type")==0){
                  temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(type, temp);
            }else if(strcasecmp(temp,"+add")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(add, temp);
            }else if(strcasecmp(temp,"+unit")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(unit, temp);
            }else if(strcasecmp(temp,"+fs")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(fs, temp);
            }
        }
    }else if(strcasecmp(instruccion ,"rep")==0){
        char *temp=strtok(lineaInstrucciones," ");
        while((temp = strtok(NULL,"::"))!=NULL){
            if(strcasecmp(temp,"-name")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(name, temp);
            }else if(strcasecmp(temp,"-path")==0){
                  temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(path, temp);
            }else if(strcasecmp(temp,"-id")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(id, temp);
            }else if(strcasecmp(temp,"+ruta")==0){
                   temp = strtok(NULL, " ");
                if (temp[0] == ':'){
                memmove(temp, temp+1, strlen(temp));
                }
                strcpy(ruta, temp);
            }
            printf("Rep\n");
        }
    }else if(strcasecmp(instruccion ,"exec")==0){
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
        printf("Exec\n");
    }else{
        printf("%s no es parte de los comandos de este sistema. Verifique y vuelva a intentar",instruccion);
    }
}
