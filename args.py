import numpy as np
import os
import sys
import time

INT_MAX = 214748364#7
INT_MIN = -214748364#8
INT_OVERFLOW_MIN = -92147483648
INT_OVERFLOW_MAX = 82147483647


def main():
    n = sys.argv[1]
    arg_array = np.random.randint(INT_MIN, INT_MAX, int(n))
    args = ""
    for i in arg_array:
        args += str(i)
        args += " "
    print (args)


if __name__ == "__main__":
    main()
