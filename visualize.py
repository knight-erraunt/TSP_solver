#!/bin/env python3

import argparse
import sys
import tkinter as tk
import math

SCALE = 20
POINT_SIZE = 3 # a square consisting of 4 squares of size
               # POINT_SIZE will represent each city

n = 0
points = []
order = []

master = tk.Tk()

canvas = None

#canvas.create_line(0, 0, 200, 100)

def dist(p1, p2):
    return math.sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] -
        p2[1])*(p1[1] - p2[1]))

def draw_points(canvas, points):
    for x, y in points:
        canvas.create_rectangle(x * SCALE - POINT_SIZE, y * SCALE - POINT_SIZE,
                                x * SCALE + POINT_SIZE, y * SCALE + POINT_SIZE,
                                fill = 'blue')
def draw_lines(canvas, order):
    """
    Draw lines and count their lenght
    """
    result = 0
    prev = points[order[0]]
    for node in [points[i] for i in order[1:]]:

        result += dist(prev, node)
        canvas.create_line(prev[0] * SCALE, prev[1] * SCALE,
                           node[0] * SCALE, node[1] * SCALE,
                           fill = 'red')
        prev = node

    canvas.create_line(points[order[-1]][0] * SCALE, points[order[-1]][1] * SCALE,
                       points[order[0]][0] * SCALE, points[order[0]][1] * SCALE,
                       fill = 'red')

    result += dist(points[order[-1]], points[order[0]])

    return result



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Visualize the TSP path')
    parser.add_argument('-g', help='file containing the graph', required=True)
    parser.add_argument('-p', help='file containing the path', required=True)
    parser.add_argument('-max_x', help='the range of the x coordiante (default=20)', default=20)
    parser.add_argument('-max_y', help='the range of the y coordiante (default=20)', default=20)

    args = parser.parse_args()

    graph_file = open(args.g, 'r')
    n = int(graph_file.readline())

    for line in graph_file:
        points.append(list(map(int, line.split())))

    if len(points) != n:
        print("The graph number of nodes does not match the description")
        sys.exit(1)


    path_file = open(args.p, 'r')

    cost = float(path_file.readline().strip())
    vertex_visit_time = list(map(int, path_file.readline().split()))

    order = list(range(n))

    for i in range(n):
        order[vertex_visit_time[i]] = i

    if len(order) != n:
        print("The path is not of the length of all the points")
        sys.exit(1)

    canvas = tk.Canvas(master, width=args.max_x * SCALE, height=args.max_y * SCALE)
    canvas.pack()

    draw_points(canvas, points)
    lines_len = draw_lines(canvas, order)
    
    if abs(lines_len - cost) > 0.1:
        print("The length of the path output by program does not match \
                it's output cost")
    
    tk.mainloop()





