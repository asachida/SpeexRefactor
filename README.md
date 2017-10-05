# Speex Codec Rewrite Challenge

## Plan for rewrite using C++11
* Identify Objects: The following can be considered as independent objects:
  - Encoder
  - Decoder
  - Bit Stream Data
  - File Parser 
  - Speex Header
  
* The following can be simplified/ modified using C++
  - We can combine data and functions into C++ classes. Ex: **SpeexBits**, **SpeexHeader**.
  - Wherever possible, rather than allocating and freeing memory, we could use new and delete. 
  - Better yet, is to use the C++11 smart pointers internally for dynamic memory allocation, such as **std::shared_ptr** and **std::unique_ptr**, which does a pretty good job of deleting heap objects that go out of scope.
  - Wherever possible, rather than using preprocessor directive (#define), we could use Enums. Ex: **EncoderModeTypes { ENC_MODE_NARROW_BAND, ENC_MODE_WIDE_BAND, ENC_MODE_ULTRA_WIDE_BAND}**
  - We could have interface classes (abstract base classes) exposed to the client and inherit this to form our internal headers and src files. 
      Ex, we could have **class ISpeexEncoder** as abstract base class and classes **SpeexNarrowBandEncoder**, **SpeexWideBandEncoder** and **SpeeUltraWideBandEncoder** derived from this.
  - We could also have a **IFileParer** abstract base class, which can be derived by respective audio format classes such as **WavFileParser**.
  - Too many conditional statements can hamper the overall performance of the system. We could use structural (factory) and behavioral(strategy) design patterns and separate them out into different classes.
  - We could use C++ *std::string* objects instead of allocating memory to char pointers where possible. The gains from this is so high that the performance impact is negligible.
  - We could make extensive use of C++ **exceptions** and throw relevant exceptions during errors and unexpected inputs.
  - We could write a **Logger** class to log all the error/warning and info messages onto a specific text file for easy debug.
  - We could use the [fixed length integer types](http://en.cppreference.com/w/cpp/types/integer) that C++11 provides, to maintain platform independent fixed size data type usage.
  - We could have minimum number of functions that are exported to the clients outside the library. As in the code, **SpeexRefactorAPI.cpp** contains only three APIS that are exposed. **GetEncoder(SpeexEnumType)** returns the respective encoder pointer. Clients can use this to call all the APIs in the Encoder interface for encoding purpose. Clients do however, need to call **Release()** to release all dynamic memory allocated by Encoder. 
  - In addition to the above, we could use various features C++11 has to offer, such as algorithms and Lambda expressions while iterating through a set of data and filtering, extensively use STL data types where appropriate.

* Elaborate analysis of all the components of Speex Codec
  - ### Speex Encoder
      - SpeexEncoder depending on the bit rate, is of three types: NarrowBand, Wide Band and UltraWideBand encoders.
      - Each of these encoders consists of frame size, complexity, sampling rate, encoding quality, variable bit rate encoding quality, an input frame to be encoded and output frame where an encoded frame data is written.
      - Each of these encoders has the ability to enable/disable the following
          - Variable Bit Rate Encoding (VBR)
          - High pass filter
          - Voice Activity Detection (VAD)
          - Discontinous Transmission (DTX)
      - It can read the input wav file (on windows)
      - Determine which encoding mode to be used based on bit rate in the wav header
      - Set all the controls required for encoding such as enabling VBR, VAD,  HighPass etc.
      - Write the SpeexHeader packet data followed by the entire audio bit stream data, encoding one frame at a time
      
  - ### Speex Header
      - SpeexHeader is the header data to be written into the encoded frame, before encoding the actual frames.
      - It consists of the following properties:
          - Encoding name
          - Version Info
          - Bit rate used
          - Mode encoded in (Narrow band, wide band, etc..)
          - No of channels encoded (2 for stereo, 1 for mono)
          - Frame size
          - Frames per packet
      - It can perform Initialization of number of channels, bit rate and encoding mode.
      - It can convert SpeexHeader to a packet and vice-versa.
 
  - ### Speex Bit Stream
      - SpeexBitStream is the actual audio stream data that is used during both encodin and decoding.
      - It consists of the following:
          - char pointer for raw data (char is used to access byte wise data)
          - Byte cursor pointer
          - Bit cursor pointer inside every byte
          - Indicator to specify whether the stream owns the raw data or is a mere shallow copy of someone elses data.
          - Overflow indicator set if we read past the valid data.
          - Buffer Size.
      - It can perform he following:
          - Initialie the raw data with a buffer by copying all the buffer data to the raw data memory(deep copy)
          - Initialize raw data with a pointer to the actual data (shallow copy)
          - Reset the buffer data
          - Rewind (Move cursor backwards)/ Forward (Move cursor forward)
          - Read from a memory location.
          - Write to a memory location.
          - Pack/ Unpack data with additional bits to fill the packet.
          - Know the remaining bits to read.
          - Insert a terminating character after every frame.
          
  - ### File Parser
      - Wav file parser is used to read from a wav file after parsing.
      - It has the ability: 
          - to read header and get values such as encoding mode, bit rate
          - to determine whether the header or the entire file itself is corrupted.
          - to write wav header
          
  - ### Wav output
      - Wav output used on windows is to create audio streams specific to Windows OS.
      - It has the ability to:
          - Set parameters such as sampling frequency, bits per sample and number of channels.
          - Play audio samples on Windows. (Treats action as critical section)
          - Close audio samples on Windows. (Treats action as critical section)
          
  - ### Speex Decoder
      - SpeexDecoder is used to decode speech from an encoded bit stream.
      - It can perform:
          - Read a wav file 
          - Initialize SpeexBitStream
          - Read data and write it into a ogg file buffer
          - Read first packet and process it as SpeexHeader, following reading packet by packet
          - Copy ogg packet to Speex Bit stream
          - Decode the frame.
          - Use Wav output to play the sample frame.
          - Continue until no more frames exist.
   
   * Individual object interactions:
      - The [Object interactions](https://github.com/asachida/SpeexRefactor/blob/master/SpeexRefactored_ObjectInteractions_UML.pdf) are described in this pdf file.

   
