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
# import numpy as np
from random import randint
from random import uniform 
from random import gauss
import csv

# check inputs
if (len(sys.argv) != 4):
  print("Usage: <n> <d> <k>")

n = int(sys.argv[1]) # number of samples
d = int(sys.argv[2]) # dimensions
k = int(sys.argv[3]) # clusters

s = open('/scratch/loughlin.c/samples.csv', 'w')
# c = open('clusters.csv', 'w', newline='') 
c = open('/scratch/loughlin.c/cluster.csv', 'w')
swrite = csv.writer(s)
cwrite = csv.writer(c)

# create means and deviations
# first dimension is 0-k
# second dimension is 0-d
mu = [0]*k
sigma = [0]*k
cluster = [0]*n

# init
for i in range(0, k):
  mu[i] = [0]*d
  sigma[i]= [0]*d
  for j in range(0, d):
    mu[i][j] = uniform(-5,5) # fiddle with this to get means
    # sigma[i][j] = uniform(1,5) # fiddle with this to get sigma
  
sample = [0]*n
for i in range(0, n):
  sample[i] = [0]*d
  	
for i in range (0, n):
  # assign samples to clusters
  cluster[i] = randint(0, k-1)
  # generate data
  for j in range(0, d):
    myc = cluster[i]
    sample[i][j] = gauss(mu[myc][j], 1)

# output to csv
for i in range(0, n):	
  swrite.writerow(sample[i])
  
cwrite.writerow(cluster)

s.close()
c.close()
