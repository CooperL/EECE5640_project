#!/bin/bash

#############################################
#
# Script to run project code modified from 
# example by Julian Guttierez
#
#############################################

#############################################
#
# Static configuration variables
#
#############################################

#export OMP_NUM_THREADS=32
#export OMP_NESTED=TRUE

# Current working directory (where the executable should be located)
workdir=`pwd`

# time you think you need; default is one day
# in minutes in this case, hh:mm:ss
time="01:00:00"

# number of tasks you are requesting
ntasks=3

# partition to use
partition="ser-par-10g-3"

# number of nodes to distribute n tasks across
nodes=3

#############################################
#
# On the run configuration variables
#
#############################################

# Message
echo "****************************"
echo "* Example run of MPI on the Discovery Cluster *"
echo "****************************"
echo ""

echo -n "Job submition name: "
read job

echo -n "File path to the executable file (for example, ./hello_mpi): "
read exe

#############################################
#
# DONT MODIFY ANYTHING AFTER THIS LINE
#
#############################################

command="sbatch --job-name=$job \
                 --output=$job.out \
                 --error=$job.err \
                 --time=$time \
                 -n $ntasks \
                 --exclusive \
                 --partition=$partition \
                 -N $nodes \
                 --workdir $workdir \
                 run.sbatch $exe"

eval $command
echo "SBATCH job has been submmitted."
echo "Run squeue $USER to check the status of the submission"

