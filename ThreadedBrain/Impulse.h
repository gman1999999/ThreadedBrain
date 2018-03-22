#pragma once
#include "Cell.h"

#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include "mqdefs.h"
#include "mqueue.h"


class Impulse
{
    public:
    Impulse(Cell* parent);
    void receiveImpulse();

    static void sendImpulse(StructuraTa *mesaj);

    protected:
    mqd_t m_memory = -1;
    Cell* parent = NULL; //cand iti faci new Cell sa dai parametru this (ca sa stie cine e parintele)

};