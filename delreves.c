#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <string.h>

int main ( int argc, char *argv[] ) {

        int i;
        int j = 1;
        int counter = 0;
        FILE *archivo;
        char name[2048];
        int longitud;


        /* Caso de String */

        if(argc == 1){

                if(fgets(name, 2048, stdin)){

                        longitud = strlen(name) - 3;

                        for(i = 0; i <= longitud; i++){
                                counter = counter + 1;
                        }

                        for(i = counter; i > -1; i--){
                                printf("%c", name[i]);
                        }

                        printf("\n");
                }

                else{
                        return EX_NOINPUT;
                }

        }

        /* Caso de -h y --help */

        else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
                printf ("delreves: Uso: delreves [ fichero1, ficehro2, ... ]\n");
                 printf ("delreves: Invierte el contenido de las lineas de los ficheros (o de la entrada).\n");
        }

        /* Caso de Ficheros */

        else if(argc >= 2){

                while(argv[j] != NULL){

                        archivo = fopen(argv[j],"r");

                        if(archivo != NULL){

                            while(fgets(name, 2048, archivo)){

                                longitud = strlen(name) - 3;

                                for(i = 0; i <= longitud; i++){
                                        counter = counter + 1;
                                }

                                for(i = counter; i > -1; i--){
                                        printf("%c", name[i]);
                                }
                                    counter = 0;
                                    printf("\n");
                            }

                            fclose(archivo);
                            j++;

                        }

                        else{
                            return EX_NOINPUT;
                        }

                }
        }

        else{
                return EX_NOINPUT;
        }

        return EX_OK;
}

