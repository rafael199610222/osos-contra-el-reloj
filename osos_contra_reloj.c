#include <stdio.h>
#include <stdbool.h>

#define POLAR 'I'
#define PANDA 'P'
#define PARDO 'G'

#define ANIME 'A'
#define MUSICA 'M'
#define LIMPIEZA 'L'

#define BAMBU 'B'
#define PESCADO 'P'
#define FOCAS 'F'

#define NUMERO_PISO_MAXIMO 18
#define NUMERO_PISO_MINIMO 1
#define GRITO_MAXIMO 18
#define GRITO_MINIMO 1
#define PUNTAJE_UNO 1
#define PUNTAJE_DOS 2
#define PUNTAJE_TRES 3
#define PUNTAJE_SEIS 6
#define PUNTAJE_NUEVE 9
#define MINIMO_PUNTAJE_POLAR 5
#define MAXIMO_PUNTAJE_POLAR 24
#define MINIMO_PUNTAJE_PANDA 25       
#define MAXIMO_PUNTAJE_PANDA 43
#define MINIMO_PUNTAJE_PARDO 44
#define MAXIMO_PUNTAJE_PARDO 63


/*
 *PRE: Ninguna
 *POST: Devolvera  "TRUE" si los canales que eligio  es distinto a convecion de canales de los osos,si no "FALSE".
 */     
bool es_canal_valido(char canales){
	return (canales != ANIME && canales != MUSICA) && (canales != LIMPIEZA);
}


/*
 *PRE: Ninguna.
 *POST: Devuelve una letra mayuscula si esta dentro de la convecion que elegimos [Anime(A), Musica pop(M), Limpieza(L)]
 */

void canales_a_elegir(char* canales){
     printf("vas a ver television. elegi el canal\n");
     scanf(" %c",canales);
     while(es_canal_valido(*canales)){
          printf("solo tenemos 3 canales ingrese uno de los canales: Anime(A), Musica pop(M), Limpieza(L) \n");
          scanf(" %c",canales);
        }
}


/*
 *PRE:Ninguna
 *POST: Devolvera TRUE si el tipo de comida que eligio es distinto ala convecion de comida de los osos,si no "FALSE".
 */
bool validando_tipo_de_comida(char alimento){
     return((alimento != BAMBU && alimento != PESCADO) && (alimento != FOCAS));
 }


/*
 *PRE: Ninguna
 *POST: Devuelve una letra  mayuscula si esta dentro de la convecion que elegimos [Bambú (B), Pescado (P), Focas (F)]
 */  

void guardar_vianda(char* alimento){
     printf("Solo podes guardar un alimento en tu vianda\n");
     scanf(" %c",alimento);
     while(validando_tipo_de_comida(*alimento)){
          printf("te equivocaste elegi el alimento que este en la convecion: Bambú (B), Pescado (P), Focas (F).\n");
          scanf(" %c",alimento);
        }
}


/*
 *PRE: Ninguna
 *POST: Devolvera "TRUE" si el numero de piso esta dentro del rango o "FALSE" si no.
 */
bool VALIDANDO_NUMERO_PISO(int avitacion){
	 return (avitacion >= NUMERO_PISO_MINIMO && avitacion <= NUMERO_PISO_MAXIMO);
}


/*
 *PRE: Ninguna
 *POST: Devuelve un numero entre 1 y 18.
 */

void numero_piso(int* avitacion){
	 printf("Te compras una torre con tus dos.  ¿En que piso te gustaría vivir?\n");
     scanf(" %i",avitacion);
     while(!VALIDANDO_NUMERO_PISO(*avitacion)){
     	printf("solo son 18 pisos ingrese un intervalo entre[1,18]\n");
        scanf(" %i",avitacion);
     }
}


/*
 *PRE: Ninguna
 *POST: Devolvera "TRUE" si tu miedo alas ratas esta dentro del rango o "FALSE" si no.
 */
bool validando_miedo_ala_ratas(int miedo){
	return( miedo >= GRITO_MINIMO && miedo <= GRITO_MAXIMO);
}


/*
 *PRE: Ninguna
 *POST:Devuelve un numero entre 1 y 18.
 */

void midiendo_tu_miedo_alas_ratas(int* miedo){
	 printf("¡Oh, una rata! ¿Que tan fuerte gritas\n");
     scanf(" %i",miedo);
     while(!validando_miedo_ala_ratas(*miedo)){
     	printf("ingres tu miedo en un intervalo entre[1,18] siendo 1 no gritar y 18 desgarrarse la garganta \n");
        scanf(" %i",miedo);
    }
}


/*
 *PRE: canal: es un canal valido para el detector de personajes
 *
 *POST: - 1 si se cumple la condicion
 *      - 2 si se cumple la condicion
 *      - 3 si se culple la condicion
 */

int puntaje_television(char canal){
	 int retorno;
	 if(canal == LIMPIEZA){
         retorno = PUNTAJE_UNO;
	    }
	 else if(canal == ANIME){
	 	 retorno = PUNTAJE_DOS; 
	    }
	 else if(canal == MUSICA){
	 	 retorno = PUNTAJE_TRES;
	    }
	 return retorno;
}


/*
 *PRE: vianda: es un alimento valido para el detector de personajes
 *
 *POST: -3 si se cumple la condicion
 *      -6 si se cumple la condicion
 *      -9 si se cumple la condicion
 */

int puntaje_alimento(char vianda){
	 int retorno;
	 if(vianda == FOCAS){
        retorno = PUNTAJE_TRES;
	    }
	 else if(vianda == BAMBU){
	 	retorno = PUNTAJE_SEIS;
	 }
	 else if(vianda == PESCADO){
	 	retorno = PUNTAJE_NUEVE;
	 }
	 return retorno;
}


/*
 *PRE: puntaje_miedo  : es un puntaje valido para el detector de personajes
 *     puntaje_piso   : es un puntaje valido para el detector de personajes
 *     puntaje_comida : es un puntaje valido para el detector de personajes
 *     puntaje_canal  : es un puntaje valido para el detector de personajes
 *
 *     
 *POST: Devolvera el puntaje total del detector de peronajes
 */

int calculando_puntaje_total(int puntaje_miedo, int puntaje_piso, int puntaje_comida, int puntaje_canal){
	int puntaje_total;
    puntaje_total = ((puntaje_comida * puntaje_canal) + puntaje_piso + puntaje_miedo);
    return puntaje_total;
}


/*
 *PRE: Nada
 *POST: imprimira por pantalla el nombre del  personaje  si el puntaje_total esta  dentro de su ramgo de uno de elos 3.
 */

void Determinacion_del_personaje(int* puntaje_total){

	 if( (*puntaje_total) >= MINIMO_PUNTAJE_POLAR && (*puntaje_total) <= MAXIMO_PUNTAJE_POLAR){
	 	printf("- Polar (I) -\n");
	 }
	 else if((*puntaje_total) >= MINIMO_PUNTAJE_PANDA && (*puntaje_total) <= MAXIMO_PUNTAJE_PANDA){
        printf("- Panda (P) -\n");
	 }
	 else if((*puntaje_total) >= MINIMO_PUNTAJE_PARDO && (*puntaje_total) <= MAXIMO_PUNTAJE_PARDO){
        printf("- Pardo (G) -\n");
	 }	 

}
int main(){
   char canal,comida;
   int numero_avitacion,fobia_ratas,puntaje_total;
   canales_a_elegir(&canal);
   guardar_vianda(&comida);
   numero_piso(&numero_avitacion);
   midiendo_tu_miedo_alas_ratas(&fobia_ratas);
   puntaje_total = calculando_puntaje_total(fobia_ratas, numero_avitacion, puntaje_alimento(comida), puntaje_television(canal));
   Determinacion_del_personaje(&puntaje_total);
   return 0;
}