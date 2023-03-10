## vehicle-direction-and-hazard-indicator-controller
#Description

The application uses FreeRtos to switch between 2 tasks (poller and FSM) and poller has higher priority
As the poller reads the switches and detect a press, the FSM handles led states 
When entering a state, a specific led, both leds or no leds blinks depending on the buttons state and the timer of this led starts counting.
Upon changing buttons' states, the timer of the currently running led stops, poller detect the  new state and FSM proceed to handle this new state 

#Finite State Machine for the Project
![image](https://user-images.githubusercontent.com/42315079/224442827-0a204fe4-bfb9-4e15-89b5-9b4205fefe9f.png)

Demo

