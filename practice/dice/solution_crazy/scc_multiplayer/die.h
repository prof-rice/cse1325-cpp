#ifndef __DIE_H
#define __DIE_H

class Die {
  public:
    Die(int faces);
    int faces();
    int roll();
    void keep(bool);
    bool keep();
  private:
    int _faces;
    int _roll;
    bool _keep;
};

#endif

