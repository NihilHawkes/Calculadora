#include<iostream>		//cin y cout
#include<stdlib.h>		//para la rand
#include<fstream>		//para leer y escribir archivos
#include"pj.h"
//using namespace std;	//Ni idea por que pero lo necesito para la string

//https://docs.google.com/spreadsheets/d/1lwYnpWyiZblvgpLXOIY6vWetmqHca2Yem54Ybshgh-U/edit#gid=0

void pj::crearPersonaje(std::string nombreRecibido, int numeroClaseRecibido, int edadRecibida, int sexo , float stats[15][11][2]){
	
	nombre = nombreRecibido ;
	numeroClase = numeroClaseRecibido ;
	edad = edadRecibida ;
	
	humano = true ;
	undead = false ;
	demonio = false ;
	volador = false ;
	
	afinidadPyro = 0 ;
	afinidadTerra = 0 ;
	afinidadBrisa = 0 ;
	afinidadAqua = 0 ;
	afinidadElectro = 0 ;
	afinidadLux = 0 ;
	afinidadMale = 0 ;
	afinidadLotus = 0 ;
	afinidadBio = 0 ;
	afinidadCaos = 0 ;
	
	lvl = 1 ;
	experiencia = 0 ;
	vida = stats[numeroClase][0][0] ;
	
	resistencia = stats[numeroClase][0][0] ;
	fuerza = stats[numeroClase][1][0] ;
	armadura = stats[numeroClase][2][0] ;
	poderMagico = stats[numeroClase][3][0] ;
	afinidadMagica = stats[numeroClase][4][0] ;
	agilidad = stats[numeroClase][5][0] ;
	habilidad = stats[numeroClase][6][0] ;
	suerte = stats[numeroClase][7][0] ;
	velocidad = stats[numeroClase][8][0] ;
	vitalidad = stats[numeroClase][9][0] ;
	movimiento = stats[numeroClase][10][0] ;
	
	inventario[0] = 0 ;
	inventario[1] = 0 ;
	inventario[2] = 0 ;
	inventario[3] = 0 ;
	inventario[4] = 0 ;
	inventario[5] = 0 ;
	inventario[6] = 0 ;
	inventario[7] = 0 ;
	
	switch(sexo){
		case 1:
			masculino = true ;
			femenino = false ;
			break;
		case 2:
			masculino = false ;
			femenino = true ;
			break;
		default:
			masculino = false ;
			femenino = false ;
	};
	
	switch (numeroClase){
		case 0:
			clase = "Basico" ;
			break;
		case 1:
			clase = "Ladron" ;
			break;
		case 2:
			clase = "Maestro hoja" ;
			break;
		case 3:
			clase = "Arquero" ;
			break;
		case 4:
			clase = "Jinete" ;
			break;
		case 5:
			clase = "Blindado" ;
			break;
		case 6:
			clase = "Barbaro" ;
			break;
		case 7:
			clase = "Cruzado" ;
			break;
		case 8:
			clase = "Auriga" ;
			volador = true ;
			break;
		case 9:
			clase = "Mago" ;
			break;
		case 10:
			clase = "Chaman" ;
			afinidadMale = 1 ;
			break;
		case 11:
			clase = "Sacerdote" ;
			afinidadLux = 1 ;
			break;
		case 12:
			clase = "Conjurador" ;
			afinidadPyro = 1 ;
			afinidadTerra = 1 ;
			afinidadAqua = 1 ;
			afinidadBrisa = 1 ;
			break;
		case 13:
			clase = "Esper" ;
			afinidadLotus = 1 ;
			break;
		case 14:
			clase = "Alquimista" ;
			break;
	};
}

void pj::lvlUp(float stats[15][11][2]){
	
	int crecimiento[10], i ;
	float cont[10] ;
	bool end ;

	for(i=0 ; i<10 ; i++){
		crecimiento[i] = 0;		//Pongo en 0 el vector q luego mostrare
	}
	for(i=0 ; i<10 ; i++){
		cont[i] = stats[numeroClase][i][1] ;	//Copio el vector de probabilidades, segun la clase, en un vector de conteo
	}
	for(i=0 ; i<10 ; i++){
		do{
			if(cont[i]>1){
				crecimiento[i] = crecimiento[i] + 1;
				cont[i] = cont[i] - 1;
				end = false ;
			}else{
				end = true;
				if((rand() % 101) < cont[i] * 100){
					crecimiento[i] = crecimiento[i] + 1;
				}
			}
		}while(end==false);
	}
	lvl = lvl + 1 ;
	
	resistencia = resistencia + crecimiento[0] ;
	fuerza = fuerza + crecimiento[1] ;
	armadura = armadura + crecimiento[2] ;
	poderMagico = poderMagico + crecimiento[3] ;
	afinidadMagica = afinidadMagica + crecimiento[4] ;
	agilidad = agilidad + crecimiento[5] ;
	habilidad = habilidad + crecimiento[6] ;
	suerte = suerte + crecimiento[7] ;
	velocidad = velocidad + crecimiento[8] ;
	vitalidad = vitalidad + crecimiento[9] ;
	
	std::cout << std::endl << nombre << " ha subido de nivel ! Nv. " << lvl << " - y obtuvo;";
	std::cout << std::endl << "Resistencia: +" << crecimiento[0] ;
	std::cout << std::endl << "Fuerza: +" << crecimiento[1] ;
	std::cout << std::endl << "Armadura: +" << crecimiento[2] ;
	std::cout << std::endl << "Poder magico: +" << crecimiento[3] ;
	std::cout << std::endl << "Afinidad magica: +" << crecimiento[4] ;
	std::cout << std::endl << "Agilidad: +" << crecimiento[5] ;
	std::cout << std::endl << "Habilidad: +" << crecimiento[6] ;
	std::cout << std::endl << "Suerte: +" << crecimiento[7] ;
	std::cout << std::endl << "Velocidad: +" << crecimiento[8] ;
	std::cout << std::endl << "Vitalidad: +" << crecimiento[9] ;

}

void pj::guardar(pj& cualGuardar){
	
	std::ofstream characterToSave ;
	
	characterToSave.open("save.bin", std::ios::binary);
	
	characterToSave.write((char*)&cualGuardar,sizeof(cualGuardar));
	
	characterToSave.close();
}

void pj::cargar(pj& dondeCargar){
	
	std::ifstream characterToLoad ;
	
	characterToLoad.open("save.bin", std::ios::binary);
	
	characterToLoad.read((char*)&dondeCargar,sizeof(dondeCargar));
	
	characterToLoad.close();
}

