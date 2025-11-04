Aim:- Implementation of all dimension tables and fact tables based on experiment
1 case study.

Theory:-

Fact tables and dimension tables are key components of star or snowflake schemas.
Fact tables store numeric data like sales or order amounts and include foreign keys
linking to dimension tables. Dimension tables provide context with descriptive details
like product names or customer demographics. The main difference between Fact or
Reality table and the Dimension table is that dimension table contains attributes on
that measures are taken actually table

What is a fact table?
● A fact table is a central table in a dimensional model, often used in data warehousing
and business intelligence. It stores quantitative data (facts) about a business process,
along with foreign keys that link it to dimension tables.

What is a dimension table?
● A dimension table in data warehousing stores descriptive information or attributes
related to the facts stored in a fact table. It provides context and helps analyze the
data in the fact table

Customer Date Store Product Contact Supplier
CustomerKey DateKey StoreKey ProductKey CustomerKey StoreKey
FirstName FullDate StoreName ProductName Number SupplierKey
LastName Year StoreType Category
Gender Region Brand
Country
