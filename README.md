# BellTower Simulator
A simple bell tower simulator setup - for installation into a tower of church bells for silent ringing practice.

Main simulator flow  [Bell Sensor -> Arduino -> RaspberryPI -> Speakers]
<br>
plus optionally [RaspberryPI -> PC] for serial output to a pc or laptop running additional bell ringing software

The sensors being used are cheap and readily available KY-032 IR obstacle sensors (others could be used with changes to the Arduino code).  The KY-032 sensor is particularly good because R5 and R6 in the image below allow you to alter sensitivity and distance of detection.<br>
<img src="KY-032.png"  alt="KY-032" width="300" height="400">

The Raspberry PI is connected to the Arduino via a USB cable therefore providing power to it.  The Arduino in turn also powers all the KY-032 sensors (they are very low power).  3 wires are required to each sensor - Ground, +5v and Sense.  The Ground and +5v can be shared from the Arduino to all the sensors but each sensor requires its own Sense wire run independantly to the Arduino.  Therefore 8 bells require 10 wires from the Arduino to where the bells are hung

<h2>Raspberry PI Setup</h2>
<p>Any version of a Raspberry PI is suitable for this purpose but one with a headphone socket is preferable
<list>
  <li>Install your preferred OS.. eg Raspberry Pi OS with desktop from https://www.raspberrypi.com/software/ with the user as "tower"
  <li>Follow the <a href="https://nodered.org/docs/getting-started/raspberrypi">instructions here to install NodeRed</a>
  <li>Log into NodeRed and import [<a href="nodered-flow.txt">nodered-flow.txt</a>]
  <li>Allow any library dependencies to be installed automatically as required
  <li>Plug speakers into the arduino headphone socket
  <li>Transfer your preferred bell sound files as "1.wav" etc to  /home/tower/.node-red/audio.. Check the nodered 'configuration' nodes to confirm that it correctly specifies the location of the audio files 
  <li>Use the Test flows to check that the audio files are played correctly
</list>

<h2>Arduino Setup</h2>
<list>
  <li>Install the Arduino IDE (on whatever machine is easiest.. it can be the raspberry pi)
  <li>Using the ArduinoIDE upload [<a href="arduinoKY032.ino">arduinoKY032.ino</a>] to a suitable device.. eg an <a href="https://www.teachmemicro.com/wp-content/uploads/2019/06/Arduino-Nano-pinout.jpg">Arduino Nano</a><br>
</list>
Note: This code assumes an Arduino Nano but can easily be modified for other Arduino device.

<h2>Final Raspberry PI Setup</h2>
<list>
  <li>Connect test sensors to the Arduino as per the pin definitions in "arduinoKY032.ino"
  <li>Plug the Arduino into the Raspberry PI
  <li>Follow the instructions <a href="https://www.freva.com/assign-fixed-usb-port-names-to-your-raspberry-pi/">here</a> to create symlinks to the Arduino serial port [ie no matter which USB the RPI is connected the arduino will always be addressable as /dev/ttyUSB_ARDUINO]
</list>

<h2>Tower Installation [TBC]</h2>
  <li>The Raspberry PI and arduino are installed somewhere in the ringing chamber
  <li>8 core / 4 core alarm cable is used to run from the Arduino to where the bells hang (this is cheap and available in good lengths).  In many cases its probably best to run 2*8core cable up to a central spot then 4 core to each bell.
  <li>
  <li>
<list>
  
</list>


