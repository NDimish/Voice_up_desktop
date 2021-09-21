import pyaudio
import numpy as np
import wave
import sys
import mmap
import ctypes

# this file gets the frequency and send to cpp file

# cache class structures
# two peice of data, one data is written by py other by cpp
class TransferData(ctypes.Structure):
    _fields_ = [
        ('exLg', ctypes.c_float),
        ('ex', ctypes.c_float),
    ]

def fill(data,num):
    data.exLg = num


# open stream
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 44100

CHUNK = 2048 # RATE / number of updates per second
window = np.blackman(CHUNK)

# code to interpret the audio stream
def soundPlot(stream):
    data = stream.read(CHUNK, exception_on_overflow=False)
    waveData = wave.struct.unpack("%dh"%(CHUNK), data)
    npArrayData = np.array(waveData)
    indata = npArrayData*window
    #Plot time domain
    fftData=np.abs(np.fft.rfft(indata))
    fftTime=np.fft.rfftfreq(CHUNK, 1./RATE)


    which = fftData[1:].argmax() + 1
    # use quadratic interpolation around the max
    if which != len(fftData)-1:
        y0,y1,y2 = np.log(fftData[which-1:which+2:])
        x1 = (y2 - y0) * .5 / (2 * y1 - y2 - y0)
        # find the frequency and output it
        thefreq = (which+x1)*RATE/CHUNK
        thefreq = round(thefreq)
        #print ("The freq is %f Hz." % (thefreq))
        return thefreq
    else:
        thefreq = which*RATE/CHUNK
        thefreq = round(thefreq)
        #print ("The freq is %f Hz." % 5(thefreq))
        return thefreq







# main code
if __name__=="__main__":

     #the code below creats the shared memory
    shmem = mmap.mmap(-1, ctypes.sizeof(TransferData),
                      "TransferDataSHMEM")
    # structure to connect to cache
    data = TransferData.from_buffer(shmem)

#the code below opens the audio stream
    p=pyaudio.PyAudio()
    stream=p.open(format=pyaudio.paInt16,channels=1,rate=RATE,input=True,
                  frames_per_buffer=CHUNK)

    try:
# checks the cpp want to keep file ope if not cpp give a -1
        while True:
            data2 = TransferData.from_buffer(shmem)
            if data2.ex == -1:
                shmem.flush()
                shmem.close()
                break
                #print(data2.ex)
            fill(data,soundPlot(stream))
        #shmem.close()
# close strem if python closes
    except NULL:
        fill(data,-1.0)
        pass

    stream.stop_stream()
    stream.close()
    p.terminate()
















