# DBMS stuff

A database system has two parts
- **Database:** Collection of interrelated data
    - Structured data - tables
    - Unstructured data - photos, videos etc.
- **Databse Management System:** Responsible for storing, managing and querying data
    - RDBMS used for relational databases where data is stored in the form of related tables

## File system vs DBMS
1. Searching easy in DBMS but very difficult in file systems.
2. For searching files we need their attributes like path of its location.
3. No protocols for concurreny, unlike DBMS.
4. Role based security in DBMS, no such thing in file systems.
5. Data redundancy in file systems but constraints prevent it in DBMS.

## Two tier architecture
Consists of two layers
1. **Client Layer:** Application programs
2. **Data Layer:** Database server

<img src="https://prepinsta.com/wp-content/uploads/2021/04/twotier.webp" height=500>

Client server architecture, client directly interacts with the database server which takes the queries of the client, processes and executes them and returns the result to the client.

Easily maintainable as it is simple but not scalable and secure.

## Three tier architecture
Consists of three layers
1. **Client Layer:** Application programs
2. **Business Layer:** Application server
3. **Data Layer:** Database server

<img src="https://prepinsta.com/wp-content/uploads/2021/04/threetier.webp" height=500>

All client requests are processed by the server and after processing are sent to the databse server that then returns the desired data which the server after processing passes onto the client, reducing the processing load on the database server.

Hence it is scalable and secure but since it is complex, it is not easily maintainable.

## Three Schema Architecture

**Schema:** It is the structure or logical representation of a database.

The three schema architecture consists of three levels
1. **View level:** External schema, visible to the user.
2. **Logical level:** Conceptual schema, logical representation of the data stored.
3. **Physical level:** Physical schema, actual physical storage of the data.

<img src="https://www.tutorialspoint.com/assets/questions/media/53823/three_level_schema_architecture.jpg" height=540>

Provides data abstraction and independence as user can't directly access the data stored. User is not aware of how the data is actually stored.

**Logical data independance** between view level and logical level, changes in the conceptual schema do not affect the external schema.

**Physical data independance** between logical level and physical level, changes in the physical schema do not affect the conceptual schema.

## Different keys

**Candidate key** is an attribute or column that uniquely identifies each row. From the collection of candidate keys, we choose the primary key.

**Primary key** is used to uniquely identify each row and only one key is selected as primary key from the set of candidate keys, the remaining keys are called **alternate keys**. Primary keys have unique and not null constraints.

**Foreign key** is an attribute or set of attributes that references the primary key of same table or another table. Foreign key maintains refrential integrity. There can be multiple foreign keys in a table. The table having the foreign key is called referencing table and the table whose primary key is being referenced is called referenced table.


Example of creating a foreign key in a table
```sql
CREATE TABLE course(
    course_id int,
    course_name varchar(20),
    roll_no int references student(roll_no)
);
```

<img src="https://static.javatpoint.com/dbms/images/foreign-key-in-dbms3.png">

When carrying out different actions on referenced table, some problems can arise.
1. **Insert:** No violation will occur.
2. **Delete:** Violation may occur, as data is deleted from referenced table but may still be referenced by the referencing table. Can fix this using `ON DELETE CASCADE`,`ON DELETE SET NULL`, etc.
3. **Update:** Violation may occur due to data inconsistency. Can be fixed using `ON UPDATE CASCADE`,`ON UPDATE SET NULL`, etc.

In case of referencing table
1. **Insert:** Violation may occur if value of foreign key in new row is invalid.
2. **Delete:** No violation will occur.
3. **Update:** Violation may occur if updated foreign key is invalid.

**Super key** is a combination of all possible attributes that can uniquely identify each row, Super key is super set of any primary key, if there are n attributes A1, A2, A3, ... An and candidate key is A1, then possible super keys can be A1, (A1,A2), (A1,A3) .... There will $2^{n-1}$ super keys in this case. Similarly, if there are two candidate keys, there are $2^{n-1} + 2^{n-1} - 2^{n-2}$ 

## Entity - Relationship (ER) Model

ER model is a logical representation of the data in a system that shows the differents entities present, their attributes and their relationships.

**Entity** is any object that has a physical existence. **Relationship** is any association or connection between entities. **Attributes** are the properties representing an entity. 

In ER diagram, entity is denoted by **rectangle**, relationship by **diamond** and attribute by **ellipse**. 

<img src="https://prepinsta.com/wp-content/uploads/2021/04/entityrelationship.webp" height=500>

### Types of Attributes
1. **Single vs Multivalued** <br>
Single valued attributes can contain only a single value, like age, but muiltivalued attributes can have multiple values, like a person can have multiple phone numbers. Multivalued attributes are represented using double ellipse.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept7.png"> </center>

2. **Simple vs Composite** <br>
Composite attributes can be further broken down into multiple attributes, like name can be broken down into first name, last name, etc while simple attributes can't be broken down.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept6.png"></center>

3. **Stored vs Derived** <br>
Stored attributes are directly provided but derived attributes aren't directly provided. Instead, their value is derived from other attributes, like we can get the age of a person from their date of birth. Derived attributes are represented using dotted ellipse.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept8.png"></center>

4. **Key vs Non-key** <br>
Key attributes uniquely identify an entity whereas the value of non-key attributes may or may not be unique. Key attributes are underlined.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept5.png"></center>

5. **Required vs Optional** (not part of ER model) <br>
Required attributes must be provided for every entity whereas optional arguments may or may not be provided.

6. **Complex attributes** <br>
Composite + multivalued hehe

### Type or Degree of Relationships
1. **One to One Relationship (1-1)** <br>
Relationship in which an instance of an entity is related to only a single instance of another entity. Here, primary key of any of the entities can become primary key of the relationship table.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept10.png"></center>

2. **One to Many Relationship (1-M) and Many to One Relationship (M-1)** <br>
Single instance of an entity is related to more than one instance of another entity. In this case, primary key of the entity on the many side acts as the primary key in the realtionship table.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept11.png"></center>
<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept12.png"></center>

3. **Many to Many Relationship (M-N)** <br>
Multiple instances of one entity can be related to multiple instances of another entity. Primary key in the relationship table will be a composite key made using the primary keys of the two entites. Table reduction is not possible.

<center><img src="https://static.javatpoint.com/dbms/images/dbms-er-model-concept13.png"></center>