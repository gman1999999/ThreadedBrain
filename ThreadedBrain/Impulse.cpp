#include "Impulse.h"


Impulse::Impulse(Cell* parent)
{
    mqd_t mq;
    struct mq_attr attr;
    char buffer[sizeof(StructuraTa)];
    

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = CATE_MESAJE_VREI; ///////++++
    attr.mq_msgsize = sizeof(StructuraTa);
    attr.mq_curmsgs = 0;

    m_memory = mq_open(parent->name+"X", O_CREAT | O_RDONLY, 0644, &attr); //am pus X ca sa nu se confuzeze
}

void Impulse::receiveImpulse() //this is your main thread. daca nu vrei sa fie, muta 
{
    int must_stop = 0;
    do {
        ssize_t bytes_read;
        char buffer[sizeof(StructuraTa)]; ///////++++
        /* receive the message */
        bytes_read = mq_receive(mq, buffer, sizeof(StructuraTa), NULL); //replace NULL with timeout daca vrei o celula plictisita sa moara

        action((StructuraTa)buffer);//basically, tu vrei aici sa faci chestii:
        //exemple de action : self kill : must_stop = 1;
        //                    reproduce : dai nastere la o celula noua


    } while (!must_stop); 
}

//sendimpulse fiind static nu e o metoda a unei celule.
//se foloseste direct Impulse::sendImpulse(&mesaj);
void Impulse::sendImpulse(StructuraTa *mesaj) // asta poate fi statica
{
    mq = mq_open(pointerCatreCelulaDestinatie->nume+"X", O_WRONLY);
    CHECK((mqd_t)-1 != mq);

    mq_send(mq, mesaj, sizeof(StructuraTa), 0);
}