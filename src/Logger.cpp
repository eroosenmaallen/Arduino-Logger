/** @file	Logger.cpp
 *  @author	Eddie Roosenmaallen <eddie@page.ca>
 *  @date	June 2014
 */

#include "Logger.h"


Logger::Logger()
{
  _logServer[0] = 0;
  _logPort = 0;
}

Logger::Logger(const byte server[], const unsigned int port)
{
  memcpy(_logServer, server, 4);
  _logPort = port;
}


boolean Logger::connected(void)
{
  return logger.connected();
}


boolean Logger::connect()
{
  if (_logServer[0] == 0)
    return false;
  if (_logPort == 0)
    return false;
  
  return logger.connect(_logServer, _logPort);
}

boolean Logger::connect(const byte server[], const unsigned int port)
{
  memcpy(_logServer, server, 4);
  _logPort = port;
  
  logger.connect(_logServer, _logPort);
}


size_t Logger::print(String message)
{
  char buffer[64];
  
  if (!logger.connected())
    connect();
  
  message.toCharArray(buffer, 64);

  logger.print(buffer);
  Serial.print(buffer);
}

size_t Logger::println(String message)
{
  char buffer[64];
  
  if (!logger.connected())
    connect();
  
  message.toCharArray(buffer, 64);

  logger.println(buffer);
  Serial.println(buffer);
}

size_t Logger::write(String message)
{
  char buffer[64];
  
  if (!logger.connected())
    connect();
  
  message.toCharArray(buffer, 64);

  logger.write(buffer);
  Serial.write(buffer);
}

size_t Logger::print(byte ch)
{
  if (!logger.connected())
    connect();

  logger.print(ch);
  Serial.print(ch); 
}

size_t Logger::println(byte ch)
{
  if (!logger.connected())
    connect();

  logger.println(ch);
  Serial.println(ch); 
}

size_t Logger::write(byte ch)
{
  if (!logger.connected())
    connect();

  logger.write(ch);
  Serial.write(ch); 
}

size_t Logger::print(long l)
{
  if (!logger.connected())
    connect();

  logger.print(l);
  Serial.print(l); 
}

size_t Logger::println(long l)
{
  if (!logger.connected())
    connect();

  logger.println(l);
  Serial.println(l); 
}

size_t Logger::write(long l)
{
  if (!logger.connected())
    connect();

  logger.write(l);
  Serial.write(l); 
}

size_t Logger::print(int message)
{
  if (!logger.connected())
    connect();

  logger.print(message);
  Serial.print(message); 
}

size_t Logger::println(int message)
{
  if (!logger.connected())
    connect();

  logger.println(message);
  Serial.println(message); 
}

size_t Logger::write(int message)
{
  if (!logger.connected())
    connect();

  logger.write(message);
  Serial.write(message); 
}

size_t Logger::print(int message, int format)
{
  if (!logger.connected())
    connect();

  logger.print(message, format);
  Serial.print(message, format); 
}

size_t Logger::println(int message, int format)
{
  if (!logger.connected())
    connect();

  logger.println(message, format);
  Serial.println(message, format); 
}

void Logger::flush(void)
{
  logger.flush();
  Serial.flush();
}

int Logger::available()
{
  return logger.available();
}

int Logger::read()
{
  return logger.read();
}

int Logger::peek()
{
  return logger.peek();
}
