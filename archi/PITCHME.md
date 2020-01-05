### Micro-Architectural Attacks
##### (6 Jan, 2020) 
---
### Micro-Architectural Attacks

- Information Leakage
	- Side Channels: Unintentional leakage of sensitive data
	- Covert Channels: Deliberate leakage of sensitive data (by a Trojan) 
- Denial of Service

---
### Information Leakage
- Types of Side Channel in the micro-architectural Context
	- Storage Side-Channels: e.g unprotected memory locations.
	- Timing Side channels: e.g Information contained in cache hit/miss time difference.

---
### Recap: Computer Architecture

- Processor |
- MMU |
- Cache |
- Main Memory (DDR) |
---
### Recap: Computer Architecture

- Main Memory (DDR) 
- Cache 
- MMU 
- Processor 
---
### DRAM Operation: A single DRAM Bank
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/ddr_bank.svg" height="400"/>
---
### DRAM Operation: Banks 
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/ddr.svg" height="400"/>
---
### DRAM Operation: DRAM Operation
* READ: Activate (open the row)-> Read -> Precharge (close).
* WRITE: Activate (open the row)-> Write -> Precharge (close).
* REFRESH: READ-> WRITE back.
---
### DRAM Traffic TCL,TRCD,TRP
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/dram.svg" height="400"/>
---

### DRAM Traffic
* DRAM is the main performance bottleneck in a SoC.
* DRAM response can come out of order, has high initial latency.
---
### RECAP: Cache
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/opencl.svg" height="400"/>
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

<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/cache.svg" height="400"/>
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
### Recap : MMU
#HSLIDE?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/mmu.svg&size=auto 90%
<!-- .slide: data-background-transition="none" -->
#HSLIDE?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/mmu1.svg&size=auto 90%
---

### Recap: MMu Operation
* Translation Lookaside Buffer
	* Keeps a page table for virtual to physical address translation.
	* 4GB memory with page size of 4K => ~4MB
	* Each process has a different page table.
	* page table is kept in main memory.
    * Each access will need two accesses to main memory.
    * TLB acts as a cache for page table entries (PTE).
---
### Recap : Life of a Memory Request
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/vm_path.svg" height="400"/>
---

### Recap : Memory Hierarchy
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/memory_hier.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_mobile.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_laptop.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_desktop.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/memhier_server.svg&size=auto 90%
---
### Recap: Processors 
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/simd.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/simd1.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/simd2.svg&size=auto 90%
+++?image=http://perso.telecom-paristech.fr/~chaudhur/tpt39/simd3.svg&size=auto 90%
---
### Uniprocessor
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/uniprocessor.svg" height="400"/>
---
### Multiprocessor
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/gpu_mimd.svg" height="400"/>
---
### Multiprocessor: UMA
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/uma.svg" height="400"/>
---
### Multiprocessor: NUMA
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/numa.svg" height="400"/>
---
### Processor: VLIW
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/vliw.svg" height="400"/>
---
### Multi-Threading: Superscalar
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/superscalar.svg" height="400"/>
---
### Multi-Threading: Coarse-Grained
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/coarse_mt.svg" height="400"/>
---
### Multi-Threading: Fine-Grained
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/fine_mt.svg" height="400"/>
---
### Multi-Threading: Simultaneous
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/smt.svg" height="400"/>
---
### Reacp: Multi-Threading
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/mt.svg" height="400"/>
---
### In Order Processor Pipeline
<img src="assets/up-pipeline.png" height="400"/>
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

+++?code=archi/src/ex1.asm&lang=c&title=Dynamic Scheduling and Out-of-Order execution [1] p.193
@[1-2](Dependence)
@[3](Stalled)
---

### Out-of-Order Pipeline
<img src="assets/ooo.png" height="400"/>
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
### SCA Classifications
<img src="http://perso.telecom-paristech.fr/~chaudhur/micro_archi_attacks/sca_classification.svg" height="400"/>
---

### Example: Branch Target Buffer Side Channel (Ref [2])
- BTB stores the target addresses of previous branches.
- Acts like a cache.
----
+++?code=archi/src/mm.c&lang=c&title=Montgomery Multiplier BTB Attack
@[1-2](Dependence)
@[3](Stalled)
---
### Example: Branch Target Buffer Side Channel (Ref [2])
- assume that an adversary can run a spy process simultaneously with the cipher |
- spy process continuously executes unconditional branches |
- these branches map to the same BTB set with the conditional branch under attack. [
---
### Example: Branch Target Buffer Side Channel (Ref [2])
- The adversary starts the spy process before the cipher |
- Cipher cannot find the target address of the target branch in BTB -> misprediction |
- misprediction -> the target address of the branch needs to be stored in BTB. |
- spy branch is evicted. (they occupy the whole BTB set) |
- spy finds from its own execution time if the branch was taken. |
---

### Example: Cache Side Channel
<img src="assets/slide1.jpg" height="600"/>
----
### A
<img src="assets/slide2.jpg" height="600"/>
---
### B
<img src="assets/slide3.jpg" height="600"/>
---
### C
<img src="assets/slide4.jpg" height="600"/>
---
### Example: Memory Controller Side Channel
<img src="http://perso.telecom-paristech.fr/~chaudhur/micro_archi_attacks/slide1.svg" height="400"/>
----


### Example Heterogeneous SoCs
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/acecontext.svg" height="400"/>
---
### Our SoC: Exynos 5422
<img src="http://perso.telecom-paristech.fr/~chaudhur/tpt39/fig/exynos5422.svg" height="400"/>
---

#### quiz

* What is maximum computation rate in Flops/S. ?
