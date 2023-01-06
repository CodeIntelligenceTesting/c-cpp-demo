<a href="https://www.code-intelligence.com/">
<img src="https://www.code-intelligence.com/hubfs/Logos/CI%20Logos/Logo_quer_white.png" alt="Code Intelligence logo" width="450px">
</a>

# C/C++ demo

A demo project showcasing two vulnerabilities.

To find them on your own, download [cifuzz](https://github.com/CodeIntelligenceTesting/cifuzz).

Clone this repository and run

```
cifuzz run heap_buffer_overflow_test
```

to detect the heap buffer overflow or run 


```
cifuzz run stack_buffer_overflow_test
```

to detect the stack buffer overflow.


To learn more about how to write your own fuzz tests have a look [here](https://github.com/CodeIntelligenceTesting/cifuzz/blob/main/docs/How-To-Write-A-Fuzz-Test.md).

If you want to learn more about fuzzing in general, head over to [Code Intelligence](https://www.code-intelligence.com). 
 
## Running inside docker
If you want to run cifuzz without installing it (and the dependencies) you can just run
it inside docker with the provided `Dockerfile`

```
docker build -t cifuzz-demo .
docker run -it cifuzz-demo cifuzz run stack_buffer_overflow_test
```
