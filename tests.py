import numpy as np
import os
import sys
import time

INT_MAX = 2147483647
INT_MIN = -2147483648
INT_OVERFLOW_MIN = -92147483648
INT_OVERFLOW_MAX = 82147483647


def main():
    n = sys.argv[1]
    arg_array = np.random.randint(INT_MIN, INT_MAX, int(n))
    args = ""
    for n in arg_array:
        args += str(n)
        args += " "
    start = time.perf_counter()
    os.system('./push_swap ' + args)
    stop = time.perf_counter()
    print(f"Elapsed time : {stop - start:0.4f} sec\n")


if __name__ == "__main__":
    main()