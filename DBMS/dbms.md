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