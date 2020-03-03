import random as rand
import numpy as np
import time
import cv2


def draw(tensor):
    cv2.imshow("Pi Estimation", tensor)
    cv2.waitKey(1)


def main():
    rand.seed(a=None)
    time.process_time()
    iterate = 10000000
    hits = 0
    r = 511
    img = np.zeros((r+1, r+1, 3), np.uint8)

    for i in range(0, iterate+1):
        x = rand.uniform(0, r)
        y = rand.uniform(0, r)
        if x**2+y**2 <= r**2:
            hits += 1
            img[round(x), round(y)] = 255

    # For a quick visualization I plot 1000 points at a time
        if i % 1000 == 0:
            draw(img)

    pi = 4*(hits/iterate)
    stop = time.process_time()
    print(pi, "\t", stop, "seconds")
    input("Press a key to continue: ")


main()
