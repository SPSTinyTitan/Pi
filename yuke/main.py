from time import perf_counter
import edge_detect
import torch
import cv2
import math


#Create 10000x10000 grid (100m samples)
size = 10000
circle = edge_detect.edge_detect(size)
torch.set_printoptions(precision=10)
#Edge detection
t1 = perf_counter()
result = circle.calc_fine()
pi = circle.calc_pi()
t4 = perf_counter()
print("Pi =", pi)
print("Error:", math.pi - pi)
print("Total time for pi using edge detection:", t4 - t1)

#Calculating pi without edge detection
t5 = perf_counter()
pi = circle.calc_raw()
t6 = perf_counter()
print("Pi =", pi)
print("Error:", math.pi - pi)
print("Total time for pi without edge detection:", t6 - t5)


#Draw the detected edge
#edge_detect.draw(result)