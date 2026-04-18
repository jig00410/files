def dfs(graph, node, visited):
    # Current node ko visited mark karein aur print karein
    visited.add(node)
    print(node, end=" ")
    
    # Har neighbor ke liye recursively call karein jo abhi tak visit nahi hua
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# ---------------- USER INPUT ----------------
graph = {}

# Vertices input lein
num_vertices = int(input("Enter number of vertices: "))
for i in range(num_vertices):
    v_name = input(f"Enter vertex {i+1} name: ")
    graph[v_name] = []

# Edges input lein
num_edges = int(input("Enter number of edges: "))
for i in range(num_edges):
    # Edge input ko split karke u aur v mein store karein
    try:
        u, v_edge = input("Enter edge (u v): ").split()
        if u in graph and v_edge in graph:
            graph[u].append(v_edge)
            graph[v_edge].append(u)
        else:
            print(f"Error: Vertex {u} or {v_edge} not defined.")
    except ValueError:
        print("Error: Please enter exactly two vertices separated by a space (e.g., A B).")

start_node = input("Enter starting vertex for DFS: ")

visited_nodes = set()
print("\nDFS Traversal:")
dfs(graph, start_node, visited_nodes)

print("\n\nRUN IN COLAB BY JIGNESH")