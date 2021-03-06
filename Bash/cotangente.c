/*
Autor:   
Fecha:  
compilador:  
Para Compilar: gcc -o minimoscuadrados minimoscuadrados.c -lm
Version: 
librerias: stdio, math
Resumen: Ejercicio de la cuerda para carne 
*/

//libreiras
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float f(float x);
float df(float x);
void NR(float x0, float tol,float maxiter,int *actiter,float *sol);

void main(void){
    //definimos variables
    float x_inicial=1.5, tolerancia=10,xS;
    int interaciones=10, aiteracion;

    //solucion
    NR(x_inicial,tolerancia,interaciones,&aiteracion,&xS);
    printf("Luego de %d iteraciones, se obtiene %.8f \n",aiteracion,xS);

}
//f(x)
float f(float x){
    float res=0;
    res = cos(x)/sin(x);
    return res;
}
//derivamos
float df(float x){
    float res=0;
    res = -1*pow(sin(x),-2);
    return res;
}
void NR(float x0, float tol,float maxiter,int *actiter,float *sol){
    float xant,x,dif;
    int i=1;
    xant=x0;
    //primera iteracion:
    x=xant-f(xant)/df(xant);
    x=x-xant;
    (dif<0)?dif=-dif:dif;
    while(dif<tol && i<maxiter){
        xant=x;
        x=xant-f(xant)/df(xant);
        i++;
    }
    *sol=x;
    *actiter=i;
}
