#ifndef PJ_H
#define PJ_H

class pj
{
	public:
		std::string nombre, clase;
		unsigned int resistencia, fuerza, armadura, poderMagico, afinidadMagica, agilidad, habilidad, suerte, velocidad, vitalidad, movimiento, lvl, experiencia, vida ;
		unsigned int afinidadPyro, afinidadTerra, afinidadBrisa, afinidadAqua, afinidadElectro, afinidadLux, afinidadMale, afinidadLotus, afinidadBio, afinidadCaos ;
		unsigned int numeroClase, edad, inventario[8] ;
		bool volador, undead, demonio, masculino, femenino, humano ;
		
		void crearPersonaje(std::string nombreRecibido, int numeroClaseRecibido, int edadRecibida, int sexo, float stats[15][11][2]);
		void lvlUp(float stats[15][11][2]);
		void guardar(pj& cualGuardar);
		void cargar(pj& dondeCargar);
};

#endif
