
STAR SCHEMA:-


CREATE TABLE FactSales (
 SalesID INT PRIMARY KEY,DateKey INT,ProductKey INT, CustomerKey
INT, StoreKey INT
);
CREATE TABLE DimDate (
 DateKey INT PRIMARY KEY, FullDate DATE, Year INT
);
CREATE TABLE DimProduct (
 ProductKey INT PRIMARY KEY, ProductName VARCHAR(100), Category
VARCHAR(50), Brand VARCHAR(50),

);
CREATE TABLE DimCustomer (
 CustomerKey INT PRIMARY KEY, FirstName VARCHAR(50), LastName
VARCHAR(50), Gender CHAR(1), Country VARCHAR(50),

);
CREATE TABLE DimStore (
 StoreKey INT PRIMARY KEY, StoreName VARCHAR(100), StoreType
VARCHAR(50),Region VARCHAR(50)
);


SNOWFLAKE SCHEMA

CREATE TABLE FactSales (
 SalesID INT PRIMARY KEY,DateKey INT,ProductKey INT, CustomerKey INT,
StoreKey INT);
CREATE TABLE DimDate (
 DateKey INT PRIMARY KEY, FullDate DATE, Year INT);
CREATE TABLE DimProduct (
 ProductKey INT PRIMARY KEY, ProductName VARCHAR(100), Category
VARCHAR(50), Brand VARCHAR(50), );
CREATE TABLE DimCustomer (
 CustomerKey INT PRIMARY KEY, FirstName VARCHAR(50), LastName
VARCHAR(50), Gender CHAR(1), Country VARCHAR(50), );

CREATE TABLE DimStore (
 StoreKey INT PRIMARY KEY, StoreName VARCHAR(100), StoreType
VARCHAR(50),Region VARCHAR(50));
create table DimSupplier(
 SupplierKey int Primary key,SupplierType varchar(50));
create table DimContact(

 ContactId int primary key,number int);
