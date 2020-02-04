//#include <stdlib.h>
#include <stdio.h>
//#include <system.h>
#include "io.h"

/*=======  main =========*/
int main (void) {
	volatile int * ADC = (int *) 0x4041020;//asignar la memoria del ADC
	int * memoria = (int *) 0x00; // SDRAM address
	//Variable de lectura
	unsigned int ldr;
	unsigned int humedad_suelo;
	unsigned int humedad_aire;
	unsigned int temperatura;
	//Canales mediciones
	unsigned int canal_ldr;
	unsigned int canal_humedad_suelo;
	unsigned int canal_humedad_aire;
	unsigned int canal_temperatura;

	*(ADC) = 0; //setear valores de los canales en 0

	while (1){

		//Asignar valores a los canales
		canal_ldr = 0;
		canal_humedad_suelo = 1;
		canal_humedad_aire = 2;
		canal_temperatura = 3;
		//Lectura LDR
		int ldrRMS = 0;
		for(int n=0;n<4000;n++)
		{
			ldr = *(ADC+canal_ldr);
			ldrRMS = ldrRMS + ldr;
		}
		ldrRMS = ldrRMS*1.41/4000;
		//ldr = *(ADC+canal_ldr); //Obtener el valor del ldr
		//ldr=(ldr*3.3)*100/(4095*3)-10; //Convertir el valor en porcentaje
		//printf("El valor del LDR en el canal %d es --> %d Porciento \n",canal_ldr,ldr);

		//Lectura FC-28
		humedad_suelo = *(ADC+canal_humedad_suelo); //Obtener el valor del sensor FC-28
		humedad_suelo=(humedad_suelo*3.3)*100/(4095*3)-10; //Convertir el valor en porcentaje
		//printf("El valor del sensor FC-28 en el canal %d es --> %d Porciento \n",canal_humedad_suelo,humedad_suelo);

		//Lectura Humedad del aire
		humedad_aire = *(ADC+canal_humedad_aire); //Obtener el valor de la humedad del aire
		humedad_aire=(humedad_aire*3.3)*100/(4095*3)-10; //Convertir el valor en porcentaje
		//printf("El valor de la humedad del aire en el canal %d es --> %d Porciento \n",canal_humedad_aire,humedad_aire);

		//Lectura de la temperatura del ambiente
		temperatura = *(ADC+canal_temperatura); //Obtener el valor de la humedad del aire
		//temperatura=(temperatura*3.3)*100/(4095*3)-10; //Convertir el valor en porcentaje
		temperatura = 44;
		//printf("El valor de la temperatura en el canal %d es --> %d Porciento \n",canal_temperatura,temperatura);

		//Escritura en memoria
		IOWR(memoria,0x000,ldr);
		IOWR(memoria,0x001,humedad_suelo);
		IOWR(memoria,0x002,humedad_aire);
		IOWR(memoria,0x003,temperatura);
		printf("El valor del LDR es --> %d Porciento \n",ldrRMS);
		usleep(1000000);
	}
	return 0;
}
