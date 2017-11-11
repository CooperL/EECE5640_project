import sys
import numpy as np
from random import randint

# check inputs
if (len(sys.argv) != 4):
  print("Usage: <n> <d> <k>")

n = int(sys.argv[1])
d = int(sys.argv[2])
k = int(sys.argv[3])

s = open('samples.txt', 'w')
c = open('clusters.txt', 'w')

# create means and deviations
mu = [][]
sigma = [][]

# assign samples to clusters
cluster = [0]*n
for i in range (0, n-1):
  # assign samples to clusters
  cluster[i] = randint(0, k)
  c.write(str(cluster[i]) + '\n')
  # generate data
  for j in range(0, d):
    s.write(str(np.random.normal(mu[cluster[i][d], sigma[cluster[i][d], 1)).strip("[]") + ',')
  s.write('\n')


s.close()
c.close()

