int controller_loadFromText(LinkedList* pArrayListLibros, int (*pFunc) (FILE*, LinkedList*));
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addLibro(LinkedList* pArrayListEmployee);
int controller_editLibro(LinkedList* pArrayListEmployee);
int controller_removeLibro(LinkedList* pArrayListEmployee);
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* listaEditoriales);
int controller_sortLibros(LinkedList* pArrayListLibros, LinkedList* pArrayEditoriales);

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
//int controller_loadFromTextEditorial(char* path , LinkedList* pArrayListEditorial);
int controller_ListEditoriales(LinkedList* pArrayListEditoriales);

int controller_filtrarLibros(LinkedList* listaLibros,LinkedList* listaEditoriales);

int controller_saveAsText(char* path , LinkedList* pArrayListLibro);

