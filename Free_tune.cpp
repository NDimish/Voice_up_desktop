// this is the free tune src file
#include "Free_tune.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/windows_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <iostream>
#include <windows.h>
#include<thread> 
// this is the structure used for the shared memory
struct TransferData
{
    float exLg;
    float ex;
};
// function to make new thread for the python audio thing
void signal_callback_handler() {
    //std::cout << "new thread\n\n";
    system("python Audio_shared_memory.py");
    //Error_screens::Error_log("Python finished");
}


// free tune function
void Free_tune::AudioCheck() {
    float percentoff = ((7902.13 - 7458.13)/7902.13) * 1.059463094;
    using namespace boost::interprocess;
    int x = 5;
    std::thread thread_object(signal_callback_handler);

    if (x > 1)
    {
        Sleep(1000);
        // Get Data
        windows_shared_memory shmem(open_only, "TransferDataSHMEM", read_write);
        //shared_memory_object shmem(open_only, "PyTransferDataSHMEM", read_write);
        mapped_region region(shmem, read_write);
        TransferData* data;
        int avrg;
        do {
           // float avrg =0;
          //  for (int i=0; i < 20; i++) {
                data = reinterpret_cast<TransferData*>(region.get_address());
                avrg = (*data).exLg;
                //Error_screens::Error_log(avrg);
                // example of checking note to how close and output light
           // }
            //avrg = avrg / 20;
            if ((*Lights).Notefrequency - (percentoff* (*Lights).Notefrequency) < avrg && avrg < (*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency))
                Lights->Lights(9);

            // for lower than note
            else if ((*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency) > avrg && avrg > (*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency)*2)
                Lights->Lights(1);
            else if ((*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency)*2 > avrg && avrg > (*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency)*3)
                Lights->Lights(2);
            else if ((*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency)*3 > avrg && avrg > (*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency)*4)
                Lights->Lights(3);
            else if ((*Lights).Notefrequency - (percentoff * (*Lights).Notefrequency)*4 > avrg)
                Lights->Lights(4);

            // for higher than note 
            else if ((*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency) < avrg && avrg < (*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency)*2)
                Lights->Lights(5);
            else if ((*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency)*2 < avrg && avrg < (*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency)*3)
                Lights->Lights(6);
            else if ((*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency)*3 < avrg && avrg < (*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency)*4)
                Lights->Lights(7);
            else if ((*Lights).Notefrequency + (percentoff * (*Lights).Notefrequency)*4 < avrg)
                Lights->Lights(8);
           

         } while ((*data).exLg != -1 && (*Lights).exit == false);

        std::memset(region.get_address(), 0, sizeof(TransferData));
        data->ex = -1;
        Error_screens::Error_log("Execution sent");
        Sleep(1000);
        thread_object.detach();

    }
}


#include "SineWave.h"
#include "RtWvOut.h"
#include <cstdlib>
#include "RtWvIn.h"
// play note 
using namespace stk;
void Free_tune::noteout(float HZ) {

    // Set the global sample rate before creating class instances.
    Stk::setSampleRate(44100.0);
    Stk::showWarnings(true);
    int nFrames = 33333;
    SineWave sine;
    RtWvOut* dac = 0;
    try {
        // Define and open the default realtime output device for one-channel playback
        dac = new RtWvOut(1);
    }
    catch (StkError&) {
        exit(1);
    }
    // output noise
    sine.setFrequency(HZ);
    for (int i = 0; i < nFrames; i++) {
        try {
            dac->tick(sine.tick());
        }
        catch (StkError&) {
            goto cleanup;
        }
    }
cleanup:
    delete dac;
}