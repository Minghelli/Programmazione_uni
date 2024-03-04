/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/
typedef struct{
    int punti;
    char nominativo[40];
} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
