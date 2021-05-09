# Initialization
1. Create "build" directory in main project directory
2. Create empty "data" directory
3. Go to build and use "cmake .." command
4. Use "make" command
5. For running tests run build/tst/rotation2D_tst
7. For running main program run /build/rotation2D_run 
8. Enjoy !

# Program structure
    The program includes 3 class templates. Vector (with type and dimention), Matrix which have 2 classes inherate from him. Matrix 3x3(3- dimension and double type) and Matrix4x4 which is usles in project but it is required.
Template class Cuboid(i shoud use simple class, but i want to train template alitle bit) consist vertices vectors and 12 side langth. It has metod to translate cuboid and to rotate it.


    The final class is scene. It has 5 cuboid, properly seted Lacze do gnuplota and metods to draw thouse cuboid and animate its. 

    In main() user can interact with scene class, guided by simple terminal menu.

    Of course program doesnt generate big amount of numerical errors.

# Info
In lib directory is local version of "Gtests" and "LaczeDoGnuplota" external library used for tests and is program.
In tst directory are all test, inferior CmakeList, and main function for running all tests.
