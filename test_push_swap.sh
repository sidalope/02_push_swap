#!/bin/bash

# Fully AI written quick acceptance tester
# Also runs second AI script for visualizing overall performance as bar graph and scatter plot
# Usage: ./test_push_swap.sh [max_size] [num_tests_per_size]

MAX_SIZE=${1:-500}
TESTS_PER_SIZE=${2:-5}
PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# CSV logging variables
CSV_FILE="test_push_swap_detailed.csv"
CSV_SIZES=""
CSV_OPERATIONS=""

echo -e "${BLUE}=== Push Swap Tester ===${NC}"
echo "Testing sizes from 0 to $MAX_SIZE"
echo "Running $TESTS_PER_SIZE tests per size"
echo ""

# Function to generate random numbers without duplicates
generate_random_list() {
    local size=$1
    
    if [ $size -eq 0 ]; then
        echo ""
        return
    fi
    
    local numbers=()
    
    # Generate unique random numbers
    while [ ${#numbers[@]} -lt $size ]; do
        local num=$((RANDOM % 2001 - 1000))  # Range -1000 to 1000
        
        # Check if number already exists
        local exists=false
        for existing in "${numbers[@]}"; do
            if [ "$existing" -eq "$num" ]; then
                exists=true
                break
            fi
        done
        
        if [ "$exists" = false ]; then
            numbers+=($num)
        fi
    done
    
    echo "${numbers[@]}"
}

# Function to test a specific list
test_list() {
    local size=$1
    local test_num=$2
    local arg_list=$3
    
    if [ -z "$arg_list" ] && [ $size -gt 0 ]; then
        echo -e "${RED}Failed to generate list for size $size${NC}"
        return 1
    fi
    
    # Skip empty lists
    if [ $size -eq 0 ]; then
        echo -e "${YELLOW}Skipping size 0 (empty list)${NC}"
        return 0
    fi
    
    echo -n "Size $size, Test $test_num: "
    
    # Check if checker_linux exists and is executable
    if [ ! -x "$CHECKER" ]; then
        echo -e "${YELLOW}SKIP (checker_linux not found/executable)${NC}"
        return 0
    fi
    
    # Count operations for CSV logging
    local operations=$($PUSH_SWAP $arg_list 2>/dev/null)
    local operations_count=$(echo "$operations" | wc -l)
    if [ -z "$operations" ]; then
        operations_count=0
    fi
    
    # Run push_swap and pipe to checker (original logic)
    local result
    result=$($PUSH_SWAP $arg_list 2>/dev/null | $CHECKER $arg_list 2>/dev/null)
    local exit_code=$?
    
    # Add to CSV data
    if [ -n "$CSV_SIZES" ]; then
        CSV_SIZES="$CSV_SIZES, $size"
        CSV_OPERATIONS="$CSV_OPERATIONS, $operations_count"
    else
        CSV_SIZES="$size"
        CSV_OPERATIONS="$operations_count"
    fi
    
    # Check the result (original logic unchanged)
    if [ "$result" = "OK" ]; then
        echo -e "${GREEN}PASS${NC}"
        ((PASSED_TESTS++))
        return 0
    elif [ "$result" = "KO" ]; then
        echo -e "${RED}FAIL${NC}"
        echo "  List: $arg_list"
        ((FAILED_TESTS++))
        return 1
    else
        echo -e "${RED}ERROR (unexpected output: '$result')${NC}"
        echo "  List: $arg_list"
        ((FAILED_TESTS++))
        return 1
    fi
}

# Check if executables exist
if [ ! -x "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: $PUSH_SWAP not found or not executable${NC}"
    echo "Make sure to compile the project first: make"
    exit 1
fi

if [ ! -x "$CHECKER" ]; then
    echo -e "${YELLOW}Warning: $CHECKER not found or not executable${NC}"
    echo "Continuing with limited testing..."
fi

# Test random lists of various sizes
echo -e "${BLUE}Testing random lists:${NC}"

for size in $(seq 1 $MAX_SIZE); do
    for test_num in $(seq 1 $TESTS_PER_SIZE); do
        ARG=$(generate_random_list $size)
        test_list $size $test_num "$ARG"
        ((TOTAL_TESTS++))
        
        # Add a small delay to avoid overwhelming the system
        if [ $((TOTAL_TESTS % 50)) -eq 0 ]; then
            sleep 0.1
        fi
    done
    
    # Progress indicator every 10 sizes
    if [ $((size % 10)) -eq 0 ]; then
        echo -e "${BLUE}Completed testing up to size $size...${NC}"
    fi
done

# Test edge cases after random tests
echo ""
echo -e "${BLUE}Testing edge cases:${NC}"

# Test with already sorted list
echo -n "Already sorted (1 2 3 4 5): "
ARG="1 2 3 4 5"
operations=$($PUSH_SWAP $ARG 2>/dev/null)
operations_count=$(echo "$operations" | wc -l)
if [ -z "$operations" ]; then
    operations_count=0
fi
result=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>/dev/null)
if [ "$result" = "OK" ]; then
    echo -e "${GREEN}PASS${NC}"
    ((PASSED_TESTS++))
else
    echo -e "${RED}FAIL${NC}"
    ((FAILED_TESTS++))
fi
((TOTAL_TESTS++))
# Add to CSV
if [ -n "$CSV_SIZES" ]; then
    CSV_SIZES="$CSV_SIZES, 5"
    CSV_OPERATIONS="$CSV_OPERATIONS, $operations_count"
else
    CSV_SIZES="5"
    CSV_OPERATIONS="$operations_count"
fi

# Test with reverse sorted list
echo -n "Reverse sorted (5 4 3 2 1): "
ARG="5 4 3 2 1"
operations=$($PUSH_SWAP $ARG 2>/dev/null)
operations_count=$(echo "$operations" | wc -l)
if [ -z "$operations" ]; then
    operations_count=0
fi
result=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>/dev/null)
if [ "$result" = "OK" ]; then
    echo -e "${GREEN}PASS${NC}"
    ((PASSED_TESTS++))
else
    echo -e "${RED}FAIL${NC}"
    ((FAILED_TESTS++))
fi
((TOTAL_TESTS++))
# Add to CSV
CSV_SIZES="$CSV_SIZES, 5"
CSV_OPERATIONS="$CSV_OPERATIONS, $operations_count"

# Test with negative numbers
echo -n "With negatives (-3 -1 0 2 4): "
ARG="-3 -1 0 2 4"
operations=$($PUSH_SWAP $ARG 2>/dev/null)
operations_count=$(echo "$operations" | wc -l)
if [ -z "$operations" ]; then
    operations_count=0
fi
result=$($PUSH_SWAP $ARG 2>/dev/null | $CHECKER $ARG 2>/dev/null)
if [ "$result" = "OK" ]; then
    echo -e "${GREEN}PASS${NC}"
    ((PASSED_TESTS++))
else
    echo -e "${RED}FAIL${NC}"
    ((FAILED_TESTS++))
fi
((TOTAL_TESTS++))
# Add to CSV
CSV_SIZES="$CSV_SIZES, 5"
CSV_OPERATIONS="$CSV_OPERATIONS, $operations_count"

# Summary
echo ""
echo -e "${BLUE}=== Test Summary ===${NC}"
echo "Total tests: $TOTAL_TESTS"
echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
echo -e "Failed: ${RED}$FAILED_TESTS${NC}"

# Save CSV data
echo "$CSV_SIZES" > "$CSV_FILE"
echo "$CSV_OPERATIONS" >> "$CSV_FILE"
echo ""
echo "Results saved to: $CSV_FILE"

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed. Check the output above for details.${NC}"
    exit 1
fi

python3 plot_results.py
