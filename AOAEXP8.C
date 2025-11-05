import matplotlib.pyplot as plt
import pandas as pd
import scipy.cluster.hierarchy as sch
from sklearn import datasets
from sklearn.cluster import AgglomerativeClustering
#load iris datset
iris=datasets.load_iris()
df=pd.DataFrame(iris.data,columns=iris.feature_names)
df['flower_type']=iris.target
#features and label
X=df.iloc[:,:-1].values
y=df.iloc[:,-1].values
#visualise original classes
plt.figure(figsize=(10,7))
plt.scatter(X[y==0,0],X[y==0,1],s=100,c='blue',label='Type 1 (Setosa)')
plt.scatter(X[y==1,0],X[y==1,1],s=100,c='yellow',label='Type 2 (Versicolor)')
plt.scatter(X[y==2,0],X[y==2,1],s=100,c='green',label='Type 3 (Virginica)')
plt.legend()
plt.show()
#plot dendogram
plt.figure(figsize=(20,7))
plt.title('Dendrogram')
dendrogram=sch.dendrogram(sch.linkage(X,method='ward'))
plt.xlabel('SAMPLE INDEX')
plt.ylabel('Eucledian distance')
plt.show()
# agglome
hc= AgglomerativeClustering(n_clusters=3,metric='euclidean',linkage='ward')
labels=hc.fit_predict(X)
print("cluster labels:\n",labels)
#vis
plt.figure(figsize=(10,7))
plt.scatter(X[labels==0,0],X[labels==0,1],s=100,c='blue',label='cluster 1')
plt.scatter(X[labels==1,0],X[labels==1,1],s=100,c='yellow',label='cluster 2')


plt.scatter(X[labels==2,0],X[labels==2,1],s=100,c='green',label='cluster 3')
plt.xlabel('sepal length(cm)')
plt.ylabel('sepal width(cm)')
plt.title('Agglomerative Clustering')
plt.legend()
plt.show()