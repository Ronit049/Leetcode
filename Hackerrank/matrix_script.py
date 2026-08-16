#!/bin/python3

import math
import os
import random
import re
import sys




first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

decoded_list = list(zip(*matrix))

decoded_string = ''
for item in decoded_list:
    decoded_string = decoded_string + "".join(item)

print(re.sub(r'\b[^a-zA-Z0-9]+\b',r' ',decoded_string))