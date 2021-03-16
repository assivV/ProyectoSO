DROP DATABASE IF EXISTS datos_juego;
CREATE DATABASE datos_juego;
USE datos_juego;


CREATE TABLE PARTIDA (
ID INT NOT NULL,
FECHA VARCHAR(50),
HORA INT,
DURACION INT,
GANADOR VARCHAR(50),
PRIMARY KEY(ID)
)ENGINE=InnoDB;

CREATE TABLE JUGADOR (
ID INT NOT NULL,
NOMBRE VARCHAR(50),
CONTRASENA VARCHAR(50),
PAIS VARCHAR(50),
PRIMARY KEY(ID)
)ENGINE=InnoDB;

CREATE TABLE DATOS (
ID_P INT NOT NULL,
ID_J INT NOT NULL,
PUNTOS INT,
FOREIGN KEY (ID_P) REFERENCES PARTIDA(ID),
FOREIGN KEY (ID_J) REFERENCES JUGADOR(ID)
)ENGINE=InnoDB;


INSERT INTO PARTIDA VALUES (1,'13/3/21',22,10,'SERGIO');
INSERT INTO PARTIDA VALUES (2,'13/3/21',23,13,'NICOLAI');
INSERT INTO PARTIDA VALUES (3,'13/3/21',2,12,'CARLES');
INSERT INTO PARTIDA VALUES (4,'14/3/21',9,2,'SERGIO');
INSERT INTO PARTIDA VALUES (5,'14/3/21',8,4,'SERGIO');

INSERT INTO JUGADOR VALUES (1,'SERGIO','C1','ESPANA');
INSERT INTO JUGADOR VALUES (2,'CARLES','C2','ESPANA');
INSERT INTO JUGADOR VALUES (3,'NICOLAI','C3','RUSIA');

INSERT INTO DATOS VALUES (1,1,150);
INSERT INTO DATOS VALUES (2,1,20);
INSERT INTO DATOS VALUES (3,2,300);
INSERT INTO DATOS VALUES (2,3,150);
INSERT INTO DATOS VALUES (1,2,5);
INSERT INTO DATOS VALUES (4,1,400);
INSERT INTO DATOS VALUES (5,1,750);
INSERT INTO DATOS VALUES (4,2,100);
INSERT INTO DATOS VALUES (5,3,150);

