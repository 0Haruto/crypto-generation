#!/bin/bash
# SPDX-FileCopyrightText: 2024 Haruto Yamamoto
# SPDX-License-Identifier: BSD-3-Clause

# テストケース1
echo "Hello, World!" | ./crypto_generation.py > output1.txt
tester_output1="85!2!2!5  ?3!5!8!24 "
if diff <(echo "$tester_output1") output1.txt; then
    echo "Test 1 passed!"
else
    echo "Test 1 failed!"
fi
rm output1.txt
# テストケース2
echo "I love games!" | ./crypto_generation.py > output2.txt
tester_output2="9 !2!5?25 71!35!9 "
if diff <(echo "$tester_output2") output2.txt; then
    echo "Test 2 passed!"
else
    echo "Test 2 failed!"
fi
rm output2.txt
# テストケース3
echo "Let's test this script." | ./crypto_generation.py > output3.txt
tester_output3="!2520 !9 205!920 2089!9 !93!89!620 "
if diff <(echo "$tester_output3") output3.txt; then
    echo "Test 3 passed!"
else
    echo "Test 3 failed!"
fi
rm output3.txt
