# Internet_of_Things-IoT

Problem Statement:-

Internet of Things (IoT) devices that use multiple sensors, actuators etc are finding their way into our homes at an alarming rate. The need to store, access and analyse the data from these devices becomes increasingly a top priority, mainly due to the requirement to provide real-time monitoring of activities happening within the home.

In this assignment, you will develop an active control system with the following specifications:
1. Read data captured from IoT devices that has been stored in text files. The files contain a day's worth of data captured at hourly 
   intervals. You are required to use the code provided (in the appendix below) but adapt it to make use of structures.
2. Process data to activate/deactivate devices. The sensor data is used either turn ON or OFF
   devices within the rooms being monitored
3. Display state of devices based on location and/or time.

The following devices are used as part of the home monitoring system:
● Humidity sensors (used to turn ON or OFF a ventilation system)
● Internal and external temperature sensors (used to turn ON or OFF a heating system)
● Motion sensors (used to turn ON or OFF lights in that room)

Data Files:-

The data files containing the days worth of information have been provided (on the Moodle assignment link) and contain information at which the sensor data has recorded. The files are named per the location where the data was recorded.

Each text file contains information in the following order:
timestamp, outside temperature and inside temperature​, ​humidity and ​motion sensors (6 samples over a 1 hour slot i.e. one sample every 10 minutes)
               00:33:44 11.5 15.7 57.2 9.5 10.7 7.5 9.5 7.1 11.5 
               01:33:44 8.5 18.8 41.5 11.6 9.5 9.6 10.7 8.5 10.5 
               02:33:44 10.4 13.5 49.5 9.5 7.5 11.8 10.5 7.7 7.5 
               03:33:44 10.9 15.5 59.5 8.5 7.7 9.5 10.5 11.9 11.5 
               04:33:44 9.8 14.5 57.3 9.5 10.2 8.5 11.5 11.9 9.2

Energy Consumption:-

Three files are available for data recorded in the living room, bedroom and kitchen. The data loaded from these files are then used to to:
1. Decide wherever to turn ON or OFF the associated device (e.g. heating, ventilation and lights)
2. Compute the energy consumption based on how long the devices have been ON on a daily basis. Daily consumption (per KiloJoules (KJ) is 
   calculated using equation 1.0 below

              Daily Consumption (KJ) = Daily Heating Energy + Daily Ventilation Energy + Daily Light Energy (Equation 1.0 Energy 
                                                                                                             Consumption)
   
            The information in Table 1.0 indicates the amount of energy consumer per hour when the respective devices are ON.
   
                                 Table 1.0 Energy Consumption
   
                                   Heating          300KJ
                                   Ventilation      250KJ
                                   Lights           100KJ


Your program will need the following functionality:

1. Read/load data from sensor files provided using the ReadDataFunction provided in Appendix. Note you will need to request the user to 
   provide a file location as a string for each file prior to running this function
     a. TimeDat[] for the time
     b. TempArr[][] for the temperatures
     c. HumiArr[] for humidity
     d. MotionArr[][] for motion sensors

Your system should therefore provide a menu system that provides options to the user by using functions ​for the following:

2. Control the state of the devices (turn ON or OFF)​ ​based on the user’s specifications
   It is expected the user will supply a threshold for each device, regardless of location, to turn ON

3. Calculate the energy consumption per day. It is expected you will use a 2D array (time v/s device) to store the states of the device at 
   any given time. E.g. one table per location. Each element in the array will contain either a 0 (OFF) or 1 (ON). The program will then 
   use the total units when each device is ON to calculate total energy (using equation 1.0 for every location and using table 1.0 to get 
   hourly energy).
   
   Energy consumption calculate is to be added to an Energy Log (Energy.txt) with a timestamp of the day that the information was 
   calculated on

4. Display the state of the devices for all rooms at a specific time of the day. Given that function 2 (control state of device) has been 
   provided first, print to the console the state of all devices for all the rooms for a specific time of day. For example, an input could 
   be: ​Humidity, 13:00

5. Monitor each device type individually. Given that function 2 (control state of device) has been provided first, print to the console the 
   state of the device for all the rooms for the entire day. For example, an input could be: Humidity

6. Write the state of the devices for an hourly basis in three different files (and separate from the ones you read in). If the file does 
   not exist the program should create one for you. For each location, write to a follow up file e.g. KitchenDevices.txt that displays for 
   each timestamp, wherever each device was ON or OFF
