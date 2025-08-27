import random
import time
## Case 1: Traffic Light Control Agent
class TrafficEnvironment: 
    #constructor to initialize the traffic light state
    def __init__(self): 
        self.traffic_density = "low"
        self.timer= 0
        self.light = "Red"

    def get_percept(self):
        return self.traffic_density, self.timer, self.light
    
    def update_environment(self):
        self.traffic_density = random.choice(["low", "High"])
        self.timer +=1

    def execute_action(self, action):
        if action == "SwitchToGreen":
            self.light = "Green"
            self.timer = 0
            print("Action: Light switched to Green")
        elif action == "SwitchToRed":
            self.light = "Red"
            self.timer = 1000
            print("Action: Light switched to Red")
        else: 
            self.light  = "Yellow"
            self.timer = 100
            print("Action: Light Switched to Yellow Get Ready")

class TrafficLightAgent: 
    def decide(self, traffic_density, timer, current_light): 
        if current_light == "Red" and traffic_density == "High":
            return "SwitchToGreen"
        elif current_light == "Green" and traffic_density =="low":
            return "SwitchToRed"
        else: 
            return "Yellow Light Get Ready"

# ======== Case 2: Smart Light Automation Agent ========
class RoomEnvironment: 
    def __init__(self): 
        self.presence = False
        self.time = "Day"
        self.light = "OFF"

    def get_percept(self): 
        return self.presence, self.time, self.light 
    
    def update_environment(self): 
        self.presence = random.choice(["True", "False"])
        self.time = random.choice(["Day", "Night"])

    def execute_action(self, action):
        if action == "TurnOn": 
            self.light = "ON"
            print("Action: Light turned ON")
        elif action == "TurnOff": 
            self.light = "OFF"
            print("Action: Light turned OFF")
        else: 
            print("Action: No changes")

class SmartLightAgent:
    def decide(self, presence, time_of_day, current_light): 
        if presence == "True" and time_of_day =="Night": 
            return "TurnOn"
        elif presence == "False" and time_of_day =="Day": 
            return "TurnOff"
        else: 
            return "No Changes "



##Simulation 
def simulate_traffic_agent(steps=5):
    print("\n ---- Traffic light agent simulation ")
    env = TrafficEnvironment()
    agent = TrafficLightAgent()


    for step in range(steps):
        print(f"\n [Steps: {step +1}]")
        env.update_environment()
        percepts = env.get_percept()
        print(f"Percepts: Traffic Density {percepts[0]}, Timer {percepts[1]}, Light {percepts[2]}")
        action = agent.decide(*percepts)
        env.execute_action(action)
        time.sleep(1)

def simulate_smart_light_agent(steps=5):
    print("Smart light agent: \n")
    env = RoomEnvironment()
    agent = SmartLightAgent()

    for step in range(steps): 
        print(f"\n Step: {step +1}")
        env.update_environment()
        percepts = env.get_percept()
        print(f" \n Percepts: presence = {percepts[0]}, Time = {percepts[1]}, Light = {percepts[2]}")
        action = agent.decide(*percepts)
        env.execute_action(action)
        time.sleep(1)


# run both 

if __name__ == "__main__":
    simulate_traffic_agent(steps=5)
    simulate_smart_light_agent(steps=5)




