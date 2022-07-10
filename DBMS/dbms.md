# DBMS stuff

A database system has two parts
- **Database:** Collection of interrelated data
    - Structured data - tables
    - Unstructured data - photos, videos etc.
- **Databse Management System:** Responsible for storing, managing and querying data
    - RDBMS used for relational databses where data is stored in the form of related tables

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

Client server architecture, client directly interacts with the database server which takes the wueries of the client, processes and executes them and returns the result to the client.

Easily maintainable as it is simple but not scalable and secure.

## Three tier architecture
Consists of three layers
1. **Client Layer:** Application programs
2. **Business Layer:** Application server
3. **Data Layer:** Database server

<img src="https://prepinsta.com/wp-content/uploads/2021/04/threetier.webp" height=500>

All client requests are processed by the server and after processing are sent to the databse server that then returns the desired data which the server after processing passes onto the client, reducing the processing load on the databse server.

Hence it is scalable and secure but since it is complex, it is not easily maintainable.