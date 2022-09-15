import numpy as np
import os
import sys


def main():
    n = sys.argv[1]
    arg_array = np.random.randint(-2147483648, 2147483647, int(n))
    args = ""
    for n in arg_array:
        args += str(n)
        args += " "
    os.system('./push_swap ' + args)


if __name__ == "__main__":
    main()