-- Usar base de datos 
USE tarea_6_sql;
-- Tabla con info de cada curso
CREATE TABLE IF NOT EXISTS Cursos(
CursoID INT PRIMARY KEY,
Sigla VARCHAR(50) NOT NULL UNIQUE ,
Nombre VARCHAR(100)  NOT NULL UNIQUE,
Semestre VARCHAR(10) NOT NULL,
Creditos INT NOT NULL);

-- Tabla con descripcion y dificultad 
CREATE TABLE IF NOT EXISTS Descripciones(
DescripcionID INT PRIMARY KEY,
CursoID INT NOT NULL UNIQUE ,
Descripcion TEXT,
Dificultad VARCHAR(100),
FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID)
);

-- Tabla que resume las relaciones entre los cursos
CREATE TABLE IF NOT EXISTS Requisitos(
RequisitoID INT PRIMARY KEY,
CursoID INT NOT NULL,
RequisitoCursoID INT NOT NULL,
FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID),
FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID)
);

-- Informacion del plan de estudios 

-- Insertar cursos de licenciatura
INSERT INTO Cursos(CursoID,Sigla,Nombre,Semestre,Creditos)
VALUES
('0579','IE-0579','Administración de Sistemas','IX',4),
('0613','IE-0613','Electrónica Industrial','IX',4),
('0599','IE-0599','Anteproyecto de TFG','IX',4),
('0001','Optativa-X1','Optativa I','IX',3),
('0002','Optativa-X2','Optativa II','IX',3),
('0679','IE-0679','Ciencias de datos para la est. y pron. de eventos','X',3),
('0541','IE-0541','Seguridad ocupacional','X',3),
('0003','Optativa-X3','Optativa III','X',3),
('0004','Optativa-X4','Optativa IV','X',3);

-- Insertar cursos de bachillerato requisitos
INSERT INTO Cursos(CursoID,Sigla,Nombre,Semestre,Creditos)
VALUES
('0479','IE-0479','Ingeniería Económica','VIII',3),
('0413','IE-0413','Electrónica II','V',3),
('0315','IE-0315','Máquinas Eléctricas I','VI',3),
('0499','IE-0499','Proyecto Eléctrico','VIII',3),
('0405','IE-0405','Modélos Probabilísticos de Señales y Sistemas','VI',3),
('0501','IE-0501','Responsabilidad en le ejercicio profesional de la ingeniería eléctrica','VI',3);

INSERT INTO Requisitos(RequisitoID,CursoID,RequisitoCursoID)
VALUES
(04790579,0579,0479),
(06130413,0613,0413),
(06130315,0613,0315),
(05990499,0599,0499),
(06790405,0679,0405),
(06790579,0679,0579),
(05410501,0541,0501);

INSERT INTO Descripciones(DescripcionID,CursoID,Descripcion,Dificultad)
VALUES
(1,0579,
'El profesional en ingeniería eléctrica se verá, tan pronto se incorpore al mercado laboral, en actividades técnicas que se relacionarán con diferentes tipos de organizaciones o empresas, leyes, reglamentos, normativas y muchos otros condicionantes, cuyo funcionamiento es una responsabilidad conocer Por ello, en este curso, se considerará la organización o empresa como la unidad de estudio, sobre la cual se desarrollará el análisis de factores internos y externos tales como geopolítica, evolución tecnológica, globalización de mercados, cambios económicos, transformaciones del mercado, papel del estado, y otros, aspectos que gravitan en el adecuado accionar de estos sistemas.',
'Fácil'),
(2,0613,
'El curso permite introducir los principios y fundamentos de la electrónica de potencia.',
'Difícil'),
(3,0599,
'El curso de Anteproyecto de Tesis es un curso orientado a desarrollar en el estudiante las habilidades necesarias para elaborar su propuesta de investigación.',
'Fácil'),
(4,0679,
'Integra la formación profesional del estudiante de Ingeniería Eléctrica mediante la aplicación de conceptos estudiados en cursos anteriores, junto con nuevas herramientas que permitan apoyar de manera sistémica el proceso de análisis de eventos',
'Media'),
(5,0541,
'¿Porqué es importante la Salud y la Seguridad ocupacional en el ambiente laboral?',
'Fácil');

-- Descripciones faltantes Bachillerato
INSERT INTO Descripciones(DescripcionID,CursoID,Descripcion,Dificultad)
VALUES
(6,'0479','El curso esta diseñado para los estudiantes del plan de bachillerato en Ingeniería eléctrica, a
fin de que adquieran habilidades para la toma racional de decisiones en materia de inversión
privada o pública, partiendo de la premisa básica del problema económico: los recursos son
escasos, las necesidades ilimitadas.','Fácil'),
(7,'0413','Este es un curso de electrónica analógica basado en el análisis y diseño de circuitos con
amplificadores operacionales','Difícil'),
(8,'0315','El curso procura familiarizar a los estudiantes con las maquinas eléctricas que los ingenieros
deben utilizar en las distintas aplicaciones en la industria y en los sistemas eléctricos de
potencia','Difícil'),
(9,'0499','El curso de proyecto eléctrico es un curso integrador y abierto en su temática, y de aplicación de estrategias de diseño, investigación y solución a un problema en el campo de la ingeniería eléctrica y ramas afines.','Medio'),
(10,'0405','Este curso constituye una introducción a los conceptos de la probabilidad que son utilizados
en el análisis de señales y diseño de sistemas en diversas áreas de la Ingeniería eléctrica. Está
enfocado a que el estudiante aprenda a usar tales conceptos mediante su uso directo en
ejemplos extraídos de la práctica normal del ingeniero electricista.', 'Fácil'),
(11,'0501','Dotar al estudiante de los conocimientos básicos de la ética y del ordenamiento jurídico
en que se desenvolverá profesionalmente, de manera que su conducta se ajuste en todo
momento a los principios de la Ética Profesional y tenga un cabal conocimiento del grado de
responsabilidad moral y legal de sus actuaciones.','Fácil');
-- Cursos Nuevos 

INSERT INTO cursos(CursoID,Sigla,Nombre,Semestre,Creditos)
VALUES
(0789,'IE-0789','Robotica','X',3),
(0890,'IE-0890','Sistemas Embebidos','IX',3);

INSERT INTO descripciones(DescripcionID,CursoID,Descripcion,Dificultad)
VALUES
(12,0789,'Curso centrado en la creación de robots','Dificil'),
(13,0890,'se centra en el estudio y desarrollo de sistemas informáticos especializados que están integrados 
dentro de otros dispositivos, no son visibles para el usuario y realizan funciones específicas','Media');


-- Insertar Requisitos 
INSERT INTO cursos(CursoID,Sigla,Nombre,Semestre,Creditos)
VALUES
(0523,'IE-0523','Circuitos Digitales II','VI',3),
(0425,'IE-0425','Redes de Computadores','VIII',3);

-- Relacion de Requisito Cursos Inventados
INSERT INTO Requisitos(RequisitoID,CursoID,RequisitoCursoID)
VALUES
(07890523,0789,0523),
(08900425,0890,0425);

-- Consultas

-- Consultar todos los cursos

SELECT cursos.Sigla,cursos.Nombre,cursos.Semestre,cursos.Creditos,descripciones.Descripcion,descripciones.Dificultad
FROM cursos
JOIN descripciones
WHERE cursos.CursoID = descripciones.CursoID;


-- Listar requisitos de Electrónica Industrial
SELECT cursos.Nombre AS RequisitoDeElectrónicaIndustrial , cursos.Sigla 
From cursos
Join requisitos
WHERE requisitos.CursoID = 0613 AND cursos.CursoID = requisitos.RequisitoCursoID;

-- Cursos que no son Optativas
SELECT *
FROM cursos
WHERE Nombre NOT LIKE 'Optativa%';

-- Cursos del semestre X
SELECT *
FROM cursos
WHERE Semestre = 'X';

-- Actualizar cursos optativos
UPDATE cursos
SET Nombre = 'Visión por Computador' , Sigla = 'IE-0437', Creditos = 4
WHERE Nombre = 'Optativa I';

UPDATE cursos
SET Nombre = 'Diseño eléctrico industrial I' , Sigla = 'IE-0471' , Creditos = 4
WHERE Nombre = 'Optativa III';

UPDATE cursos
SET Nombre = 'Estructuras de computadores digitales II' , Sigla = 'IE-0521' , Creditos =4
WHERE Nombre = 'Optativa IV';

-- Actualizar descripciones y dificultad 
UPDATE descripciones
SET Descripcion = 'Curso de electrónica de potencia' , dificultad = 'Fácil'
WHERE CursoID = 0613;

UPDATE descripciones
SET Descripcion = 'Curso de amplificadores' , dificultad = 'Media'
WHERE CursoID = 0413;

UPDATE descripciones
SET Descripcion = 'Como no ser demandado' , dificultad = 'Media'
WHERE CursoID = 0501;

-- Eliminaciones

-- Primero agregar la opcion de borrado en cascada
ALTER TABLE descripciones
DROP FOREIGN KEY descripciones_ibfk_1;

ALTER TABLE descripciones
ADD CONSTRAINT descripciones_ibfk_1
	FOREIGN KEY (CursoID)
    REFERENCES cursos(CursoID)
    ON DELETE CASCADE;

ALTER TABLE requisitos
DROP FOREIGN KEY requisitos_ibfk_1;

ALTER TABLE requisitos
DROP FOREIGN KEY requisitos_ibfk_2;

ALTER TABLE requisitos
ADD CONSTRAINT requisitos_ibfk_1
	FOREIGN KEY (CursoID)
    REFERENCES cursos(CursoID)
    ON DELETE CASCADE;
    
ALTER TABLE requisitos
ADD CONSTRAINT requisitos_ibfk_2
	FOREIGN KEY (RequisitoCursoID)
    REFERENCES cursos(CursoID)
    ON DELETE CASCADE;

-- Eliminar
DELETE FROM cursos
WHERE CursoID IN(0789,0613,0599);

-- Eliminar requsitos 
DELETE FROM requisitos
WHERE CursoID IN(579,890);

