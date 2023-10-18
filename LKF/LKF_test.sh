#!/bin/bash
# ./LKF_test.o $1
gnuplot -e "
    file = \"$1\";
    plot file using 0:3 with lines lc rgb \"#0000ff\" lw 1 dt 1 title \"real v\",
         file using 0:5 with lines lc rgb \"#0000ff\" lw 1 dt 2 title \"estimate v\",
         file using 0:7 with lines lc rgb \"#0000ff\" lw 1 dt 3 title \"predict v\",
         file using 0:1 with lines lc rgb \"#0000ff\" lw 1 dt 4 title \"sensor v\",
         file using 0:2 with lines lc rgb \"#ff0000\" lw 1 dt 1 title \"real x\",
         file using 0:4 with lines lc rgb \"#ff0000\" lw 1 dt 2 title \"estimate x\",
         file using 0:6 with lines lc rgb \"#ff0000\" lw 1 dt 3 title \"predict x\";
    pause -1
    "
    
gnuplot -e "
    file = \"$1\";
    plot file using 0:3 with lines lc rgb \"#0000ff\" lw 1 dt 1 title \"real v\",
         file using 0:5 with lines lc rgb \"#0000ff\" lw 1 dt 2 title \"estimate v\",
         file using 0:7 with lines lc rgb \"#0000ff\" lw 1 dt 3 title \"predict v\",
         file using 0:1 with lines lc rgb \"#0000ff\" lw 1 dt 4 title \"sensor v\";
    pause -1
    "

gnuplot -e "
    file = \"$1\";
    plot file using 0:2 with lines lc rgb \"#ff0000\" lw 1 dt 1 title \"real x\",
         file using 0:4 with lines lc rgb \"#ff0000\" lw 1 dt 2 title \"estimate x\",
         file using 0:6 with lines lc rgb \"#ff0000\" lw 1 dt 3 title \"predict x\";
    pause -1
    "
