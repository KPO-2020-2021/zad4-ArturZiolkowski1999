#include <iostream>
#include <fstream>
#include <lacze_do_gnuplota.hh>
#include <utility>
#include "../inc/Matrix3x3.h"
#include "Cuboid.h"
#include "Vector.h"
#include "scene.h"
#define Vector Vector<double, 3>


void menuDisplay();
void getRotationMatrix(Cuboid<double> &cub, Matrix3x3 &rotMatrix, scene &gnu);

int main(int argc, char** argv) {
    /* Initialize Cuboid and translation vector and axis*/
    Vector Ver0 = Vector(0,1,1);
    Vector Ver1 = Vector(5,1,1);
    Vector Ver2 = Vector(5,1,4);
    Vector Ver3 = Vector(0,1,4);

    Vector Ver4 = Vector(0,9,1);
    Vector Ver5 = Vector(5,9,1);
    Vector Ver6 = Vector(5,9,4);
    Vector Ver7 = Vector(0,9,4);

    Vector vertices[VERTICES_NUMBER] = {Ver0, Ver1, Ver2, Ver3, Ver4, Ver5, Ver6, Ver7};

    char axis;
    /* Initialize "Lacze do gnuplota" to work with in class scene*/
    std ::string file ="../data/data.txt";
    double XRange[2] = {-15, 15};
    double YRange[2] = {-15, 15};
    double ZRange[2] = {-15, 15};
    scene gnu = scene(file, XRange, YRange, ZRange);
    gnu.cub = Cuboid<double>(vertices);
    /* Drawing initial rectangle and display menu*/
    menuDisplay();

    Matrix3x3 matrixGetForSingleRotation = Matrix3x3();

    double amountOfRotation;
    char c = ' ';
    while(c != 'k'){
        gnu.drawCuboid(gnu.cub);
        if(!(std::cin >> c)){
            throw std::exception();
        }
        switch (c) {
            case 'm':
                menuDisplay();
                break;
            case 'o':
                gnu.rotMatrix = Matrix3x3();
                getRotationMatrix(gnu.cub, gnu.rotMatrix, gnu);
                std::cout << "give amount of rotation (it has to be positive integer) \n";
                if(amountOfRotation <= 0){
                    throw std::invalid_argument("Incorrect amount of rotation");
                }
                std::cin >> amountOfRotation;

                gnu.rotateByAmountOfRotation(amountOfRotation);
//                matrixGetForSingleRotation = gnu.rotMatrix;
//                for(int k = 1; k < amountOfRotation; k++){
//                    gnu.rotMatrix = matrixGetForSingleRotation * gnu.rotMatrix;
//                }
//                gnu.cub.rotationByMatrix(gnu.rotMatrix);
//                gnu.drawCuboid(gnu.cub);
                break;
            case 'p':
                std::cin >> gnu.translation;
                gnu.animateTranslateRectangle(gnu.cub,gnu.translation);
                break;
            case 'w':
                std::cout << gnu.cub;
                break;
            case 'r':
                std::cout << gnu.rotMatrix;
                break;
            case 'k':
                break;
            case 't':
                gnu.cub.rotationByMatrix(gnu.rotMatrix);
                gnu.drawCuboid(gnu.cub);
                break;
            case 'l':
                gnu.cub.calculateSidesLength();
                std::cout << "first sides: " << gnu.cub.getSideLength(0) << std::endl;
                std::cout << "first sides: " << gnu.cub.getSideLength(1) << std::endl;
                std::cout << "first sides: " << gnu.cub.getSideLength(2) << std::endl;
                std::cout << "first sides: " << gnu.cub.getSideLength(3) << std::endl;

                std::cout << "second sides: " << gnu.cub.getSideLength(4) << std::endl;
                std::cout << "second sides: " << gnu.cub.getSideLength(5) << std::endl;
                std::cout << "second sides: " << gnu.cub.getSideLength(6) << std::endl;
                std::cout << "second sides: " << gnu.cub.getSideLength(7) << std::endl;

                std::cout << "third sides: " << gnu.cub.getSideLength(8) << std::endl;
                std::cout << "third sides: " << gnu.cub.getSideLength(9) << std::endl;
                std::cout << "third sides: " << gnu.cub.getSideLength(10) << std::endl;
                std::cout << "third sides: " << gnu.cub.getSideLength(11) << std::endl;
                break;
            default:
                std::cout << "unknown argument, pleas use correct arguments\n";
                break;
        }
        std::cout << "You chose: '"<< c << "' (m-menu)\n";


    }
}

void menuDisplay(){
  std::cout << "o - rotate rectangle by angle in degree\n";
  std::cout << "p - translate rectangle by vector\n";
  std::cout << "w - display coordinates of rectangle vertices\n";
  std::cout << "m - display menu\n";
  std::cout << "k - close\n";
  std::cout << "l - display length of sides\n";
  std::cout << "r - display last rotational matrix\n";
  std::cout << "t - repeat the last rotation\n";
}

void getRotationMatrix(Cuboid<double> &cub, Matrix3x3 &rotMatrix, scene &gnu){
    char c;
    bool fail = false;
    Cuboid<double> animateCuboid = cub;
    Matrix rot = Matrix3x3 ();
    rotMatrix = Matrix3x3();
    double degree;
    while(c != '.'){
        std::cout << "give axis ann angle in degree\n";
        if(!(std::cin >> c)){
            throw std::exception();
        }
        if(c == '.') break;
        switch (c) {
            case'x':
                fail = false;
                break;
            case'y':
                fail = false;
                break;
            case'z':
                fail = false;
                break;
            default:
                std::cout <<"unknown axis, try again\n";
                fail = true;
                break;
        }
        if(!fail){
            if(!(std::cin >> degree)){
                throw std::exception();
            }
            rot = Matrix3x3(degree, c);
            gnu.animateRotateCuboid(animateCuboid, degree, c);
            rotMatrix = rot * rotMatrix;
        }
    }
}
