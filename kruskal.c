def kruskal(n, edges):
parent=list(range(n))
def find(x):
while parent[x]!=x: x=parent[x]
return x
def union(a,b): parent[find(a)]=find(b)
edges=sorted(edges,key=lambda e:e[2])
T=[]
for u,v,w in edges:
if find(u)!=find(v):
union(u,v); T.append((u,v,w))
return T
print(kruskal(3, [(0,1,1),(1,2,2),(0,2,3)]))