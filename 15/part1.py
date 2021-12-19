import numpy as np
import pyastar2d

with open('input', 'r') as f:
  lines = f.readlines()

w = []
for line in lines:
  l = []
  for c in line.strip():
    l.append(float(c))
  w.append(l)

# The minimum cost must be 1 for the heuristic to be valid.
# The weights array must have np.float32 dtype to be compatible with the C++ code.
weights = np.array(w, dtype=np.float32)
# The start and goal coordinates are in matrix coordinates (i, j).
path = pyastar2d.astar_path(weights, (0, 0), (len(w)-1, len(w[0])-1), allow_diagonal=False)
result = 0
for p in path:
  result += w[p[0]][p[1]]
result -= w[0][0]
print(result)