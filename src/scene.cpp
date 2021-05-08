//
// Created by artur on 4/11/21.
//
#include "scene.h"

scene::scene() {
    GNU.ZmienTrybRys(PzG::TR_3D);
    this->fileName = "";
    this->XRange[0] = 0;
    this->XRange[1] = 0;
    this->YRange[0] = 0;
    this->YRange[1] = 0;
}

scene::scene(std::string _fileName, double _XRange[2], double _YRange[2], double _ZRange[2]) {
    this->fileName = _fileName;
    this->XRange[0] = _XRange[0];
    this->XRange[1] = _XRange[1];
    this->YRange[0] = _YRange[0];
    this->YRange[1] = _YRange[1];
    this->ZRange[0] = _ZRange[0];
    this->ZRange[1] = _ZRange[1];
    GNU.UstawRotacjeXZ(60,30);
    GNU.DodajNazwePliku(this->fileName.c_str())
        .ZmienSposobRys(PzG::SR_Ciagly);
    GNU.DodajNazwePliku(this->fileName.c_str())
        .ZmienSposobRys(PzG::SR_Punktowy)
        .ZmienSzerokosc(1)
        .ZmienKolor(4);
    GNU.ZmienTrybRys(PzG::TR_3D);
    GNU.UstawZakresX((this->XRange[0]),(this->XRange[1]));
    GNU.UstawZakresY((this->YRange[0]),(this->YRange[1]));
    GNU.UstawZakresZ((this->ZRange[0]),(this->ZRange[1]));
}

void scene::drawCuboid(Cuboid<double> &cub){
    std::ofstream os;
    os.open(this->fileName);
    if(!os){
        throw std::exception();
    }
    os << cub;
    os << cub[0];
    os.close();
    GNU.Inicjalizuj();
    GNU.Rysuj();

}

void scene::drawVector(Vector<double, 3> &Vec){
    std::ofstream os;
    os.open(this->fileName);
    if(!os){
        throw std::exception();
    }
    os << Vec;
    os << 0 << " " << 0;
    GNU.Inicjalizuj();
    GNU.Rysuj();
    os.close();
}

void scene::animateRotateCuboid(Cuboid<double> &cub, double &degree, char &axis) {
    Cuboid<double> animateCub = cub;
    Matrix3x3 rotMatrix = Matrix3x3();
    double singleDegree = 0;
    while (std::abs(singleDegree) < std::abs(degree)){
        singleDegree += 2;
        if(degree >= 0){
            rotMatrix = Matrix3x3(2,axis);
            animateCub.rotationByMatrix(rotMatrix);
        }else{
            rotMatrix = Matrix3x3(-2,axis);
            animateCub.rotationByMatrix(rotMatrix);
        }
        usleep(ANIMATION_SPEED);
        drawCuboid(animateCub);
    }
    rotMatrix = Matrix3x3(degree, axis);
    cub.rotationByMatrix(rotMatrix);
    drawCuboid(cub);
}

void scene::animateTranslateRectangle(Cuboid<double> &cub, Vector<double, 3> &translation) {
    Cuboid<double> animateCub = cub;
    Vector<double, 3> animateTranslation = translation/translation.getLength();
    Vector<double, 3> unityTranslation = translation/translation.getLength();
    unityTranslation = unityTranslation/RESOLUTION;
    double i = 0;
    while (animateTranslation.getLength() < translation.getLength()){
        i++;
        animateTranslation = unityTranslation * i;
        animateCub.translationByVector(animateTranslation);
        usleep(ANIMATION_SPEED);
        drawCuboid(animateCub);
        animateTranslation = animateTranslation + unityTranslation;
        animateCub = cub;
    }
    cub.translationByVector(translation);
    drawCuboid(cub);
}
