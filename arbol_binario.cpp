#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int contador=0;
int cont=0;
int bandera=0;
class nodo {
	//dESDE OTRA CLASE SE PUEDEN acceder a estos atributos
   public:
    nodo(int v, nodo *izq, nodo *der ,nodo *pad)
    {
       valor = v;
       izquierda = izq;
       derecha = der;
       padre=pad;
    }
    //Desde otra clase/funcion no de puede acceder a los atributos o metodos privados.
   private:
    int valor;
    nodo *izquierda;
    nodo *derecha;
    nodo *padre;

   //Una funcion externa puede acceder a los atributos privados.
   friend class lista;
};

//PROTOTIPOS
void menu();
void mostrar();
nodo *crearnodo(int,nodo *);


nodo *arbol = NULL; //incializa el arbol en NULL
nodo *anterior_eliminar = NULL; //incializa el arbol en NULL
nodo *raiz=NULL;//guarda un apuntador a la raiz del arbol;
nodo *subderecho=NULL;
nodo *subizquierdo=NULL;
typedef nodo *pnodo;

class lista {
   public:
   	void insertarnodo(nodo *&, int, nodo * );
   	void mostrararbol(nodo *); //funcion para mostrar el arbol con recursividad
   	void mostrararbol2(nodo *); //FUNCIOIN PARA RECCORER EL arbol con while
   	int buscar(int , nodo *);
   	int eliminar(int, nodo *);
   	int aniadir(nodo *);
   	int identificar(int,nodo *);
   	int caracteristicas(int, nodo*);
   	void preorden(nodo *);
	void inorden(nodo *);
	void postorden(nodo *);
   private:
    pnodo primero;
    pnodo actual;
};




bool encontrado;
int main() {
	menu();
   system("pause");
   return 0;
}

void menu(){
	int opcion=0,val=0,contador=0;
	do {
		system("cls");
		cout<<"--------------ARBOLES---------------------"<<	endl;
		cout<<"1. Insertar un nodo"<<endl;
		//cout<<"2. listar nodos usando while"<<endl;
		cout<<"2. listar nodos usando recursividad"<<endl;
		cout<<"3. buscar un nodo por su valor"<<endl;
		cout<<"4. Eliminar nodo por su valor"<<endl;
		cout<<"5. Identificar nodo"<<endl;
		cout<<"6. Caracteristicas de un nodo"<<endl;
		cout<<"7. Recorrido en Pre_orden"<<endl;		
		cout<<"8. Recorrido en In_orden"<<endl;		
		cout<<"9. Recorrido en Pos_orden"<<endl;
		cout<<"0. salir"<<endl<<endl;
		cout<<"ingrese una opcion: ";
		cin>>opcion;
			switch(opcion){
				case 1:
						system("cls");
						cout<<"--------INGRESANDO UN NODO--------"<<endl;
						cout<<"ingrese el valor del nodo: ";
						cin>>val;
						lista Lista;
						Lista.insertarnodo(arbol,val,NULL);
						system("pause");
						break;
				case 2: 
						system("cls");
						cout<<"--------MOSTRANDO EL ARBOL RECURSIVO--------"<<endl;
						lista Lista2;
						Lista2.mostrararbol(arbol);
						system("pause");
						break;
						
				case 5:
						system("cls");
						cout<<""<<endl;
						cout<<"--------IDENTIFICANDO UN NODO--------"<<endl;
						cout<<endl<<"ingrese el valor del nodo a identificar: "; cin>>val;
						bandera=0;
						lista lista5;
						lista5.identificar(val,arbol);
						if(bandera != 1){
							cout<<endl<<"=============== NODO NO ENCONTRADO ==========================="<<endl;	
						}			
						system("pause");
						break;
						
				case 4:
						system("cls");
						cout<<"-------ELIMINAR UN NODO POR SU VALOR--------------------"<<endl<<endl;
						cout<<"ingrese el valor del nodo a eliminar: "; cin>>val;
						bandera=0;
						lista Lista4;
						arbol=raiz;
						Lista4.eliminar(val,arbol);
						if(bandera != 1){
							cout<<endl<<"=============== NODO NO ENCONTRADO ==========================="<<endl;	
						}
						system("pause");
						break;	
				case 6:
						system("cls");
						cout<<"-------CARACTERISTICAS DE UN NODO-------------"<<endl<<endl;
						cout<<"ingrese el valor del nodo: "; cin>>val;
						cont=0;
						bandera=0;
						lista lista6;
						lista6.caracteristicas(val,arbol);
						if(bandera != 1){
							cout<<endl<<"=============== NODO NO ENCONTRADO ==========================="<<endl;	
						}
						system("pause");
						break;
				case 7:
						system("cls");
						cout<<"-----------PRE-ORDEN-----------"<<endl;
						lista Lista7;
						Lista7.preorden(arbol);
						cout<<"\n\n";
						system("pause");
				break;
				case 8:
						system("cls");
						cout<<"-----------IN-ORDEN-----------"<<endl;
						lista Lista8;
						Lista8.inorden(arbol);
						cout<<"\n\n";
						system("pause");
				break;
				case 9:
											system("cls");
						cout<<"-----------POS-ORDEN-----------"<<endl;
						lista Lista9;
						Lista9.postorden(arbol);
						cout<<"\n\n";
						system("pause");
				break;				
						
				case 3:
						system("cls");
						cout<<"-------BUSAR UN NODO POR SU VALOR--------------------"<<endl<<endl;
						int valor_buscado=0;
						cout<<"ingrese el valor buscado: "; cin>>valor_buscado;
						bandera=0;
						lista Lista3;
					 	Lista3.buscar(valor_buscado,arbol);
					 	if(bandera != 1){
							cout<<endl<<"=============== NODO NO ENCONTRADO ==========================="<<endl;	
						}
						system("pause");
						break;
				
				
			}	
	}while(opcion != 0);
}
//funcion para recorrido de profundidad PRE-ORDEN
void lista::preorden(nodo *arbol){
	if(arbol == NULL){ //Si el arbol esta vacio
		return;
	}
	else{
		cout<<arbol->valor<<" - ";
		preorden(arbol->izquierda);
		preorden(arbol->derecha);	
	}	
}

//Funcion para recorrido en profundidad  - InOrden
void lista::inorden(nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inorden(arbol->izquierda);
		cout<<arbol->valor<<" - ";
		inorden(arbol->derecha);
	}
}


//Funcion para recorrido en profundidad - PosOrden
void lista::postorden(nodo *arbol){
	if(arbol == NULL){ //Si el arbol esta vacio
		return;
	}
	else{
		postorden(arbol->izquierda);
		postorden(arbol->derecha);
		cout<<arbol->valor<<" - ";
	}
}


//funcion para describir las caracteristicas de un nodo
int lista::caracteristicas(int n,nodo *arbol){
	if(arbol== NULL){
		return 0;
	}else{
		if(arbol->valor == n){
			//muestra el camino y la longitud de camino
			if(arbol==raiz){
				cout<<"ERROR. no se puede describir al nodo raiz"<<endl;
				bandera=1;
				return 0;
			}else{
				cout<<"EL ORDEN DEL NODO INGRESADO ES : 2" <<endl;
				//buscamos el orden
				if(arbol->izquierda != NULL && arbol->derecha != NULL){
					cout<<"EL GRADO DEL NODO INGRESADO ES : 2" <<endl;
				}else if(arbol->izquierda== NULL && arbol->derecha != NULL){
					cout<<"EL GRADO DEL NODO INGRESADO ES : 1" <<endl;
				}else if(arbol->izquierda != NULL && arbol->derecha ==NULL){
					cout<<"EL GRADO DEL NODO INGRESADO ES : 1" <<endl;
				}else if(arbol->izquierda == NULL & arbol->derecha == NULL){
					cout<<"EL GRADO DEL NODO INGRESADO ES : 0" <<endl;
				}
				//buscamos el camino y la longitud 
				cout<<"para llegar al nodo especificado debe visitar los siguientes nodos: "<<endl;
				while(arbol!=NULL)	{
					 arbol=arbol->padre;
						cont++;
						cout<<arbol->valor<<endl;
						if(arbol->padre==NULL){
							cout<<"LA LONGITUD DEL CAMINO ES: "<<cont<<endl;
							cout<<"EL NIVEL DEL NODO INGRESADO ES : " <<cont+1<<endl;
							cout<<"LA ALTURA DEL NODO INGRESADO ES : " <<cont+1<<endl;
							bandera=1;
							return 0;
						}
				}//fin del while
				
				//ahora buscamos la altura del nodo ingresado
						
			}//fin del else de igual a raiz
			
		}else{
			
			 	 caracteristicas(n,arbol->izquierda);
			 	 caracteristicas(n,arbol->derecha);	
			 	
			 
		}
	}//fin del if
}

//funcion para identificar un nodo
int lista::identificar( int valor2,nodo *arbol){
	if(arbol == NULL){
		return 0;
	}else{
		if(arbol->valor == valor2){
			if(arbol->padre == NULL){
				cout<<"EL NODO INGRESADO ES NODO RAIZ"<<endl;
			}else{
				if(arbol->padre->izquierda == arbol){ //si es hijo izquierdo
					cout<<"EL NODO INGRESADO ES HIJO IZQUIERDO DEL NODO CON VALOR "<<arbol->padre->valor<<endl;
					if(arbol->padre->derecha != NULL){
						cout<<"EL NODO INGRESADO ES HERMANO DEL NODO CON VALOR "<<arbol->padre->derecha->valor<<endl;
					}
				}else if( arbol->padre->derecha == arbol){//si es hijo derecho
					cout<<"EL NODO INGRESADO ES HIJO DERECHO DEL NODO CON VALOR "<<arbol->padre->valor<<endl;	
					if(arbol->padre->izquierda != NULL){
						cout<<"EL NODO INGRESADO ES HERMANO DEL NODO CON VALOR "<<arbol->padre->izquierda->valor<<endl;
					}
				}
			}
			if(arbol->izquierda != NULL || arbol->derecha !=NULL){
				cout<<"EL NODO INGRESADO ES NODO PADRE"<<endl;
			}
			if(arbol->izquierda == NULL && arbol->derecha == NULL){
				cout<<"EL NODO INGRESADO ES NODO HOJA "<<endl;
			}else{
				if(arbol != raiz){
					cout<<"EL NODO INGRESADO ES NODO RAMA"<<endl;
				}
				
			}
			bandera=1;
			return 0;
		}else{
			identificar(valor2,arbol->izquierda);
			identificar(valor2,arbol->derecha);
		}
	}
}//fin de la funcion identificar


//funcioni para eliminar un nodo y hacer que el subarbol derecho ocupe el lugar del nodo que se elimine.
int lista::eliminar(int valor, nodo *arbol){
	if(arbol == NULL){
		return 0;
	}else{
		if(arbol->valor == valor){ //cuando lo encuentre lo va mostrar y luego procede a eliminarlo
		anterior_eliminar=NULL;
		//comprobamos si es un nodo hoja
			if(arbol->izquierda == NULL && arbol->derecha == NULL){
				anterior_eliminar=arbol->padre;
				//ahora vemos si es hoa izq o der
				if(anterior_eliminar->izquierda == arbol){
					delete arbol;
					anterior_eliminar->izquierda = NULL;
					cout<<" ----NODO HOJA ELIMINADO----"<<endl;
					//arbol=raiz;
					bandera=1;
					return 0;
				}else if(anterior_eliminar->derecha ==arbol){
					delete arbol;
					anterior_eliminar->derecha = NULL;
					cout<<" ----NODO HOJA ELIMINADO----"<<endl;
					//arbol=raiz;
					bandera=1;
					return 0;
				}
				// en caso que no sea hoja,, cuando tenga hijo izquierdo pero no derecho
			}else if(arbol->izquierda !=NULL && arbol->derecha == NULL){//comprobamos si tiene nodo hijio izquierdo pero no derecho
				//aca se puede presentar dos situaciones, que el nodo a liminar sea izquierdo, o que sea hijo derecho
				//vamos a evaludar de que situacion se trata
				//cout<<"es cuando el nodo tiene solo hijo izquierdo, y no derecho"<<endl;
				subizquierdo=arbol->izquierda;
				anterior_eliminar=arbol->padre; 
				//cout<<"el valor del padre es:  "<<anterior_eliminar->valor<<endl; system("pause"); 
				if(anterior_eliminar->izquierda == arbol){ //si es nodo hijo izquierdo
					//cout<<"es nodo izquierdo con hijo izquierdo"<<endl; system("pause");
					anterior_eliminar->izquierda=subizquierdo;
					subizquierdo->padre=anterior_eliminar;
					delete arbol;
					cout<<endl<<"------ nodo eliminado----------"<<endl;
					//arbol=raiz;
					bandera=1;
					return 0;
				}else if(anterior_eliminar->derecha==arbol){//si es nodo hijo derecho
					//cout<<"es nodo izquierdo con hijo derecho"<<endl; system("pause");
					anterior_eliminar->derecha=subizquierdo;
					subizquierdo->padre=anterior_eliminar;
					delete arbol; 
					cout<<endl<<"------ nodo eliminado----------"<<endl;
					//arbol=raiz;
					bandera=1;
					return 0;
				}
			}else if(arbol->izquierda == NULL && arbol->derecha !=NULL){
				subderecho=arbol->derecha;
				anterior_eliminar=arbol->padre;
				//evaluamos si es hijo izquierdo
				if(anterior_eliminar->izquierda==arbol){
					anterior_eliminar->izquierda=subderecho;
					subderecho->padre=anterior_eliminar;
					delete arbol;
					cout<<endl<<"------ nodo eliminado----------"<<endl;
					//arbol=raiz;
					bandera=1;
					return 0;
				}else if( anterior_eliminar->derecha == arbol){ //si es un hijo derecho
					anterior_eliminar->derecha=subderecho;
					subderecho->padre=anterior_eliminar;
					delete arbol;
					cout<<endl<<"------ nodo eliminado----------"<<endl;
					//arbol=raiz;
					bandera=1;
					return 0;
				}
			}else if(arbol->izquierda != NULL && arbol->derecha != NULL){//si tiene hijo izquierdo y derecho
						//cout<<" ES CUANDO TIENE DOS HIJOS"<<endl; system("pause");
						anterior_eliminar=arbol->padre;
						subderecho=arbol->derecha;
						subizquierdo=arbol->izquierda;
						
						if(anterior_eliminar->izquierda == arbol){//es un nodo hijo izquierdo
						//cout<<"es nodo izquierdo con dos hijos "<<endl;  system("pause");
							anterior_eliminar->izquierda=subizquierdo;
							subizquierdo->padre=anterior_eliminar;
							delete arbol; 
							cout<<endl<<"------ nodo eliminado----------"<<endl;
							arbol=subizquierdo;
							while(arbol!=NULL){
								if(arbol->derecha == NULL){
									arbol->derecha=subderecho;
									subderecho->padre=arbol;
									bandera=1;
									return 0;
								}
								arbol=arbol->derecha;
							}
							
							
						}else if(anterior_eliminar->derecha == arbol){//es un nodo hijo derecho
						//out<<"es nodo derecho con dos hijos "<<endl;  system("pause");
							anterior_eliminar->derecha=subderecho;
							subderecho->padre=anterior_eliminar;
							delete arbol;
							cout<<endl<<"------ nodo eliminado----------"<<endl;
							arbol=subderecho;
							while(arbol!=NULL){
								if(arbol->izquierda == NULL){
									arbol->izquierda=subizquierdo;
									subizquierdo->padre=arbol;
									//arbol=raiz;
									bandera=1;
									return 0;
								}
								arbol=arbol->izquierda;
							}
							
						}
					}
		}else{
				
				eliminar(valor,arbol->izquierda);
				eliminar(valor,arbol->derecha);
			}
	}
}



//funcion para crear nodos nuevos
nodo *crearnodo(int n,nodo *padre){
     nodo *nuevo_nodo= new nodo(n,NULL,NULL,padre);
     return nuevo_nodo;
}

//funcion para insertar nodos en el arbol
void lista::insertarnodo(nodo *&arbol, int n, nodo *padre){
     if(arbol==NULL)
     {		//si el arbol esta vacio
            nodo *nuevo_nodo=crearnodo(n,padre);
            arbol=nuevo_nodo;
             if (contador == 0){
            	raiz=arbol;
			}
           contador++;
     }else //si el arbol tiene al menos un nodo
     {		//aca debemos preguntar a que lado del unico nodo que tiene va insertar, si a  la izq, o la derecha
  			cout<<"------------Seleccione una opcion: ---------"<<endl<<endl;
  			cout<<"1. Ingresar nodos a la izquiera "<<endl;
  			cout<<"2. Ingresar nodos a la derecha "<<endl;
  			int selec=0; cin>>selec;
  			switch(selec){
  				case 1: //ingresamos el valor al nodo izquierdo
  						insertarnodo(arbol->izquierda,n,arbol);
  						break;
  				case 2://ingresamos el valor al nodo derecho
  						insertarnodo(arbol->derecha,n,arbol);
  						break;
			  }
     }
}

//funcion para buscar un nodo por su valor dentro del arbol
int lista::buscar(int v, nodo *arbol){
	//verificamos qu el arbol no este vacio
	if(arbol == NULL){
			return 0;
	}else{ //si no esta vacio
		if(arbol->valor == v){
			cout<<"codigo_nodo: "<<arbol<<" , valor: "<<arbol->valor<<" ,nodo izq: "<<arbol->izquierda<<" ,nodo der"<<arbol->derecha<<endl;
			bandera=1;
			return 0;
		}else{
				buscar(v,arbol->izquierda);
				buscar(v,arbol->derecha);
		}
	
		
	}
}
	
//funcon para mostrar el arbol con recursividad
void lista::mostrararbol(nodo *arbol){
     if(arbol== NULL)
     {
                return ;
     }
     else
     {	
        cout<<"codigo_nodo: "<<arbol<<" , valor: "<<arbol->valor<<" ,nodo izq: "<<arbol->izquierda<<" ,nodo der"<<arbol->derecha<<endl;
		mostrararbol(arbol->izquierda);
		mostrararbol(arbol->derecha);
     }
}

