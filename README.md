## vehicle-direction-and-hazard-indicator-controller

# Description

The application uses FreeRtos to switch between 2 tasks (poller and FSM) and poller has higher priority
As the poller reads the switches and detect a press, the FSM handles led states 
When entering a state, a specific led, both leds or no leds blinks depending on the buttons state and the timer of this led starts counting.
Upon changing buttons' states, the timer of the currently running led stops, poller detect the  new state and FSM proceed to handle this new state 

# System Inputs 
The system has four inputs. One Push button is referred to as SW1. This button simulates the
input coming from the hazard button. Two on off switch inputs. They are combined in an SP3T
connection. Two terminals are connected to the MCU and are referred to as SW2 and SW3. The
third terminal is not connected. So, when selected, no input will be applied from the two switch
inputs. The combination simulates the input coming from the indicator arm with the three
selections, right indicator, left indicator and no indicator. The last input is an ON/OFF switch
with one terminal. The switch simulates the ignition key of the vehicle

# Finite State Machine for the Project
![image](https://user-images.githubusercontent.com/42315079/224442827-0a204fe4-bfb9-4e15-89b5-9b4205fefe9f.png)

# Demo


