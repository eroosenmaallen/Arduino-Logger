/** 
 *  @file	Logger.h
 *  @author	Eddie Roosenmaallen <eddie@page.ca>
 *
 *  Logs stuff to Serial and a connected EthernetClient.
 */

#ifndef Logger_h
#define Logger_h

#include <SPI.h>
#include <Ethernet.h>

#define OUTPUTS(t)	size_t print(t);	size_t write(t);	size_t println(t);

#include <SPI.h>
#include <Ethernet.h>

class Logger : public Stream
{
  protected:
    EthernetClient logger;
    byte	   _logServer[4];
    unsigned int   _logPort;
  
  public:
    Logger(const byte server[], const unsigned int port);
    Logger();
    
    boolean connected();
    
    boolean connect();
    boolean connect(const byte[], const unsigned int);

    int available();
    int read();
    int peek();

    void flush();
    
    
    OUTPUTS(String);
    
    OUTPUTS(byte);
    
    OUTPUTS(long);
    
    OUTPUTS(int);
    
    size_t print(int, int);
    size_t println(int, int);
};


#endif /* defined Logger_h */
