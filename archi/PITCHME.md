### Micro-Architectural Attacks

##### Sumanta Chaudhuri 

##### (04 Jan, 2021) 
---
### Micro-Architectural Attacks

- Information Leakage
	- Side Channels: Unintentional leakage of sensitive data
	- Covert Channels: Deliberate leakage of sensitive data (by a Trojan) 
- Denial of Service
- Reverse Engineering.

---
### Information Leakage
- Types of Side Channel in the micro-architectural Context
	- Storage Side-Channels: e.g unprotected memory locations.
	- Timing Side channels: e.g Information contained in cache hit/miss time difference.

---
### SCA Classifications
![width=1000](assets/sca_classification.svg)
---
### Recap: Computer Architecture

- Processor |
- MMU |
- Cache |
- Main Memory (DDR) |
---
### SCA Classifications
![width=1000](assets/sca_classification.svg)
---
### Recap: Processors 
+++?image=assets/simd.svg&size=auto 90%
+++?image=assets/simd1.svg&size=auto 90%
+++?image=assets/simd2.svg&size=auto 90%
+++?image=assets/simd3.svg&size=auto 90%
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Uniprocessor
[drag=70 100, drop=right]
![width=500](assets/fig/uniprocessor.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multiprocessor
[drag=70 100, drop=right]
![width=1000](assets/fig/gpu_mimd.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multiprocessor: UMA
[drag=70 100, drop=right]
![width=1000](assets/fig/uma.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multiprocessor: NUMA
[drag=70 100, drop=right]
![width=1000](assets/fig/numa.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Processor: VLIW
[drag=70 100, drop=right]
![width=1000](assets/fig/vliw.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multi-Threading: Superscalar
[drag=70 100, drop=right]
![width=1000](assets/fig/superscalar.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multi-Threading: Coarse-Grained
[drag=70 100, drop=right]
![width=1000](assets/fig/coarse_mt.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multi-Threading: Fine-Grained
[drag=70 100, drop=right]
![width=1000](assets/fig/fine_mt.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Multi-Threading: Simultaneous
[drag=70 100, drop=right]
![width=1000](assets/fig/smt.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=0.8, set=text-white]
### Reacp: Multi-Threading
[drag=70 100, drop=right]
![width=1000](assets/fig/mt.svg)
---
### In Order Processor Pipeline
![width=1500](assets/up-pipeline.png)
---
### In Order Processor Pipeline
- Statically Scheduled (During Compile Time)
- Pipeline Hazards
	- Structural Hazards: e.g two back-to-back instructions using the floaitng point unit.
	- Data Hazards: e.g an instruction depends on the result of the previous instruction.
	- Control Hazards: e.g branhces , future value of PC is not known.
---
### In Order Processor Pipeline
- Data hazards stall the pipeline.
- Need Branch predictors for control hazards:
	- Simple 1 bit/ 2 bit predictors. ([1], p.C-24)
	- Correlating Branch Predictor. ([1] p. 182)
	- Tournament Predictors. ([1] p. 184)
	- Tagged Hybrid Predcitors. ([1] p.188)
---

[drop=0 10, fit=1.4]
-Dynamic Scheduling and Out-of-Order execution [1] p.193
[drag=99, drop=right, fit=0.8]
@code[c](archi/src/ex1.asm)
[drag=30 50, drop=topright, font=bubblegum]
@[1-2](Dependence)
@[3](Stalled)
---

### Out-of-Order Pipeline
![width=1200](assets/ooo.png)
---

### Out-of-Order Pipeline
- Multiple Insturction are fetched in parallel.
- Execute Instructions that are ready (I.e data available)
- Instructions are commited in-order using the reorder buffer
---

### Out-of-Order Pipeline
- Hides Latency (Like Cache, & Multiple threads)
- Much More complex
- Security Hazards (As we will see later)
- Can not be done in compiler as compiler does not have runtime data.
	- e.g dynamic Scheduling
---

### Example: Branch Target Buffer Side Channel (Ref [2])
- BTB stores the target addresses of previous branches.
- Acts like a cache.
---
[drop=0 10, fit=0.8]
Montgomery Multiplier BTB Attack
[drag=99, drop=center, fit=0.8]
@code[c](archi/src/mm.c)
[drag=30 50, drop=topright, font=bubblegum]
@[5-6](branch not taken)
@[7-10](branch taken)
---
### Example: Branch Target Buffer Side Channel (Ref [2])
- assume that an adversary can run a spy process simultaneously with the cipher |
- spy process continuously executes unconditional branches |
- these branches map to the same BTB set with the conditional branch under attack. |
---
### Example: Branch Target Buffer Side Channel (Ref [2])
- The adversary starts the spy process before the cipher |
- Cipher cannot find the target address of the target branch in BTB -> misprediction |
- misprediction -> the target address of the branch needs to be stored in BTB. |
- spy branch is evicted. (they occupy the whole BTB set) |
- spy finds from its own execution time if the branch was taken. |
---
### SCA Classifications
![width=1000](assets/sca_classification.svg)
---

### RECAP: Cache
![width=600](assets/opencl.svg)
---

### RECAP: Cache: Cache Terminology
* Memory contains up-to-date data, and cache has a copy  (cache line): CLEAN
* Cache has up-to-date data, and it must be written back to memory: DIRTY
* Memory contains up-to-date data, and cache does not : INVALID
* Memory does not have up-to-date data, cache does not : INVALID
---

### RECAP Cache Terminology

* HIT: Data found in Cache.
* MISS: Data is not in the cache.
* EVICT: A clean cache line is replaced due to a new allocation.

---

### RECAP  Cache Organization (4 Way)

![width=700](assets/cache.svg)
---
### RECAP  Cache Policies

* Allocation 
  * Write Allocate : On a Write miss replace the cache line.
  * Read Allocate : On a read miss replace the cache line.
---
### RECAP  Cache Policies
* Update
  * Write Through : A write updates both the cache and the main  memory.
  * Write Back: Write updates the cache only (marked as dirty). Main memory is updated, when the line is evicted, cache is flushed.

---

### RECAP: Cache Coherence
* Case 1. Memory update by another master. Cached copy is out of date.
* Case 2. For write back cache, when master writes to cache, main memory is out of date.
---
### RECAP: Cache Coherence
* Cache Coherency Protocols
	* MEI (Modified, Exclusive, Invalid)
	* MESI (Modified, Exclusive, Shared Invalid)
	* MOESI (Modified, Owned, Exclusive, Shared Invalid)
* Goals
	* Cache to Cache copy of clean data.
	* Cache to Cache move of Dirty data without accessing external memory.

---
[drag=30 100, drop=left, bg=#0B5D8C]
@ul[list-spaced-bullets list-fade-bullets, drag=30 100, drop=left, fit=1.4, set=text-white, sync=true]
- Recap : Virtual Memory
- MMU
@ul
[drag=70 100, drop=right, flow=stack, sync=true]
![width=1000](assets/mmu.svg)
![width=1000](assets/mmu1.svg)
---

### Recap: MMU Operation
* Translation Lookaside Buffer
	* Keeps a page table for virtual to physical address translation.
	* 4GB memory with page size of 4K => ~4MB
	* Each process has a different page table.
	* page table is kept in main memory.
    * Each access will need two accesses to main memory.
    * TLB acts as a cache for page table entries (PTE).
---
### Recap : Life of a Memory Request
![](assets/vm_path.svg)
---

### Recap : Memory Hierarchy
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/memory_hier.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_mobile.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_laptop.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_desktop.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_server.svg&size=auto 90%
---
### Example: Cache Side Channel (Ref [3])
---
![width=2000](assets/slide1.jpg)
---
![width=2000](assets/slide2.jpg)
---
![width=2000](assets/slide3.jpg)
---
![width=2000](assets/slide4.jpg)
---
![width=2000](assets/prime_probe1-1.png)
---
![width=2000](assets/prime_probe2-1.png)
---
![width=2000](assets/prime_probe3-1.png)
---
### SCA Classifications
![width=1000](assets/sca_classification.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=1.4, set=text-white]
- DRAM Operation: A single DRAM Bank
[drag=70 100, drop=right]
![width=1000](assets/fig/ddr_bank.svg)
---

### DRAM Operation: DRAM Operation
* READ: Activate (open the row)-> Read -> Precharge (close).
* WRITE: Activate (open the row)-> Write -> Precharge (close).
* REFRESH: READ-> WRITE back.
---
### DRAM Traffic TCL,TRCD,TRP
![width=1500](assets/fig/dram.svg)
---
[drag=30 100, drop=left, bg=#0B5D8C, fit=1.4, set=text-white]
- DRAM Operation: Banks 
[drag=70 100, drop=right]
![width=1500](assets/fig/ddr.svg)
---
### DRAM Traffic TCL,TRCD,TRP
![width=1500](assets/fig/dram.svg)
---

### DRAM Traffic
* DRAM is the main performance bottleneck in a SoC.
* DRAM response can come out of order, has high initial latency.
---
### Example: Memory Controller Side Channel (Ref [4])
- Detecting firefox keystrokes from row buffer conflicts.
- find target addresses
- open a row in the same bank.
- detect memory access from rowbuffer hit/miss time.
---
[drag=99, drop=center, fit=0.5]
@code[c](archi/src/spectre.c)
[drag=30 10, drop=topright, font=bubblegum]
@[41-45](Speculative execution of branch even when x > array1_size.)
---
[drag=99, drop=center, fit=0.8]
@code[c](archi/src/spectre.c)
[drag=30 50, drop=topright, font=bubblegum]
@[41-45](Train the branch predictor for some iterations. Force it to mispredict.)

---
### Spectre
![width=1500](assets/spectre_bp.svg)
---
### Spectre
if (x < array1_size)
           y = array2[array1[x] * 4096];
- To attack
      - â victim_address=array1+x
      - â So â x=victim_address-array1
      - â The array2 index accessed is the value stored in victim_address.

---
### Spectre
if (x < array1_size)
           y = array2[array1[x] * 4096];
- To attack
      - â Find out the array2 index accessed with Flush+Reload
      - â Why do we need to multiply by a stride of 64 ?

---

### Spectre Mitigations

- All Out-of-Order Processors are affected by spectre.
- However it is harder to exploit. Need to find code pattern in the victim:
         if (x < array1_size)
                    y = array2[array1[x] * 4096];
---
### MeltDown
![width=1500](assets/meltdown1.svg)
---
### MeltDown
![width=1500](assets/meltdown2.svg)
---

### MeltDown
- 1. raise_exception();
- 2. // the line below is never reached
- 3. access(probe_array[data * 4096]);
Spill over to the Kernel memory space.
Find the value through Flush+Reload.

---
### MeltDown
- Step 1 The content of an attacker-chosen memory location, which is inaccessible to the attacker, is loaded into a register.
- Step 2 A transient instruction accesses a cache line based on the secret content of the register.
- Step 3 The attacker uses Flush+Reload to determine the accessed cache line and hence the secret stored at the chosen memory location

---
### MeltDown Mitigations
- KAISER Patch: User space does not have access to kernel memory.
- KASLR (Address space layout randomization): Makes the attack difficult.



---



#### TP : GEM5 Config
![width=1500](assets/gem5.png)

---
#### TP STEP 1
- @size[0.5em](Clone the repository  https://github.com/amusant/micro_archi_attacks)
- @size[0.5em]($source env.sh  → sets up environment variables.)
- @size[0.5em](Go to directory hit_miss; look into code hit_miss.c)
- @size[0.5em](Run make to compile the code in hit_miss directory)
- @size[0.5em](Runs $make launch to launch simulation.)
- @size[0.5em](We use the gem5 simulator to simulate a basic system with x86 processor and two levels of cache.)
- @size[0.5em](Understand the code used for )
    - @size[0.5em](Flush)
    - @size[0.5em](Acces )
    - @size[0.5em](Reload)
- @size[0.5em](By changing the acces pattern  do you see any difference in the output  ?)
- @size[0.5em](What is the role of STRIDE, does the code still work after changing STRIDE ?)
---
[drag=99, drop=center, fit=0.8]
@code[c](archi/src/hit_miss.c)
[drag=30 50, drop=topright, font=bubblegum]
@[24-26](Flushing the array)
@[28-30](Access by Victim)
@[32-39](Reload and measure time)
---
#### TP STEP 2
- @size[0.5em](Go to directory flush_reload; look into code flush_reload.c)
- @size[0.5em](The function victim does the following:)
- @size[0.5em](It accesses the array[secret[desknumber][i]*STRIDE])
- @size[0.5em](Where the secret is a 16 character secret key. )
	- @size[0.5em](secret[desknumber]=”XXXXXXXXXXXXXXXX”)
- @size[0.5em](Your goal is to find the 16 characters of the secret value.)
- @size[0.5em](The secret value changes with desk number.)
- @size[0.5em](Run make to compile the code in flush_reload directory)
- @size[0.5em](Runs $make launch to launch simulation.)
- @size[0.5em](Inspire yourself from the hit_miss code.)
---
#### TP STEP 3
- Download the Spectre Example link from
	- spectre/link
- Read and Understand the code.
- Compile the code
	-$gcc spectre.c
	-Launch the experiment
		- $gem5.opt ../configs/two_level.py ./a.out
		- does it work ?
- Change line 99 in ../configs/two_level.py
	- from DerivO3CPU() to TimingSimpleCPU()
	- realaunch simulation
	- Does it work ? 
---
### References
- @size[0.5em]([1] Computer Architecture:  A Quantitative Approach. Hennesssy & Patterson)
- @size[0.5em]([2] Predicting Secret Keys via Branch Prediction, Onur Acıicmez, Jean-Pierre Seifert, and C¸ etin Kaya Ko¸c)
- @size[0.5em]([3] FLUSH+RELOAD: a High Resolution, Low Noise, L3 Cache Side-Channel Attack)
- @size[0.5em]([4] Meltdown: Reading Kernel Memory from User Space Moritz Lipp, Michael Schwarz, Daniel Gruss, Thomas Prescher,Werner Haas, Anders Fogh, Jann Horn, Stefan Mangard,Paul Kocher, Daniel Genkin, Yuval Yarom, Mike Hamburg)
---
### References
- @size[0.5em]([5] DRAMA: Exploiting DRAM Addressing for Cross-CPU Attacks Peter Pessl, Daniel Gruss, Clémentine Maurice, Michael Schwarz, and Stefan Mangard,)
- @size[0.5em]([6] A Survey of Microarchitectural Timing Attacks and Countermeasures on Contemporary Hardware Qian Ge, Yuval Yarom2 , David Cock, and Gernot Heiser)
- @size[0.5em]([7] Spectre Attacks: Exploiting Speculative Execution Paul Kocher, Jann Horn, Anders Fogh, Daniel Genkin,Daniel Gruss, Werner Haas, Mike Hamburg, Moritz Lipp,Stefan Mangard, Thomas Prescher, Michael Schwarz, Yuval Yarom)
---
