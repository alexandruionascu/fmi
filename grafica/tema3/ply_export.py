from math import *
import numpy as np

t_min = -1
t_max = 1
s_min = 0
s_max = 2 * pi

polygons = 100
verticies = [
        (t * cos(s), t * sin(s), s) 
            for s in np.linspace(s_min, s_max, polygons)
            for t in np.linspace(t_min, t_max, polygons)
    ]
print("ply")
print("format ascii 1.0")
print("element vertex {0}".format(len(verticies)))
print("property float32 x")
print("property float32 y")
print("property float32 z")
print("element face {0}".format(len(verticies) - 2))
print("property list uint8 int32 vertex_index")
print("end_header")
for vertex in verticies:
    print("{0} {1} {2}".format(round(vertex[0], 2), round(vertex[1], 2), round(vertex[2], 2)))
for i in range(len(verticies) - 2):
    print("3 {0} {1} {2}".format(i, i + 1, i + 2))
