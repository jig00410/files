
import pandas as pd
from mlxtend.frequent_patterns import apriori, association_rules
# sample dataset: transections
dataset= [
['milk','bread','eggs'],
['milk','bread'],
['milk','eggs'],
['bread','eggs'],
['milk','bread','eggs']
]
from mlxtend.preprocessing import TransactionEncoder
te = TransactionEncoder()
te_ary = te.fit(dataset).transform(dataset)
df = pd.DataFrame(te_ary, columns=te.columns_)
print("one-hot encoded DataFrame")
print(df)
#step 1: find frequent item with minimum supprt=0.5
frequent_itemsets=apriori(df, min_support=0.5, use_colnames=True)
print("\nFrequent Itemsets:")
print(frequent_itemsets)

Name-Jignesh Bhatia Roll.No-10 Batch-A1
#step2: generate association rules with confidence>=0.7
rules=association_rules(frequent_itemsets, metric="confidence",
min_threshold=0.7)
print("\nAssociation Rules:")
print(rules)













Aim: Implementation of Association Rule Mining algorithm (Apriori)
Theory:
The Apriori algorithm is used for mining frequent itemsets and devising
association rules from a transactional database. The parameters “support” and
“confidence” are used. Support refers to items’ frequency of occurrence;
confidence is a conditional probability.
Items in a transaction form an item set. The algorithm begins by identifying frequent,
individual items (items with a frequency greater than or equal to the given support)
in the database and continues to extend them to larger, frequent itemsets.
Algorithm:
The following are the main steps of the algorithm:
1. Calculate the support of item sets (of size k = 1) in the transactional
database (note that support is the frequency of occurrence of an
itemset). This is called generating the candidate set.
2. Prune the candidate set by eliminating items with a
support less than the given threshold.
3. Join the frequent itemsets to form sets of size k + 1, and repeat the
above sets until no more itemsets can be formed. This will happen
when the set(s) formed have a
support less than the given support.