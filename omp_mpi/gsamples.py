#################################
## gsamples.py
## 
## INPUT: n, d, k
## number of samples, dimensions, and clusters
## OUTPUT: two CSV files
## samples.csv is nxd array of data points
##  clusters.csv is 1xn vector of assignments
##
## author: Brian Yarbrough
##
################################

import sys
import numpy as np
#import scipy as sp
from random import randint
from random import uniform 
#from random import gauss
import csv

# check inputs
if (len(sys.argv) != 4):
  print("Usage: <n> <d> <k>")

n = int(sys.argv[1]) # number of samples
d = int(sys.argv[2]) # dimensions
k = int(sys.argv[3]) # clusters

s = open('samples.csv', 'w')
c = open('clusters.csv', 'w', newline='') 
swrite = csv.writer(s)
cwrite = csv.writer(c)

# create means and deviations
# first dimension is 0-k
# second dimension is 0-d
mu = [0]*k
sigma = [0]*k
for i in range(0, k):
  mu[i] = [0]*d
  sigma[i]= [0]*d
  for j in range(0, d):
    mu[i][j] = uniform(-5,5) # fiddle with this to get means
    # sigma[i][j] = uniform(1,5) # fiddle with this to get sigma
    

# assign samples to clusters
cluster = [0]*n
for i in range (0, n):
  # assign samples to clusters
  cluster[i] = randint(0, k-1)
  sample = [0]*d
  # generate data
  for j in range(0, d):
    myc = cluster[i]
    # sample[j] = np.random.normal(mu[myc][j], sigma[myc][j], 1)[0]
    sample[j] = np.random.normal(mu[myc][j], 1, 1)[0]
    # sample[j] = gauss(mu[myc][j], 1)[0]
  swrite.writerow(sample)

cwrite.writerow(cluster)

s.close()
c.close()
