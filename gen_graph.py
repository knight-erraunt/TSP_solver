#!/bin/env python3

import argparse
import random
import time


class random_graph_generator():
    def __init__(self, n, s, w, h):
        self.n = n
        self.s = s
        self.w = w
        self.h = h

    def generate_points(self):
        random.seed(self.s) 
        set_of_points = set()
        while len(set_of_points) < self.n:
            set_of_points.add((random.randint(0, self.w),
                random.randint(0, self.h)))
        return [a for a in set_of_points]



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate random set of points on a plane')
    parser.add_argument('-n', help='the number of points desired (default=10)', default=10)
    parser.add_argument('-s', help='the seed for the random number generator (by default time is taken)', default=str(int(time.time())))
    parser.add_argument('-max_x', help='the range of the x coordiante (default=20)', default=20)
    parser.add_argument('-max_y', help='the range of the y coordiante (default=20)', default=20)
    
    args = parser.parse_args()

    rgg = random_graph_generator(int(args.n), int(args.s),
            int(args.max_x), int(args.max_y))

    points = rgg.generate_points()

    print(rgg.n)

    for x, y in points:
        print(str(x) + " " + str(y))




