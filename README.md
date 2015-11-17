# TSP_solver

A traveling salesman problem solver for a university project.


Graph file format:
    first line contains n - the number of points on plane
    next n line contain two integers, the x and y coordinate
    respecitvely

    example:

        4
        1 5
        14 16
        12 11
        16 18

Path file format:
    first line contains the approximate cost of the path
    next line contains n numbers, the i'th says when was
    the i'th vertex visited

    example (answer to the graph above):

    40.450035
    0 3 1 2 


To generate random graph :

    gen_graph.py > output_file

    for help:
    gen_graph.py -h 


Test w greedy algorithm :

    greedy < in_file > output_file


Visualize the output path:

    visualize -g graph_file -p tsp_path_file

    for help:
    visualize -h



