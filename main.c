/**
 * @file    OneLed.c
 * @brief   Application entry point.
 */
/**Standard input/output to debug console*/
#include <stdio.h>
/**Standard integer definition provided by the compiler*/
#include <stdint.h>
#include "MK64F12.h"

#define DELAY 1000000
void delay(uint32_t delay);             //Función para establecer el Delay
void led_red();							//Función para ON/OFF del led rojo
void led_blue();						//Función para ON/OFF del led azul
void led_green();						//Función para ON/OFF del led verde


int main(void) {

	while(1){
		led_blue();
		led_red();
		led_green();
	}

    return 0 ;
}

void delay(uint32_t delay)
{
	volatile uint32_t i;

	for(i = 0; i < DELAY; ++i){

	}
}

void led_red()
{
	SIM->SCGC5 = 0x400;                         // Activa la señal de reloj para el Puerto B
	PORTB->PCR[22] = 0x00000100;                // Asigna al puerto B la primer función (Alt1) para el pin 22 del Puerto B, Led Rojo
	GPIOB->PDOR = 0x00400000;                  // Registro que permite un valor lógico en el PIN, en el bit 22 del PB, permite que el Led esté en OFF
	GPIOB->PDDR = 0x00400000;                  // Registro que pone como salida el Pin 22 del Puerto B

	/*Led Rojo*/
	GPIOB->PDOR = 0;

	printf("RED LED ON\n");
	delay(DELAY);

	GPIOB->PDOR= 0x00400000;

	printf("RED LED OFF\n");
	delay(DELAY);
}

void led_blue()
{
	SIM->SCGC5 = 0x400;                         // Activa la señal de reloj para el Puerto B
	PORTB->PCR[21] = 0x00000100;                // Asigna el puerto B la primer función para el pin 21 del Puerto B, Led Azul
	GPIOB->PDOR = 0x00200000;                  // Registro que permite un valor lógico en el PIN, en el bit 21 del PB
	GPIOB->PDDR = 0x00200000;                  // Registro que pone como salida el Pin 21 del Puerto B

	/*Led Azul*/
	GPIOB->PDOR = 0;

	printf("BLUE LED ON\n");
	delay(DELAY);

	GPIOB->PDOR= 0x00200000;

	printf("BLUE LED OFF\n");
	delay(DELAY);
}

void led_green()
{
	SIM->SCGC5 = 0x2000;                        // Activa la señal de reloj para el Puerto E
	PORTE->PCR[26] = 0x00000100;                // Asigna al puerto E la primer función para el pin 26 del Puerto E, Led Verde
	GPIOE->PDOR = 0x04000000;                  //Registro que permite un valor lógico en el PIN, en el bit 26 del PE
	GPIOE->PDDR = 0x04000000;                  // Registro que pone como salida el Pin 26 del Puerto E

	/*Led Verde*/
	GPIOE->PDOR = 0;

	printf("GREEN LED ON\n");
	delay(DELAY);

	GPIOE->PDOR= 0x04000000;

	printf("GREEN LED OFF\n");
	delay(DELAY);

}

