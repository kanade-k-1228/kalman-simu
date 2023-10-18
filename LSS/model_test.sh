#!/bin/bash

./LSSmodel_test $1
gnuplot -e "
    file = \"$1\";
    plot file using 0:1 with linespoints title \"real x\",
         file using 0:2 with linespoints title \"real v\",
         file using 0:3 with linespoints title \"observe v"\,
         file using 0:4 with linespoints title \"noize x\",
         file using 0:5 with linespoints title \"observation noize\";
    pause -1
    "
