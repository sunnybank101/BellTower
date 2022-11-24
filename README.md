# BellTower
Bell tower simulator setup

Main simulator flow  [Bell Sensor -> Arduino -> RaspberryPI -> Speakers]

[RPI -> PC]  for serial output to pc bell ringing software

Sensors used are readily available KY-032 IR obstacle sensors but others can be used with changes to the Arduino code
<img src="KY-032.png"  alt="KY-032" width="300" height="400">

<h2>Raspberry PI Setup</h2>
<p>Any version of a Raspberry PI is suitable for this purpose but one with a headphone socket is preferable
<list>
  <li>Install your preferred OS.. eg Raspberry Pi OS with desktop from https://www.raspberrypi.com/software/ with the user as "tower"
  <li>Follow the <a href="https://nodered.org/docs/getting-started/raspberrypi">instructions here to install NodeRed</a>
  <li>Log into NodeRed and import [<a href="nodered-flow.txt">nodered-flow.txt</a>].  Allow any library dependancies to be installed automatically as required
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

<h2>Final Setup</h2>
<list>
  <li>Connect the sensors to the Arduino as per the pin definitions in "arduinoKY032.ino"
  <li>Plug the Arduino into the Raspberry PI
  <li>Follow the instructions in the nodered flow comments to create symlinks to the Arduino serial port [ie no matter which USB the RPI is connected the arduino will always be addressable as /dev/ttyUSB_ARDUINO]
</list>

