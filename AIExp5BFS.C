from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)
    
    while queue:
        node = queue.popleft()
        print(node, end=" ")
        
        # Har neighbor ko check karein jo abhi tak visit nahi hua
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# ---------------- USER INPUT ----------------
graph = {}

# Vertices input lein
num_vertices = int(input("Enter number of vertices: "))
for i in range(num_vertices):
    node = input(f"Enter vertex {i+1} name: ")
    graph[node] = []

# Edges input lein
num_edges = int(input("Enter number of edges: "))
for i in range(num_edges):
    u, v_edge = input("Enter edge (u v): ").split()
    # Undirected graph ke liye dono taraf add karein
    if u in graph and v_edge in graph:
        graph[u].append(v_edge)
        graph[v_edge].append(u)
    else:
        print(f"Error: One of the vertices {u} or {v_edge} not found in graph.")

start_node = input("Enter starting vertex for BFS: ")

print("\nBFS Traversal:")
bfs(graph, start_node)

print("\n\nRUN IN COLAB BY JIGNESH")