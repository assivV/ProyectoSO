#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>

//Programa que consulta la base de datos y calcula el tiempo total jugado de un jugador pasado como parametro.
int main(int argc, char *argv[]) {
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexin
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "datos_juego",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	char nombre[20];
	printf ("Dame el nombre del jugador: \n"); 
	scanf ("%s", nombre);
	char consulta [200];
	strcpy (consulta,"SELECT PARTIDA.DURACION FROM (JUGADOR,PARTIDA,DATOS) WHERE JUGADOR.NOMBRE ='");
	strcat (consulta, nombre);
	strcat (consulta,"'AND JUGADOR.ID = DATOS.ID_J AND DATOS.ID_P = PARTIDA.ID");
	
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	int contador;
	int fila;
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	//contador principal
	else
		while (row !=NULL) {
			//printf ("%s\n", row[0]);
			fila= atoi(row[0]);
			contador = contador+fila;

			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
	}
		printf ("El jugador: %s ha jugado durante: %i minutos",nombre, contador);
		mysql_close (conn);
		exit(0);
}


