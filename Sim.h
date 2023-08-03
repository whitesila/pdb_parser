#ifndef Sim_H
#define Sim_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "Env.h"
#include "parm.h"

class simulation{
private:
std::unique_ptr<Environment> coord;
std::unique_ptr<parm> top;
std::fstream temp_file;
void displacement_vect(std::vector<float>& d, int atom1, int atom2);
void magnitude(std::vector<float>& object, float& mag);
void unit_vector(float& mag, std::vector<float> d, std::vector<float>& unitv);
void theta_from_dot(int& atom1, int& atom2, int& atom3, float& theta);
void dot(std::vector<float>& disp1, std::vector<float>& disp2, float& val);
void cross(std::vector<float>& vect1, std::vector<float>& vect2, std::vector<float>& cprod);
void DHtheta_from_dot(std::vector<float>& nplane1, std::vector<float>& nplane2, float np1mag, float np2mag, float& theta);
void DHrotTheta_from_dot(std::vector<float>& disp1, std::vector<float>& disp2, float& mag_disp1, float& mag_disp2, float& theta);
void resize(std::vector<float>& vect, float scale);
void vect_add(std::vector<float>& v1, std::vector<float>& v2, std::vector<float>& product);
void DH_LJF(int atom1, int atom4, float SCNBF, float LJA, float LJB);
using T = std::variant<int, float, std::string>;

public:
std::vector<float> velocities;
std::vector<float> forces;



simulation(Environment& coord, parm& top, float step, std::string export_name);
void update_coord(float step_size, int frames, int export_step);
void exports();
void spring_force(int atom1, int atom2, float kval, float eq);
void force_additions();
void VerletAlg(float& step); 
void angle_force(int atom1, int atom2, int atom3, float k, float eq);
void dihedral_force(int atom1, int atom2, int atom3, int atom4, float k, float period, float sceef, float scnbf, float phase);

};


#endif