#include<iostream>		//cin y cout
#include<stdlib.h>		//para la rand
#include<fstream>		//para leer y escribir archivos
#include"pj.h"
#include"Items.h"
//using namespace std;	//Ni idea por que pero lo necesito para la string

int numeroPersonajes ;

static float stats[15][11][2];	//1era dimension: representa la clase, 2da dimension, represente la stat, 0=Fuerza .... 10=Movimiento, 3ra dimension representa el crecimiento por lvl

pj personaje[100];	//Puedo manejar hasta 100 pj

void cargarMatrizStats(){
	
	int i, j ;
	
	std::ifstream archivoStats ("stats.txt");	//Cargo la matriz de stats
	
	if (archivoStats.is_open()){	//Porsiaca no se abre o no esta el archivo stats.txt
		
		for(i=0 ; i<=10 ; i++){
			for(j=0 ; j<=14 ; j++){
			
				archivoStats>>stats[j][i][0];	//Cargo las stats basicas
			};
		};
		
		for(i=0 ; i<=9 ; i++){
			for(j=0 ; j<=14 ; j++){
			
				archivoStats>>stats[j][i][1];	//Cargo los crecimientos
			
			};
		};
		archivoStats.close();
	}else{
		std::cout<<"ERROR: No se puedo abrir el archivo stats.txt"<<std::endl;
	}
}

void mostrarPersonajes(){
	
	int i, option ;
	bool rep = true ;
	
	std::cout << std::endl << "Hay " << numeroPersonajes << " personajes cargados en este momento: " << std::endl;
	
	for (i=0 ; i < numeroPersonajes ; i++){
		std::cout << " - " << i << " - " << personaje[i].nombre << std::endl ;
	}
	
	do{
		std::cout << std::endl << "Desea conocer las estadisticas de alguno? 100 = NO : " ;
		std::cin >> option ;
		if(option > numeroPersonajes){
			rep = false ;
		}else{
			
			std::cout << std::endl << personaje[option].nombre << std::endl << "Clase: " << personaje[option].clase << " - " << personaje[option].numeroClase << std::endl ;
			std::cout << "Masculino:  " << personaje[option].masculino << " - Femenino: " << personaje[option].femenino << std::endl ;
			std::cout << "Nivel: " << personaje[option].lvl << " - Experiencia: " << personaje[option].experiencia << std::endl ;
			std::cout << "Resistencia: " << personaje[option].resistencia << " / (Actual): " << personaje[option].vida << std::endl ;
			std::cout << "Fuerza: " << personaje[option].fuerza << std::endl ;
			std::cout << "Armadura: " << personaje[option].armadura << std::endl ;
			std::cout << "Poder magico: " << personaje[option].poderMagico << std::endl ;
			std::cout << "Afinidad magica: " << personaje[option].afinidadMagica << std::endl ;
			std::cout << "Agilidad: " << personaje[option].agilidad << std::endl ;
			std::cout << "Habilidad: " << personaje[option].habilidad << std::endl ;
			std::cout << "Suerte: " << personaje[option].suerte << std::endl ;
			std::cout << "Velocidad: " << personaje[option].velocidad << std::endl ;
			std::cout << "Vitalidad: " << personaje[option].vitalidad << std::endl ;
			std::cout << "Movimiento: " << personaje[option].movimiento << std::endl ;
		}
	}while(rep == true);
}

void controlPersonajes(){

	std::string nombre;
	int numeroClase, edad, sexo, option, respuesta;
	bool rep=true;
	
	do{
		std::cout << std::endl << "1-Mostrar personajes, 2-Crear personaje, 3-Cargar personaje, 4-Guardar personaje, 5-Borrar personaje, " << std::endl;
		std::cout << " 6-lvlUp" << std::endl;
		std::cin >> option ;
		switch (option){
			case 1:
				mostrarPersonajes();
				break;
			case 2:
				std::cout << "Como se llamara el personaje?" << std::endl;
 				std::cin >> nombre;
  				std::cout << "Que edad tiene?" << std::endl;
  				std::cin >> edad;
  				std::cout << "Cual es su sexo? 1-Masculino, 2-Femenino" << std::endl;
	 			std::cin >> sexo;
	 			std::cout << "Elija la clase: 1-Ladron, 2-Maestro de la hoja, 3-Arquero, 4-jinete, 5-Blindado, 6-Barbaro, 7-Cruzado," << std::endl ;
				std::cout << " 8-Auriga, 9-Mago, 10-Mago negro, 11-Clerigo, 12-Bardo, 13-Esper, 14-Alquimista, 15-Conjurador" << std::endl;
				std::cin >> numeroClase;
				personaje[numeroPersonajes].nombre = nombre ;
			
				personaje[numeroPersonajes].crearPersonaje(nombre,numeroClase,edad, sexo, stats);
				std::cout << personaje[numeroPersonajes].nombre << " se creo correctamente!" << std::endl;
				numeroPersonajes = numeroPersonajes + 1;
				break;
			case 3:
				personaje[numeroPersonajes].cargar(personaje[numeroPersonajes]) ;
				std::cout << personaje[numeroPersonajes].nombre << " se cargo correctamente!" << std::endl;
				numeroPersonajes = numeroPersonajes + 1;
				break;
			case 4:
				std::cout << "Ingrese el numero identificador del personaje a guardar (Puede verlos en 'Mostrar personajes'). 100 = Cancelar : " << std::endl;
				std::cin >> respuesta ;
				if(respuesta < numeroPersonajes){
					personaje[respuesta].guardar(personaje[respuesta]) ;
					std::cout << personaje[respuesta].nombre << " guardado correctamente en el archivo 'save.bin' " << std::endl;
				}else{
					std::cout << "No hay ningun personaje en ese identificador (Puede verlos en 'Mostrar personajes')" << std::endl;
				}
				break;
			case 5:
				std::cout << "Ingrese el numero identificador del personaje a borrar (Puede verlos en 'Mostrar personajes'). 100 = Cancelar" << std::endl << "CUIDADO: NO SE PUEDE DESHACER!: ";
				std::cin >> respuesta ;
				if(respuesta < numeroPersonajes){
					std::cout << std::endl << "SE HA BORRADO EL PERSONAJE " << personaje[respuesta].nombre << std::endl;
					numeroPersonajes = numeroPersonajes - 1 ;
					if(respuesta != (numeroPersonajes)){
						std::cout << "SE HA MOVIDO LA IDENTIDAD DE " << personaje[numeroPersonajes].nombre << " id: " << numeroPersonajes << " A NUEVA id: " << respuesta << std::endl;
						personaje[respuesta] = personaje[numeroPersonajes] ;
					}
				}else{
					std::cout << std::endl << "No se ha borrado ningun personaje" << std::endl;
				}
				break;
			case 6:
				std::cout << "Ingrese el numero identificador del personaje a levelear (Puede verlos en 'Mostrar personajes'). 100 = Cancelar" << std::endl;
				std::cin >> respuesta ;
				personaje[respuesta].lvlUp(stats) ;
				break;
			
			default:
				rep = false;
		}
		
	}while(rep == true);
}

void golpe(std::string nombre1, int str,int hit,Item& arma1,std::string nombre2, int eva,int pdef){

	float crit ;
	unsigned int chance, dmg;
	int probCritico=5;
	dmg = str - pdef;

  	if (eva<1){
  		eva = 1; 		//Evita el denominador en 0
	}
	crit = arma1.multiplicadorCritico ;
	chance = (hit * 100 / eva) ;
    if(chance < 1){
    	chance = 1 ;	//Evita chances negativas
	}
  	if(dmg < 0){		//Evita daño negativo, "curar con un golpe"
      	dmg = 0;
    }
    if(chance < (rand() % 100)){										//Revisa si el ataque fallara
    	if((probCritico + 50 - (5000 / chance)) < (rand () % 100)){		//Recita el critical
    		std::cout << "     " << nombre1 << " --> Golpe critico! --> " << nombre2 << " por " << dmg * crit << " de vida perdida. - " << arma1.nombre << std::endl;
		}else{
			std::cout << "     " << nombre1 << " --> Golpe --> " << nombre2 << " por " << dmg << " de vida perdida. - " << arma1.nombre << std::endl;
		}
	}else{
		std::cout << "     " << nombre1 << " --> Ataque esquivado --> " << nombre2 << " - " << arma1.nombre << std::endl;
	}
}

void attack(){

	int str1, hit1, eva1, pdef1, dmg1, speed1, golpes, respuesta;
	int str2, hit2, eva2, pdef2, dmg2, speed2;
	std::string nombre1, nombre2 ;
	Item arma1, arma2 ;
	
	std::cout << "Quien sera el agresor? 100-Cargar datos: ";
	std::cin >> respuesta;
	if(respuesta<numeroPersonajes){
		arma1 = selectorItem(personaje[respuesta].inventaio[0]) ;
		std::cout << personaje[respuesta].nombre << " sera el agresor";
		nombre1 = personaje[respuesta].nombre ;
		str1 = personaje[respuesta].fuerza ;
		pdef1 = personaje[respuesta].armadura ;
		eva1 = personaje[respuesta].agilidad ;
		hit1 = personaje[respuesta].habilidad ;
		speed1 = personaje[respuesta].velocidad ;
	}else{
		arma1 = selectorItem(unsigned int 0) ;
		std::cout << "Fuerza del agresor: ";
  		std::cin >> str1;
  		std::cout << "Armadura del agresor: ";
  		std::cin >> pdef1;
  		std::cout << "Agilidad del agresor: ";
  		std::cin >> eva1;
  		std::cout << "Habilidad del agresor: ";
  		std::cin >> hit1;
  		std::cout << "Velocidad del agresor: ";
  		std::cin >> speed1;
  		nombre1 = "Agresor" ;
	}
	std::cout << "Quien sera el defensor? 100-Cargar datos: ";
	std::cin >> respuesta;
	if(respuesta<numeroPersonajes){
		arma2 = selectorItem(personaje[respuesta].inventaio[0]) ;
		std::cout << personaje[respuesta].nombre << " sera el defensor";
		nombre2 = personaje[respuesta].nombre ;
		str2 = personaje[respuesta].fuerza ;
		pdef2 = personaje[respuesta].armadura ;
		eva2 = personaje[respuesta].agilidad ;
		hit2 = personaje[respuesta].habilidad ;
		speed2 = personaje[respuesta].velocidad ;
	}else{
		arma2 = selectorItem(unsigned int 0) ;
		std::cout << "Fuerza del defensor: ";
  		std::cin >> str2;
  		std::cout << "Armadura del defensor: ";
  		std::cin >> pdef2;
  		std::cout << "Agilidad del defensor: ";
  		std::cin >> eva2;
  		std::cout << "Habilidad del defensor: ";
  		std::cin >> hit2;
  		std::cout << "Velocidad del agresor: ";
  		std::cin >> speed2;
  		nombre2 = "Defensor" ;
	}
	if(speed2<speed1){
		golpes = 0;
		while(golpes<=speed1){
			golpe(nombre1,str1,hit1,arma1,nombre2,eva2,pdef2);
			golpes = golpes + speed2;
		}
	}else{
		golpes = speed1 * 2;
		golpe(nombre1,str1,hit1,arma1,nombre2,eva2,pdef2);
		while(golpes<=speed2){
			golpe(nombre2,str2,hit2,arma2,nombre1,eva1,pdef1);
			golpes = golpes + speed2;
		}
	}
}

void magicattack(){

  	int mg, hit, eva, mdef, dmg, chance, crit=3, repetir;

  	std::cout << "Poder magico del Agresor: ";
  	std::cin >> mg;
  	std::cout << "Afinidad magica del Defensor: ";
  	std::cin >> mdef;
  	std::cout << "Agilidad del Defensor: ";
  	std::cin >> eva;
  	std::cout << "Habilidad del Agresor: ";
  	std::cin >> hit;

  	dmg = mg - mdef;
  	chance = (hit * 100 / eva);

  	if (eva<1){
  		eva = 1; 														//Evita el denominador en 0
	  }

  	if (dmg < 0){														//Evita daño negativo, "curar con un golpe"
      	dmg = 0;
    }

  	do{
      	if (chance < 100){												//Revisa si el ataque fallara
	  		if (chance < (rand () % 100)){
	      		std::cout << "Ataque esquivado" << std::endl;
	    	}else{
	      		std::cout << "Golpe: " << dmg << std::endl;
	    	}
		}else{															//El ataque es inesquivable y revisa el critical
	  		if (((100 - (10000 / chance)) < (rand () % 100))){
	      		std::cout << "Golpe: " << dmg << std::endl;
	    	}else{
	      		std::cout << "Golpe critico! : " << dmg * crit << std::endl;
	    	}
		}

      	std::cout << std::endl << "Repetir? 1-Si, 2-No: ";
      	std::cin >> repetir;

    }while (repetir == 1);
}

int dice(){

	int caras, num, repetir;

	std::cout << "Cuantas caras tendra el dado? ";
  	std::cin >> caras;

	do{
		num = (rand() % caras);
		std::cout <<num<< " de "<<caras<<" caras"<< std::endl;
		std::cout << "Repetir? 1-Si, 2-No: ";
      	std::cin >> repetir;

	}while (repetir == 1);
}

int main(){
	
	cargarMatrizStats();
	
	int option, str, hit, wdmg=0, weight=0, pdef, eva;
  	unsigned long int seed;
  	bool rep=true;
  	std::cout << "Hola! Rol V2.4 -Niwil 17/11/2020" << std::endl;

  	do{
      	std::cout << std::endl << "1-Menu de personajes, 2-Ataque fisico, 3-Golpe fisico, 4-Ataque magico, 5-Lanzar dado, 6-Elegir semilla, " << std::endl;
      	std::cout << " 0-Salir" << std::endl ;
      	std::cin >> option;
      	switch (option){
	  		case 1:
	  			controlPersonajes();
	    		break;
	  		case 2:
	  			attack();
	    		break;
	    	case 3:
	    		std::cout << "Fuerza del agresor: ";
  				std::cin >> str;
  				std::cout << "Habilidad del agresor: ";
  				std::cin >> hit;
  				//std::cout << "Wdmg del agresor: ";
  				//std::cin >> wdmg;
  				//std::cout << "weight del agresor: ";
  				//std::cin >> weight;
  				std::cout << "Armadura del defensor: ";
  				std::cin >> pdef;
  				std::cout << "Agilidad del defensor: ";
  				std::cin >> eva;
	  			golpe ("Agresor",str,hit,0,0,"Defensor",pdef,eva);
	    		break;
	  		case 4:
	  			magicattack ();
	    		break;
	    	case 5:
	    		dice();
	    		break;
	    	case 6:
	    		std::cout << "Ingrese un numero para la semilla: ";
	    		std::cin >> seed;
	    		srand (seed);
	    		break;
	  		default:
	    		rep = false;
	    		std::cout << "Gracias por jugar con nosotros! Agradecimientos especiales a:" << std::endl << "- Facundo Reynoso - Por ayudar con la programacion" << std::endl ;
	    		std::cout << "- Nelson - Por ayudar con la programacion" << std::endl << "- Stefano Colla - Por TODO! Programacion, planeacion, y el apoyo!" << std::endl ;
	    		std::cout << "- Lando" << std::endl ;
		};
    }while (rep == true);
  	return 0;
}

