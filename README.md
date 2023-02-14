# Parallel OMNet++ simulation examples

### A simple tutorial on running OMNet++ in parallel, including simulation of FatTree, GEANT, and Abilene topologies.

### Environment Setup
#### Dependency Libraries Installation
Our simulation examples are based on the OMNet++ simulator, which requires dependency libraries to be installed before running:
```
sudo apt-get install build-essential gcc g++ bison flex perl \
tcl-dev tk-dev libxml2-dev zlib1g-dev default-jre \
doxygen graphviz libwebkitgtk-1.0-0 openmpi-bin \
libopenmpi-dev libpcap-dev
```

#### Simulator Installation
```
./configure
make
```

**Note that the MPI component must be installed if you want to run the simulation in parallel**

### How To Run
All the sample programs are placed in the `sample` folder.

#### Run The Simulation In A Single Process
Enter the folder, build and run the program. For example, the `Fattree-4`  topology can be run using the following commands:
```
cd samples/fat_tree_simple-4
make
./fat_tree_simple -u Cmdenv
```
Simulation feedback is given continuously until all events are simulated.

#### Run With Multiple Processes
Modify the configuration file to specify which nodes each process emulate and use `mpirun` to run the program parallelly.

We have placed different configuration files in the same folder, corresponding to various number of processes. `omnetpp.ini` is the configuration file in use and `X_processes.txt` is the configuration file to use X process parallelism. 

Similarly, Run FatTree-4 with 2 processes:
```
cp 2_processes.txt omnetpp.ini
mpirun -n 2 ./fat_tree_simple -u Cmdenv
```

#### Run With Multiple machines
Ensure that programs on different machines have the same path. Parallel simulation can then be started on a primary server. Based on the above command, add IP addresses of all machines after `-host`. For example, run FatTree-4 on two machines:
```
mpirun -n 2 -hosts 12.12.12.101,12.12.12.102(IP addresses of your machines) ./fat_tree_simple -u Cmdenv
```

