#ifndef TRACKABLE_H
#define TRACKABLE_H

class Trackable
{
public:
    virtual ~Trackable();

    long getModCount() const;

protected:
    void bumpModCount();

private:
    long modCount_ = 0;
};

#endif