# README TAREA #6

## Parte teórica


### 1. ¿Qué es una base de datos relacional y cuáles son sus características fundamentales?

Una base de datos relacional emplea filas y columnas para organizar los datos, los cuales están relacionados entre sí. Una fila se considera un registro y una columna un atributo. Para organizar los datos se emplean múltiples tablas unidas por claves foráneas que identifican las relaciones entre ellas. Algunas de sus características principales son:

- **Tabla**: Es la estructura de almacenamiento.
- **Columna**: Atributo o característica de los datos.
- **Fila**: Un registro o muestra en la tabla.
- **Clave Primaria**: Un campo cuyo propósito es identificar cada fila de la tabla.
- **Clave Foránea**: Establece la relación entre dos tablas.
- **Vista**: Es una tabla virtual que es el producto de la consulta de una o más tablas.
- **Índice**: Forma de organizar los datos que mejora la eficiencia de las operaciones.

Fuente: [IBM](https://www.ibm.com/topics/relational-databases)

### 2. ¿Cuál es la diferencia entre una clave primaria y una clave candidata en una base de datos relacional?

Una clave candidata hace referencia a los atributos que podrían identificar de manera única una tabla. Puede haber más de una clave candidata y pueden contener valores NULL. En contraste, una clave primaria es única en una tabla y no puede contener valores NULL. Básicamente, una llave primaria es una llave candidata, pero una llave candidata puede o no ser una llave primaria.

Fuente: [GeeksforGeeks](https://www.geeksforgeeks.org/difference-between-primary-and-candidate-key/)

### 3. ¿Qué son las claves foráneas y cómo se utilizan para mantener la integridad referencial en una base de datos?

La integridad referencial alude a las relaciones entre tablas. Cada tabla en la base de datos tiene una llave primaria que puede aparecer en otras tablas como clave foránea. El uso de llaves foráneas permite unir tablas y formar una jerarquía de dependencias entre ellas. Por ejemplo, si se elimina una fila en una tabla que contiene una llave primaria, se destruye la unión con cualquier fila de otra tabla que la contenía como llave foránea. La integridad referencial significa que existe una dependencia lógica entre una llave foránea y una llave primaria. El uso de llaves foráneas protege la integridad de los datos, por ejemplo, con el comando `ON DELETE CASCADE` que permite eliminar en cadena desde la tabla padre hasta las hijas.

Fuente: [IBM](https://www.ibm.com/docs/en/informix-servers/14.10?topic=integrity-referential)

### 4. ¿Qué es una transacción en el contexto de bases de datos y cuáles son las propiedades ACID que debe cumplir?

Una transacción en una base de datos es una secuencia de operaciones que se realizan como una única secuencia lógica. Un ejemplo clásico es la transferencia de dinero. Las propiedades ACID que debe cumplir una transacción son:

- **Atomicidad**: Todo o nada. Si una transacción falla, la base de datos retorna a su estado original.
- **Consistencia**: Los datos se mantienen en un estado consistente de inicio a fin.
- **Aislamiento (Isolation)**: Las transacciones concurrentes deben ser independientes una de la otra.
- **Durabilidad**: Los cambios realizados por una transacción exitosa perduran y no pueden ser revertidos, incluso en caso de fallos del sistema.

Fuentes: [IBM](https://www.ibm.com/topics/relational-databases), [Fauna](https://fauna.com/blog/database-transaction)

### 5. ¿Qué son las vistas (views) en SQL y cuáles son los beneficios y limitaciones de su uso?

Una vista se asemeja a una tabla ya que está conformada por filas y columnas, pero sus datos no son almacenados en el disco. Se crean a partir de consultas a otras tablas. Algunos de sus beneficios son:

- **Esconde complejidad**: Las consultas complejas pueden ser divididas entre múltiples vistas, facilitando el manejo y mantenimiento.
- **Protege datos**: Delimita la información a la que tienen acceso ciertos usuarios.
- **Manejo de cambios en esquemas**: Facilita la gestión de cambios en las tablas originales.

Limitaciones:

- No se pueden pasar parámetros a una vista.
- No se puede usar la cláusula ORDER BY en vistas sin especificar FOR XML o TOP.
- No se pueden crear en tablas temporales.
- No se pueden usar reglas y valores predeterminados en las vistas.

Fuentes: [Medium](https://medium.com/@the_infinity/views-in-relational-databases-2958ae4f734f), [MSSQLTips](https://www.mssqltips.com/sqlservertip/5147/limitations-when-working-with-sql-server-views/)

### 6. ¿Qué es la normalización en bases de datos y cuáles son las diferentes formas normales (normal forms)?

La normalización es un proceso para remover las redundancias en las relaciones de una base de datos. Las diferentes formas normales son:

1. **Primera forma normal (1NF)**: Cada celda de la tabla debe contener un único valor y cada columna un nombre único.
2. **Segunda forma normal (2NF)**: Cada atributo que no sea llave debe ser dependiente de la llave primaria.
3. **Tercera forma normal (3NF)**: Todos los atributos que no sean llaves deben ser independientes entre ellos.
4. **Forma normal de Boyce-Codd (BCNF)**: Cada determinante en la tabla debe ser una llave candidata.
5. **Cuarta forma normal (4NF)**: La tabla no debe contener dependencias multivalor.
6. **Quinta forma normal (5NF)**: Implica descomponer una tabla en tablas más pequeñas para remover las redundancias.

Fuente: [GeeksforGeeks](https://www.geeksforgeeks.org/normal-forms-in-dbms/)

### 7. ¿Cómo funcionan los índices en SQL y cuál es su impacto en el rendimiento de las consultas?

Los índices son tablas de búsqueda especializadas que aumentan la rapidez de la ejecución de las consultas al crear punteros a los datos. Aunque mejoran el rendimiento de las consultas, los índices ocupan más espacio y pueden ralentizar operaciones como `DELETE`, `INSERT` y `UPDATE`, que implican modificar los índices.

Fuente: [Simplilearn](https://www.simplilearn.com/tutorials/sql-tutorial/index-in-sql)

### 8. ¿Qué es SQL Injection y cuáles son las mejores prácticas para prevenir este tipo de ataque?

SQL Injection es una técnica que permite a un atacante interferir con las consultas que una aplicación o sitio web hace a su base de datos. Para prevenir este tipo de ataque:

- Utilizar consultas parametrizadas en vez de concatenación de strings.
- Mantener los privilegios de acceso restringidos.
- Validar los inputs del usuario.

Fuente: [Berkeley Security](https://security.berkeley.edu/education-awareness/how-protect-against-sql-injection-attacks#:~:text=Developers%20can%20prevent%20SQL%20Injection,NET%2C%20PHP%2C%20and%20more)

### 9. ¿Qué son los procedimientos almacenados (stored procedures) en SQL y cómo pueden mejorar la eficiencia y seguridad de las operaciones de base de datos?

Un procedimiento almacenado es un fragmento de código SQL guardado para ser reutilizado en varias ocasiones. Mejora la eficiencia y seguridad de las operaciones de base de datos:

- **Rendimiento**: Procesa datos en el servidor, reduciendo el tráfico de datos.
- **Reusabilidad**: Un procedimiento almacenado solo debe ser compilado una vez.
- **Seguridad**: Restringe el acceso de los usuarios a los datos, protegiendo aspectos del esquema de la base de datos.

Fuente: [Site24x7](https://www.site24x7.com/learn/sql-stored-procedure.html#:~:text=A%20stored%20procedure%20is%20a,and%20return%20multiple%20output%20values)

### 10. ¿Cómo se implementan las relaciones uno a uno, uno a muchos y muchos a muchos en una base de datos relacional y qué consideraciones se deben tener en cuenta en cada caso?

- **Uno a Uno**: Cada fila en la tabla A se asocia con una única fila en la tabla B y viceversa. Se realiza incluyendo una llave foránea en una tabla que referencia la llave primaria en otra.
- **Uno a Muchos**: Cada fila de la tabla A puede relacionarse con múltiples filas de B, pero cada fila de B solo puede asociarse con una fila de A. Se incluye una clave foránea en el lado de muchos en la tabla B que referencia una llave primaria en la tabla A.
- **Muchos a Muchos**: Cada fila de la tabla A se asocia con muchas filas de B y viceversa. Se crea una tabla intermedia con llaves foráneas que referencian a ambas tablas.

Fuente: [GeeksforGeeks](https://www.geeksforgeeks.org/relationships-in-sql-one-to-one-one-to-many-many-to-many/)
## Documentación de la tarea

### **Creación de la base de datos y tablas**
En la siguiente imagen se detallan los comandos utilizados para crear las tablas de la base de datos. Se específican las claves primarias de cada tabla, las candidatas (unicas en una tabla) y las relaciones entre ellas por medio de claves foráneas.

Para la tabla de cursos:
```sql
-- Tabla con info de cada curso
CREATE TABLE IF NOT EXISTS Cursos(
CursoID INT PRIMARY KEY,
Sigla VARCHAR(50) NOT NULL UNIQUE ,
Nombre VARCHAR(100)  NOT NULL UNIQUE,
Semestre VARCHAR(10) NOT NULL,
Creditos INT NOT NULL);
```

Para la tabla de descripciones:
```sql
-- Tabla con descripcion y dificultad 
CREATE TABLE IF NOT EXISTS Descripciones(
DescripcionID INT PRIMARY KEY,
CursoID INT NOT NULL UNIQUE ,
Descripcion TEXT,
Dificultad VARCHAR(100),
FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID)
);
```

Para la tabla de requisitos:
```sql
-- Tabla que resume las relaciones entre los cursos
CREATE TABLE IF NOT EXISTS Requisitos(
RequisitoID INT PRIMARY KEY,
CursoID INT NOT NULL,
RequisitoCursoID INT NOT NULL,
FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID),
FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID)
);
```
![Crear](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/CrearTablas.png)


![Im](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaCursos.png)

![TablaVaciaRequi](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaRequi.png)

![https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaDescrip.png](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaDescrip.png)

### Inserción de datos



Luego, se muestran los comandos para llenar las tablas con la información de los cursos.Notar que se deben agregar los cursos propios a la licenciatura y los que son requesitos de estos para que la clave ya que requisitoID como es una clave foranea debe corresponder con lo contenido en la columna de CursoID.

```sql

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
```

Descripciones de cursos requesito en bachillerato:

```sql

-- Descripciones faltantes 
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
```

- **Antes**

    ![Im](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaCursos.png)

    ![TablaVaciaRequi](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaRequi.png)

    ![https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaDescrip.png](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaVaciaDescrip.png)

- **Despues**

1. Tabla de cursos


    ![https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaLLenaICursosMuestra.png](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaLLenaICursosMuestra.png)

2. Tabla requisitos

    ![TablaRequisitos](https://github.com/Msolis314/Clases/blob/main/Imagenes/TablaLLenaIRequisitosMuestra.png)

3. Tabla descripciones

    ![Tablla decripciones](https://github.com/Msolis314/Clases/blob/main/Imagenes/Despues_Agregar_Descrips.png)


Para insertar cursos inventados se ejecuto:
```sql

-- Cursos Nuevos 

INSERT INTO cursos(CursoID,Sigla,Nombre,Semestre,Creditos)
VALUES
(0789,'IE-0789','Robotica','X',3),
(0890,'IE-0890','Sistemas Embebidos','IX',3);

INSERT INTO descripciones(DescripcionID,CursoID,Descripcion,Dificultad)
VALUES
(7,0789,'Curso centrado en la creación de robots','Dificil'),
(8,0890,'se centra en el estudio y desarrollo de sistemas informáticos especializados que están integrados 
dentro de otros dispositivos, no son visibles para el usuario y realizan funciones específicas','Media');
```

- **Antes**:
 1. Tabla cursos

 
    ![https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaLLenaICursosMuestra.png](https://github.com/Msolis314/ie0217/blob/main/Tareas/Tarea6/Imagenes/TablaLLenaICursosMuestra.png)

2. Tabla descripciones

    ![Tablla decripciones](https://github.com/Msolis314/Clases/blob/main/Imagenes/Despues_Agregar_Descrips.png)

- **Despúes**

1. Cursos 

    ![https://github.com/Msolis314/Clases/blob/main/Imagenes/InsertarCursosCustomMuestra.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/InsertarCursosCustomMuestra.png)


2. Descripciones
    ![https://github.com/Msolis314/Clases/blob/main/Imagenes/Despues_Agregar_Descrips_After.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Despues_Agregar_Descrips_After.png)

Insertar cursos y relación de requesitos

```sql
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
```

- **Antes**
 1. Cursos

    ![https://github.com/Msolis314/Clases/blob/main/Imagenes/InsertarCursosCustomMuestra.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/InsertarCursosCustomMuestra.png)

 2. Requisitos

    ![TablaRequisitos](https://github.com/Msolis314/Clases/blob/main/Imagenes/TablaLLenaIRequisitosMuestra.png)

 - **Despues**

1. Cursos

    ![https://github.com/Msolis314/Clases/blob/main/Imagenes/Cursos_Despues_Requisitos.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Cursos_Despues_Requisitos.png)

2. Requesitos

    ![https://github.com/Msolis314/Clases/blob/main/Imagenes/Nuevos_Requisitos.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Nuevos_Requisitos.png)

### Consultas

Para consultar todos los cursos con su sigla,nombre,semestre, créditos,descripción y dificultad se utilizó lo siguiente:
```sql

-- Consultar todos los cursos

SELECT cursos.Sigla,cursos.Nombre,cursos.Semestre,cursos.Creditos,descripciones.Descripcion,descripciones.Dificultad
FROM cursos
JOIN descripciones
WHERE cursos.CursoID = descripciones.CursoID;

```

Se obtuvo :

![https://github.com/Msolis314/Clases/blob/main/Imagenes/ConsultaI.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/ConsultaI.png)


Para consultar todos los requisitos de un curso en particular (en este caso Electrónica Industrial) se utilizó:
```sql

-- Listar requisitos de Electrónica Industrial
SELECT cursos.Nombre AS RequisitoDeElectrónicaIndustrial , cursos.Sigla 
From cursos
Join requisitos
WHERE requisitos.CursoID = 0613 AND cursos.CursoID = requisitos.RequisitoCursoID;
```

Se obtuvo:

![https://github.com/Msolis314/Clases/blob/main/Imagenes/Resultado_Consulta_Requisito.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Resultado_Consulta_Requisito.png)

Luego, la consulta de los cursos no optativos fue hecha de la siguiente manera:

```sql
-- Cursos que no son Optativas
SELECT *
FROM cursos
WHERE Nombre NOT LIKE 'Optativa%';
```

Se obtuvo:

![https://github.com/Msolis314/Clases/blob/main/Imagenes/Resultado_Not_Optativas.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Resultado_Not_Optativas.png)

Los cursos del semestre X se obtuvierón:

```sql
-- Cursos del semestre X
SELECT *
FROM cursos
WHERE Semestre = 'X';
```

Con el siguiente resultado:

![https://github.com/Msolis314/Clases/blob/main/Imagenes/SemestreX_Muestra.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/SemestreX_Muestra.png)

### Actualizaciones

Para actualizar el nombre y créditos de 3 cursos optativos:

```sql
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
```

- **Antes**

![https://github.com/Msolis314/Clases/blob/main/Imagenes/Cursos_Despues_Requisitos.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Cursos_Despues_Requisitos.png)

- **Despues**

![https://github.com/Msolis314/Clases/blob/main/Imagenes/After_Update.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/After_Update.png)


Actualizar la descripción y dificultad de los cursos:
1. Electrónica Industrial (Código 0613)
2. Electrónica II (Código 0413)
3. Responsabilidad en le ejercicio profesional de la ingeniería eléctrica (Código 0501)

Se consigue:
```sql
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
```

- **Antes** 

![https://github.com/Msolis314/Clases/blob/main/Imagenes/Despues_Agregar_Descrips_After.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Despues_Agregar_Descrips_After.png)

- **Despues**

![https://github.com/Msolis314/Clases/blob/main/Imagenes/After_DEscr.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/After_DEscr.png)


### Eliminaciones
Eliminar los siguientes 3 cursos:
1. Robótica (Inventado)
2. Electrónica Industrial (0613)
3. Anteproyecto de TFG (0599)

Primero, se modificarón las tablas para que las llaves foráneas tuvieran el _Constraint_ de borrado en cascada y se eliminaran cuando se borra la fila a la que referencian.

```sql
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

```

Luego para eliminar los cursos:
```sql
DELETE FROM cursos
WHERE CursoID IN(0789,0613,0599);
```

- **Antes**

1. Descripciones

![https://github.com/Msolis314/Clases/blob/main/Imagenes/After_DEscr.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/After_DEscr.png)

2. Cursos

![https://github.com/Msolis314/Clases/blob/main/Imagenes/After_Update.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/After_Update.png)

- **Despues**

1. Descripciones

![https://github.com/Msolis314/Clases/blob/main/Imagenes/Descrip_After_delete.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Descrip_After_delete.png)

2. Cursos

![https://github.com/Msolis314/Clases/blob/main/Imagenes/After_Update.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/After_Update.png)

Para eliminar los requesitos:

```sql
-- Eliminar requsitos 
DELETE FROM requisitos
WHERE CursoID IN(579,890);
```

- **Antes**

![https://github.com/Msolis314/Clases/blob/main/Imagenes/Nuevos_Requisitos.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/Nuevos_Requisitos.png)

- **Despues**

    ![https://github.com/Msolis314/Clases/blob/main/Imagenes/requisitos_after_delete.png](https://github.com/Msolis314/Clases/blob/main/Imagenes/requisitos_after_delete.png)