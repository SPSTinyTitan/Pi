import random as rand
import numpy as np
import time
import cv2
from matplotlib import pyplot as plt

time.process_time()
rand.seed(a=None)

iterate = 100000
hits = 0
r = 127
img = np.zeros((r+1, r+1, 3), np.uint8)
window = "Window"

for i in range(0, iterate+1):
    x = rand.uniform(0, r)
    y = rand.uniform(0, r)
    if x**2+y**2 <= r**2:
        hits += 1
        img[round(x), round(y)] = 255
    else:
        img[round(x), round(y)] = 0

    # For a quick visualization I plot 1000 points at a time
    if i % 1000 == 0:
        plt.ion()
        plt.imshow(img)
        plt.show(block=False)

pi = 4*(hits/iterate)
stop = time.process_time()
print(pi, "\t", stop, "seconds")
