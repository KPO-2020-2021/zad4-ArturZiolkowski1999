# Initialization
1. Create "build" directory in main project directory
3. Go to build and use "cmake .." command
4. Use "make" command
5. For running tests run build/tst/rotation2D_tst
7. For running main program run /build/rotation2D_run 
8. Enjoy !

# Program structure
The program includes 4 classes. The first is Vector, next one is Matrix.
Is contains static table of doubles. Class that contains all above is Cuboid. 
method rotate and translate with belong to this class rotate or translate vertices of given rectangle. 
Final class is GnuplotDrawings which enable program to comunicate with Gnuplot through external static
library "LaczeDoGnuplota". For the program to run corectly you have to initialize rectangle with 4 vertices which create perpendicular sides.

# Info
In lib directory is local version of "Gtests" and "LaczeDoGnuplota" external library used for tests and is program.
In tst directory are all test, inferior CmakeList, and main function for running all tests.
