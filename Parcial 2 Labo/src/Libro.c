#include "Libro.h"


eLibro* Libro_newParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial)
{
	eLibro* pLibro;

	pLibro = Libro_new();

	if (pLibro != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial)
		{
			if (
				Libro_setId(pLibro,atoi(id))!= 0 ||
		        Libro_setTitulo(pLibro,titulo) != 0 ||
				Libro_setTAutor(pLibro,autor) != 0 ||
		        Libro_setPrecio(pLibro,atof(precio))!=0||
				Libro_setIdEditorial(pLibro,atoi(idEditorial))!= 0 )
			{
				Libro_delete(pLibro);

			}
		}
	return pLibro;
}



int Libro_setId(eLibro* this,int id)
{
	int retorno;
	retorno = -1;

	if(this !=NULL && id > 0)
	{
		this->id =id;
		retorno = 0;
	}


	return retorno;
}
int Libro_getId(eLibro* this,int* id)
{
	int retorno;
	retorno = -1;
	if(this!=NULL && id !=NULL)
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}

int Libro_setIdEditorial(eLibro* this,int idEditorial)
{
	int retorno;
	retorno = -1;

	if(this !=NULL && idEditorial > 0)
	{
		this->idEditorial =idEditorial;
		retorno = 0;
	}


	return retorno;
}
int Libro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno;
	retorno = -1;
	if(this!=NULL && idEditorial !=NULL)
	{
		*idEditorial = this->idEditorial;
		retorno=0;
	}

	return retorno;
}

int Libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno;
	retorno =-1;

	    if(this!=NULL && titulo!=NULL)
	    {
	        strcpy(this->titulo,titulo);
	        retorno = 0;;
	    }

	    return retorno;
}
int Libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno;
	retorno =-1;
	if(this!=NULL && titulo!=NULL)
	    {
	        strcpy(titulo,this->titulo);
	        retorno = 0;
	    }

	return retorno;
}
int Libro_setTAutor(eLibro* this,char* autor)
{
	int retorno;
	retorno =-1;

	    if(this!=NULL && autor!=NULL)
	    {
	        strcpy(this->autor,autor);
	        retorno = 0;;
	    }

	    return retorno;
}
int Libro_getAutor(eLibro* this,char* autor)
{
	int retorno;
	retorno =-1;
	if(this!=NULL && autor!=NULL)
	    {
	        strcpy(autor,this->autor);
	        retorno = 0;
	    }

	return retorno;
}

int Libro_setPrecio(eLibro* this,float precio)
{
	int retorno;
	retorno =-1;

	if(this!=NULL)
	{
	     this->precio = precio;
	     retorno = 0;
	}

	return retorno;
}
int Libro_getPrecio(eLibro* this,float* precio)
{
	int retorno;
	retorno =-1;

	if (this!=NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}


	return retorno;
}

/*int Libro_setSueldo(eLibro* this,int sueldo)
{
	int retorno;
	retorno =-1;
	if (this!=NULL)
	{
		this->precio = sueldo;
		retorno = 0;
	}
	return retorno;
}
int Libro_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno =-1;
	if (this!=NULL)
	{
		*sueldo= this->precio;
		retorno = 0;
	}
	return retorno;
}*/

eLibro* Libro_new()
{
	eLibro* pLibro;

	pLibro = (eLibro*) calloc(sizeof(eLibro),1);

	return pLibro;
}

void Libro_delete(eLibro* this)
{
	if(this!=NULL)
	    {
	        free(this);
	        this=NULL;
	    }
}

void imprimirUnLibro(eLibro* this, LinkedList* listaEditoriales)
{
	int   id;
	char  titulo[30];
	char  autor[30];
	float precio;
	int   idEditorial;
	int   len;
	char  nombreAux[30];
	int idEditorialAux;


	eEditorial* pEditorial;

	if (this != NULL)
	{
	   if(Libro_getId(this, &id)!=-1
		  &&Libro_getTitulo(this, titulo) !=-1
		  &&Libro_getAutor(this, autor) !=-1
		  &&Libro_getPrecio(this, &precio) !=-1
		  &&Libro_getIdEditorial(this, &idEditorial)!=-1)
	   {
		 len = ll_len(listaEditoriales);

	   	 for (int i = 0; i < len; ++i)
	   	 {
	   		 pEditorial =(eEditorial*)ll_get(listaEditoriales,i);
	   		 Editorial_getId(pEditorial, &idEditorialAux);

	   		 if(idEditorial == idEditorialAux)
	   		 {

	   			 Editorial_getNombre(pEditorial, nombreAux);

	   		 }
		 }
	   	printf("%d\t%15s\t\t%15st\t%.2f\t\t%s\n",id,titulo,autor,precio,nombreAux);
	   }
	}
}




//--------------------------------------------------------------------------
/*eLibro* CrearNuevoLibro(int* idAsignar)
{
	eLibro* pLibro;
	char id[128];
	char titulo[128];
    char autor[128];
    char precio[128];
    char idEditorial[128];
    int nuevaId;
    int auxId;
	pLibro = NULL;

	PedirCadena(titulo, "Ingrese el Titulo del libro","Error");
	PedirCadenaB(autor, "Ingrese el autor del libro");
	PedirCadenaB(precio, "Ingrese el precio del libro");
	//PedirUnEnteroRango("Ingrese la id de la editorial", 0, 500);
	PedirCadenaB(idEditorial, "Ingrese la id de la editorial");
	UltimoId("ArchivoId.txt",nuevaId);
	auxId = atoi(nuevaId)+1;

	itoa(auxId,nuevaId,10);

	printf("%d",auxId);

	pLibro = Libro_newParametros(nuevaId,titulo,autor,precio,idEditorial);
	if(pLibro != NULL)
	{
		*idAsignar = auxId;
	}

	return pLibro;
}

*/

int UltimoId(char* PATH, char* cadena)
{
	int retorno;
	retorno =-1;
	FILE* pFile;

	if(PATH != NULL)
	{
		pFile = fopen(PATH,"r");
		fgets(cadena,10,pFile);
		fclose(pFile);
		retorno = 0;
	}


	return retorno;
}
//-----------------------------------------------------------------------------------------------------
int libro_CompararPorAutor(void* valor1, void* valor2) // respeta el prototipo que pide el sort
{
	int rtn;

	eLibro*e1;
	eLibro*e2;

	e1 = (eLibro*) valor1; //castea
	e2 = (eLibro*) valor2;

	rtn = strcmp(e1->autor, e2->autor); //comparo 2 cadenas a-z. el orden lo determina el sort.

	return rtn;
}
int empleado_CompararPorId(void* valor1, void* valor2)
{
	int retorno = 0;
	eLibro*e1;
	eLibro*e2;

	e1 = (eLibro*) valor1; //castea
	e2 = (eLibro*) valor2;

	if (e1->id > e2->id) // ordena numericamente.
	{
		retorno = 1;
	}
	else
	{
		if (e1->id < e2->id)
		{
			retorno = -1;
		}

	}
	return retorno;
}
int empleado_CompararPorSueldo(void* valor1, void* valor2)
{
	int retorno = 0;
	eLibro*e1;
	eLibro*e2;

	e1 = (eLibro*) valor1; //castea
	e2 = (eLibro*) valor2;

	if (e1->precio > e2->precio) // ordena numericamente.
	{
		retorno = 1;
	}
	else
	{
		if (e1->precio < e2->precio)
		{
			retorno = -1;
		}

	}
	return retorno;
}
//--------------------------------------------------------------------------
int filtrarMinotauro(void*libro)
{
	int retorno = 0;

	eLibro* pLibro;

	if(libro!=NULL)
	{
		pLibro = (eLibro*)libro;

		if(pLibro->idEditorial == 4)
		{
			//printf("%d \n",pLibro->idEditorial);
			retorno = 1;
		}
	}

	return retorno;
}

