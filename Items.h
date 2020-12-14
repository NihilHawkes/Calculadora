#ifndef ITEMS_H
#define ITEMS_H

class Items
{
	public:
		
		int probabilidadCritico ;
		unsigned int peso, numeroTipo ;
		float multiplicadorCritico, perfArmadura ;
		
		std::string nombre, tipo ;
		bool equipable ;
		
		void selectorItem(unsigned int identificador);
		
		//Armas hasta el 068
					//Dagas
		void 001();		//Daga
		void 002();		//Cuchillo
		void 003();		//Estilete
		void 004();		//Bayoneta
		void 005();		//Kunai
		void 006();		//Hoz de mano
		void 007();		//Karambit
		void 008();		//Facon
					//Espadas
		void 009();		//Espada bastarda
		void 011();		//Espada ropera
		void 012();		//Katana
		void 013();		//Nodachi
		void 014();		//Claymore
		void 015();		//Sable
		void 016();		//Gladio
		void 017();		//Espada dentada
		void 018();		//Katana dentada
		void 019();		//Espada diamantina
		void 020();		//Machete
		void 021();		//Mandoble
		void 022();		//Corquete de mano
		void 023();		//Gurka
		void 024();		//Falcata
		void 025();		//Espada larga
		void 026();		//Espada de obsidiana
					//Lanzas
		void 027();		//Lanza de madera
		void 028();		//Lanza de metal
		void 029();		//Pica
		void 030();		//Alabarda
		void 031();		//Javalina
		void 032();		//Naginata
		void 033();		//Hoz larga
		void 034();		//Corquete enastado
		void 035();		//Tridente
		void 036();		//Bidente
		void 037();		//Yari
		void 038();		//Baston
					//Hachas
		void 039();		//Tomahawk
		void 040();		//Hacha doble hoja
		void 041();		//Hacha de hierro
		void 042();		//Hacha de acero
		void 043();		//Hacha enorme
		void 044();		//Alabardon de doble filo
					//Mazas
		void 045();		//Martillo de guerra
		void 046();		//Maza
		void 047();		//Lucero del alba
		void 048();		//Garrote
		void 049();		//Milicia
		void 050();		//Corona
		void 051();		//Puno americano
		void 052();		//Estrella negra
					//Arcos
		void 053();		//Arco corto
		void 054();		//Arco largo
		void 055();		//Yumi
		void 056();		//Arco curvo
		void 057();		//Arco de caza
					//Otras armas
		void 058();		//Ballesta
		void 059();		//Balista
		void 060();		//Chu ko nu
		void 061();		//Arbalesta
		void 062();		//Honda
		void 063();		//Boleadoras dobles
		void 064();		//Boleadoras triples
		void 065();		//Tirachinas
		void 066();		//Pistola
		void 067();		//Arcabus
		void 068();		//Lanzadardos

};

#endif


