import sys
import numpy as np
from random import randint

# check inputs
if (len(sys.argv) != 4):
  print("Usage: <n> <d> <k>")

n = int(sys.argv[1]) # number of samples
d = int(sys.argv[2]) # dimensions
k = int(sys.argv[3]) # clusters

s = open('samples.txt', 'w')
c = open('clusters.txt', 'w')

# create means and deviations
# first dimension is 0-k
# second dimension is 0-d
mu = [][]
sigma = [][]
for i in range(0, n-1):
  for j in range(0, d-1):
    mu[i][j] = random()
    sigma[i][j] = random()

# assign samples to clusters
cluster = [0]*n
for i in range (0, n-1):
  # assign samples to clusters
  cluster[i] = randint(0, k)
  c.write(str(cluster[i]) + '\n')
  # generate data
  for j in range(0, d-1):
    s.write(str(np.random.normal(mu[cluster[i][d], sigma[cluster[i][d], 1)).strip("[]") + ',')
  s.write('\n')


s.close()
c.close()

