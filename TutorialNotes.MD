# The following notes provide more in depth explanations 

### These will cover the following points

- Reasons for using header files [Why use Header files](#header-files)
  
- Registers that we use along with ports and why 

- Explanation of header file code  line by line 

- Why we have a main method 

- Explanation of the  configuration fields and what they do 


## Header Files   

Header files are a fundamental part of C programming, especially for organizing code in projects. Below are the reasons for using header files in this  project:

### Code Organization and Reusability

### Why : 

- By separating code into header files (port_scan.h in this case), we keep reusable and logically related functions or definitions in one place. This makes the main file (blinkf88.c) more readable and manageable.

### Example:

-   Timer initialization and delay functions are in the header file because they can be reused in multiple projects without rewriting them.


### Separation of Declarations and Implementations

-   Header files typically contain function prototypes and definitions (e.g., macros, constants), while their actual implementations reside in .c files. This separation makes it easier to understand the overall structure of the program.

### Example 

- The init_timer0 and scan_portb_pins function prototypes are declared in the header file and defined in the same file to simplify modularity.


### Ease of Debugging and Maintenance

-   When a project grows, separating logic into different files helps locate bugs and update specific components without impacting the entire codebase

-  If there’s an issue with scan_portb_pins, we only need to check the relevant logic in port_scan.h rather than searching through the entire project.


### Improved Compilation Efficiency 

-    During compilation, the compiler includes header files where needed. This modularity ensures that only updated files are recompiled, speeding up the build process.

-   When editing port_scan.h, only that file is recompiled unless changes affect the main file.

### Abstraction for Cleaner Code  

-   Header files abstract away complex details, allowing the main file to focus on the high-level functionality.


### In blinkf88.c:
-   
    The main file simply calls init_timer0() and scan_portb_pins(), without worrying about the internal implementation details. 