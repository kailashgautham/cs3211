#!/bin/bash

# Initialize counter
count=0

for i in {1..50}; do
    # Run the command and capture the output
    output=$(./"Grader ARM64" engine < scripts/50threads100000buysellcancel_2.txt 2>&1)
    
    # Get the last line of the output and trim whitespace
    last_line=$(echo "$output" | tail -n 1)
    # Check if the last line equals "test passed"
    case "$last_line" in
        "test passed." )
            ((count++))
            ;;
        *) 
            echo "Last line: $last_line"
            echo "Test case failed"
            exit 1
            ;;
    esac
    echo "${i} done..."
done

# Output the count of successful runs
echo "Test cases passed $count times out of 50."
