#!/bin/bash

# COUNT=${1:-10}
# MAX=${2:-100}
# valgrind -s --leak-check=full ./push_swap 1 2 3 0 78 3 3 5 643 64
# valgrind -s --leak-check=full ./push_swap $(cat tests/random_10.txt)
# ./push_swap 1 2 3 0 78 3 3 5 643 64
ARG=$(python3 -c "import random; nums=set();
while len(nums)<100: nums.add(random.randint(-2147483648, 2147483647));
print(' '.join(map(str, nums)))")
./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
