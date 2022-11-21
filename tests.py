import numpy as np
import subprocess
import sys
import matplotlib.pyplot as plt
import time

INT_MAX = 214748364#7
INT_MIN = -214748364#8
INT_OVERFLOW_MIN = -92147483648
INT_OVERFLOW_MAX = 82147483647


def main():
    stats_n = []
    stats_r = []
    x = [3,5,10,100,500]
    for n in x:
        T = int(sys.argv[1])
        result= []

        for j in range(T):
            arg_array = np.random.randint(INT_MIN, INT_MAX, int(n))
            args = ""
            for i in arg_array:
                args += str(i)
                args += " "
            r = int(subprocess.check_output('./push_swap ' + args + '| wc -l', shell=True))
            result.append(r)
            stats_r.append(r)
            stats_n.append(n)
        print(f"Sorting {n} numbers over {T} iterations\nCounting operations : \tAverage:\t{int(sum(result)/len(result))}\tMax:\t{max(result)}\tMin:\t{min(result)}\n")
    ref_nlogn = []
    for x in stats_n:
        ref_nlogn.append(x * np.log(x))
    plt.plot(stats_n,stats_r)
    plt.plot(stats_n,ref_nlogn)
    plt.show()
if __name__ == "__main__":
    main()