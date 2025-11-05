STAR SCHEMA

CREATE TABLE FactSales (
    SalesID INT PRIMARY KEY,
    DateKey INT,
    ProductKey INT,
    CustomerKey INT,
    StoreKey INT
);

CREATE TABLE DimDate (
    DateKey INT PRIMARY KEY,
    FullDate DATE,
    Year INT
);

CREATE TABLE DimProduct (
    ProductKey INT PRIMARY KEY,
    ProductName VARCHAR(100),
    Category VARCHAR(50),
    Brand VARCHAR(50)
);

CREATE TABLE DimCustomer (
    CustomerKey INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Gender CHAR(1),
    Country VARCHAR(50)
);

CREATE TABLE DimStore (
    StoreKey INT PRIMARY KEY,
    StoreName VARCHAR(100),
    StoreType VARCHAR(50),
    Region VARCHAR(50)
);





SNOWFLAKE SCHEMA

-- Fact Table
CREATE TABLE FactSales (
    SalesID INT PRIMARY KEY,
    DateKey INT,
    ProductKey INT,
    CustomerKey INT,
    StoreKey INT,
    FOREIGN KEY (DateKey) REFERENCES DimDate(DateKey),
    FOREIGN KEY (ProductKey) REFERENCES DimProduct(ProductKey),
    FOREIGN KEY (CustomerKey) REFERENCES DimCustomer(CustomerKey),
    FOREIGN KEY (StoreKey) REFERENCES DimStore(StoreKey)
);

-- Dimension Tables

CREATE TABLE DimDate (
    DateKey INT PRIMARY KEY,
    FullDate DATE,
    Year INT
);

CREATE TABLE DimProduct (
    ProductKey INT PRIMARY KEY,
    ProductName VARCHAR(100),
    Category VARCHAR(50),
    Brand VARCHAR(50)
);

CREATE TABLE DimCustomer (
    CustomerKey INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Gender CHAR(1),
    Country VARCHAR(50)
);

CREATE TABLE DimContact (
    CustomerKey INT,
    Number BIGINT,
    PRIMARY KEY (CustomerKey),
    FOREIGN KEY (CustomerKey) REFERENCES DimCustomer(CustomerKey)
);

CREATE TABLE DimStore (
    StoreKey INT PRIMARY KEY,
    StoreName VARCHAR(100),
    StoreType VARCHAR(50),
    Region VARCHAR(50)
);

CREATE TABLE DimSupplier (
    StoreKey INT,
    SupplierType VARCHAR(50),
    PRIMARY KEY (StoreKey),
    FOREIGN KEY (StoreKey) REFERENCES DimStore(StoreKey)
);
