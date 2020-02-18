'''
Leo Smart
Pi approximation Fast
'''
import numpy
import time

def main():
    iterations = 1000000
    hits = numpy.sum(numpy.random.rand(iterations)**2 + numpy.random.rand(iterations)**2 < 1)
    print(4*hits / iterations)
    
start_time = time.clock()
main()
print (time.clock() - start_time, "seconds")
