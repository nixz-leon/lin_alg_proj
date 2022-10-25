#include <iostream>
using namespace std;

struct object{
    float size = 1;
    float pos_vec[3] = {0,0,0};  // the point in 3d space that the object is
    float motion_vec[3] = {0,0,0}; // the x,y,z velocity componets of the object
    float accel_vec[3] = {0,0,0}; // the x,y,z 
    //float force_vec[3] = {0,0,0};
    int mass = 1;
    int dimension = 2;
};

void find_pos(object &ob, float time_step){
    for(int i = 0; i < ob.dimension; i++){
        ob.pos_vec[i] = ob.pos_vec[i] + (ob.motion_vec[i] * time_step) +((0.5f)*(ob.accel_vec[i] * time_step * time_step));
        ob.motion_vec[i] = ob.motion_vec[i] + (ob.accel_vec[i] * time_step);
        
    }
}
void add_force(object &ob, float forces[3]){
    for(int i =0; i < ob.dimension; i++){

        ob.accel_vec[i] += forces[i]/ob.mass; 
    }
}
void display_pos(object ob){
    cout << "pos {";
    for(int i =0; i < ob.dimension-1; i++){
        cout << ob.pos_vec[i] << ",";
    }
    cout << ob.pos_vec[ob.dimension-1] << "}" << endl;
}
void display_velocity(object ob){
    cout << "velocity {";
    for(int i =0; i < ob.dimension-1; i++){
        cout << ob.motion_vec[i] << ",";
    }
    cout << ob.motion_vec[ob.dimension-1] << "}" << endl;
}
void display_accel(object ob){
    cout << "accel {";
    for(int i =0; i < ob.dimension-1; i++){
        cout << ob.accel_vec[i] << ",";
    }
    cout << ob.accel_vec[ob.dimension-1] << "}" << endl;
}

// to add collison detection we are going to use a pointer or an array to represent position
// could we represent each objects using a matrix, with either equations or actualy values, we can create a disc or line (3d vs 2d) the lenght of which can be used to tune fedelity  
// from that we can do a quick test for intersections to tell if the objects are colliding. We can ignore checks for static objects
// and just focus on the moving objects in any given scene.

int main(){
    object ob1;
    float force_vec[3] = {0,0,0};
    float time_step = 1.f;
    float total_time = 0.f;
    display_pos(ob1);
    /*
    while(true){
        cout << "Apply Force" << endl;
        cout << "X component" << endl;
        cin >> force_vec[0];
        cout << "Y component" << endl;
        cin >> force_vec[1];
        cout << "Z component" << endl;
        cin >> force_vec[2];
        add_force(ob1, force_vec);
        while(total_time < 10){
            find_pos(ob1, time_step);
            total_time += time_step;
        }
        display_pos(ob1);
        display_velocity(ob1);
        display_accel(ob1);
        total_time = 0;
    }
    */

}