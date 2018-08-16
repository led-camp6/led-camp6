/**
 * @file PreEvent.h
 * @brief �C�x���g�Ǘ�
 * @author Naoki Okayama
 * @date 2017/06/28
 */

#ifndef __EVENT_H__
#define __EVENT_H__

#include <cstdint>

class Controller;

#define E_UP ((unsigned long)0x00000001)
#define E_DOWN ((unsigned long)0x00000002)
#define E_LEFT ((unsigned long)0x00000004)
#define E_RIGHT ((unsigned long)0x00000008)
#define E_CHANGE_DISTANCE ((unsigned long)0x00000010)
#define E_CHANGE_ANGLE ((unsigned long)0x00000020)
#define E_CHANGE_RANGING ((unsigned long)0x00000040)
#define E_REACH ((unsigned long)0x00000080)


#define TRUE (1)
#define FALSE (0)

class Event {
public:
    Event(Controller* controller);
    void updateEvent();
    unsigned long getEvent();

private:
    Controller* controller;
    unsigned long event;

    float distanceOld;
    float angleOld;
    uint16_t rangingDistanceOld;
};

#endif