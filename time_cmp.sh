#!/bin/bash

if [ -z "$2" ] || [ "$1" == "-h" ]; then
    echo "Usage: ./time_cmp.sh amount_of_test_cases test_case_size"
    exit 0
fi

if [ ! -e greedy_solver ] || [ ! -e mst_solver ]; then
    echo "There is no greedy_solver or mst_solver, have You ran make successfully?"
    exit 1
fi

for i in `seq 0 $(($1 - 1))`; do
    echo "Generating test $i"
    ./gen_graph.py -n $2 > ./test_cases/test_case_$i
    echo "Running greedy algorithm"
    time ./greedy_solver < ./test_cases/test_case_$i \
        > ./test_results/greedy_result_$i
    echo
    echo "Running mst heuristic algorithm"
    time ./mst_solver < ./test_cases/test_case_$i \
        > ./test_results/mst_heuristic_result_$i
    echo "Comparing the results lengths"
    if [ $(head -n 1 ./test_results/greedy_result_$i) == \
         $(head -n 1 ./test_results/mst_heuristic_result_$i) ]; then
        echo "The results lengths are the same"
    else
        echo "The results do not match on test $i"
        exit 1
    fi
    echo -e "\n\n"
done

