import numpy as np
import os

arg_array = np.random.randint(-9000, 9000, 10)
args = ""
for n in arg_array:
    args += str(n)
    args += " "
os.system('./push_swap ' + args)