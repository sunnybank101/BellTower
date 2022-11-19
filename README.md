# BellTower
Bell tower simulator setup

Main simulator flow  [Bell Sensor -> Arduino -> RaspberryPI -> Speakers]

[RPI -> PC]  for serial output to pc bell ringing software

Sensors used are readily available KY-032 IR obstacle sensors but others can be used with changes to the Arduino code

<h2>Arduino Setup</h2>
Using the ArduinoIDE upload "arduinoKY032.ino" to a suitable device.. eg an <a href="https://www.teachmemicro.com/wp-content/uploads/2019/06/Arduino-Nano-pinout.jpg">Arduino Nano</a><br>
Note: This code assumes an Arduino Nano but can easily be modified for other Arduino device.

<h2>Raspberry PI Setup</h2>
<p>Any version of a Raspberry PI is suitable for this purpose but one with a headphone socket is preferable
<list>
<li>Install your preferred OS.. eg Raspberry Pi OS with desktop from https://www.raspberrypi.com/software/
<li>Follow the instructions here to install NodeRed https://nodered.org/docs/getting-started/raspberrypi
<li>Log into NodeRed and import [flows.nodered]
<li>Plug the Arduino into the Raspberry PI
<li>Follow the instructions in the flow comment to create symlinks to the Arduino serial port (so that no matter what is plugged into the RPI serial ports the arduino will always be addressable as /dev/ttyUSB_ARDUINO
<li>.
</list>
