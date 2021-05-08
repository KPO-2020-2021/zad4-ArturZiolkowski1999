//
// Created by artur on 4/11/21.
//

#ifndef ROTATION3D_GNUPLOTDRAWINGS_H
#define ROTATION3D_GNUPLOTDRAWINGS_H
#include <unistd.h>
#include "Cuboid.h"
#include <lacze_do_gnuplota.hh>
#include <fstream>

class scene{
private:
    std::string fileName;
    PzG::LaczeDoGNUPlota GNU;
    double XRange[2];
    double YRange[2];
    double ZRange[2];

public:
    scene();
    scene(std::string _fileName, double _XRange[2], double _YRange[2], double _ZRange[2]);
    void drawCuboid(Cuboid<double> &cub);
    void drawVector(Vector<double, 3> &Vec);
    void animateRotateCuboid(Cuboid<double> &cub, double &degree, char &axis);
    void animateTranslateRectangle(Cuboid<double> &cub, Vector<double, 3> &translation);
};

#endif //ROTATION3D_GNUPLOTDRAWINGS_H
