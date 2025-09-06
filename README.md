# libunit
- the micro-framework, named libunit.a, is designed to facilitate the execution of a series of tests on various functions in a structured and efficient manner

## Core functionalities:

### Test Execution
The framework allows for the execution of multiple tests sequentially, ensuring that each test runs in its own separate process. This isolation helps in accurately capturing the results and any potential errors that may occur during execution.

### Test Management
Each test is stored in a list or array, identified by a specific name. This organization allows for easy management and retrieval of tests.
The framework will output the name of the function being tested along with the name of each test and its corresponding result.

### Result Reporting
After each test execution, the framework captures the result and reports it in a standardized format:
- OK: Test succeeded.
- KO: Test failed.
- SIGSEGV: Segmentation Fault detected.
- SIGBUS: Bus Error detected.
- the output format will be: [test_function]:[test_name]:[status]

### Summary of Results
At the end of the test execution, the framework will display the total number of tests run and the count of successful tests.
If all tests pass, the program will exit with a return value of 0; if any test fails, it will return -1.

#### ✅ This micro-framework provides a robust and organized approach to testing C functions, making it easier for developers to validate their code and ensure reliability.
