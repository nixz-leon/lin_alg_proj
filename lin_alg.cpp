#include <iostream>
using namespace std;

struct object{
    int size;
    int pos_vec[3] = {0,0,0};  // the point in 3d space that the object is
    int motion_vec[3] = {0,0,0}; // the x,y,z velocity componets of the object
    int accel_vec[3] = {0,0,0}; // the x,y,z 
    int force_vec[3] = {0,0,0};
    int mass;
};

void  find_pos(object &circ, int time_step){
    for(int i = 0; i < 3; i++){

        circ.pos_vec[i] = circ.pos_vec[i] + (circ.motion_vec[i] * time_step) + (((float)circ.accel_vec[i] * time_step *time_step)/2);
        circ.motion_vec[i] = circ.motion_vec[i] + (circ.accel_vec[i] * time_step);
    }
}

void display_pos(object circ){
    cout << "{" << circ.pos_vec[0] << "," << circ.pos_vec[1] << "," << circ.pos_vec[2] << "}"  << endl;
}

int main(){
    object ob1;
    for(int i = 0; i < 2; i ++){
        ob1.accel_vec[i] = 1;
    }
    int time_step = 1;
    int total_time = 0;
    while(total_time <= 10){
        find_pos(ob1, time_step);
        display_pos(ob1);
        total_time += time_step;
    }
}