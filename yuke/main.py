from time import perf_counter
import edge_detect
import torch
import cv2



size = 10000

circle = edge_detect.edge_detect(size)

t1 = perf_counter()
result = circle.calc_fine()
t2 = perf_counter()
print("Elapsed time:", t2 - t1, "s")
edge_detect.draw(result)