import math

def minimax(depth, nodeIndex, isMax, values, maxDepth):
    # Base case: Jab hum tree ki leaf nodes (gehraai) par pahunch jayein
    if depth == maxDepth:
        return values[nodeIndex]

    if isMax:
        # Maximizer ka turn: Max value chunein
        left = minimax(depth + 1, nodeIndex * 2, False, values, maxDepth)
        right = minimax(depth + 1, nodeIndex * 2 + 1, False, values, maxDepth)
        return max(left, right)
    else:
        # Minimizer ka turn: Min value chunein
        left = minimax(depth + 1, nodeIndex * 2, True, values, maxDepth)
        right = minimax(depth + 1, nodeIndex * 2 + 1, True, values, maxDepth)
        return min(left, right)

# -------- USER INPUT --------
try:
    n = int(input("Enter number of leaf nodes (must be power of 2, e.g., 4, 8): "))
    values = []
    
    print(f"Enter {n} values of leaf nodes:")
    for i in range(n):
        val = int(input(f"Value {i+1}: "))
        values.append(val)

    # Depth calculate karein (log base 2)
    maxDepth = int(math.log2(n))

    # Algorithm shuru karein (starting with Maximizer at root)
    result = minimax(0, 0, True, values, maxDepth)
    print("\nOptimal value (Minimax):", result)

except ValueError:
    print("Invalid input! Please enter numbers only and ensure leaf nodes are a power of 2.")

print("\nRUN IN COLAB BY JIGNESH")