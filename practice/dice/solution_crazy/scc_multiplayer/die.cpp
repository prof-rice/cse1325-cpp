#include "die.h"
#include <cstdlib>

Die::Die(int faces) : _faces{faces}, _keep{false}, _roll{1} { }
int Die::faces() {return _faces;}
int Die::roll() {
    if(!_keep) _roll = 1+std::rand()%_faces;
    return _roll;
}
void Die::keep(bool k) {_keep = k;}
bool Die::keep() {return _keep;}
