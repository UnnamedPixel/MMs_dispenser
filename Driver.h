#ifndef DRIVER_H
#define DRIVER_H

class Driver {
  protected:
    int nport;

    int virtual getINOUT();//0 -> IN/Sensor, 1 -> OUT/Actuator
    int virtual getTypeCom();  //0 -> Digital , 1 -> Analog

  public:
    Driver(int n);
};

#endif