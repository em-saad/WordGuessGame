#ifndef MODE_H
#define MODE_H

class Mode {
public:
    virtual void play() = 0; // Pure virtual function
    virtual ~Mode() {}       // Virtual destructor
};

#endif // MODE_H