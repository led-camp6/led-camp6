#include <iostream>
#include <time.h>
#include "PreEvent.h"
#include "Controller.h"
#include <sys/time.h>

#include "LEDTank.h"


int main(void){
  struct timeval now;
  struct timeval old;

  Controller *controller;
  PreEvent *preEvent;

  LEDTank *lEDTank;
  controller = Controller::getInstance();

  lEDTank = new LEDTank(controller);

  preEvent = new PreEvent(controller);

  gettimeofday(&now, NULL);
  gettimeofday(&old, NULL);

  while(true){
    while((now.tv_sec - old.tv_sec) + (now.tv_usec - old.tv_usec)*1.0E-6  < 0.05F){
      gettimeofday(&now, NULL);
    }
    old = now;

    preEvent->updatePreEvent();

    lEDTank->execState();
    lEDTank->doTransition(preEvent->getPreEvent());
  }

  delete lEDTank;
  delete preEvent;
}
