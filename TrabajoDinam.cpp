#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
	
class nodo{
	void* info;
	nodo* siguiente;
	
public:
	
nodo(void* v)
{
	info=v; 
	siguiente=0;
}

void poner_siguiente(nodo*n){
	siguiente=n;
}
nodo*leer_siguiente()
{
	return siguiente;
}
 void*leer_info()
{
	return info;
}

};
class lista{
	nodo*cabecera;
	int nodo_num;
public:
	lista(){
		nodo_num=0;
		cabecera=0;
	}
	void quitar(int);
	void insertar(void*,int);
	void poner(void* v)
	{ 
	insertar(v,nodo_num+1);
	}
	void encontrar(int);
	void visualizar();
};

void lista::quitar(int pos)
{
	nodo*prev,*cursor=cabecera;
	if(pos =1)
	{
		cabecera=cursor->leer_siguiente();
		delete cursor;

	}
	else
	{
		for(int i=0;i<pos;i++)
		{
			prev=cursor;
			cursor=cursor-> leer_siguiente();
		}
		if(!cursor->leer_siguiente())
		{
			delete cursor;
			prev->poner_siguiente(0);

		}
		else{
			prev->poner_siguiente(cursor-> leer_siguiente());
			delete cursor;
			nodo_num;
		}
}
	void lista::insertar (void*val,int pos)
	{
		nodo*prev,*cursor=cabecera;
		nodo*aux=new nodo(val);
		 if(! cabecera)
		 	cabecera=aux;
		 else if(pos=0)
		 {
		 	aux-> poner_siguiente(cabecera);
		 	cabecera=aux;
		 }
		 else 
		 {
		 	for(int i=0;(i<pos)&& cursor ->leer_siguiente()M i++)
		 	{
		 		prev=cursor;
		 		if(cursor ->leer_siguiente())
		 		cursor=cursor ->leer_siguiente();

		 	}
		 	if(!cursor ->leer_siguiente())
		 		cursor=cursor->leer_siguiente();
		 }
		 if(!cursor->leer_siguiente());
		 cursor->poner_siguiente(aux);
		 else
		 {
		 	aux->poner_siguiente(cursor);
		 	prev->poner_siguiente(aux);
		 }
	   	}
	    nodo_num ++;
	} 
	void*lista::encontrar(int pos)
	{
		if(!cabecera)
			return 0;
		nodo*cursor=cabecera;

		for(int i=0;i<pos;i++)
			cursor=cursor->leer_siguiente();
		if(cursor)
			return cursor ->leer_info();
			return 0;

	}
	void lista::visualizar()
	{
		void*aux;
		for(int i=0; ;i++)
		{
			if(!(aux=encontrar(i)))
				break;
			cout<<"*" <<(char*)aux<<"\n";
		}
	

	int main()
	{
		lista l;
		l.insertar("Luana",0);
		l.insertar("Jose",1);
		L.insertar("Miriam",2);
		l.visualizar();
	}
}




